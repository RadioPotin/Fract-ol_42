/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:27:16 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/07 12:10:13 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		store_event(t_event *holder, int (*f)(int), int n)
{
	int i;

	i = 0;
	while (i < n)
		holder[i++] = *f;
}

static t_event	*fetchevent(void)
{
	static t_event	holder[160];

	if (!holder[0])
	{
		store_event(&holder[0], &do_nothing, 160);
		store_event(&holder[53], &ft_cleanclose, 1);
		store_event(&holder[8], &switch_palette, 1);
		store_event(&holder[49], &lockmvt, 1);
		store_event(&holder[82], &ft_switch, 10);
		store_event(&holder[123], &ft_translate, 4);
		store_event(&holder[115], &ft_reset, 1);
	}
	return (holder);
}

static int		is_event(int k)
{
	if (k == 53 || k == 49 || (k >= 123 && k <= 126)
			|| k == 115 || (k >= 82 && k <= 92)
				|| k == 1 || k == 2 || k == 5 || k == 4 || k == 8)
		return (1);
	return (0);
}

int				event_manager(int k)
{
	t_fractol	*fractol;
	t_event		*event_holder;

	if (!is_event(k))
		return (0);
	fractol = fetchenv();
	event_holder = fetchevent();
	mlx_destroy_image(fractol->mlx_server_ptr, fractol->mlx_img_ptr);
	fractol->mlx_img_ptr = mlx_new_image(fractol->mlx_server_ptr,\
			WIDTH, HEIGHT);
	fractol->img_tab = (int *)mlx_get_data_addr(fractol->mlx_img_ptr,
			&fractol->bpp, &fractol->size_line, &fractol->endian);
	event_holder[k](k);
	menudisplay();
	return (1);
}
