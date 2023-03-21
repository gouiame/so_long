
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
        write(1, "Error\nThe map does not end with .ber", 36);
        exit (1);
    }
}
int	map_line(t_data *data)
{
	data->count = 0;

	while(data->ptr[data->count])
		data->count++;
	return (data->count);
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

char	check_characters(t_data data)
{
	int x;
	int y;
	int e_count;
	int p_count;
	int c_count;
	
	x = 0;
	e_count = 0;
	p_count = 0;
	c_count = 0;
	// for(int i = 0; i < 4; i++)
	// 	printf("-%s-", data.ptr[i]);
	
	while (data.ptr[x])
	{
   	 	y = 0;
    	while (data.ptr[x][y])
    	{
        	if(data.ptr[x][y] != '1' && data.ptr[x][y] != '0' && data.ptr[x][y] != 'C' 
			&& data.ptr[x][y] != 'E' && data.ptr[x][y] != 'P' && data.ptr[x][y] != '\n')
			{
				// printf("%c -\n", data.ptr[x][y]);
				puts("map non valiiiiiide");
				// free (data.ptr);
				exit (1);
			}
			else if (data.ptr[x][y] == 'E')
                e_count++;
			else if (data.ptr[x][y] == 'P')
				p_count++;
			else if (data.ptr[x][y] == 'C')
				c_count++;				
        y++;
    	}
    x++;
	}
	  if (e_count != 1 || p_count != 1)
    {
        puts("carte non valide");
        exit(1);
    }
	if (c_count < 1)
	{
		puts("carte n'est pas valide");
        exit(1);
	}
	return (0);
}
int	map_len(t_data *data)
{
	int i;
	int row_len;
	
	i = 0;
	data->first_row_len = ft_strlen(data->ptr[0]);
	  if (data->first_row_len == 0)
    {
        puts("la carte est vide");
        exit(1);
    }
	while (data->ptr[i])
	{
		row_len = ft_strlen(data->ptr[i]);
		// printf("%d   - %s", data->first_row_len, data->ptr[i]);
		if (data->ptr[i + 1] == NULL)
		{
			if (row_len + 1 != data->first_row_len)
			{
				puts("last line");
				exit(1);
			}
		}
		else if (row_len != data->first_row_len)
		{
			puts("Map non valide");
			exit (1);
		}
		i++;
	}
	return (0);
}
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
	//free(str);
	return (NULL);
}

// void f()
// {
// 	system ("leaks a.out");
// }

int main (int argc, char **argv)
{
	t_data data;
	//  atexit(f);
	 int x = 0;
	 int y = 0;
    int fd = open (argv[1], O_RDONLY );
    ft_1(argv[1]);
	
	
    get_next_line(fd, &data);
	data.ptr = ft_split(data.save, '\n');
	if (!data.ptr)
		return 0;
	map_len(&data);

	// check_characters(data);
	map_line(&data);
	dup_map(&data);
								// printf("%c\n\n", check_map(data));
								// dup_map(&data);
								// printf("%d", data.count);
	for (int i = 0; i < data.count; i++)
		printf("%s",data.map[i]);




	// for (int i = 0; i < data.count; i++)
	// 	printf("%s\n",data.map[i]);
	// valid_path(data, x, y);
	// int j = 0;
	// while(data.ptr[j])
	// {
	// 	printf("%s", data.ptr[j]);
	// 	j++;
	// }
}
