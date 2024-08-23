/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:27:10 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/23 05:09:09 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*remove_nl(char *str)
{
	char	*temp;
	int		i;

	temp = malloc(ft_strlen_n(str));
	i = 0;
	while (str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}



// int	get_map(t_data *d, char *path)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open(path, O_RDONLY);
// 	if (fd < 1)
// 		return (-1);
// 	d->map = malloc(1 * sizeof(char *));
// 	if (!d->map)
// 		return (-1);
// 	d->map[0] = NULL;
// 	//while ()
// 		d->map = add_to_array(d->map, remove_nl(line));

// }



void	display_map(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (d->map[y])
	{
		x = 0;
		while (d->map[y][x])
		{
			printf("%c", d->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void middle_check(t_data *d)
{
	printf("paths:\nno: %s\nso: %s\nwe: %s\nea: %s\n", d->tex->no_path, d->tex->so_path, d->tex->we_path, d->tex->ea_path);
	printf("colors: \nF: %s\nC: %s\n", d->color_f, d->color_c);
	printf("f_r = %d\nf_g = %d\nf_b = %d\nc_r = %d\nc_g = %d\nc_b = %d\n", d->colors->f_r, d->colors->f_g, d->colors->f_b, d->colors->c_r, d->colors->c_g, d->colors->c_b);
	display_map(d);
	free_all(d);
	exit (0);
}

int	main(int ac, char **av)
{
	t_data	d;

	if (ac != 2)
		return (ft_error("Please enter the arguments correctly\n"));
	if (arg_check(av[1]) == -1)
		return (ft_error("Incorrect cub file\n"));
	if (init_all(&d) == -1)
		return (free_all(&d), ft_error("Error: malloc failed\n"));
	if (check_map(av[1], &d) == -1)
		return (free_all(&d), -1);
	if (check_actual_map(&d) == -1)
		return (free_all(&d), -1);
	get_player(&d);
	get_player_angle(&d);
	d.root = mlx_init();
	d.floor_color = get_color_from_rgb(220, 100, 0); // here we can pass now f_r, f_g and so on, from colors struct
	d.ceiling_color = get_color_from_rgb(225, 30, 0);
	d.window = mlx_new_window(d.root, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (get_tex_data(&d) == -1)
		return (-1);
	draw_map(&d);
	mlx_hook(d.window, KeyPress, KeyPressMask, handle_key_press, &d);
	mlx_hook(d.window, KeyRelease, KeyReleaseMask, release_key, &d);
	mlx_loop_hook(d.root, move_player, &d);
	mlx_loop(d.root);
}
