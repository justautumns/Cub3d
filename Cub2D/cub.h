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

#define PI 3.14159265358979323846
#define TILE_SIZE 64
#define NORTH 3 * PI / 2
#define SOUTH PI / 2
#define WEST PI
#define EAST 2 * PI
#define DEGREE 0.0174533

typedef struct data
{
	void	*root;
	void	*window;
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*hit_point;
	char	**map;
	int		map_x;
	int		map_y;
	int		map_max_width;
	int		map_max_height;
	int		img_x;
	int		img_y;
	int		win_x;
	int		win_y;
	float	player_x;
	float	player_y;
	float	player_angle;
	float	ray_angle;
	float	ray_x;
	float	ray_y;
	float	x_offset;
	float	y_offset;
	float	dist_H;
	float	dist_V;
	float	horizontal_x;
	float	horizontal_y;
	float	vertical_x;
	float	vertical_y;
	int		to_collect;
	int		on_exit;
	int		moves;
}	t_data;


void	draw_map(t_data *d);
void	draw_player(t_data *d);
int	handle_key_press(int keysym, t_data *d);
void move_down (t_data *d);
void move_up (t_data *d);
void move_right (t_data *d);
void move_left (t_data *d);
void draw_player_init(t_data *d, int x, int y, int size);
void	display_map(t_data *d);
int	ft_strlen(char *str);
char	*ft_strdup(const char *s);
void	free_env(char ***env);
char	**add_to_array(char **arr, char *str);
void	cast_rays(t_data *d);
void	normalize_angle(float *angle);
