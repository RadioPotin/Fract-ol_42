/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:20:41 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/18 12:55:29 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_fractol(void)
{
	t_fractol *fractol;

	fractol = fetchenv();
	//fractol algo
	mlx_hook(fractol->mlx_win, 2, 0, &event_manager, &fractol);
	mlx_hook(fractol->mlx_win, 17, 0, &ft_cleanclose, &fractol);
	mlx_loop(fractol->mlx_server_ptr);
	return (0);
}

int				main(int argc, char **argv)
{
	t_fractol *fractol;

(void)argv;
	fractol = fetchenv();
	if (argc != 2)
	{
		if (argc != 2)
		{
			ft_printf("Usage: ./fractol [Valid_FdF_Map_File]\n");
			ft_cleanclose();
		}
		return (-1);
	}
	ft_fractol();
	return (0);
}
