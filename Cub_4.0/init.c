/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 07:12:30 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/23 06:12:49 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_textures(t_data *d)
{
	d->tex = malloc(sizeof(t_tex));
	if (!d->tex)
		return (-1);
	d->tex->tex_path = malloc(5 * sizeof(char *));
	if (!d->tex->tex_path)
		return (-1);
	d->tex->tex_path[0] = NULL;
	d->tex->tex_data = malloc(5 * sizeof(char *));
	if (!d->tex->tex_data)
		return (-1);
	d->tex->tex_data[0] = NULL;
	d->tex->textures = malloc(5 * sizeof(void *));
	if (!d->tex->textures)
		return (-1);
	d->tex->textures[0] = NULL;
	d->tex->tex_bpp = malloc(4 * sizeof(int));
	if (!d->tex->tex_bpp)
		return (-1);
	d->tex->tex_line_len = malloc(4 * sizeof(int));
	if (!d->tex->tex_line_len)
		return (-1);
	d->tex->tex_endian = malloc(4 * sizeof(int));
	if (!d->tex->tex_endian)
		return (-1);
	return (0);
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

void	init_stuff(t_data *d)
{
	d->tex->no_path = NULL;
	d->tex->so_path = NULL;
	d->tex->we_path = NULL;
	d->tex->ea_path = NULL;
	d->color_c = NULL;
	d->color_f = NULL;
	d->colors->c_b = -1;
	d->colors->c_g = -1;
	d->colors->c_r = -1;
	d->colors->f_b = -1;
	d->colors->f_g = -1;
	d->colors->f_r = -1;
	d->root = NULL;
	d->window = NULL;
	d->image = NULL;
	d->img_addr = NULL;
}

int	init_all(t_data *d)
{
	d->colors = malloc(sizeof(t_colors));
	if (!d->colors)
		return (ft_error("Error: malloc failed\n"));
	d->map = malloc(1 * sizeof(char *));
	if (!d->map)
		return (ft_error("Error: malloc failed\n"));
	d->map[0] = NULL;
	init_key_struct(d);
	if (init_textures(d) == -1)
		return (-1);
	init_stuff(d);
	return (0);
}
