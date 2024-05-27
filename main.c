/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:22:11 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/27 19:28:12 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dest;

	dest = data->adress + (y * data->lenght + x * (data->bits / 8));
	*(unsigned int*)dest = color;
}
void	drawing_square(t_data *data , int x , int y, int size, int color)
{
	int i = 0;
	int j;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void init_char(t_data *data)
{
	data->adress = NULL;
	data->img = NULL;
	data->bits = 0;
	data->lenght = 0;
	data->endian = 0;
}
int main(int ac, char **av)
{
	if (ac > 1)
	{
		void *mlx;
		t_data character;
		void *mlx_win;
		// void *img;
		init_char(&character);
		mlx = mlx_init();
		character.img = mlx_new_image(mlx, 580, 260);
		mlx_win = mlx_new_window(mlx,1080, 640, av[1]);
		// img = mlx_new_image(mlx, 220, 120);
		// mlx_loop(mlx);
		character.adress = mlx_get_data_addr(character.img, &character.bits, &character.lenght, &character.endian);
		//my_mlx_pixel_put(&character, 125, 125, 0x000FF0000);
		drawing_square(&character, 150, 150, 120, 0x000FF0000);
		mlx_put_image_to_window(mlx, mlx_win, character.img, 0, 0);
		mlx_loop(mlx);
	}
	return (0);
}
