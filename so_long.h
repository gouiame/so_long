/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:28:18 by cgouiame          #+#    #+#             */
/*   Updated: 2023/04/16 15:49:25 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct t_data{
	char	**ptr;
	char	*save;
	char	**map;
	int		n;
	int		len;
	int		x;
	int		y;
	int		e_count;
	int		p_count;
	int		c_count;
	void	*init;
	void	*window;
	void	*player;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*space;
	int		move;
	int		px;
	int		py;
}t_data;

void			ft_name(char *s);
void			map_line(t_data *s);
void			ft_ecp_count(t_data *s);
void			ft_ecp_check(t_data *s);
char			check_characters(t_data *s);
int				ft_strlen(char *str);
char			*ft_strdup(char *s1);
char			*ft_substr(char *s, int start, int len);
char			**free_memory(char **p);
size_t			words_counter(char *str, char c);
char			**ft_split(char *s, char c);
int				ft_check(t_data *s, int x, int y);
void			valid_path(t_data *s);
void			dup_map(t_data *s);
void			convert_images(t_data *s);
void			display_pc(t_data *s, int y, int x);
void			display_images(t_data *s);
char			**free_memory(char **p);
void			check_dup_map(t_data *s);
void			check_valid(t_data *s, int x, int y);
void			moves_number(int move);
int				move_down(t_data *s, int c);
int				move_up(t_data *s, int c);
int				move_left(t_data *s, int c);
int				move_right(t_data *s, int c);
int				ft_moves(int key, t_data *s);
void			check_map(t_data *s);
void			check_map_line(t_data *s);
void			ft_putnbr(int nbr);
void			ft_print(t_data *s);
int				ft_cross(t_data *s);
void			find_player_position(t_data *s);
void			protect(void *p, char **ptr);
#endif
