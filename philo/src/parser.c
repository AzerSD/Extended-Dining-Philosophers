/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:20:40 by asioud            #+#    #+#             */
/*   Updated: 2023/03/07 09:40:03 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "philo.h"
#include "parse.h"

int parse(int argc, char **argv, t_philo_data *philo)
{
	int					param[argc - 1];
	int					i;
	enum e_error_code	err;
	
	if (argc != 5 && argc != 6)
		return (NB_PARAM);
	i = 0;
	while (++i < argc)
	{
		err = check_number(argv[i], param);
		if (err != VALID)
			return (err);
	}
	i = 0;
	while (i < argc - 1)
	{
		if ((i == 0 && param[i] < 1) || (i != 0 && param[i] < 60))
			return (OUT_OF_RANGE);
		i++;
	}
	init(argc, param, philo);
	return (VALID);
}

enum e_error_code check_number(char *nb, int *param)
{
	int			i;
	static int  c;

	i = 0;
	while (nb[i])
	{
		if (nb[i] < '0' || nb[i] > '9')
			return (NOT_A_NUMBER);
		i++;
	}
	param[c] = ft_atoi(nb);
	c++;
	return (VALID);
}

int	display_err(enum e_error_code err)
{
	if (err == NOT_A_NUMBER)
		printf(BRED"Error: Only Numeric Input Is Accepted!!!!\n"RST);
	else if (err == NB_PARAM)
		printf(BRED"Error: Wrong Number Of Parameters!!!!\n"RST);
	else if (err == OUT_OF_RANGE)
		printf(BRED"Error: Numbers Out Of Range!!!!\n"RST);
	printf(BGRN"Usage: ./philo");
	printf(GRN" number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"RST);
    return 0;
}

void init(int argc, int *param, t_philo_data *philo)
{
	if (argc == 6)
		philo->number_to_eat = param[4];
	philo->nb_philos = param[0];
	philo->time_to_die = param[1];
	philo->time_to_eat = param[2];
	philo->time_to_sleep = param[3];
}
