#include "cub.h"

char *remove_nl(char *str)
{
	char *temp = malloc(ft_strlen(str));
	int i = 0;

	while (str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

void get_map(t_data *d)
{
	FILE *file = fopen("map.cub", "r+");
	char line[100];
	int y = 0;

	d->map_max_height = 0;
	d->map_max_width = 0;
	d->map = malloc(1 * sizeof(char *));
	d->map[0] = NULL;
	while (fgets(line, 100, file))
		d->map = add_to_array(d->map, remove_nl(line));
	while (d->map[y])
	{
		d->map_max_height++;
		y++;
	}
	y = 0;
	d->map_max_width = ft_strlen(d->map[y]);
	while (d->map[y])
	{
		if (ft_strlen(d->map[y]) > d->map_max_width)
			d->map_max_width = ft_strlen(d->map[y]);
		y++;
	}
}

void	display_map(t_data *d)
{
	int x = 0;
	int y = 0;

	while (d->map[y])
	{
		x = 0;
		while (d->map[y][x])
		{
			printf("%c", d->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int main()
{
	t_data d;

	get_map(&d);
	//printf("map max height = %d\nmap max width = %d\n", d.map_max_height, d.map_max_width);
	d.root = mlx_init();
	d.win_x = 800;
	d.win_y = 800;
	d.player_x = 0;
	d.player_y = 0;
	d.window = mlx_new_window(d.root, d.win_x, d.win_y, "cat_test");
	d.player_angle = NORTH;
	draw_map(&d);
	draw_player_init(&d, 5, 5, 15);
	cast_rays(&d);
	mlx_hook(d.window, KeyPress, KeyPressMask, handle_key_press, &d);
	mlx_loop(d.root);
}
