/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:27:10 by mtrojano          #+#    #+#             */
/*   Updated: 2024/07/26 07:37:33 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*remove_nl(char *str)
{
	char	*temp;
	int		i;

	temp = malloc(ft_strlen(str));
	i = 0;
	while (str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

void	get_map(t_data *d)
{
	FILE	*file;
	char	line[100];
	int		y;

	y = 0;
	file = fopen("map.cub", "r+");
	d->map_max_height = 0;
	d->map_max_width = 0;
	d->map = malloc(1 * sizeof(char *));
	d->map[0] = NULL;
	while (fgets(line, 100, file))
		d->map = add_to_array(d->map, remove_nl(line));
	while (d->map[y])
	{
		d->map_max_height++;
		y++;
	}
	y = 0;
	d->map_max_width = ft_strlen(d->map[y]);
	while (d->map[y])
	{
		if (ft_strlen(d->map[y]) > d->map_max_width)
			d->map_max_width = ft_strlen(d->map[y]);
		y++;
	}
}

void	get_player(t_data *d)
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
			if (d->map[y][x] == 'N' || d->map[y][x] == 'S'
				|| d->map[y][x] == 'E' || d->map[y][x] == 'W')
			{
				d->player_x = x;
				d->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_player_angle(t_data *d)
{
	if (d->map[(int)d->player_y][(int)d->player_x] == 'N')
		d->player_angle = NORTH;
	if (d->map[(int)d->player_y][(int)d->player_x] == 'S')
		d->player_angle = SOUTH;
	if (d->map[(int)d->player_y][(int)d->player_x] == 'E')
		d->player_angle = EAST;
	if (d->map[(int)d->player_y][(int)d->player_x] == 'W')
		d->player_angle = WEST;
	d->player_x = d->player_x * TILE_SIZE + (TILE_SIZE / 2);
	d->player_y = d->player_y * TILE_SIZE + (TILE_SIZE / 2);
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
		printf("\n");
		y++;
	}
}

void	init_textures(t_data *d)
{
	int	i;

	i = 0;
	d->tex = malloc(sizeof(t_tex));
	d->tex->tex_path = malloc(5 * sizeof(char *));
	d->tex->tex_path[0] = NULL;
	d->tex->tex_path = add_to_array(d->tex->tex_path, "textures/deneme0.xpm\0");
	d->tex->tex_path = add_to_array(d->tex->tex_path, "textures/deneme1.xpm\0");
	d->tex->tex_path = add_to_array(d->tex->tex_path, "textures/deneme2.xpm\0");
	d->tex->tex_path = add_to_array(d->tex->tex_path, "textures/deneme3.xpm\0");
	d->tex->tex_data = malloc(4 * sizeof(char *));
	d->tex->tex_data[0] = NULL;
	d->tex->textures = malloc(4 * sizeof(void *));
	d->tex->textures[0] = NULL;
	d->tex->tex_bpp = malloc(4 * sizeof(int));
	d->tex->tex_line_len = malloc(4 * sizeof(int));
	d->tex->tex_endian = malloc(4 * sizeof(int));
	while (i < 4)
	{
		d->tex->textures[i] = mlx_xpm_file_to_image(d->root,
			d->tex->tex_path[i], &d->img_x, &d->img_y);
		d->tex->tex_data[i] = mlx_get_data_addr(d->tex->textures[i],
			&d->tex->tex_bpp[i], &d->tex->tex_line_len[i], &d->tex->tex_endian[i]);
		i++;
	}
}

void	init_key_struct(t_data *d)
{
	d->keys.w = 0;
	d->keys.s = 0;
	d->keys.a = 0;
	d->keys.d = 0;
	d->keys.left = 0;
	d->keys.right = 0;
}

int	main(void)
{
	t_data	d;

	init_key_struct(&d);
	get_map(&d);
	get_player(&d);
	get_player_angle(&d);
	//printf("map max height = %d\nmap max width = %d\n", d.map_max_height, d.map_max_width);
	d.root = mlx_init();
	d.floor_color = get_color_from_rgb(220, 100, 0);
	d.ceiling_color = get_color_from_rgb(225, 30, 0);
	d.window = mlx_new_window(d.root, WIN_WIDTH, WIN_HEIGHT, "cat_test");
	init_textures(&d);
	draw_map(&d);
	// cast_rays(&d);
	// mlx_put_image_to_window(d.root, d.window, d.tex->textures[0], 0, 0);
	// mlx_put_image_to_window(d.root, d.window, d.tex->textures[1], 64, 0);
	// mlx_put_image_to_window(d.root, d.window, d.tex->textures[2], 128, 0);
	// mlx_put_image_to_window(d.root, d.window, d.tex->textures[3], 192, 0);
	mlx_hook(d.window, KeyPress, KeyPressMask, handle_key_press, &d);
	mlx_hook(d.window, KeyRelease, KeyReleaseMask, release_key, &d);
	mlx_loop_hook(d.root, move_player, &d);
	mlx_loop(d.root);
}
