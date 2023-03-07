/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:28:32 by asioud            #+#    #+#             */
/*   Updated: 2023/03/07 09:31:07 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdbool.h>

int32_t     ft_atoi(const char *str);
bool        ft_isspace(int32_t c);
bool        ft_isdigit(char c);


#endif