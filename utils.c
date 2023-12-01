/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:12:21 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/01 13:19:00 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void print_arr(char **arr)
{
    int i;

    i = -1;
    while(arr[++i])
        printf("%s\n",arr[i]);
}

int count_line(char **map)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    return(i);
}

void free_arr(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

static void do_cpy(char **map,char **map_cpy)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            map_cpy[i][j] = map[i][j];
            j++;
        }
        map_cpy[i][j] = '\0';
        i++;
        j = 0;
    }
}

char ** map_cpy(char **map,int verticale)
{
    char **new_map;
    int i = -1;

    new_map = malloc(sizeof(char*) * verticale + 1);
    if(new_map == NULL)
    {
        ft_puterror("failed allocation new_map");
        return NULL;
    }
    while(++i < verticale)
    {
        new_map[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
        if(!new_map[i])
        {
            free_arr(new_map);
            ft_puterror("failed allocation new_map[i]");
            return(NULL);
        }
    }
    do_cpy(map,new_map);
    return(new_map);
}
