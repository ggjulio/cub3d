/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:04:25 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/07 14:33:28 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen_charset(const char *s, const char *charset)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (ft_in_charset(s[i], charset))
			len++;
		i++;
	}
	return (len);
}

size_t  ft_strlen_no_end_space(const char *s)
{
    size_t i;
    size_t len;

    i = 0;
    len = 0;
    while (s[i])
    {
        if (s[i] != ' ')
            len = ++i;
        else
            i++;
    }
    return (len);
}

int		count_str_arr(char **arr)
{
	int len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	free_split(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr[i]);
	free(arr);
	arr = NULL;
}

void    print_map(void)
{
    int i;
    int j;

    i = -1;
    j = -1;
    while (++i < g_game.map_len_y)
    {
        j = -1;
        while (++j < g_game.map_len_x)
            ft_printf("%c", map_value(j, i) + '0');
        ft_printf("\n");
    }
}
