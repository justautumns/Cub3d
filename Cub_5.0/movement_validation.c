/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:27:06 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/30 04:41:54 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	move_up_valid(t_data *d)
{
	int	map_x;
	int	map_y;

	map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED
			* cos(d->player_angle)) / TILE_SIZE;
	map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED
			* sin(d->player_angle)) / TILE_SIZE;
	if (d->map[map_y][map_x] == '1')
		return (-1);
	map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED
			* cos(d->player_angle - (20 * DEGREE))) / TILE_SIZE;
	map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED
			* sin(d->player_angle - (20 * DEGREE))) / TILE_SIZE;
	if (d->map[map_y][map_x] == '1')
		return (-1);
	map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED
			* cos(d->player_angle + (20 * DEGREE))) / TILE_SIZE;
	map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED
			* sin(d->player_angle + (20 * DEGREE))) / TILE_SIZE;
	if (d->map[map_y][map_x] == '1')
		return (-1);
	return (0);
}

int	move_down_valid(t_data *d)
{
	int	map_x;
	int	map_y;

	map_x = (int)(d->player_x - DIST_FROM_WALL * MOVE_SPEED
			* cos(d->player_angle)) / TILE_SIZE;
	map_y = (int)(d->player_y - DIST_FROM_WALL * MOVE_SPEED
			* sin(d->player_angle)) / TILE_SIZE;
	if (d->map[map_y][map_x] == '1')
		return (-1);
	map_x = (int)(d->player_x - DIST_FROM_WALL * MOVE_SPEED
			* cos(d->player_angle - (20 * DEGREE))) / TILE_SIZE;
	map_y = (int)(d->player_y - DIST_FROM_WALL * MOVE_SPEED
			* sin(d->player_angle - (20 * DEGREE))) / TILE_SIZE;
	if (d->map[map_y][map_x] == '1')
		return (-1);
	map_x = (int)(d->player_x - DIST_FROM_WALL * MOVE_SPEED
			* cos(d->player_angle + (20 * DEGREE))) / TILE_SIZE;
	map_y = (int)(d->player_y - DIST_FROM_WALL * MOVE_SPEED
			* sin(d->player_angle + (20 * DEGREE))) / TILE_SIZE;
	if (d->map[map_y][map_x] == '1')
		return (-1);
	return (0);
}

int	move_left_valid(t_data *d)
{
	int		map_x;
	int		map_y;
	double	angle_left;

	angle_left = d->player_angle - (PI / 2);
	map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED
			* cos(angle_left)) / TILE_SIZE;
	map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED
			* sin(angle_left)) / TILE_SIZE;
	if (d->map[map_y][map_x] == '1')
		return (-1);
	map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED
			* cos(angle_left - (20 * DEGREE))) / TILE_SIZE;
	map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED
			* sin(angle_left - (20 * DEGREE))) / TILE_SIZE;
	if (d->map[map_y][map_x] == '1')
		return (-1);
	map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED
			* cos(angle_left + (20 * DEGREE))) / TILE_SIZE;
	map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED
			* sin(angle_left + (20 * DEGREE))) / TILE_SIZE;
	if (d->map[map_y][map_x] == '1')
		return (-1);
	return (0);
}

int	move_right_valid(t_data *d)
{
	int		map_x;
	int		map_y;
	double	angle_right;

	angle_right = d->player_angle + (PI / 2);
	map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED
			* cos(angle_right)) / TILE_SIZE;
	map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED
			* sin(angle_right)) / TILE_SIZE;
	if (d->map[map_y][map_x] == '1')
		return (-1);
	map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED
			* cos(angle_right - (20 * DEGREE))) / TILE_SIZE;
	map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED
			* sin(angle_right - (20 * DEGREE))) / TILE_SIZE;
	if (d->map[map_y][map_x] == '1')
		return (-1);
	map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED
			* cos(angle_right + (20 * DEGREE))) / TILE_SIZE;
	map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED
			* sin(angle_right + (20 * DEGREE))) / TILE_SIZE;
	if (d->map[map_y][map_x] == '1')
		return (-1);
	return (0);
}

int	validate_move(t_data *d, char c)
{
	if (c == 'w' && move_up_valid(d) == -1)
		return (-1);
	if (c == 's' && move_down_valid(d) == -1)
		return (-1);
	if (c == 'a' && move_left_valid(d) == -1)
		return (-1);
	if (c == 'd' && move_right_valid(d) == -1)
		return (-1);
	return (0);
}
/*
 at line 27 && 81  // to not pass through corners 
 109 && 114 to not pass through corners
 */