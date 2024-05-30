/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:22:11 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/30 21:20:16 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	mlx_loop(game.mlx);
	return (0);
}
