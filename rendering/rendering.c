/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:15:27 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/31 18:27:35 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_square(t_game *game, int x, int y, int color)
{
	int	m;
	int	k;

	m = 0;
	while (m < TILE_SIZE)
	{
		k = 0;
		while (k < TILE_SIZE)
		{
			mlx_pixel_put(game->mlx, game->win, x + m, y + k, color);
			k++;
		}
		m++;
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	int	tile_size;
	int	color;

	y = 0;
	tile_size = TILE_SIZE;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map_data[y][x] == '1')
				color = 0xFFFFFF;
			else
				color = 0x00000;
			draw_square(game, x * tile_size, y * tile_size, color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
{
	int	player_pos_x;
	int	player_pos_y;
	int	line_lenght;
	int	end_x;
	int	end_y;

	player_pos_x = game->player.x * TILE_SIZE;
	player_pos_y = game->player.y * TILE_SIZE;
	mlx_pixel_put(game->mlx, game->win, player_pos_x, player_pos_y, 0xFF0000);
	line_lenght = 20;
	end_x = player_pos_x + game->player.dir_x * line_lenght;
	end_y = player_pos_y + game->player.dir_y * line_lenght;
	mlx_pixel_put(game->mlx, game->win, end_x, end_y, 0xFF0000);
}

int	render_next_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	draw_player(game);
	return (0);
}
