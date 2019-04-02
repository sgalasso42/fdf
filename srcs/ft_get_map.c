#include "../includes/fdf.h"

int		ft_tabadd(t_map *map)
{
	int	**new;
	int i;

	i = 0;
	if (map->nb_y > 0)
	{
		if (!(new = (int **)(malloc(sizeof(int *) * (map->nb_y + 1)))))
			return (0);
		while (i < map->nb_y)
		{
			if (!(new[i] = ft_intdup(map, map->grid[i])))
				return (0);
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = new;
	}
	return (1);
}

void	ft_parserror(t_map *map, char *line, int fd)
{
	map->nb_y++;
	ft_free_grid(map);
	close(fd);
	free(line);
	ft_putendl("Error : bad map character");
	exit(EXIT_FAILURE);
}

void	ft_is_valid_char(t_map *map, char *line, int i, int fd)
{
	if (line[i] && line[i] == '-')
	{
		if (line[i + 1] == '0')
			ft_parserror(map, line, fd);
		else if (!ft_isdigit(line[i + 1]))
			ft_parserror(map, line, fd);
	}
	else if (line[i] && !ft_isdigit(line[i]))
		ft_parserror(map, line, fd);
}

int		ft_parse_map(t_map *map, char *line, int fd)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if (!(map->grid[map->nb_y] = (int *)(malloc(sizeof(int)
	* (ft_nbwords(line, ' '))))))
		return (0);
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == 0)
			break ;
		ft_is_valid_char(map, line, i, fd);
		map->grid[map->nb_y][x] = ft_atoi(line + i);
		if (map->grid[map->nb_y][x] > 2000 || map->grid[map->nb_y][x] < -2000)
			ft_parserror(map, line, fd);
		i += ft_nbrlen(map->grid[map->nb_y][x++]);
	}
	if (map->nb_y == 0)
		map->nb_x = x;
	else if (x != map->nb_x)
		ft_parserror(map, line, fd);
	return (1);
}

void	ft_get_map(t_map *map, char **argv)
{
	int		fd;
	char	*line;

	fd = 0;
	if (!(map->grid = (int **)(ft_memalloc(sizeof(int *) * (1)))))
		ft_error_exit("Fdf: error, out of memory", map);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error_exit("Fdf: error, out of memory", map);
	while (get_next_line(fd, &line) > 0)
	{
		if ((!ft_tabadd(map)) || (!ft_parse_map(map, line, fd)))
		{
			close(fd);
			ft_error_exit("Fdf: error, out of memory", map);
		}
		map->nb_y++;
		free(line);
	}
	free(line);
	close(fd);
}
