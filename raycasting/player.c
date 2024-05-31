/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:31:07 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/31 18:41:16 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(game->mlx, game->win);
	else if (keycode == XK_w)
		game->player.y -= 0.1;
	else if (keycode == XK_s)
		game->player.y += 0.1;
	else if (keycode == XK_a)
		game->player.x -= 0.1;
	else if (keycode == XK_d)
		game->player.x += 0.1;
	return (0);
}
