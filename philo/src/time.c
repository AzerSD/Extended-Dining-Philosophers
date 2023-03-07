/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:45:28 by asioud            #+#    #+#             */
/*   Updated: 2023/03/07 09:15:07 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/time.h>
#include <unistd.h>

u_int64_t	get_time(void)
{
	struct timeval  time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);

	return ((u_int64_t)(time.tv_sec * 1000) + (u_int64_t)(time.tv_sec / 1000));
}

void	ft_sleep(int ms)
{
	long long goal;

	goal = get_time + ms;
	while (get_time() < goal)
		usleep(300);
}
