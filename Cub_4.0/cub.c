/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:27:10 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/27 19:00:00 by mehmeyil         ###   ########.fr       */
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
	free(str);
	return (temp);
}

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
		y++;
	}
}

int	do_checks(int ac, char **av, t_data *d)
{
	if (ac != 2)
		return (ft_error("Please enter the arguments correctly\n"));
	if (arg_check(av[1]) == -1)
		return (ft_error("Incorrect cub file\n"));
	if (init_all(d) == -1)
		return (free_all(d), ft_error("Error: malloc failed\n"));
	if (check_map(av[1], d) == -1)
		return (free_all(d), -1);
	if (check_actual_map(d) == -1)
		return (free_all(d), -1);
	get_player(d);
	get_player_angle(d);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	d;

	if (do_checks(ac, av, &d) == -1)
		return (-1);
	d.root = mlx_init();
	d.window = mlx_new_window(d.root, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	d.floor_color = get_color_from_rgb(d.colors->f_r,
			d.colors->f_g, d.colors->f_b);
	d.ceiling_color = get_color_from_rgb(d.colors->c_r,
			d.colors->c_g, d.colors->c_b);
	if (get_tex_data(&d) == -1)
		return (free_all(&d), -1);
	draw_map(&d);
	mlx_hook(d.window, KeyPress, KeyPressMask, handle_key_press, &d);
	mlx_hook(d.window, KeyRelease, KeyReleaseMask, release_key, &d);
	mlx_hook(d.window, 17, 0, quit, &d);
	mlx_loop_hook(d.root, move_player, &d);
	mlx_loop(d.root);
}
