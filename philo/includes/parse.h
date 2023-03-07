/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:31:24 by asioud            #+#    #+#             */
/*   Updated: 2023/03/07 09:46:28 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"

# define GRN		"\e[0;32m"
# define BGRN	"\e[1;32m"
# define BRED	"\e[1;31m"
# define RST		"\e[0m"

enum    e_error_code
{
	VALID,
	NOT_A_NUMBER,
	NB_PARAM,
	OUT_OF_RANGE
};

int	display_err(enum e_error_code err);
int parse(int argc, char **argv, t_philo_data *philo);
enum e_error_code check_number(char *nb, int *param);
void init(int argc, int *param, t_philo_data *philo);

#endif

