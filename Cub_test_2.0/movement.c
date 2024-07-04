#include "cub.h"

void	normalize_angle(float *angle)
{
	if ((*angle) > (2 * PI))
		(*angle) -= 2 * PI;
	else if ((*angle) < 0)
		(*angle) += 2 * PI;
}

void rotate_left (t_data *d)
{
	// Adjust player_angle by angle_offset
	d->player_angle -= ROTATION_SPEED;
	// Normalize player_angle to be within 0 to 2*PI
	normalize_angle(&d->player_angle);
}

void rotate_right (t_data *d)
{
	// Adjust player_angle by angle_offset
	d->player_angle += ROTATION_SPEED;
	// Normalize player_angle to be within 0 to 2*PI
	normalize_angle(&d->player_angle);
}

void move_right(t_data *d)
{
	double angle_right = d->player_angle + (PI / 2);
	d->player_x = d->player_x + MOVE_SPEED * cos(angle_right);
	d->player_y = d->player_y + MOVE_SPEED * sin(angle_right);
}

void move_left(t_data *d)
{
	double angle_left = d->player_angle - (PI / 2);
	d->player_x = d->player_x + MOVE_SPEED * cos(angle_left);
	d->player_y = d->player_y + MOVE_SPEED * sin(angle_left);
}

void move_up (t_data *d)
{
	d->player_x = d->player_x + MOVE_SPEED * cos(d->player_angle);
	d->player_y = d->player_y + MOVE_SPEED * sin(d->player_angle);
}

void move_down (t_data *d)
{
	d->player_x = d->player_x - MOVE_SPEED * cos(d->player_angle);
	d->player_y = d->player_y - MOVE_SPEED * sin(d->player_angle);
}

int	validate_move(t_data *d, char c)
{
	int map_x;
	int map_y;

	if (c == 'w')
	{
		map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED * cos(d->player_angle)) / TILE_SIZE;
		map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED * sin(d->player_angle)) / TILE_SIZE;
		if (d->map[map_y][map_x] == '1')
			return (-1);
		map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED * cos(d->player_angle - (20 * DEGREE))) / TILE_SIZE; // to not pass through corners
		map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED * sin(d->player_angle - (20 * DEGREE))) / TILE_SIZE;
		if (d->map[map_y][map_x] == '1')
			return (-1);
		map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED * cos(d->player_angle + (20 * DEGREE))) / TILE_SIZE;
		map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED * sin(d->player_angle + (20 * DEGREE))) / TILE_SIZE;
		if (d->map[map_y][map_x] == '1')
			return (-1);
	}
	if (c == 's')
	{
		map_x = (int)(d->player_x - DIST_FROM_WALL * MOVE_SPEED * cos(d->player_angle)) / TILE_SIZE;
		map_y = (int)(d->player_y - DIST_FROM_WALL * MOVE_SPEED * sin(d->player_angle)) / TILE_SIZE;
		if (d->map[map_y][map_x] == '1')
			return (-1);
		map_x = (int)(d->player_x - DIST_FROM_WALL * MOVE_SPEED * cos(d->player_angle - (20 * DEGREE))) / TILE_SIZE;
		map_y = (int)(d->player_y - DIST_FROM_WALL * MOVE_SPEED * sin(d->player_angle - (20 * DEGREE))) / TILE_SIZE;
		if (d->map[map_y][map_x] == '1')
			return (-1);
		map_x = (int)(d->player_x - DIST_FROM_WALL * MOVE_SPEED * cos(d->player_angle + (20 * DEGREE))) / TILE_SIZE;
		map_y = (int)(d->player_y - DIST_FROM_WALL * MOVE_SPEED * sin(d->player_angle + (20 * DEGREE))) / TILE_SIZE;
		if (d->map[map_y][map_x] == '1')
			return (-1);
	}
	if (c == 'a')
	{
		double angle_left = d->player_angle - (PI / 2);
		map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED * cos(angle_left)) / TILE_SIZE;
		map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED * sin(angle_left)) / TILE_SIZE;
		if (d->map[map_y][map_x] == '1')
			return (-1);
		map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED * cos(angle_left - (20 * DEGREE))) / TILE_SIZE; // to not pass through corners
		map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED * sin(angle_left - (20 * DEGREE))) / TILE_SIZE;
		if (d->map[map_y][map_x] == '1')
			return (-1);
		map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED * cos(angle_left + (20 * DEGREE))) / TILE_SIZE;
		map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED * sin(angle_left + (20 * DEGREE))) / TILE_SIZE;
		if (d->map[map_y][map_x] == '1')
			return (-1);
	}
	if (c == 'd')
	{
		double angle_right = d->player_angle + (PI / 2);
		map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED * cos(angle_right)) / TILE_SIZE;
		map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED * sin(angle_right)) / TILE_SIZE;
		if (d->map[map_y][map_x] == '1')
			return (-1);
		map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED * cos(angle_right - (20 * DEGREE))) / TILE_SIZE; // to not pass through corners
		map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED * sin(angle_right - (20 * DEGREE))) / TILE_SIZE;
		if (d->map[map_y][map_x] == '1')
			return (-1);
		map_x = (int)(d->player_x + DIST_FROM_WALL * MOVE_SPEED * cos(angle_right + (20 * DEGREE))) / TILE_SIZE;
		map_y = (int)(d->player_y + DIST_FROM_WALL * MOVE_SPEED * sin(angle_right + (20 * DEGREE))) / TILE_SIZE;
		if (d->map[map_y][map_x] == '1')
			return (-1);
	}
	return (0);
}

int	handle_key_press(int keysym, t_data *d)
{
	if (keysym == XK_Escape)
		exit(0);
	if (keysym == XK_w)
		if (validate_move(d, 'w') == 0)
			move_up(d);
	if (keysym == XK_s)
		if (validate_move(d, 's') == 0)
			move_down(d);
	if (keysym == XK_a)
		if (validate_move(d, 'a') == 0)
			move_left(d);
	if (keysym == XK_d)
		if (validate_move(d, 'd') == 0)
			move_right(d);
	if (keysym == XK_Left)
		rotate_left(d);
	if (keysym == XK_Right)
		rotate_right(d);
	mlx_destroy_image(d->root, d->image);
	draw_map(d);
	cast_rays(d);
	return (0);
}
