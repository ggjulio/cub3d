/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:14:37 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/08 19:59:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cube_3d.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbru_fd(unsigned int n, int *fd)
{
	if (n >= 10)
		ft_putnbru_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', *fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbru_fd(-n, &fd);
	}
	else
		ft_putnbru_fd(n, &fd);
}

void	ft_putstr(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

int	deal_key(int key, void *param)
{
	(void)key;
	(void)param;
	ft_putnbr_fd(key, 1);
	ft_putstr("\n");
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Name windows");
//	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
//	mlx_key_hook(win_ptr, deal_key, (void *)0);
	img = mlx_new_image(1000, 1000);
	
	mlx_destroy_image(mlx_ptr);
	mlx_loop(mlx_ptr);
	if (ptr && win)
		mlx_destroy_window(ptr, win);
}

