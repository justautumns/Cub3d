/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:12:28 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/31 18:32:08 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "./libft/libft.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720
# define TILE_SIZE 64

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	void	*img_north;
	void	*img_south;
	void	*img_west;
	void	*img_east;
}	t_texture;

typedef struct s_colors
{
	int	floor;
	int	ceiling;
}	t_colors;

typedef struct s_map
{
	char	**map_data;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_texture	textures;
	t_colors	colors;
	t_map		map;
	t_player	player;
}	t_game;

// PARSING PART
char	*get_next_line(int fd);
int		arg_check(char *str);
int		texture_check(char *str);
int		parse_color(char *str);
char	*get_textures_path(char *str);
void	parse_cub_file(char *path, t_game *game);
void	initialize(t_game *game);
void	init_game(t_game *game);

// RENDERING
int	render_next_frame(t_game *game);

// PLAYER (RAYCAST FUNCTIONS)
int	key_press(int keycode, t_game *game);
#endif
