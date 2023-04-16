/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:05:02 by cgouiame          #+#    #+#             */
/*   Updated: 2023/04/16 01:12:23 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_data *s, int c)
{
	if (s->ptr[s->py][s->px + 1] == 'C')
	{
		s->ptr[s->py][s->px + 1] = 'P';
		s->ptr[s->py][s->px] = '0';
		moves_number(s->move++);
		s->px++;
		return (1);
	}
	if (s->ptr[s->py][s->px + 1] == '0')
	{
		s->ptr[s->py][s->px + 1] = 'P';
		s->ptr[s->py][s->px] = '0';
		moves_number(s->move++);
		s->px++;
		return (0);
	}
	if (s->ptr[s->py][s->px + 1] == 'E' && c == s->c_count)
	{
		free_memory(s->ptr);
		mlx_destroy_window(s->init, s->window);
		write(1, "You won.", 8);
		exit(0);
	}
	return (0);
}

int	move_left(t_data *s, int c)
{
	if (s->ptr[s->py][s->px - 1] == 'C')
	{
		s->ptr[s->py][s->px - 1] = 'P';
		s->ptr[s->py][s->px] = '0';
		moves_number(s->move++);
		s->px--;
		return (1);
	}
	if (s->ptr[s->py][s->px - 1] == '0')
	{
		s->ptr[s->py][s->px - 1] = 'P';
		s->ptr[s->py][s->px] = '0';
		moves_number(s->move++);
		s->px--;
		return (0);
	}
	if (s->ptr[s->py][s->px - 1] == 'E' && c == s->c_count)
	{
		free_memory(s->ptr);
		mlx_destroy_window(s->init, s->window);
		write(1, "You won.", 8);
		exit(0);
	}
	return (0);
}

int	move_up(t_data *s, int c)
{
	if (s->ptr[s->py - 1][s->px] == 'C')
	{
		s->ptr[s->py - 1][s->px] = 'P';
		s->ptr[s->py][s->px] = '0';
		moves_number(s->move++);
		s->py--;
		return (1);
	}
	if (s->ptr[s->py - 1][s->px] == '0')
	{
		s->ptr[s->py - 1][s->px] = 'P';
		s->ptr[s->py][s->px] = '0';
		moves_number(s->move++);
		s->py--;
		return (0);
	}
	if (s->ptr[s->py - 1][s->px] == 'E' && c == s->c_count)
	{
		free_memory(s->ptr);
		mlx_destroy_window(s->init, s->window);
		write(1, "You won.", 8);
		exit(0);
	}
	return (0);
}

int	move_down(t_data *s, int c)
{
	if (s->ptr[s->py + 1][s->px] == 'C')
	{
		s->ptr[s->py + 1][s->px] = 'P';
		s->ptr[s->py][s->px] = '0';
		moves_number(s->move++);
		s->py++;
		return (1);
	}
	if (s->ptr[s->py + 1][s->px] == '0')
	{
		s->ptr[s->py + 1][s->px] = 'P';
		s->ptr[s->py][s->px] = '0';
		moves_number(s->move++);
		s->py++;
		return (0);
	}
	if (s->ptr[s->py + 1][s->px] == 'E' && c == s->c_count)
	{
		free_memory(s->ptr);
		mlx_destroy_window(s->init, s->window);
		write(1, "You won!", 8);
		exit(0);
	}
	return (0);
}
