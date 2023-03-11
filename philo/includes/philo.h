/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:46:10 by asioud            #+#    #+#             */
/*   Updated: 2023/03/11 13:26:39 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define GRN "\e[0;32m"
# define BGRN "\e[1;32m"
# define BRED "\e[1;31m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define RST "\e[0m"

# define DIED "died"
# define IS_EATING MAG"is eating"RST
# define IS_SLEEPING BLU"is sleeping"RST
# define IS_THINKING CYN"is thinking"RST
# define TAKEN_FORK YEL"has taken a fork"RST

typedef enum e_error_code
{
	VALID,
	NOT_A_NUMBER,
	MALLOC_ERROR,
	NB_PARAM,
	OUT_OF_RANGE,
	MUTEX_ERROR
}					t_error;

typedef struct s_data
{
	struct s_philo	*philo;
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				number_to_eat;
	int				stop;
	long int		start;
	pthread_mutex_t	finish;
	pthread_mutex_t	philo_log;
}					t_data;

typedef struct s_philo
{
	t_data			*data;
	long int		last_meal;
	int				nb_meal;
	int				id;
	pthread_t		t_id;
	pthread_t		alive;
	pthread_t		t_alive;
	pthread_mutex_t	fork;
	pthread_mutex_t	m_last_meal;
	pthread_mutex_t	m_nb_meal;
}					t_philo;

#endif