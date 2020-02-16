/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:24:01 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/16 16:03:17 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_header(uint8_t header[54], \
				uint32_t size_file, uint32_t width_px, uint32_t height_px)
{
	uint32_t *size;
	uint32_t *width;
	uint32_t *height;

	size = (unsigned int *)&header[2];
	width = (unsigned int *)&header[18];
	height = (unsigned int *)&header[22];
	*size = size_file;
	*width = width_px;
	*height = height_px;
}

void	write_header(int fd, int w, int h)
{
	static uint8_t header[54] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, \
			0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24};

	set_header(
		header,
		54 + (w * sizeof(char) + (4 - ((w * sizeof(char)) % 4)) % 4) * h,
		w,
		h);
	write(fd, header, 54);
}

void	write_line(int w, int **img, int fd)
{
	int		i;
	t_color	color;
	int		*tmp;

	tmp = *img - w;
	*img = tmp;
	i = 0;
	while (i++ < w)
	{
		(tmp)++;
		color.c = (*tmp);
		write(fd, &color.c, sizeof(char) * 3);
	}
	write(fd, "000", (4 - ((w * sizeof(char)) % 4)) % 4);
}

void	save_image(char *file_name)
{
	int fd;
	int i;
	int *image;

	image = &((int *)g_app.pixels)[g_app.res.x * g_app.res.y];
	if ((fd = open(file_name, O_RDWR | O_CREAT, 0666)) == -1)
	{
		ft_error("Can't save screenshot.");
		return ;
	}
	i = 0;
	write_header(fd, g_app.res.x, g_app.res.y);
	while (i++ < g_app.res.y)
		write_line(g_app.res.x, &image, fd);
	close(fd);
}
