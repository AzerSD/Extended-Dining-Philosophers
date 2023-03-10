/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:45:28 by asioud            #+#    #+#             */
/*   Updated: 2023/03/10 18:05:37 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "time.h"

long int	get_time(void)
{
	struct timeval  time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);

	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_sleep(long int time)
{
	usleep(time * 1000);
}
