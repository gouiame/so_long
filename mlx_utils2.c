/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:00:42 by cgouiame          #+#    #+#             */
/*   Updated: 2023/04/16 01:19:25 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(t_data *s)
{
	int	y;
	int	x;

	s->move = 1;
	y = 0;
	while (s->ptr[y])
	{
		x = 0;
		while (s->ptr[y][x])
		{
			if (s->ptr[y][x] == 'P')
			{
				s->px = x;
				s->py = y;
			}
			x++;
		}
		y++;
	}
}

void	protect(void *p, char **ptr)
{
	if (p == NULL)
	{
		write(1, "Error\nmxl_init / mlx_new_window =>failed", 41);
		free_memory(ptr);
		exit (1);
	}
}

int	ft_moves(int key, t_data *s)
{
	int			i;
	static int	c;

	if (key == 2 || key == 124)
		i = move_right(s, c);
	if (key == 0 || key == 123)
		i = move_left(s, c);
	if (key == 13 || key == 126)
		i = move_up(s, c);
	if (key == 1 || key == 125)
		i = move_down(s, c);
	if (key == 53)
	{
		free_memory(s->ptr);
		mlx_destroy_window(s->init, s->window);
		exit(0);
	}
	if (i == 1)
		c++;
	mlx_clear_window(s->init, s->window);
	display_images(s);
	return (0);
}

int	ft_cross(t_data *s)
{
	free_memory(s->ptr);
	mlx_destroy_window(s->init, s->window);
	exit(0);
}
