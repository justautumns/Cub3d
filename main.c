/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:22:11 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/30 18:58:24 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }
// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char *dest;

// 	dest = data->adress + (y * data->lenght + x * (data->bits / 8));
// 	*(unsigned int*)dest = color;
// }
// void	drawing_square(t_data *data , int x , int y, int size, int color)
// {
// 	int i = 0;
// 	int j;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			my_mlx_pixel_put(data, x + i, y + j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

int main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (printf("Error, Invalid number of args\n"), -1);
	if (arg_check(av[1]) != 0)
		return (printf("Error, Bad file type\n"), -1);
	if (!parse_map(av[1], &game))
		return (printf("Error, map parsing went wrong!"), -1);

	return (0);
}
