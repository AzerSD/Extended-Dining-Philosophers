/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:42:32 by asioud            #+#    #+#             */
/*   Updated: 2023/03/10 12:28:01 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

void    clean_thread_mutexes(t_data *data);
void    destroy_thread_mutexes(t_data *data, int i);
void    destroy_data_mutexes(t_data *data);
void     philo_log(long int timestamp, int id, const char *status, t_data *data);

#endif