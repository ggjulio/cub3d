/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:51:02 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/30 18:29:18 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		create_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	t_color color;

	color.rgba.r = r;
	color.rgba.g = g;
	color.rgba.b = b;
	color.rgba.a = a;
	return (color);
}

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
	t_color color;
	char	**arr;

	arr = ft_split(format, ',');
	color = create_color(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]), 0);
	return (color);
}
