/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:50:20 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/07 14:33:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include "cub3d.h"

int		count_str_arr(char **arr);
void	free_split(char **arr);
size_t	ft_strlen_charset(const char *s, const char *charset);
size_t	ft_strlen_no_end_space(const char *s);
void	print_map(void);

#endif
