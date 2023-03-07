/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:20:46 by asioud            #+#    #+#             */
/*   Updated: 2023/03/07 10:47:21 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pthread.h>
# include <stdio.h>

# include "philo.h"
# include "parse.h"

void    *routine()
{
    static int i = 0;
    printf("%d. hello, World!\n", i);
    i++;
    return 0;
}

void spawn()
{
    pthread_t t1;
    
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    
}
int main(int argc, char **argv)
{
    t_philo_data    philo;
    enum e_error_code err;
    
    err = parse(argc, argv, &philo);
    if (err != VALID)
        display_err(err);

    for (int i = 0; i < 10000000; i++)
        spawn();
    
}