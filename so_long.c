/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:55:25 by cgouiame          #+#    #+#             */
/*   Updated: 2023/04/16 16:09:31 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_name(char *s)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(s, O_RDONLY);
	while (s[i])
		i++;
	if (s[i - 1] != 'r' || s[i - 2] != 'e'
		|| s[i - 3] != 'b' || s[i - 4] != '.')
	{
		write(1, "Error\nThe map does not end with .ber", 37);
		exit (1);
	}
	if (fd == -1)
	{
		write(1, "Error\nThis file does not exist", 31);
		exit(1);
	}
}

void	ft_arg(int ac)
{
	if (ac != 2)
	{
		write(1, "Error\nThe number of arguments is not 1", 39);
		exit(1);
	}
}

void	map_len(t_data *s)
{
	int	i;

	i = 1;
	s->len = ft_strlen(s->ptr[0]);
	while (s->ptr[i])
	{
		if (s->len != ft_strlen(s->ptr[i]))
		{
			write(1, "Error\nMap not rectangular", 26);
			free_memory(s->ptr);
			exit (1);
		}
		i++;
	}
}

char	*get_next_line(int fd, t_data *s)
{
	char	str[1000000];
	char	buff[1];
	int		i;
	int		x;

	i = 0;
	x = 1;
	if (fd < 0)
		return (NULL);
	while (x > 0)
	{
		x = read(fd, buff, 1);
		if (i == 0 && x == 0)
		{
			write(1, "Error\nEmpty map", 16);
			exit(1);
		}
		if (x == 0)
			break ;
		str[i] = buff[0];
		i++;
	}
	str[i] = '\0';
	s->save = ft_strdup(str);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	s;
	int		fd;

	ft_arg(argc);
	fd = open (argv[1], O_RDONLY);
	ft_name(argv[1]);
	get_next_line(fd, &s);
	check_map_line(&s);
	s.ptr = ft_split(s.save, '\n');
	check_characters(&s);
	map_line(&s);
	map_len(&s);
	check_map(&s);
	valid_path(&s);
	check_dup_map(&s);
	s.init = mlx_init();
	protect(s.init, s.ptr);
	s.window = mlx_new_window(s.init, s.len * 40, s.n * 40, "so_long");
	protect(s.window, s.ptr);
	convert_images(&s);
	display_images(&s);
	find_player_position(&s);
	mlx_hook(s.window, 02, 0, ft_moves, &s);
	mlx_hook(s.window, 17, 0, ft_cross, &s);
	mlx_loop(s.init);
}
