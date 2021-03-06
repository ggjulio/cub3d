/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:51:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/10 14:41:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			no_digit_between_comma(char *format)
{
	char	**arr;
	int		len;

	arr = ft_split(format, ',');
	len = count_str_arr(arr);
	free_split(arr);
	return (len != 3);
}

int			valid_color_fmt(char *format)
{
	int	i;
	int	nb_comma;
	int nb;

	nb_comma = 0;
	i = -1;
	nb = 0;
	while (format[++i])
	{
		if (!ft_isdigit(format[i]) && format[i] != ',')
			return (0);
		if (format[i] == ',')
		{
			if (nb > 255)
				return (0);
			nb_comma++;
			nb = 0;
		}
		else
			nb = nb * 10 + format[i] - '0';
	}
	if (nb_comma != 2 || nb > 255 || no_digit_between_comma(format))
		return (0);
	return (1);
}

t_color		create_color_from_str(char *format)
{
	t_color result;
	char	**arr;

	arr = ft_split(format, ',');
	result = create_color(ft_atoi(arr[0]), ft_atoi(arr[1]),
						ft_atoi(arr[2]), 255);
	free_split(arr);
	return (result);
}
