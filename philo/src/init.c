/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:17:23 by asioud            #+#    #+#             */
/*   Updated: 2023/03/11 13:46:50 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "philo.h"
#include "routine.h"
#include "utils.h"

int	handle_one_philo(t_philo *philo)
{
	if (philo->data->nb_philos == 1)
	{
		pthread_mutex_lock(&philo->data->philo_log);
		philo_log(get_time(), philo->id, YEL TAKEN_FORK RST, philo->data);
		ft_sleep(philo->data->time_to_die);
		philo_log(get_time(), philo->id, BRED DIED RST, philo->data);
		pthread_mutex_unlock(&philo->data->philo_log);
		return (1);
	}
	return (0);
}

t_error	init_data_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->philo_log, NULL))
		return (MUTEX_ERROR);
	if (pthread_mutex_init(&data->finish, NULL))
	{
		pthread_mutex_destroy(&data->philo_log);
		return (MUTEX_ERROR);
	}
	return (VALID);
}

t_error	init_philo_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->philo[i].fork, NULL)
			&& pthread_mutex_init(&data->philo[i].m_last_meal, NULL)
			&& pthread_mutex_init(&data->philo[i].m_nb_meal, NULL))
		{
			destroy_thread_mutexes(data, i);
			destroy_data_mutexes(data);
			return (MUTEX_ERROR);
		}
		i++;
	}
	return (VALID);
}

void	init_philo_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_create(&data->philo[i].t_id, NULL, &routine, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(data->philo[i].t_id, NULL);
		i++;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (handle_one_philo(philo))
		return (NULL);
	if (philo->id % 2 == 1)
	{
		if (philo->data->time_to_eat > philo->data->time_to_die)
			ft_sleep(philo->data->time_to_die * 2);
		else
			ft_sleep(philo->data->time_to_eat);
	}
	philo->last_meal = philo->data->start;
	pthread_mutex_lock(&philo->data->finish);
	while (!philo->data->stop && philo->nb_meal != philo->data->number_to_eat)
	{
		pthread_mutex_unlock(&philo->data->finish);
		pthread_create(&philo->t_alive, NULL, &still_alive, philo);
		pthread_detach(philo->t_alive);
		life_cycle(philo);
		pthread_mutex_lock(&philo->data->finish);
	}
	pthread_mutex_unlock(&philo->data->finish);
	ft_sleep(philo->data->time_to_die);
	return (NULL);
}
