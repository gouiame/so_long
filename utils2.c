/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:44:32 by cgouiame          #+#    #+#             */
/*   Updated: 2023/04/16 00:43:00 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print(t_data *s)
{
	if (s->ptr[s->x][s->y] != '1'
			&& s->ptr[s->x][s->y] != '0' && s->ptr[s->x][s->y] != 'C'
			&& s->ptr[s->x][s->y] != 'E' && s->ptr[s->x][s->y] != 'P' )
	{
		write(1, "Error\nCheck characters", 23);
		exit (1);
	}
}

void	ft_ecp_count(t_data *s)
{
	if (s->ptr[s->x][s->y] == 'E')
		s->e_count++;
	else if (s->ptr[s->x][s->y] == 'P')
		s->p_count++;
	else if (s->ptr[s->x][s->y] == 'C')
		s->c_count++;
}

void	ft_ecp_check(t_data *s)
{
	if (s->e_count != 1 || s->p_count != 1)
	{
		write(1, "Error\nCheck player/Exit", 24);
		exit(1);
	}
	if (s->c_count < 1)
	{
		write(1, "Error\nThere is no collectible", 30);
		exit(1);
	}
}

char	check_characters(t_data *s)
{
	s->x = 0;
	s->e_count = 0;
	s->p_count = 0;
	s->c_count = 0;
	while (s->ptr[s->x])
	{
		s->y = 0;
		while (s->ptr[s->x][s->y])
		{
			if (s->ptr[s->x][s->y] != '1'
					&& s->ptr[s->x][s->y] != '0' && s->ptr[s->x][s->y] != 'C'
					&& s->ptr[s->x][s->y] != 'E' && s->ptr[s->x][s->y] != 'P' )
				ft_print(s);
			else if (s->ptr[s->x][s->y] == 'E' || s->ptr[s->x][s->y] == 'P'
					|| s->ptr[s->x][s->y] == 'C')
				ft_ecp_count(s);
			s->y++;
		}
		s->x++;
	}
	if (s->e_count != 1 || s->p_count != 1 || s->c_count < 1)
		ft_ecp_check(s);
	return (0);
}
