/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:07:31 by asioud            #+#    #+#             */
/*   Updated: 2023/03/11 11:46:54 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	clean_thread_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->philo[i].fork);
		pthread_mutex_destroy(&data->philo[i].m_last_meal);
		pthread_mutex_destroy(&data->philo[i].m_nb_meal);
		i++;
	}
}

void	philo_log(long int timestamp, int id, const char *status, t_data *data)
{
	int	time;

	pthread_mutex_lock(&data->finish);
	if (data->stop == 1)
	{
		pthread_mutex_unlock(&data->finish);
		return ;
	}
	pthread_mutex_unlock(&data->finish);
	time = timestamp - data->start;
	printf(WHT "%d %d %s\n" RST, time, id + 1, status);
}

void	destroy_thread_mutexes(t_data *data, int i)
{
	while (--i)
	{
		pthread_mutex_destroy(&data->philo[i].fork);
		pthread_mutex_destroy(&data->philo[i].m_last_meal);
		pthread_mutex_destroy(&data->philo[i].m_nb_meal);
	}
}

void	destroy_data_mutexes(t_data *data)
{
	pthread_mutex_destroy(&data->philo_log);
	pthread_mutex_destroy(&data->finish);
}
