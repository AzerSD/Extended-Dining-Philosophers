/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:59:50 by asioud            #+#    #+#             */
/*   Updated: 2023/03/10 18:08:45 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <unistd.h>

/**
 * @return returns the current time in milliseconds
 * second * 1000 = milliseconds
 * microseconds / 1000 = milliseconds
*/
long int   get_time(void);

/**
 * @brief Sleep for time milliseconds
*/
void	ft_sleep(long int time);

#endif
