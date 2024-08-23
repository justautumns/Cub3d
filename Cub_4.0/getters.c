/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 07:13:26 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/23 06:13:02 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

void	get_map_size(t_data *d)
{
	int	y;

	y = 0;
	d->map_max_height = 0;
	d->map_max_width = 0;
	while (d->map[y])
	{
		d->map_max_height++;
		y++;
	}
	y = 0;
	d->map_max_width = ft_strlen_n(d->map[y]);
	while (d->map[y])
	{
		if (ft_strlen_n(d->map[y]) > d->map_max_width)
			d->map_max_width = ft_strlen_n(d->map[y]);
		y++;
	}
}

int	assign_tex_path_to_arr(t_data *d)
{
	int	i;

	i = 0;
	d->tex->tex_path[0] = ft_strdup(d->tex->no_path);
	if (!d->tex->tex_path[0])
		return (ft_error("Error: malloc failed\n"));
	d->tex->tex_path[1] = ft_strdup(d->tex->ea_path);
	if (!d->tex->tex_path[1])
		return (ft_error("Error: malloc failed\n"));
	d->tex->tex_path[2] = ft_strdup(d->tex->so_path);
	if (!d->tex->tex_path[2])
		return (ft_error("Error: malloc failed\n"));
	d->tex->tex_path[3] = ft_strdup(d->tex->we_path);
	if (!d->tex->tex_path[3])
		return (ft_error("Error: malloc failed\n"));
	d->tex->tex_path[4] = NULL;
	while (i < 4)
	{
		d->tex->tex_path[i] = remove_nl(d->tex->tex_path[i]);
		if (!d->tex->tex_path[i])
			return (ft_error("Error: malloc failed\n"));
		i++;
	}
	return (0);
}

int	get_tex_data(t_data *d)
{
	int	i;

	i = 0;
	if (assign_tex_path_to_arr(d) == -1)
		return (-1);
	while (i < 4)
	{
		d->tex->textures[i] = mlx_xpm_file_to_image(d->root,
				d->tex->tex_path[i], &d->img_x, &d->img_y);
		if (!d->tex->textures[i])
			return (ft_error("mlx_xpm_to_img failed\n"));
		d->tex->tex_data[i] = mlx_get_data_addr(d->tex->textures[i],
				&d->tex->tex_bpp[i], &d->tex->tex_line_len[i],
				&d->tex->tex_endian[i]);
		if (!d->tex->tex_data[i])
			return (ft_error("mlx_get_data_addr failed\n"));
		i++;
	}
	d->tex->textures[i] = NULL;
	d->tex->tex_data[i] = NULL;
	return (0);
}
