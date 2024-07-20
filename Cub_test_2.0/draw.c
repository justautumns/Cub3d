/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:26:54 by mtrojano          #+#    #+#             */
/*   Updated: 2024/07/20 11:32:06 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_ceiling(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			d->img_addr[y * (d->line_length / 4) + x] = d->ceiling_color;
			x++;
		}
		y++;
	}
}

void	draw_floor(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			d->img_addr[y * (d->line_length / 4) + x] = d->floor_color;
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *d)
{
	d->image = mlx_new_image(d->root, WIN_WIDTH, WIN_HEIGHT);
	d->img_addr = (int *)mlx_get_data_addr(d->image,
			&d->bpp, &d->line_length, &d->endian);
	draw_ceiling(d);
	draw_floor(d);
	cast_rays(d);
}
