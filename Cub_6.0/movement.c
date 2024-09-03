/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:44:36 by mtrojano          #+#    #+#             */
/*   Updated: 2024/09/03 00:03:40 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_right(t_data *d)
{
	double	angle_right;

	angle_right = d->player_angle + (PI / 2);
	d->player_x = d->player_x + MOVE_SPEED * cos(angle_right);
	d->player_y = d->player_y + MOVE_SPEED * sin(angle_right);
}

void	move_left(t_data *d)
{
	double	angle_left;

	angle_left = d->player_angle - (PI / 2);
	d->player_x = d->player_x + MOVE_SPEED * cos(angle_left);
	d->player_y = d->player_y + MOVE_SPEED * sin(angle_left);
}

void	move_up(t_data *d)
{
	d->player_x = d->player_x + MOVE_SPEED * cos(d->player_angle);
	d->player_y = d->player_y + MOVE_SPEED * sin(d->player_angle);
}

void	move_down(t_data *d)
{
	d->player_x = d->player_x - MOVE_SPEED * cos(d->player_angle);
	d->player_y = d->player_y - MOVE_SPEED * sin(d->player_angle);
}

int	move_player(t_data *d)
{
	if (d->keys.w == 1)
		if (validate_move(d, 'w') == 0)
			move_up(d);
	if (d->keys.s == 1)
		if (validate_move(d, 's') == 0)
			move_down(d);
	if (d->keys.a == 1)
		if (validate_move(d, 'a') == 0)
			move_left(d);
	if (d->keys.d == 1)
		if (validate_move(d, 'd') == 0)
			move_right(d);
	if (d->keys.left == 1)
		rotate_left(d);
	if (d->keys.right == 1)
		rotate_right(d);
	if (d->keys.w || d->keys.s || d->keys.a || d->keys.d
		|| d->keys.left || d->keys.right)
	{
		mlx_destroy_image(d->root, d->image);
		draw_map(d);
		cast_rays(d);
	}
	return (0);
}
