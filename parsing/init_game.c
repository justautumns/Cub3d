/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:51:30 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/06/01 04:20:10 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialize(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->textures.img_east = NULL;
	game->textures.img_west = NULL;
	game->textures.img_north = NULL;
	game->textures.img_south = NULL;
	game->textures.img_height = 0;
	game->textures.img_width = 0;
	game->player.x = 1.5;
	game->player.y = 1.5;
	game->player.dir_x = -1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
}
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return ;
	game->win = mlx_new_window(game->mlx, 1600, 1400, "Cub3D");
	if (!game->win)
		return ;
	game->textures.img_north = mlx_xpm_file_to_image(game->mlx, game->textures.north, &(game->textures.img_width), &(game->textures.img_height));
	game->textures.img_south = mlx_xpm_file_to_image(game->mlx, game->textures.south, &(game->textures.img_width), &(game->textures.img_height));
	game->textures.img_west = mlx_xpm_file_to_image(game->mlx, game->textures.west, &(game->textures.img_width), &(game->textures.img_height));
	game->textures.img_east = mlx_xpm_file_to_image(game->mlx, game->textures.east, &(game->textures.img_width), &(game->textures.img_height));

	if (!game->textures.img_north || !game->textures.img_south || !game->textures.img_west || !game->textures.img_east)
		return ;
}
