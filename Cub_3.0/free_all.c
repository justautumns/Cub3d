/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:56:40 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/23 00:52:20 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_tex(t_data *d)
{
	int	i;

	i = 0;
	if (d->tex->tex_path)
		free_env(&d->tex->tex_path);
	if (d->tex->tex_data)
		free_env(&d->tex->tex_data);
	if (d->tex->textures)
	{
		while (d->tex->textures[i])
		{
			mlx_destroy_image(d->root, d->tex->textures[i]);
			i++;
		}
		free(d->tex->textures);
	}
	if (d->tex->tex_bpp)
		free(d->tex->tex_bpp);
	if (d->tex->tex_endian)
		free(d->tex->tex_endian);
	if (d->tex->tex_line_len)
		free (d->tex->tex_line_len);
}

void	free_tex_2(t_data *d)
{
	if (d->tex->no_path)
		free(d->tex->no_path);
	if (d->tex->so_path)
		free(d->tex->so_path);
	if (d->tex->we_path)
		free(d->tex->we_path);
	if (d->tex->ea_path)
		free(d->tex->ea_path);
}

void	free_all(t_data *d)
{
	free_tex(d);
	free_tex_2(d);
	if (d->image)
		mlx_destroy_image(d->root, d->image);
	if (d->window)
		mlx_destroy_window(d->root, d->window);
	// if (d->img_addr)
	// 	free(d->img_addr); // Error comes from here as it's already freed. (Error was core dump)
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
}
