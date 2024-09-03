/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:27:10 by mtrojano          #+#    #+#             */
/*   Updated: 2024/09/02 22:29:56 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_map_line_len(t_data *d)
{
	int	i;

	i = 0;
	d->map_line_len = malloc(d->map_max_height * sizeof(int));
	if (!d->map_line_len)
		return (ft_error("Error: malloc failed\n"));
	while (i < d->map_max_height)
	{
		d->map_line_len[i] = ft_strlen_n(d->map[i]);
		i++;
	}
	return (0);
}

char	*remove_nl(char *str)
{
	char	*temp;
	int		i;

	temp = malloc(ft_strlen_n(str));
	if (!temp)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
		if (str[i] == '\n')
			break ;
	}
	temp[i] = '\0';
	free(str);
	return (temp);
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
	if (get_map_line_len(d) == -1)
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
	if (!d.root)
		return (free_all(&d), ft_error("Error : mlx init fails\n"));
	d.window = mlx_new_window(d.root, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!d.window)
		return (free_all(&d), ft_error("Error : mlx window call fails\n"));
	d.floor_color = get_color_from_rgb(d.colors->f_r,
			d.colors->f_g, d.colors->f_b);
	d.ceiling_color = get_color_from_rgb(d.colors->c_r,
			d.colors->c_g, d.colors->c_b);
	if (get_tex_data(&d, 0) == -1)
		return (free_all(&d), -1);
	draw_map(&d);
	mlx_hook(d.window, KeyPress, KeyPressMask, handle_key_press, &d);
	mlx_hook(d.window, KeyRelease, KeyReleaseMask, release_key, &d);
	mlx_hook(d.window, 17, 0, quit, &d);
	mlx_loop_hook(d.root, move_player, &d);
	mlx_loop(d.root);
}
