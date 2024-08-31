/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:53:20 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/29 20:58:53 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int	check_if_outside_v(t_data *d)
{
	if (d->map_y < 0 || d->map_x < 0 || d->map_y > d->map_max_height
		|| d->map_x > ft_strlen_n(d->map[d->map_y]))
	{
		d->dist_v = distance(d->player_x, d->player_y, d->ray_x, d->ray_y);
		d->vertical_x = d->ray_x;
		d->vertical_y = d->ray_y;
		return (-1);
	}
	return (0);
}

int	check_if_outside_h(t_data *d)
{
	if (d->map_y < 0 || d->map_x < 0 || d->map_y > d->map_max_height
		|| d->map_x > ft_strlen_n(d->map[d->map_y]))
	{
		d->dist_h = distance(d->player_x, d->player_y, d->ray_x, d->ray_y);
		d->horizontal_x = d->ray_x;
		d->horizontal_y = d->ray_y;
		return (-1);
	}
	return (0);
}
