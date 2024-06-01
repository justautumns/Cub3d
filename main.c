/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:22:11 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/06/01 20:02:06 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map)
{
	int x = 0;
	int y = 0;

	if (!map)
		return ;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			printf("%c", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (printf("Error, Invalid number of args\n"), -1);
	if (arg_check(av[1]) != 0)
		return (printf("Error, Bad file type\n"), -1);
	initialize(&game);
	parse_cub_file(av[1], &game);
	init_game(&game);
	print_map(game.map.map_data);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_key_hook(game.win, key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
