/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:17:31 by cgouiame          #+#    #+#             */
/*   Updated: 2023/04/16 00:39:59 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_line(t_data *s)
{
	int	y;

	y = 0;
	while (s->ptr[y])
		y++;
	s->n = y;
}

void	check_map(t_data *s)
{
	int	x;
	int	y;

	y = 0;
	while (s->ptr[y])
	{
		x = 0;
		while (s->ptr[y][x])
		{
			if (x == 0 || x == s->len - 1 || y == 0 || y == s->n - 1)
			{
				if (s->ptr[y][x] != '1')
				{
					free_memory(s->ptr);
					write (1, "Error\nCheck walls", 18);
					exit(1);
				}
			}
			x++;
		}
		y++;
	}
}

void	check_map_line(t_data *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s->save);
	while (s->save[i])
	{
		if (s->save[0] == '\n' || (s->save[i] == '\n'
				&& s->save[i + 1] == '\n') || s->save[len - 1] == '\n')
		{
			write (1, "Error\nEmpty line", 17);
			exit(1);
		}
		i++;
	}
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)malloc ((ft_strlen(s1) + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
