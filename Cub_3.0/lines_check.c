/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:58:52 by mtrojano          #+#    #+#             */
/*   Updated: 2024/07/20 11:46:57 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	get_distance_vertical(t_data *d, int start)
{
	while (start < d->map_max_width)
	{
		d->map_x = (int)(d->ray_x) / TILE_SIZE;
		d->map_y = (int)(d->ray_y) / TILE_SIZE;
		if (d->map_x >= 0 && d->map_y >= 0 && d->map_x < d->map_max_width
			&& d->map_y < d->map_max_height
			&& d->map[d->map_y][d->map_x] == '1')
		{
			d->dist_v = distance(d->player_x, d->player_y, d->ray_x, d->ray_y);
			d->vertical_x = d->ray_x;
			d->vertical_y = d->ray_y;
			return ;
		}
		else
		{
			d->ray_x += d->x_offset;
			d->ray_y += d->y_offset;
			start++;
		}
	}
}

void	vertical_line_check(t_data *d)
{
	float	_tan;
	int		start;

	start = 0;
	_tan = -tan(d->ray_angle);
	if (d->ray_angle > PI / 2 && d->ray_angle < (3 * PI / 2)) // looking left
	{
		d->ray_x = (((int)d->player_x / TILE_SIZE) * TILE_SIZE) - 0.0001;
		d->ray_y = (d->player_x - d->ray_x) * _tan + d->player_y;
		d->x_offset = -TILE_SIZE;
		d->y_offset = -d->x_offset * _tan;
		d->ray_direction = 2;
	}
	else if (d->ray_angle < PI / 2 || d->ray_angle > (3 * PI / 2)) // looking right
	{
		d->ray_x = (((int)d->player_x / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
		d->ray_y = (d->player_x - d->ray_x) * _tan + d->player_y;
		d->x_offset = TILE_SIZE;
		d->y_offset = -d->x_offset * _tan;
		d->ray_direction = 3;
	}
	else
		start = d->map_max_width;
	get_distance_vertical(d, start);
}

void	get_distance_horizontal(t_data *d, int start)
{
	while (start < d->map_max_height)
	{
		d->map_x = (int)(d->ray_x) / TILE_SIZE;
		d->map_y = (int)(d->ray_y) / TILE_SIZE;
		if (d->map_x >= 0 && d->map_y >= 0 && d->map_x < d->map_max_width
			&& d->map_y < d->map_max_height
			&& d->map[d->map_y][d->map_x] == '1')
		{
			d->dist_h = distance(d->player_x, d->player_y, d->ray_x, d->ray_y);
			d->horizontal_x = d->ray_x;
			d->horizontal_y = d->ray_y;
			return ;
		}
		else
		{
			d->ray_x += d->x_offset;
			d->ray_y += d->y_offset;
			start++;
		}
	}
}

void	horizontal_line_check(t_data *d)
{
	float	_tan;
	int		start;

	start = 0;
	_tan = -1 / tan(d->ray_angle);
	if (d->ray_angle > PI) // looking up
	{
		d->ray_y = (((int)d->player_y / TILE_SIZE) * TILE_SIZE) - 0.0001;
		d->ray_x = (d->player_y - d->ray_y) * _tan + d->player_x;
		d->y_offset = -TILE_SIZE;
		d->x_offset = -d->y_offset * _tan;
		d->ray_direction = 0;
	}
	else if (d->ray_angle < PI) // looking down
	{
		d->ray_y = (((int)d->player_y / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
		d->ray_x = (d->player_y - d->ray_y) * _tan + d->player_x;
		d->y_offset = TILE_SIZE;
		d->x_offset = -d->y_offset * _tan;
		d->ray_direction = 1;
	}
	else
		start = d->map_max_height;
	get_distance_horizontal(d, start);
}
