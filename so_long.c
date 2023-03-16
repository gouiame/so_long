
#include "so_long.h"

void ft_1(char *s)
{
    int fd; 
	int	i; 

    i = 0;
    fd = open(s, O_RDONLY);
    if( fd == -1)
    {
        write(1, "Error\nThis file does not exist", 30);
        exit (1);
    }
    while(s[i])
        i++;
    if(s[i-1] != 'r' || s[i-2] != 'e' || s[i-3] != 'b' || s[i-4] != '.')
    {
        write(1, "Error\nThe map does not end with .ber", 40);
        exit (1);
    }
}

char	check_map(t_data data)
{
	int i;
	int j;

	i = 0;
	while(data.ptr[i])
	{
		j = 0;
		while(j < ft_strlen(data.ptr[0]) - 1)
		{
			if (data.ptr[0][j] != '1')
			{
				puts("error");
				exit (1);
			}
			j++;
		}
			i++;
	}
	j = 0;
	while(j < ft_strlen(data.ptr[i - 1]))
		{
			if (data.ptr[i - 1][j] != '1')
			{
				puts("err");
				exit (1);
			}
			j++;
		}
	j = 0;
	i = 0;
	while(data.ptr[i])
	{
		if (data.ptr[i][0] != '1')
		{
			puts("erreur");
				exit (1);
		}
		i++;
	}
	i = 0;
	while(data.ptr[i])
	{
		if (data.ptr[i][ft_strlen(data.ptr[i]) - 2] != '1')
		{
			puts("ERROR");
			exit (1);
		}
		i++;
	}
	while(data.ptr[i])
	{
		if (data.ptr[i][j] != '1')
		{
			puts("ERREUR");
			exit (1);
		}
		i++;
		j++;
	}
	i = 0;
	while(data.ptr[i])
	{
	 	printf("%s", data.ptr[i]);
		i++;
	}
	return (0);
}

int	map_len(t_data data)
{
	int i;
	int first_row_len;
	int	row_len;
	
	i = 0;
	first_row_len = ft_strlen(data.ptr[0]);
	while (data.ptr[i])
	{
		row_len = ft_strlen(data.ptr[i]);
	if (data.ptr[i + 1] == NULL)
	{
		if (row_len + 1 != first_row_len)
		{
			puts("last line");
			exit(1);
		}
	}
	else if (row_len != first_row_len)
	{
        puts("Map non valide");
        exit (1);
    }
	if (row_len == 0)
	{
		puts("pas de map");
		exit (1);
	}
	i++;
	}
	return (0);
}
// char	check_characters(t_data data)
// {
// 	int i;
// 	int j;

// 	while(data.ptr[i])
// 	{
// 		if ()
// 		{
// 			puts("map invalid");
// 			exit(1);
// 		}
// 		i++;
// 		j++;
// 	}
// 	return (0);
// }

char *get_next_line(int fd, t_data *data)
{
	char	str[1000000];
	char	buff[1];
	int		i;
	int		x;

	i = 0;
	x = 1;
	if (fd < 0)
		return (NULL);
	while (x > 0)
	{
		x = read(fd, buff, 1);
		if (x == 0)
			break ;
		str[i] = buff[0];
		i++;
	}
	str[i] = '\0';
	data->save = ft_strdup(str); 
	return (NULL);
}
int main (int argc, char **argv)
{
    int fd = open (argv[1], O_RDONLY );
    ft_1(argv[1]);
	t_data data;
    get_next_line(fd, &data);
	data.ptr = ft_split(data.save, '\n');
	if (!data.ptr)
		return 0;
	// printf("%c", check_characters(data));
	map_len(data);
	printf("%c", check_map(data));
}
