/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:16:23 by mtrojano          #+#    #+#             */
/*   Updated: 2024/09/03 04:05:24 by mtrojano         ###   ########.fr       */
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
		if (tex_y > 63)
			tex_y = 63;
		if (d->tex_x > 63)
			d->tex_x = 63;
		if (d->tex_x < 0)
			d->tex_x = 0;
		color = ((int *)d->tex->tex_data[nesw])[tex_y
			* (d->tex->tex_line_len[nesw] / 4) + d->tex_x];
		if (start >= 0 && start < WIN_HEIGHT)
			d->img_addr[start * (d->line_length / 4) + x] = color;
		y++;
		start++;
	}
}

// int	determine_texture(t_data *d, int i)
// {
// 	// if (fabsf(d->dist_h - d->dist_v) < 0.000001)
// 	// 	printf("dist_h: %f -- dist_v: %f\n", d->dist_h, d->dist_v);
// 	if (d->dist_h < d->dist_v) //|| (fabsf(d->dist_h - d->dist_v) < 0.001 && ))
// 	{
// 		if (d->ray_angle > 180 * DEGREE)
// 			return (0);
// 		else if (d->ray_angle > 0 && d->ray_angle < 180 * DEGREE)
// 			return (2);
// 	}
// 	else
// 	{
// 		if (d->ray_angle > 90 * DEGREE && d->ray_angle < 270 * DEGREE)
// 			return (3);
// 		else
// 			return (1);
// 	}
// 	return (0);
// }

int	determine_texture(t_data *d, int i)
{
	if (d->dist_h < d->dist_v)
	{
		if (i > 0 && d->prev == VERT && fabs(d->prev_value - d->dist_h) < 1.0)
		{
			//printf("horizontal caught between vertical\n");
			return (d->prev_d);
		}
		if (d->ray_angle > 180 * DEGREE)
			return (0);
		else if (d->ray_angle > 0 && d->ray_angle < 180 * DEGREE)
			return (2);
	}
	else
	{
		if (i > 0 && d->prev == HORIZ && fabs(d->prev_value - d->dist_v) < 1.0)
		{
			//printf("vertical caught between horizontal\n");
			return (d->prev_d);
		}
		if (d->ray_angle > 90 * DEGREE && d->ray_angle < 270 * DEGREE)
			return (3);
		else
			return (1);
	}
	return (0);
}

void	determine_closer_contact_point(t_data *d, int i)
{
	if (d->dist_h < d->dist_v)
	{
		d->ray_x = d->horizontal_x;
		d->ray_y = d->horizontal_y;
		d->dist_h = d->dist_h * cos(d->player_angle - d->ray_angle);
		d->tex_slice_height = (70 * WIN_HEIGHT) / d->dist_h;
		if (determine_texture(d, i) == 0)
			d->tex_x = (int)fmod(d->ray_x, TILE_SIZE);
		else
			d->tex_x = TILE_SIZE - 1 - (int)fmod(d->ray_x, TILE_SIZE);
		d->prev = HORIZ;
		d->prev_value = d->dist_h + 1;
	}
	if (d->dist_v < d->dist_h)
	{
		d->ray_x = d->vertical_x;
		d->ray_y = d->vertical_y;
		d->dist_v = d->dist_v * cos(d->player_angle - d->ray_angle);
		d->tex_slice_height = (70 * WIN_HEIGHT) / d->dist_v;
		if (determine_texture(d, i) == 1)
			d->tex_x = (int)fmod(d->ray_y, TILE_SIZE);
		else
			d->tex_x = TILE_SIZE - 1 - (int)fmod(d->ray_y, TILE_SIZE);
		d->prev = VERT;
		d->prev_value = d->dist_v;
	}
}

// void	determine_closer_contact_point(t_data *d, int i)
// {
// 	if (d->dist_h < d->dist_v)
// 	{
// 		d->ray_x = d->horizontal_x;
// 		d->ray_y = d->horizontal_y;
// 		d->dist_h = d->dist_h * cos(d->player_angle - d->ray_angle);
// 		d->tex_slice_height = (70 * WIN_HEIGHT) / d->dist_h;
// 		if (determine_texture(d, i) == 0)
// 			d->tex_x = (int)fmod(d->ray_x, TILE_SIZE);
// 		else
// 			d->tex_x = TILE_SIZE - 1 - (int)fmod(d->ray_x, TILE_SIZE);
// 		d->prev = HORIZ;
// 		d->prev_value = d->dist_h;
// 	}
// 	if (d->dist_v < d->dist_h)
// 	{
// 		d->ray_x = d->vertical_x;
// 		d->ray_y = d->vertical_y;
// 		d->dist_v = d->dist_v * cos(d->player_angle - d->ray_angle);
// 		d->tex_slice_height = (70 * WIN_HEIGHT) / d->dist_v;
// 		if (determine_texture(d, i) == 1)
// 			d->tex_x = (int)fmod(d->ray_y, TILE_SIZE);
// 		else
// 			d->tex_x = TILE_SIZE - 1 - (int)fmod(d->ray_y, TILE_SIZE);
// 		d->prev = VERT;
// 		d->prev_value = d->dist_v;
// 	}
// }


void	cast_rays(t_data *d)
{
	int		i;
	double	ray_step;

	i = 0;
	ray_step = FOV * DEGREE / WIN_WIDTH;
	d->ray_angle = d->player_angle - (FOV / 2) * DEGREE;
	normalize_angle(&d->ray_angle);
	while (i < WIN_WIDTH)
	{
		d->dist_h = 1000000;
		d->dist_v = 1000000;
		horizontal_line_check(d);
		vertical_line_check(d);
		determine_closer_contact_point(d, i);
		d->ray_direction = determine_texture(d, i);
		d->prev_d = d->ray_direction;
		draw_tex_slice(d, i, d->ray_direction);
		d->ray_angle += ray_step;
		normalize_angle(&d->ray_angle);
		i++;
	}
	mlx_put_image_to_window(d->root, d->window, d->image, 0, 0);
}
