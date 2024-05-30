/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:51:30 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/30 21:03:14 by mehmeyil         ###   ########.fr       */
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
}
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return ;
	game->win = mlx_new_window(game->mlx, 800, 600, "Cub3D");
	if (!game->win)
		return ;
	game->textures.img_north = mlx_xpm_file_to_image(game->mlx, game->textures.north, &(game->map.width), &(game->map.height));
	game->textures.img_south = mlx_xpm_file_to_image(game->mlx, game->textures.south, &(game->map.width), &(game->map.height));
	game->textures.img_west = mlx_xpm_file_to_image(game->mlx, game->textures.west, &(game->map.width), &(game->map.height));
	game->textures.img_east = mlx_xpm_file_to_image(game->mlx, game->textures.east, &(game->map.width), &(game->map.height));

	if (!game->textures.img_north || !game->textures.img_south || !game->textures.img_west || !game->textures.img_east)
		return ;
}
