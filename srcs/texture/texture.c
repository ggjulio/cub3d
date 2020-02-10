/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:06:47 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/06 16:44:53 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			valid_file(char *filename)
{
	int	fd;
	int	is_valid;

	fd = open(filename, O_RDONLY);
	is_valid = read(fd, NULL, 0) == -1 ? 0 : 1;
	close(fd);
	return (is_valid);
}

int			valid_id(char id[3])
{
	const char	ids[10][3] = {"R", "NO", "SO", "WE", "EA",
							"F", "C", "S", "1", ""};
	int8_t		i;

	i = -1;
	while (ids[++i])
		if (ft_strcmp(id, ids[i]) == 0)
			return (1);
	return (0);
}

t_texture	create_texture(char id[3], char *value)
{
	t_texture tex;

	ft_bzero(&tex, sizeof(t_texture));
	if (!valid_id(id))
		return (tex);
	ft_strcpy(tex.id, id);
	if (valid_color_fmt(value))
	{
		tex.is_color = 1;
		tex.color = create_color_from_str(value);
		tex.is_valid = 1;
	}
	else if (valid_file(value))
	{
		tex.is_texture = 1;
		if ((tex.filename = malloc(sizeof(char) * ft_strlen(value))) == NULL)
			return (tex);
		ft_strcpy(tex.filename, value);
		tex.is_valid = 1;
		if (!ft_valid_extention(value, ".xpm"))
			tex.is_bad_extention = 1;
	}
	return (tex);
}

int			init_texture(t_texture *tex)
{
	if (tex->is_color)
		return (0);
	tex->img_ptr = mlx_xpm_file_to_image(g_app.mlx_ptr, tex->filename,
									&(tex->size.x), &(tex->size.y));
	if (tex->img_ptr != NULL)
		tex->pixels = mlx_get_data_addr(tex->img_ptr, &(tex->bits_per_pixel),
									&(tex->size_line), &(tex->endian));
	else
		return (-1);
	return (0);
}

void		destroy_texture(t_texture tex)
{
	if (tex.is_valid && tex.is_texture)
	{
		if (tex.img_ptr != NULL)
			mlx_destroy_image(g_app.mlx_ptr, tex.img_ptr);
		free(tex.filename);
	}
}