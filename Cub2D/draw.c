#include "cub.h"

void	draw_map(t_data *d)
{
	int x = 0;
	int y = 0;

	d->floor = mlx_xpm_file_to_image(d->root,
			"../../Cub3d/textures/floor.xpm", &d->img_x, &d->img_y);
	while (d->map[y])
	{
		x = 0;
		while (d->map[y][x])
		{
			if (d->map[y][x] == '0' || d->map[y][x] == 'P')
				mlx_put_image_to_window(d->root, d->window,
					d->floor, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}

	x = 0;
	y = 0;
	d->wall = mlx_xpm_file_to_image(d->root,
		"../../Cub3d/textures/ceiling.xpm", &d->img_x, &d->img_y);
	while (d->map[y])
	{
		x = 0;
		while (d->map[y][x])
		{
			if (d->map[y][x] == '1')
				mlx_put_image_to_window(d->root, d->window,
					d->wall, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void draw_player_init(t_data *d, int x, int y, int size)
{
	d->player_x = x * TILE_SIZE + (TILE_SIZE / 2) - (size / 2);
	d->player_y = y * TILE_SIZE + (TILE_SIZE / 2) - (size / 2);
	d->player = mlx_xpm_file_to_image(d->root, "player2.xpm", &d->img_x, &d->img_y);
	mlx_put_image_to_window(d->root, d->window, d->player, d->player_x, d->player_y);
}

void draw_player(t_data *d)
{
	d->player = mlx_xpm_file_to_image(d->root, "player2.xpm", &d->img_x, &d->img_y);
	mlx_put_image_to_window(d->root, d->window, d->player, d->player_x, d->player_y);
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
		//printf("looking left\n");
		d->ray_x = (((int)d->player_x / TILE_SIZE) * TILE_SIZE) - 0.0001;
		d->ray_y = (d->player_x - d->ray_x) * Tan + d->player_y;
		d->x_offset = -64;
		d->y_offset = -d->x_offset * Tan;
	}
	else if (d->ray_angle < PI / 2 || d->ray_angle > (3 * PI / 2)) // looking right
	{
		//printf("looking right \n");
		d->ray_x = (((int)d->player_x / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
		d->ray_y = (d->player_x - d->ray_x) * Tan + d->player_y;
		d->x_offset = 64;
		d->y_offset = -d->x_offset * Tan;
	}
	else
		start = d->map_max_width;
	while (start < d->map_max_width)
	{
		d->map_x = (int)(d->ray_x) / TILE_SIZE;
		d->map_y = (int)(d->ray_y) / TILE_SIZE;
		//printf("vertical:\nmap x = %d\nmap y = %d\n", d->map_x, d->map_y);
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
		//printf("looking up \n");
		d->ray_y = (((int)d->player_y / TILE_SIZE) * TILE_SIZE) - 0.0001;
		d->ray_x = (d->player_y - d->ray_y) * Tan + d->player_x;
		d->y_offset = -64;
		d->x_offset = -d->y_offset * Tan;
	}
	else if (d->ray_angle < PI) // looking down
	{
		//printf("looking down \n");
		d->ray_y = (((int)d->player_y / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
		d->ray_x = (d->player_y - d->ray_y) * Tan + d->player_x;
		d->y_offset = 64;
		d->x_offset = -d->y_offset * Tan;
	}
	else
		start = d->map_max_height;
	while (start < d->map_max_height)
	{
		d->map_x = (int)(d->ray_x) / TILE_SIZE;
		d->map_y = (int)(d->ray_y) / TILE_SIZE;
		//printf("horizontal:\nmap x = %d\nmap y = %d\n", d->map_x, d->map_y);
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

void	cast_rays(t_data *d)
{
	int i = 0;

	d->ray_angle = d->player_angle - 30 * DEGREE; // minus half of FOV
	normalize_angle(&d->ray_angle);
	while (i < 60) // i less than FOV in degrees
	{
		d->dist_H = 1000000;
		d->dist_V = 1000000;
		horizontal_line_check(d);
		vertical_line_check(d);
		if (d->dist_H < d->dist_V)
		{
			d->ray_x = d->horizontal_x;
			d->ray_y = d->horizontal_y;
		}
		if (d->dist_V < d->dist_H)
		{
			d->ray_x = d->vertical_x;
			d->ray_y = d->vertical_y;
		}
		d->hit_point = mlx_xpm_file_to_image(d->root, "point.xpm", &d->img_x, &d->img_y);
		mlx_put_image_to_window(d->root, d->window, d->hit_point, d->ray_x, d->ray_y);
		d->ray_angle += DEGREE;
		normalize_angle(&d->ray_angle);
		i++;
	}
}
