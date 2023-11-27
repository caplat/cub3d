/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:12:21 by acaplat           #+#    #+#             */
/*   Updated: 2023/11/27 15:07:33 by acaplat          ###   ########.fr       */
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

int countchar(char c,char **map)
{
    int i;
    int j;
    int count;

    i = 0;
    j = 0;
    count = 0;

    while(map[i])
    {
        while(map[i][j])
        {
            if(map[i][j] == c)
                count++;
            j++;
        }
        i++;
        j = 0;    
    }
    return(count);
}
void check_map_closure(char **map,t_point var,int temp)
{
    while(map[var.x][temp])
    {
        if(map[var.x][temp] != '1')
            ft_puterror("Map not closed");
        temp++;
    }
}