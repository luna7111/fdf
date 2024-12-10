/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   fdf_to_map.c                                   .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2024/12/04 09:35:37 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2024/12/08 16:57:05 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	parse_point(t_map *map, char *raw_point, int x, int y)
{
	char	**split_point;

	split_point = ft_split(raw_point, ',');
	map->h_grid[y][x] = ft_atoi(split_point[0]);
	if (split_point[1])
		map->c_grid[y][x] = hex_to_rgba(split_point[1]);
	else
		map->c_grid[y][x] = init_rgba(255, 255, 255, 255);
	free_split(split_point);
}

void	parse_line(t_map *map, char *line, int y)
{
	char	**split_line;
	int		x;

	map->h_grid[y] = malloc(map->width * sizeof(int));
	map->c_grid[y] = malloc(map->width * sizeof(t_rgba));
	split_line = ft_split(line, ' ');
	x = 0;
	while (x < map->width && split_line[x])
	{
		parse_point(map, split_line[x], x, y);
		x ++;
	}
	while (x < map->width)
	{
		parse_point(map, "0", x, y);
		x ++;
	}
	free_split(split_line);
}

void	parse_map(t_map *map, int fd)
{
	char	**raw_map;
	int		y;

	raw_map = split_file(fd);
	map->width = get_map_width(raw_map);
	map->height = get_map_height(raw_map);
	map->h_grid = malloc(map->height * sizeof(int *));
	map->c_grid = malloc(map->height * sizeof(t_rgba *));
	y = 0;
	while (y < map->height)
	{
		parse_line(map, raw_map[y], y);
		y ++;
	}
	free_split(raw_map);
}