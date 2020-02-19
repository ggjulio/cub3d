// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mlx_windows.m                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/02/18 15:35:33 by juligonz          #+#    #+#             //
//   Updated: 2020/02/19 12:44:36 by juligonz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include    <stdio.h>

#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>

#include    "mlx_int.h"
#include    "mlx_new_window.h"

int     mlx_window_get_size(mlx_win_list_t *win, int *width, int *height)
{
	NSRect    pos;

	pos = [(id)(win->winid) frame];
	*width = NSWidth(pos);
	*height = NSHeight(pos);
	return (0);
}

int     mlx_window_set_min_size(mlx_win_list_t *win, int width, int height)
{
	id        theWindow;
	NSSize	  windowMinSize;

	theWindow = [(id)(win->winid) win];
	windowMinSize.width = width;
	windowMinSize.height = height;
	[theWindow setMinSize:windowMinSize];
	return (0);
}

int     mlx_window_set_max_size(mlx_win_list_t *win, int width, int height)
{
	id        theWindow;
	NSSize	  windowMaxSize;

	theWindow = [(id)(win->winid) win];
	windowMaxSize.width = width;
	windowMaxSize.height = height;
	[theWindow setMaxSize:windowMaxSize];
	return (0);
}

int     mlx_screen_get_resolution(int *width, int *height)
{
	NSRect rect= [[NSScreen mainScreen] frame];

	*width = (int)rect.size.width;
	*height = (int)rect.size.height;
	return (0);
}
