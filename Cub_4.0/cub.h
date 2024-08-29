/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:27:29 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/30 01:06:55 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
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
#define NORTH 4.71238898038
// #define NORTH 3 * 3.14159265358979323846 / 2
#define SOUTH 1.57079632679
// #define SOUTH PI / 2
#define WEST PI
#define EAST 6.28318530718
// #define EAST 2 * PI
#define DEGREE 0.0174533
#define FOV 60
#define MOVE_SPEED 2
#define DIST_FROM_WALL 15
#define ROTATION_SPEED DEGREE * 0.5
#define ROTATION_SPEED_W DEGREE * 2

typedef struct tex
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
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

typedef struct colors
{
	int	f_r; //floor red
	int	f_g; // floor green
	int	f_b; // floor blue
	int	c_r; // ceiling red
	int	c_g; // ceiling green
	int	c_b; // ceiling blue
}	t_colors;

typedef struct data
{
	void		*root;
	void		*window;
	char		**map;
	char		*color_f;
	char		*color_c;
	int			ceiling_color;
	int			floor_color;
	int			map_x;
	int			map_y;
	int			map_max_width;
	int			map_max_height;
	int			img_x;
	int			img_y;
	void		*image;
	int			*img_addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			tex_slice_height;
	int			tex_x;
	int			check_x;
	float		player_x;
	float		player_y;
	float		player_angle;
	float		ray_angle;
	float		ray_x;
	float		ray_y;
	int			ray_direction;
	float		x_offset;
	float		y_offset;
	float		dist_h;
	float		dist_v;
	float		horizontal_x;
	float		horizontal_y;
	float		vertical_x;
	float		vertical_y;
	t_tex		*tex;
	t_colors	*colors;
	t_keys		keys;
}	t_data;

int		quit(t_data *d);
void	draw_map(t_data *d);
void	move_down(t_data *d);
void	move_up(t_data *d);
void	move_right(t_data *d);
void	move_left(t_data *d);
void	display_map(t_data *d);
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
int		handle_key_press(int keysym, t_data *d);
int		move_player(t_data *d);

//Init
int		init_textures(t_data *d);
void	init_key_struct(t_data *d);
int		init_all(t_data *d);

//Getters
void	get_player(t_data *d);
void	get_player_angle(t_data *d);
void	get_map_size(t_data *d);
int		get_tex_data(t_data *d);

//Textures path
int		check_directions(t_data *d, char *dir, char *path);
int		check_other_two_directions(t_data *d, char *dir, char *path);

//Colors
int		assign_fc(t_data *d, char *name, char *all_values);
int		join_assign_fc_colors(t_data *d, char **arguments);
int		check_for_floor(t_data *d, char **rgb);
int		check_for_ceiling(t_data *d, char **rgb);
int		check_numbers(t_data *d, char **arguments, int place);
int		check_space_colors(char **colors);

//Read_check_utils
bool	have_all_info(t_data *d);
int		finish_reading(int fd);
int		just_spaces(char *line);
int		check_before_map(char *line);
int		compare_check(char *name);
int		check_format(char *all_values, int i, int comma, int format);
int		check_numbers2(t_data *d, char **arguments);

//read_from_cub_utils
int		check_empty_line_betweeen(char **map);
char	*skip_nl_before_map(int fd, char *line);

//lines_check_utils
int		check_if_outside_h(t_data *d);
int		check_if_outside_v(t_data *d);
float	distance(float x1, float y1, float x2, float y2);

//Errorchecks
int		arg_check(char *str);
int		texture_check(char *str);
int		ft_error(char *str);
int		read_from_map(int fd, t_data *data);
void	free_all(t_data *d);
int		check_map(char *str, t_data *d);
int		ft_strlen_n(char *str);
char	*remove_nl(char *str);
int		check_actual_map(t_data *data);
int		check_space(char **map);
int		player_pos_valid(t_data *d);
int		check_rgb_is_valid(char **str);
int		check_wall_lenght(char **map, int m, int k, int dif);
