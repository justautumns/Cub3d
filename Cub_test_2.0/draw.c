#include "cub.h"

void	draw_ceiling(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			d->img_addr[y * (d->line_length / 4) + x] = d->ceiling_color;
			x++;
		}
		y++;
	}
}

void	draw_floor(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			d->img_addr[y * (d->line_length / 4) + x] = d->floor_color;
			x++;
		}
		y++;
	}
}

void draw_map(t_data *d)
{
	d->image = mlx_new_image(d->root, WIN_WIDTH, WIN_HEIGHT);
	d->img_addr = (int *)mlx_get_data_addr(d->image, &d->bpp, &d->line_length, &d->endian);
	draw_ceiling(d);
	draw_floor(d);
}

float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	vertical_line_check(t_data *d)
{
	float	Tan;
	int		start;

	start = 0;
	Tan = -tan(d->ray_angle);
	if (d->ray_angle > PI / 2 && d->ray_angle < (3 * PI / 2)) // looking left
	{
		d->ray_x = (((int)d->player_x / TILE_SIZE) * TILE_SIZE) - 0.0001;
		d->ray_y = (d->player_x - d->ray_x) * Tan + d->player_y;
		d->x_offset = - TILE_SIZE;
		d->y_offset = -d->x_offset * Tan;
		d->ray_direction = 2;
	}
	else if (d->ray_angle < PI / 2 || d->ray_angle > (3 * PI / 2)) // looking right
	{
		d->ray_x = (((int)d->player_x / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
		d->ray_y = (d->player_x - d->ray_x) * Tan + d->player_y;
		d->x_offset = TILE_SIZE;
		d->y_offset = -d->x_offset * Tan;
		d->ray_direction = 3;
	}
	else
		start = d->map_max_width;
	while (start < d->map_max_width)
	{
		d->map_x = (int)(d->ray_x) / TILE_SIZE;
		d->map_y = (int)(d->ray_y) / TILE_SIZE;
		if (d->map_x >= 0 && d->map_y >= 0 && d->map_x < d->map_max_width
			&& d->map_y < d->map_max_height && d->map[d->map_y][d->map_x] == '1')
		{
			d->dist_V = distance(d->player_x, d->player_y, d->ray_x, d->ray_y);
			d->vertical_x = d->ray_x;
			d->vertical_y = d->ray_y;
			return ;
		}
		else
		{
			d->ray_x += d->x_offset;
			d->ray_y += d->y_offset;
			start++;
		}
	}
}

void	horizontal_line_check(t_data *d)
{
	float	Tan;
	int		start;

	start = 0;
	Tan = -1 / tan(d->ray_angle);
	if (d->ray_angle > PI) // looking up
	{
		d->ray_y = (((int)d->player_y / TILE_SIZE) * TILE_SIZE) - 0.0001;
		d->ray_x = (d->player_y - d->ray_y) * Tan + d->player_x;
		d->y_offset = - TILE_SIZE;
		d->x_offset = -d->y_offset * Tan;
		d->ray_direction = 0;
	}
	else if (d->ray_angle < PI) // looking down
	{
		d->ray_y = (((int)d->player_y / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
		d->ray_x = (d->player_y - d->ray_y) * Tan + d->player_x;
		d->y_offset = TILE_SIZE;
		d->x_offset = -d->y_offset * Tan;
		d->ray_direction = 1;
	}
	else
		start = d->map_max_height;
	while (start < d->map_max_height)
	{
		d->map_x = (int)(d->ray_x) / TILE_SIZE;
		d->map_y = (int)(d->ray_y) / TILE_SIZE;
		if (d->map_x >= 0 && d->map_y >= 0 && d->map_x < d->map_max_width
			&& d->map_y < d->map_max_height && d->map[d->map_y][d->map_x] == '1')
		{
			d->dist_H = distance(d->player_x, d->player_y, d->ray_x, d->ray_y);
			d->horizontal_x = d->ray_x;
			d->horizontal_y = d->ray_y;
			return ;
		}
		else
		{
			d->ray_x += d->x_offset;
			d->ray_y += d->y_offset;
			start++;
		}
	}
}
void	draw_tex_slice(t_data *d, int x, int nesw)
{
	int	tex_y;
	int	start;
	int	y;
	int	color;

	y = 0;
	start = (WIN_HEIGHT - d->tex_slice_height) / 2;
	while (y < d->tex_slice_height)
	{
		tex_y = (y * TILE_SIZE) / d->tex_slice_height;
		color = ((int *)d->tex->tex_data[nesw])[tex_y * (d->tex->tex_line_len[nesw] / 4) + d->tex_x];
		if (start >= 0 && start < WIN_HEIGHT)
			d->img_addr[start * (d->line_length / 4) + x] = color;
		y++;
		start++;
	}
}

int determine_texture(t_data *d)
{
	if (d->dist_H < d->dist_V)
	{
		if (d->ray_angle > 180 * DEGREE)
			return (0); // NORTH
		else if (d->ray_angle > 0 && d->ray_angle < 180 * DEGREE)
			return (1); // SOUTH
	}
	else
	{
		if (d->ray_angle > 90 * DEGREE && d->ray_angle < 270 * DEGREE)
			return (2); // WEST
		else
			return (3); // EAST
	}
	return (0);
}

void	cast_rays(t_data *d)
{
	int	i = 0;
	float ray_step = FOV * DEGREE / WIN_WIDTH;
	d->ray_angle = d->player_angle - (FOV / 2) * DEGREE; // minus half of FOV
	normalize_angle(&d->ray_angle);
	while (i < WIN_WIDTH)
	{
		d->dist_H = 1000000;
		d->dist_V = 1000000;
		horizontal_line_check(d);
		vertical_line_check(d);
		if (d->dist_H < d->dist_V)
		{
			d->ray_x = d->horizontal_x;
			d->ray_y = d->horizontal_y;
			d->dist_H = d->dist_H * cos(d->player_angle - d->ray_angle); // for fish eye effect
			d->tex_slice_height = (70 * WIN_HEIGHT) / d->dist_H; // 100 cause map is 10 by 10, later should be max x and/or y or actually whatever works best
			// if (d->tex_slice_height > WIN_HEIGHT)
			// 	d->tex_slice_height = WIN_HEIGHT;
			d->tex_x = (int)fmod(d->ray_x, TILE_SIZE);
		}
		if (d->dist_V < d->dist_H)
		{
			d->ray_x = d->vertical_x;
			d->ray_y = d->vertical_y;
			d->dist_V = d->dist_V * cos(d->player_angle - d->ray_angle);
			d->tex_slice_height = (70 * WIN_HEIGHT) / d->dist_V;
			// if (d->tex_slice_height > WIN_HEIGHT)
			// 	d->tex_slice_height = WIN_HEIGHT;
			d->tex_x = (int)fmod(d->ray_y, TILE_SIZE);
		}
		d->ray_direction = determine_texture(d);
		draw_tex_slice(d, i, d->ray_direction);
		d->ray_angle += ray_step;
		normalize_angle(&d->ray_angle);
		i++;
	}
	mlx_put_image_to_window(d->root, d->window, d->image, 0, 0);
}
