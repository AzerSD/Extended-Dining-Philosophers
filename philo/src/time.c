/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:45:28 by asioud            #+#    #+#             */
/*   Updated: 2023/03/07 10:44:44 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/time.h>
#include <unistd.h>

/**
 * @return returns the current time in milliseconds by
 * converting time to milliseconds by 
 * multiplying the number of seconds by 1000
 * and adding the number of microseconds divided by 1000
*/
uint32_t	get_time(void)
{
	struct timeval  time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);

	return ((uint32_t)(time.tv_sec * 1000) + (uint32_t)(time.tv_sec / 1000));
}


void	ft_sleep(uint32_t ms)
{
	uint32_t	goal;

	goal = get_time() + ms;
	while (get_time() < goal)
		usleep(300);
}
