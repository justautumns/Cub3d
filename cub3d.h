/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <mehmeyil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:12:28 by mehmeyil          #+#    #+#             */
/*   Updated: 2024/05/30 17:04:41 by mehmeyil         ###   ########.fr       */
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

typedef struct s_data
{
	void	*img;
	char	*adress;
	int		bits;
	int		lenght;
	int		endian;
}	t_data;

// PARSING PART
char	*get_next_line(int fd);
int		arg_check(char *str);

#endif
