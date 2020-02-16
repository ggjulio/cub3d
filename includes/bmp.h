/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:12:59 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/16 15:59:25 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include "cub3d.h"

/*
** Sources :
**    https://www.fileformat.info/format/bmp/egff.htm
**	  http://fvirtman.free.fr/recueil/01_09_02_testbmp.c.php
** http://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/
**        2003_w/misc/bmp_file_format/bmp_file_format.htm
**
** -------------  Defines  -----------------
**	BMP_HEADER_SIZE = 14 in byte (octet)
*/

# define BMP_HEADER_SIZE 54

/*
** -------------  Header  -----------------
**	16b  type;             // Magic identifier: 0x4d42
**	32b  size;             // File size in bytes
**	16b  reserved1;        // Not used
**	16b  reserved2;        // Not used
**	32b  offset; // Offset to img data in bytes from beginning of file
**
**  ------------ Dib  Header Windows BITMAPINFOHEADER  ---------------
**	32b  dib_header_size;  // DIB Header size in bytes (40 bytes)
**	32b   width_px;         // Width of the image
**	32b   height_px;        // Height of image
**	16b  num_planes;       // Number of color planes
**	16b  bits_per_pixel;   // Bits per pixel
**	32b  compression;      // Compression type
**	32b  image_size_bytes; // Image size in bytes
**	32b   x_resolution_ppm; // Pixels per meter
**	32b   y_resolution_ppm; // Pixels per meter
**	32b  num_colors;       // Number of colors
**	32b  important_colors; // Important colors
*/

/*
** This is Windows BITMAPINFOHEADER
** : https://en.wikipedia.org/wiki/BMP_file_format
*/

void			save_image(char *file_name);

#endif
