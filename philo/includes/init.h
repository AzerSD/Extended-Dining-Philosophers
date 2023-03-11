/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:56:41 by asioud            #+#    #+#             */
/*   Updated: 2023/03/10 13:30:46 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo.h"

/**
 * Init philo_log and finish mutexes and destroy them in case one failed
 * @param data philo data
*/
t_error	init_data_mutexes(t_data *data);

/**
 * Init fork, m_last_meal, m_nb_meal mutexes and destroy them in case one failed
 * @param data program data
*/
t_error	init_philo_mutexes(t_data *data);

/**
 * Initialize and create philosopher threads
 * @param data program data
*/
void	init_philo_thread(t_data *data);

/**
 * Execute the newly created philospher_thread
 * @param arg a philosopher thread
*/
void	*routine(void *arg);

#endif