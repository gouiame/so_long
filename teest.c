#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void    check_map(char *str)
{
    int i;

    i = 0;
    while(str[++i])
    {
          if (str[i] == '\n' && str[i + 1] == '\n')
        {
            free(str);
            write(1, "map invalid", 12);
            exit (1);
        }
    }
}
int main (int argc, char **argv)
{
    int fd = open (argv[1], O_RDONLY );
    // ft_1(argv[1]);
    check_map(argv[1]);
}




















// void ft_1(char *s)
// {
//     int fd;
//     int i;

//     i = 0;
//     fd = open(s, O_RDONLY);
//     if( fd == -1)
//     {
//         write(1, "Error\nThis file does not exist", 30);
//         exit (1);
//     }
//     while(s[i])
//         i++;
//     if(s[i-1] != 'r' || s[i-2] != 'e' || s[i-3] != 'b' || s[i-4] != '.')
//     {
//         write(1, "Error\nThe map does not end with .ber", 40);
//         exit (1);
//     }
// }