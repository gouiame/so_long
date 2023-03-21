#ifndef SO_LONG_H
# define SO_LONG_H


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
static char	**free_memory(char **p);
static size_t	words_counter(char *str, char c);
char	**ft_split(char *s, char c);

typedef struct t_data{
    char **ptr;
    char *save;
    char **map;
    int count;
    int first_row_len;
}t_data;
int ft_check(t_data data, int x, int y);
void valid_path(t_data data, int x, int y);
void  dup_map(t_data *data);


#endif

// int y = 0;
// int x;
// while(ptr[y])
// {
//     x = 0
//     while(ptr[y][x])
//     {
//         if(ptr[y][x] != '1' && ptr[y][x] != '0' && ptr[y][x] != 'C' && ptr[y][x] != 'E' && ptr[y][x] != 'P')
//         {
//             write(kjhdfkjkglht);
//             free ptr;
//             exit(1)
//         }
//         x++;
//     }
//     y++;
// }