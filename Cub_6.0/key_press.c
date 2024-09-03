/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrojano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 07:07:32 by mtrojano          #+#    #+#             */
/*   Updated: 2024/08/23 07:07:53 by mtrojano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	handle_key_press(int keysym, t_data *d)
{
	if (keysym == XK_Escape)
	{
		free_all(d);
		exit(0);
	}
	if (keysym == XK_w)
		d->keys.w = 1;
	if (keysym == XK_s)
		d->keys.s = 1;
	if (keysym == XK_a)
		d->keys.a = 1;
	if (keysym == XK_d)
		d->keys.d = 1;
	if (keysym == XK_Left)
		d->keys.left = 1;
	if (keysym == XK_Right)
		d->keys.right = 1;
	return (0);
}

int	release_key(int keysym, t_data *d)
{
	if (keysym == XK_w && d->keys.w == 1)
		d->keys.w = 0;
	if (keysym == XK_s && d->keys.s == 1)
		d->keys.s = 0;
	if (keysym == XK_a && d->keys.a == 1)
		d->keys.a = 0;
	if (keysym == XK_d && d->keys.d == 1)
		d->keys.d = 0;
	if (keysym == XK_Left && d->keys.left == 1)
		d->keys.left = 0;
	if (keysym == XK_Right && d->keys.right == 1)
		d->keys.right = 0;
	return (0);
}
