/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:15:06 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/11 13:36:09 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		mlx_events(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_win, 2, 0, event_manager, &fractol);
	mlx_hook(fractol->mlx_win, 6, 0, &mouse_mvt, &fractol);
	mlx_hook(fractol->mlx_win, 17, 0, ft_cleanclose, &fractol);
	mlx_loop_hook(fractol->mlx_server_ptr, mouse_mvt, &fractol);
	mlx_mouse_hook(fractol->mlx_win, mouse_zm, fractol);
}

static int		ft_fractol(int fractal)
{
	t_fractol		*fractol;

	fractol = fetchenv();
	fractol->requested_fractal = fractal;
	initialize_variables(fractal);
	fractol->fractal_type = fractal_holder(fractal);
	fractol->fractal_compute = set_compute_struct(fractal);
	draw();
	menudisplay();
	mlx_events(fractol);
	mlx_loop(fractol->mlx_server_ptr);
	return (0);
}

int				main(int argc, char **argv)
{
	int			fractal;

	if ((fractal = get_arguments(argc, argv)) < 0)
	{
		if (fractal == -1)
			usage();
		else if (fractal == -2)
			print_fractal_list();
		return (fractal);
	}
	ft_fractol(fractal);
	return (0);
}
