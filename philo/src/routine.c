/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:16:54 by asioud            #+#    #+#             */
/*   Updated: 2023/03/11 13:39:37 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "routine.h"
#include "time.h"
#include "utils.h"

void	nap_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->philo_log);
	philo_log(get_time(), philo->id, BLU IS_SLEEPING RST, philo->data);
	pthread_mutex_unlock(&philo->data->philo_log);
	if (philo->data->time_to_sleep > philo->data->time_to_die)
		ft_sleep(philo->data->time_to_die * 2);
	else
		ft_sleep(philo->data->time_to_sleep);
	pthread_mutex_lock(&philo->data->philo_log);
	philo_log(get_time(), philo->id, MAG IS_THINKING RST, philo->data);
	pthread_mutex_unlock(&philo->data->philo_log);
}

void	eat(t_philo *philo)
{
	t_data	*data;
	int		id;

	data = philo->data;
	id = philo->id;
	pthread_mutex_lock(&philo->m_last_meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->m_last_meal);
	pthread_mutex_lock(&philo->m_nb_meal);
	philo->nb_meal += 1;
	pthread_mutex_unlock(&philo->m_nb_meal);
	pthread_mutex_lock(&philo->data->philo_log);
	philo_log(get_time(), philo->id, GRN IS_EATING RST, data);
	pthread_mutex_unlock(&philo->data->philo_log);
	if (data->time_to_eat > data->time_to_die)
		ft_sleep(data->time_to_die * 2);
	else
		ft_sleep(data->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	if (id == data->nb_philos - 1)
		pthread_mutex_unlock(&data->philo[0].fork);
	else
		pthread_mutex_unlock(&data->philo[id + 1].fork);
}

void	take_fork(t_philo *philo)
{
	t_data		*data;
	uint16_t	id;

	id = philo->id;
	data = philo->data;
	pthread_mutex_lock(&data->philo[id].fork);
	if (id == data->nb_philos - 1)
		pthread_mutex_lock(&data->philo[0].fork);
	else
		pthread_mutex_lock(&data->philo[id + 1].fork);
	pthread_mutex_lock(&data->philo_log);
	philo_log(get_time(), philo->id, YEL TAKEN_FORK RST, data);
	philo_log(get_time(), philo->id, YEL TAKEN_FORK RST, data);
	pthread_mutex_unlock(&data->philo_log);
}

void	*still_alive(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_sleep(philo->data->time_to_die);
	pthread_mutex_lock(&philo->m_last_meal);
	if (get_time() - philo->last_meal >= philo->data->time_to_die)
	{
		pthread_mutex_unlock(&philo->m_last_meal);
		pthread_mutex_lock(&philo->m_nb_meal);
		if (philo->data->number_to_eat != philo->nb_meal)
		{
			pthread_mutex_unlock(&philo->m_nb_meal);
			pthread_mutex_lock(&philo->data->philo_log);
			philo_log(get_time(), philo->id, RED DIED RST, philo->data);
			pthread_mutex_unlock(&philo->data->philo_log);
		}
		else
			pthread_mutex_unlock(&philo->m_nb_meal);
		pthread_mutex_lock(&philo->data->finish);
		philo->data->stop = 1;
		pthread_mutex_unlock(&philo->data->finish);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->m_last_meal);
	return (NULL);
}

void	life_cycle(t_philo *philo)
{
	take_fork(philo);
	eat(philo);
	nap_time(philo);
}
