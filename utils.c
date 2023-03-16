#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
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
char	*ft_strjoin(char *p, char *buffer)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (p == NULL)
		p = ft_strdup("");
	result = (char *)malloc (ft_strlen (p) + ft_strlen (buffer) + 1);
	if (result == (NULL))
		return (NULL);
	while (p[i] != '\0')
	{
		result[i] = p[i];
		i++;
	}
	while (buffer[j] != '\0')
		result[i++] = buffer[j++];
	result[ft_strlen(p) + ft_strlen(buffer)] = '\0';
	free(p);
	return (result);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len_s;

	i = 0;
	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		str = malloc(ft_strlen(s + start) * sizeof(char) + 1);
	else
		str = malloc(len * sizeof(char) + 1);
	if (str == NULL )
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
