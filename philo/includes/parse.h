/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:31:24 by asioud            #+#    #+#             */
/*   Updated: 2023/03/08 13:54:51 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "philo.h"

int		display_err(t_error err);
int		parse(int argc, char **argv, t_data *data);
t_error	check_number(char *nb, int *param);
int		init(int argc, int *param, t_data *data);

#endif
