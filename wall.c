/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:50:43 by acaplat           #+#    #+#             */
/*   Updated: 2023/11/17 18:33:41 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void check_wall_n(char **map)
{
    int j;

    j = 0;
    while(map[0][j])
    {
        if(map[0][j] != '1')
        {
            ft_puterror("North wall not closed");
        }
        j++;
    }
}

static void check_wall_s(char **map)
{
    int last_row;
    int j;
    
    j = 0;
    last_row = 0;
    while(map[last_row + 1])
        last_row++;
    while(map[last_row][j])
    {
        if(map[last_row][j] != '1')
        {
            ft_puterror("South wall not closed");
        }
        j++;
    }
}

static void check_wall_sides(char **map)
{
    int i;

    i = 1;
    while(map[i])
    {
        // printf("test\n");
        if(map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
        {
            // printf("test ligne %d %c\n",i,map[i][ft_strlen(map[i]) - 1]);
            ft_puterror("Sides wall not closed");
        }
        i++;
    }  
}

void check_wall(char **map)
{
    check_wall_n(map);
    check_wall_s(map);
    check_wall_sides(map);
}