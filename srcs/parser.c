/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:59:48 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/10 14:49:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

int parse()
{

}

int load_cub(char *file)
{
	int ret;
	int fd;

	int fd = open("test", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		// line
		free(line);
	}

//	printf("%s|%d|\n", line, ret);
	free(line);
}
