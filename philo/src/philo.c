/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:20:46 by asioud            #+#    #+#             */
/*   Updated: 2023/03/06 19:02:15 by asioud           ###   ########.fr       */
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
    
}