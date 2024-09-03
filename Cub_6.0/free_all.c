/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:56:40 by mtrojano          #+#    #+#             */
/*   Updated: 2024/09/02 16:09:36 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_tex_2(t_data *d)
{
	if (d->tex->tex_bpp)
	{
		free(d->tex->tex_bpp);
		d->tex->tex_bpp = NULL;
	}
	if (d->tex->tex_endian)
	{
		free(d->tex->tex_endian);
		d->tex->tex_endian = NULL;
	}
	if (d->tex->tex_line_len)
	{
		free (d->tex->tex_line_len);
		d->tex->tex_line_len = NULL;
	}
}

void	free_tex(t_data *d)
{
	int	i;

	i = 0;
	if (!d->tex)
		return ;
	if (d->tex->tex_path)
		free_env(&d->tex->tex_path);
	if (d->tex->tex_data)
	{
		free(d->tex->tex_data);
		d->tex->tex_data = NULL;
	}
	if (d->tex->textures)
	{
		while (d->tex->textures[i])
		{
			mlx_destroy_image(d->root, d->tex->textures[i]);
			i++;
		}
		free(d->tex->textures);
		d->tex->textures = NULL;
	}
	free_tex_2(d);
}

void	free_tex_3(t_data *d)
{
	if (!d->tex)
		return ;
	if (d->tex->no_path)
	{
		free(d->tex->no_path);
		d->tex->no_path = NULL;
	}
	if (d->tex->so_path)
	{
		free(d->tex->so_path);
		d->tex->so_path = NULL;
	}
	if (d->tex->we_path)
	{
		free(d->tex->we_path);
		d->tex->we_path = NULL;
	}
	if (d->tex->ea_path)
	{
		free(d->tex->ea_path);
		d->tex->ea_path = NULL;
	}
}

void	free_all(t_data *d)
{
	free_tex(d);
	free_tex_3(d);
	if (d->root && d->image)
		mlx_destroy_image(d->root, d->image);
	if (d->root && d->window)
		mlx_destroy_window(d->root, d->window);
	if (d->root)
	{
		mlx_destroy_display(d->root);
		free(d->root);
	}
	if (d->tex)
		free(d->tex);
	if (d->map)
		free_env(&d->map);
	if (d->color_c)
		free(d->color_c);
	if (d->color_f)
		free(d->color_f);
	if (d->colors)
		free(d->colors);
	if (d->map_line_len)
		free(d->map_line_len);
}

int	quit(t_data *d)
{
	free_all(d);
	exit (0);
}
