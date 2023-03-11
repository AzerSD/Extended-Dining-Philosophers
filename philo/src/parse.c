/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:20:40 by asioud            #+#    #+#             */
/*   Updated: 2023/03/11 09:11:14 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "philo.h"

int	parse(int argc, char **argv, t_data *data)
{
	int		*param;
	int		i;
	t_error	err;

	if (argc != 5 && argc != 6)
		return (NB_PARAM);
	param = malloc(sizeof(int) * (argc - 1));
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
		if ((i == 0 && param[i] < 1) || ((i == 4) \
			&& param[i] < 0) || ((i != 0 && i != 4) && param[i] < 60))
			return (OUT_OF_RANGE);
		i++;
	}
	if (init(argc, param, data))
		return (MALLOC_ERROR);
	return (VALID);
}

t_error	check_number(char *nb, int *param)
{
	int			i;
	static int	c;

	i = 0;
	while (nb[i])
	{
		if (nb[i] < '0' || nb[i] > '9')
		{
			free(param);
			return (NOT_A_NUMBER);
		}
		i++;
	}
	param[c] = ft_atoi(nb);
	c += 1;
	return (VALID);
}

int	display_err(t_error err)
{
	if (err == NOT_A_NUMBER)
		printf(BRED "Error: Only Numeric Input Is Accepted!!!!\n" RST);
	else if (err == NB_PARAM)
		printf(BRED "Error: Wrong Number Of Parameters!!!!\n" RST);
	else if (err == OUT_OF_RANGE)
		printf(BRED "Error: Numbers Out Of Range!!!!\n" RST);
	else if (err == MALLOC_ERROR)
		printf(BRED "System Error: Philo Allocation Failed!!!!\n" RST);
	printf(BGRN "Usage: ./philo");
	printf(GRN " number_of_philosophers time_to_die time_to_eat time_to_sleep \
			[number_of_times_each_philosopher_must_eat]" RST);
	return (0);
}

int	init(int argc, int *param, t_data *data)
{
	int	i;

	if (argc == 6)
		data->number_to_eat = param[4];
	else
		data->number_to_eat = -1;
	data->nb_philos = param[0];
	data->time_to_die = param[1];
	data->time_to_eat = param[2];
	data->time_to_sleep = param[3];
	data->stop = 0;
	free(param);
	data->philo = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philo == NULL)
		return (1);
	i = 0;
	while (i < data->nb_philos)
	{
		data->philo[i] = (t_philo){0};
		data->philo[i].data = data;
		data->philo[i].id = i;
		i++;
	}
	return (0);
}
