/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:29:05 by cgouiame          #+#    #+#             */
/*   Updated: 2023/04/16 01:24:55 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_images(t_data *s)
{
	int	wh;

	wh = 0;
	s->player = mlx_xpm_file_to_image(s->init,
			"images/player.xpm", &wh, &wh);
	s->collectible = mlx_xpm_file_to_image(s->init,
			"images/collectible.xpm", &wh, &wh);
	s->exit = mlx_xpm_file_to_image(s->init,
			"images/exit.xpm", &wh, &wh);
	s->space = mlx_xpm_file_to_image(s->init,
			"images/space.xpm", &wh, &wh);
	s->wall = mlx_xpm_file_to_image(s->init,
			"images/wall.xpm", &wh, &wh);
	if (s->player == NULL || s->collectible == NULL || s->exit == NULL
		|| s->space == NULL || s->wall == NULL)
	{
		free_memory(s->ptr);
		mlx_destroy_window(s->init, s->window);
		exit(1);
	}
}

void	display_pc(t_data *s, int y, int x)
{
	if (s->ptr[y][x] == 'P')
		mlx_put_image_to_window(s->init, s->window,
			s->player, x * 40, y * 40);
	if (s->ptr[y][x] == 'C')
		mlx_put_image_to_window(s->init, s->window,
			s->collectible, x * 40, y * 40);
}

void	display_images(t_data *s)
{
	int	x;
	int	y;

	y = 0;
	while (s->ptr[y])
	{
		x = 0;
		while (s->ptr[y][x])
		{
			if (s->ptr[y][x] == '0')
				mlx_put_image_to_window(s->init, s->window,
					s->space, x * 40, y * 40);
			if (s->ptr[y][x] == '1')
				mlx_put_image_to_window(s->init, s->window,
					s->wall, x * 40, y * 40);
			if (s->ptr[y][x] == 'E')
				mlx_put_image_to_window(s->init, s->window,
					s->exit, x * 40, y * 40);
			if (s->ptr[y][x] == 'P' || s->ptr[y][x] == 'C')
				display_pc(s, y, x);
			x++;
		}
		y++;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		nbr = nbr + '0';
		write(1, &nbr, 1);
	}
}

void	moves_number(int move)
{
	write (1, "Nombre de mouvements : ", 23);
	ft_putnbr(move);
	write (1, "\n", 1);
}
