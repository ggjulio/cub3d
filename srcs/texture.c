/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:06:47 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/26 15:36:18 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_texture(char id[3], char *value)
{
	t_texture tex;

	ft_strcpy(tex.id, id);
	(void)value;

}
/*
int valid_texture(char id[3], char *value)
{
	const char	symbol[10][3] = {"R", "NO", "SO", "WE", "EA", "F", "C", "S", "1", ""};
	uint8_t		found;
	int8_t		i;
	int			fd;
	int			is_path;

	found = 0;
	i = -1;
	while (symbol[++i])
		if (ft_strcmp(id, symbol[i]) == 0)
		{
			found = 1;
			break ;
		}
	fd = open(value, O_RDONLY);
	is_path = read(fd, NULL, 0) == -1 ? 0 : 1; 
	close(fd);
	
}
*/
