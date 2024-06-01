/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:15:27 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/06/01 15:17:01 by mtrojano         ###   ########.fr       */
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

// void	draw_map(t_game *game)
// {
// 	int	x;
// 	int	y;
// 	int	tile_size;
// 	int	color;

// 	y = 0;
// 	tile_size = TILE_SIZE;
// 	while (y < game->map.height)
// 	{
// 		x = 0;
// 		while (x < game->map.width)
// 		{
// 			if (game->map.map_data[y][x] == '1')
// 				color = 0xFFFFFF;
// 			else
// 				color = 0x00000;
// 			draw_square(game, x * tile_size, y * tile_size, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	int	tile_size;
	//int	color;
	int	line_len;
	//void	*wall;

	y = 0;
	tile_size = TILE_SIZE;
	//wall = mlx_xpm_file_to_image(game->mlx, "./textures/deneme0.xpm", &(game->textures.img_width), &(game->textures.img_height));
	// printf("\nheight = %d\nwidth = %d\n", game->map.height, game->map.width);
	while (game->map.map_data[y])
	{
		x = 0;
		line_len = ft_strlen(game->map.map_data[y]);
		while (x < line_len)
		{
			if (game->map.map_data[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->textures.img_north, x * tile_size, y * tile_size);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->textures.img_south, x * tile_size, y * tile_size);
			//draw_square(game, x * tile_size, y * tile_size, color);
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
