// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mlx_windows.m                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/02/18 15:35:33 by juligonz          #+#    #+#             //
//   Updated: 2020/02/18 15:41:02 by juligonz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include    <stdio.h>

#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>

#include    "mlx_int.h"
#include    "mlx_new_window.h"

int     mlx_window_get_size(mlx_win_list_t *win, int *x, int *y)
{
	CGPoint   point;
	id        thewin;
	NSRect    pos;

	thewin = [(id)(win->winid) win];
	pos = [(id)(win->winid) frame];
	*x = NSWidth(pos);
	*y = NSHeight(pos);
	return (0);
}
