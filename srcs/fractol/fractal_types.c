/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:43:39 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/10 13:14:48 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(void)
{
	t_fractol	*f;
	double		tmp;
	int			n;

	f = fetchenv();
	n = f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i;
	while (n < 4 && f->var.iter < f->max_iteration)
	{
		tmp = f->var.z_r * f->var.z_r - f->var.z_i * f->var.z_i + f->var.c_r;
		f->var.z_i = 2.0 * f->var.z_i * f->var.z_r + f->var.c_i;
		f->var.z_r = tmp;
		f->var.iter++;
		n = f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i;
	}
	return (0);
}

int		julia(void)
{
	t_fractol	*f;
	int			n;
	double		tmp;

	f = fetchenv();
	n = f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i;
	while (n < 4 && f->var.iter < f->max_iteration)
	{
		tmp = f->var.z_r * f->var.z_r - f->var.z_i * f->var.z_i + f->var.c_r;
		f->var.z_i = 2.0 * f->var.z_i * f->var.z_r + f->var.c_i;
		f->var.z_r = tmp;
		f->var.iter++;
		n = f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i;
	}
	return (0);
}
