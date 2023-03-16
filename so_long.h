#ifndef SO_LONG_H
# define SO_LONG_H


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *p, char *buffer);
char	*ft_substr(char *s, unsigned int start, size_t len);
static char	**free_memory(char **p);
static size_t	words_counter(char *str, char c);
char	**ft_split(char *s, char c);

typedef struct t_data{
    char **ptr;
    char *save;
    int count;
    int height;
}t_data;


#endif