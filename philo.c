/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:20:46 by asioud            #+#    #+#             */
/*   Updated: 2023/03/06 11:38:21 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pthread.h>
# include <stdio.h>

# include "philo.h"
# include "parse.h"

int main(int argc, char **argv)
{
    t_philo_data    philo;
    enum e_error_code err;
    
    err = parse(argc, argv, &philo);
    if (err != VALID)
        display_err(err);
    printf("%d\n", philo.number_to_eat);
	printf("%d\n", philo.nb_philos);
	printf("%d\n", philo.time_to_die);
	printf("%d\n", philo.time_to_eat);
	printf("%d\n", philo.time_to_sleep);
}