/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:27:28 by derblang          #+#    #+#             */
/*   Updated: 2023/11/17 17:51:12 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char **read_map(char *file)
{
    int fd;
    char **arr;
    char *buf;
    char *temp;
    if((fd = ft_open_fd(file)) < 0)
        return NULL;
    buf = malloc(sizeof(char) * 1);
    if(!buf)
        return (NULL);
    buf[0] = '\0';
    temp = buf;
    while(1)
    {
        temp = get_next_line(fd);
        if(temp == NULL)
            break;
        buf = ft_strjoin(buf, temp);
        free(temp);
    }
    arr = ft_split(buf, '\n');
    free(buf);
    close(fd);
    return (arr);
}

void check_map(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            if(map[i][j] != '1' && map[i][j] != '0' &&
                map[i][j] != 'N' && map[i][j] != 'S' &&
                map[i][j] != 'E' && map[i][j] != 'W')
            {
                printf("Error\nParsing incorrect %c\n",map[i][j]);
            }
            j++;
        }
        i++;
        j = 0;
    }
}



