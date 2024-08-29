/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:47:13 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/30 01:08:59 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	normalize_angle(float *angle)
{
	if ((*angle) > (2 * PI))
		(*angle) -= 2 * PI;
	else if ((*angle) < 0)
		(*angle) += 2 * PI;
}

void	rotate_left(t_data *d)
{
	if (d->dist_h < 80 || d->dist_h < 80)
		d->player_angle -= ROTATION_SPEED_W;
	// Adjust player_angle by angle_offset
	else
		d->player_angle -= ROTATION_SPEED;
	// Normalize player_angle to be within 0 to 2*PI
	normalize_angle(&d->player_angle);
}

void	rotate_right(t_data *d)
{
	if (d->dist_h < 80 || d->dist_h < 80)
		d->player_angle += ROTATION_SPEED_W;
	// Adjust player_angle by angle_offset
	else
		d->player_angle += ROTATION_SPEED;
	// Normalize player_angle to be within 0 to 2*PI
	normalize_angle(&d->player_angle);
}
