/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:16:23 by mtrojano          #+#    #+#             */
/*   Updated: 2024/07/20 17:32:38 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_tex_slice(t_data *d, int x, int nesw)
{
	int	tex_y;
	int	start;
	int	y;
	int	color;

	y = 0;
	start = (WIN_HEIGHT - d->tex_slice_height) / 2;
	while (y < d->tex_slice_height)
	{
		tex_y = (y * TILE_SIZE) / d->tex_slice_height;
		color = ((int *)d->tex->tex_data[nesw])[tex_y
			* (d->tex->tex_line_len[nesw] / 4) + d->tex_x];
		if (start >= 0 && start < WIN_HEIGHT)
			d->img_addr[start * (d->line_length / 4) + x] = color;
		y++;
		start++;
	}
}

int	determine_texture(t_data *d)
{
	if (d->dist_h < d->dist_v)
	{
		if (d->ray_angle > 180 * DEGREE)
			return (0); // NORTH
		else if (d->ray_angle > 0 && d->ray_angle < 180 * DEGREE)
			return (1); // SOUTH
	}
	else
	{
		if (d->ray_angle > 90 * DEGREE && d->ray_angle < 270 * DEGREE)
			return (2); // WEST
		else
			return (3); // EAST
	}
	return (0);
}

void	determine_closer_contact_point(t_data *d)
{
	if (d->dist_h < d->dist_v)
	{
		d->ray_x = d->horizontal_x;
		d->ray_y = d->horizontal_y;
		d->dist_h = d->dist_h * cos(d->player_angle - d->ray_angle); // for fish eye effect
		d->tex_slice_height = (70 * WIN_HEIGHT) / d->dist_h; // 100 cause map is 10 by 10, later should be max x and/or y or actually whatever works best
		// if (d->tex_slice_height > WIN_HEIGHT)
		// 	d->tex_slice_height = WIN_HEIGHT;
		d->tex_x = (int)fmod(d->ray_x, TILE_SIZE);
	}
	if (d->dist_v < d->dist_h)
	{
		d->ray_x = d->vertical_x;
		d->ray_y = d->vertical_y;
		d->dist_v = d->dist_v * cos(d->player_angle - d->ray_angle);
		d->tex_slice_height = (70 * WIN_HEIGHT) / d->dist_v;
		// if (d->tex_slice_height > WIN_HEIGHT)
		// 	d->tex_slice_height = WIN_HEIGHT;
		d->tex_x = (int)fmod(d->ray_y, TILE_SIZE);
	}
}

void	cast_rays(t_data *d)
{
	int		i;
	float	ray_step;

	i = 0;
	ray_step = FOV * DEGREE / WIN_WIDTH;
	d->ray_angle = d->player_angle - (FOV / 2) * DEGREE; // minus half of FOV
	normalize_angle(&d->ray_angle);
	while (i < WIN_WIDTH)
	{
		d->dist_h = 1000000;
		d->dist_v = 1000000;
		horizontal_line_check(d);
		vertical_line_check(d);
		determine_closer_contact_point(d);
		d->ray_direction = determine_texture(d);
		draw_tex_slice(d, i, d->ray_direction);
		d->ray_angle += ray_step;
		normalize_angle(&d->ray_angle);
		i++;
	}
	mlx_put_image_to_window(d->root, d->window, d->image, 0, 0);
}
