/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:26:29 by cgouiame          #+#    #+#             */
/*   Updated: 2023/03/21 22:03:49 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  dup_map(t_data *data)
{
    int i;
    int j;

    data->map = (char **)malloc((data->count + 1) * sizeof(char *));
	j = 0;
    while(data->ptr[j])
    {
        i = 0;
        data->map[j] = (char *)malloc((data->first_row_len + 1) * sizeof(char));
      	while (data->ptr[j][i])
		{
			data->map[j][i] = data->ptr[j][i];
			i++;
		}
		data->map[j][data->first_row_len] = '\0';
		j++;
	}
	data->map[data->count] = NULL;

}

// int ft_check(t_data data, int x, int y)
// {
//     int c;

//     c = 0;

//     if(data.ptr[y][x + 1] == '0' || data.ptr[y][x + 1] == 'C')
//     {
//         data.ptr[y][x + 1] = 'P';
//         c = 1;
//     }
//     if(data.ptr[y][x - 1] == '0' || data.ptr[y][x - 1] == 'C')
//     {
//         data.ptr[y][x - 1] = 'P';
//         c = 1;
//     }
//     if(data.ptr[y + 1][x] == '0' || data.ptr[y + 1][x] == 'C')
//     {
//         data.ptr[y + 1][x] = 'P';
//         c = 1;
//     }
//     if(data.ptr[y - 1][x] == '0' || data.ptr[y - 1][x] == 'C')
//     {
//         data.ptr[y - 1][x] = 'P';
//         c = 1;
//     }
//     return (c);
// }
// void valid_path(t_data data, int x, int y)
// {

//     y = 0;
//     while(data.ptr[y])
//     {
//         x = 0;
//         while(data.ptr[y][x])
//         {
//             if(data.ptr[y][x] == 'P' && ft_check(data, x, y) == 1)
//             {
//                 // data.ptr[y][x] = 'P';
//                 x = 0;
//                 y = 0;
//             }
//             x++;
//         }
//         y++;
//     }
// }
// void valid_path(char **map, int *x, int *y)
// {
//     while(map[(*y)])
//     {
//         *x = 1;
//         while(map[(*y)][*x])
//         {
//             if(map[*y][*x] == 'P')
//                 return ;
//             (*x)++;
//         }
//         (*y)++;
//     }
// }

// int main() 
// {
//     int i = 0;
//     int x = 0;
//     int y = 0;
//     char **zone = malloc (sizeof(char *));
//     while (i < 5)
//     {
//         zone[i++] = malloc(9);
//     }
//     zone[0] = ft_strdup("11111111");
//     zone[1] = ft_strdup("10001001");
//     zone[2] = ft_strdup("10P10001");
//     zone[3] = ft_strdup("10110001");
//     zone[4] = ft_strdup("11111111");
//     zone[5] =NULL;
//     while (1)
//     {
//         valid_path(zone, &x, &y);
//         if (!ft_check(zone, y, x))
//             break;
//     }
//     for (int i = 0; i < 5; ++i)
// 		printf("%s\n", zone[i]);
// 	return (0);
// }
