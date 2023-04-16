/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:26:29 by cgouiame          #+#    #+#             */
/*   Updated: 2023/04/16 15:44:07 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dup_map(t_data *s)
{
	int	i;
	int	j;

	s->map = (char **)malloc((s->n + 1) * sizeof(char *));
	if (s->map == NULL)
	{
		free_memory(s->map);
		exit(1);
	}
	j = -1;
	while (s->ptr[++j])
	{
		i = -1;
		s->map[j] = (char *)malloc((s->len + 1) * sizeof(char));
		if (s->map == NULL)
		{
			free_memory(s->map);
			exit(1);
		}
		while (s->ptr[j][++i])
			s->map[j][i] = s->ptr[j][i];
		s->map[j][s->len] = '\0';
	}
	s->map[s->n] = NULL;
}

int	ft_check(t_data *s, int x, int y)
{
	int	c;

	c = 0;
	if (s->map[y][x + 1] == '0' || s->map[y][x + 1] == 'C')
	{
		s->map[y][x + 1] = 'P';
		c = 1;
	}
	if (s->map[y][x - 1] == '0' || s->map[y][x - 1] == 'C')
	{
		s->map[y][x - 1] = 'P';
		c = 1;
	}
	if (s->map[y + 1][x] == '0' || s->map[y + 1][x] == 'C')
	{
		s->map[y + 1][x] = 'P';
		c = 1;
	}
	if (s->map[y - 1][x] == '0' || s->map[y - 1][x] == 'C')
	{
		s->map[y - 1][x] = 'P';
		c = 1;
	}
	return (c);
}

void	valid_path(t_data *s)
{
	int	x;
	int	y;

	dup_map(s);
	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == 'P' && ft_check(s, x, y) == 1)
			{
				x = 0;
				y = 0;
			}
			x++;
		}
		y++;
	}
}

void	check_valid(t_data *s, int x, int y)
{
	if (s->map[y][x] == 'E')
	{
		if (s->map[y][x + 1] != 'P' && s->map[y][x - 1] != 'P' &&
				s->map[y + 1][x] != 'P' && s->map[y - 1][x] != 'P')
		{
			write (1, "Error\nPlayer won't reach the exit", 34);
			free_memory(s->map);
			free_memory(s->ptr);
			exit(1);
		}
	}
}

void	check_dup_map(t_data *s)
{
	int	x;
	int	y;

	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == 'C')
			{
				write (1, "Error\nPlayer won't reach all collectibles", 42);
				free_memory(s->map);
				free_memory(s->ptr);
				exit(1);
			}
			if (s->map[y][x] == 'E')
				check_valid(s, x, y);
			x++;
		}
		y++;
	}
	free_memory(s->map);
}
