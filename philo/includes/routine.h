/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:29:40 by asioud            #+#    #+#             */
/*   Updated: 2023/03/08 10:47:15 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef life_cycle_H
# define life_cycle_H

# include "philo.h"

void    nap_time(t_philo *philo);
void    eat(t_philo *philo);
void    take_fork(t_philo *philo);
void    life_cycle(t_philo *philo);
void	*still_alive(void *arg);

#endif