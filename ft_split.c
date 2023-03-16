#include "so_long.h"

static char	**free_memory(char **p)
{
	size_t	n;

	n = 0;
	while (p[n] != '\0')
	{
		free(p[n]);
		n++;
	}
	free (p);
	p = NULL;
	return (p);
}

static size_t	words_counter(char *str, char c)
{
	size_t	counter;
	int		i;

	i = 0;
	counter = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] == c && str[i + 1] != c) || str[i + 1] == '\0' )
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	char	**split;
	size_t	j;
	size_t	wordstart;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	split = (char **) malloc ((words_counter(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (i < words_counter(s, c) && s[j] != '\0')
	{
		if (s[0] == c)
			return (NULL);
		wordstart = j;
		while (s[j] != c && s[j] != '\0')
		{
			if(s[j + 1] == c && s[j + 2] == c)
				return NULL;
			j++;
		
		}
		j++;
		split[i] = ft_substr(s, wordstart, j - wordstart);
		if (split[i++] == NULL)
		{
			return (free_memory(split));
		}
	}
	split[i] = NULL;
	return (split);
}