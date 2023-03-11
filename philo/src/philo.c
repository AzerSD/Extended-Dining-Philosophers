/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:20:46 by asioud            #+#    #+#             */
/*   Updated: 2023/03/11 12:33:55 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parse.h"
#include "philo.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_error	err;

	err = parse(argc, argv, &data);
	if (err != VALID)
	{
		display_err(err);
		return (1);
	}
	if (init_data_mutexes(&data) != VALID || init_philo_mutexes(&data) != VALID)
		return (1);
	data.start = get_time();
	init_philo_thread(&data);
	free_data(&data);
	free(data.philo);
	return (0);
}
