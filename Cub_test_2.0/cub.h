/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:27:29 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/07 00:57:35 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <math.h>
#include <X11/X.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>

#define PI 3.14159265358979323846
#define TILE_SIZE 64
#define WIN_HEIGHT 600
#define WIN_WIDTH 800
#define NORTH 3 * 3.14159265358979323846 / 2
#define SOUTH PI / 2
#define WEST PI
#define EAST 2 * PI
#define DEGREE 0.0174533
#define FOV 60
#define MOVE_SPEED 1.5
#define DIST_FROM_WALL 20
#define ROTATION_SPEED DEGREE / 2

typedef struct tex
{
	char	**tex_path;
	void	**textures;
	char	**tex_data;
	int		*tex_bpp;
	int		*tex_line_len;
	int		*tex_endian;
}	t_tex;

typedef struct keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct data
{
	void	*root;
	void	*window;
	void	*floor;
	void	*wall;
	void	*player;
	void	*hit_point;
	char	**map;
	int		ceiling_color;
	int		floor_color;
	int		map_x;
	int		map_y;
	int		map_max_width;
	int		map_max_height;
	int		img_x;
	int		img_y;
	void	*image;
	int		*img_addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		tex_slice_height;
	int		tex_x;
	int		check_x;
	float	player_x;
	float	player_y;
	float	player_angle;
	float	ray_angle;
	float	ray_x;
	float	ray_y;
	int		ray_direction;
	float	x_offset;
	float	y_offset;
	float	dist_h;
	float	dist_v;
	float	horizontal_x;
	float	horizontal_y;
	float	vertical_x;
	float	vertical_y;
	t_tex	*tex;
	t_keys	keys;
}	t_data;

void	draw_map(t_data *d);
void	draw_player(t_data *d);
int		handle_key_press(int keysym, t_data *d);
void	move_down(t_data *d);
void	move_up(t_data *d);
void	move_right(t_data *d);
void	move_left(t_data *d);
void	draw_player_init(t_data *d, int x, int y, int size);
void	display_map(t_data *d);
int		ft_strlen(char *str);
char	*ft_strdup(const char *s);
void	free_env(char ***env);
char	**add_to_array(char **arr, char *str);
void	cast_rays(t_data *d);
void	vertical_line_check(t_data *d);
void	horizontal_line_check(t_data *d);
void	normalize_angle(float *angle);
int		get_color_from_rgb(int red, int green, int blue);
int		validate_move(t_data *d, char c);
void	rotate_left(t_data *d);
void	rotate_right(t_data *d);
int		release_key(int keysym, t_data *d);
int		move_player(t_data *d);

//Errorchecks
int		arg_check(char *str);
int		texture_check(char *str);
int		ft_error(char *str);
