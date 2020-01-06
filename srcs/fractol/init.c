/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:10:59 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/06 17:08:43 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char				**fractal_list(void)
{
	static char *list[3];

	if (!list[0])
	{
		list[0] = "julia";
		list[1] = "mandelbrot";
	}
	return (list);
}

t_fractol			*fetchenv(void)
{
	static t_fractol *fractol = NULL;

	if (fractol == NULL)
	{
		if (!(fractol = ft_memalloc(sizeof(t_fractol))))
			return (NULL);
		fractol->mlx_server_ptr = mlx_init();
		fractol->mlx_img_ptr = mlx_new_image(fractol->mlx_server_ptr,\
				WIDTH, HEIGHT);
		fractol->img_tab = (int *)mlx_get_data_addr(fractol->mlx_img_ptr, &fractol->bpp,\
				&fractol->size_line, &fractol->endian);
		fractol->mlx_win = mlx_new_window(fractol->mlx_server_ptr, WIDTH, HEIGHT,\
				"Fractalizer");
		ft_bzero(&fractol->eve, sizeof(t_eve));
	}
	return (fractol);
}