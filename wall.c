/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:10:37 by acaplat           #+#    #+#             */
/*   Updated: 2023/11/27 17:52:25 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void check_wall_n(char **map)
{
    int j;

    j = 0;
    while(map[0][j])
    {
        if(map[0][j] != '1' && map[0][j] != ' ')
        {    
            ft_puterror("North wall not closed");
        }
        j++;
    }
}

static void check_wall_s(char ** map)
{
    int last_wall;
    int j;

    last_wall = 0;
    j = 0;
    while(map[last_wall + 1])
        last_wall++;
    while(map[last_wall][j])
    { 
        if(map[last_wall][j] != '1' && map[last_wall][j] != ' ')
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
        if((map[i][0] != '1' && map[i][0] != ' ') || (map[i][ft_strlen(map[i]) - 1] != '1' 
            && map[i][ft_strlen(map[i]) -1] != ' '))
        {
            ft_puterror("Sides wall not closed");
        }
        i++;
    }  
}

// static void length_diff(char **map)
// {
//     t_point var;
//     int temp1;
//     int temp2;
//     int dim;

//     var.x = 0;
//     var.y = 0;
//     dim = count_line(map);
//     while(map[var.x] && var.x < dim - 1)
//     {
//         while(map[var.x][var.y])
//             var.y++;
//         temp1 = var.y;
//         var.y = 0;
//         while(map[var.x + 1][var.y])
//             var.y++;
//         temp2 = var.y;
//         if(temp1 > temp2)
//             check_map_closure(map,var,temp2);
//         else
//             check_map_closure(map,var,temp1);
//         var.x++;
//         var.y = 0;   
//     }
// }

// static void length_diff(char **map)
// {
//     int i;
//     int j;
//     int temp1;
//     int temp2;
//     int dim;

//     i = 0;
//     j = 0;
//     dim = count_line(map);
//     while(map[i] && i < dim - 1)
//     {
//         // printf("i : %d\n",i);
//         while(map[i][j])
//             j++;
//         temp1 = j;
//         j = 0;
//         while(map[i + 1][j])
//             j++;
//         temp2 = j;
//         if(temp1 > temp2)
//         {
//             printf("A\n");
//             while(map[i][temp2])
//             {
//                 if(map[i][temp2] != '1')
//                     ft_puterror("Map not closed");
//                 temp2++;
//             }
//         }
//         else if(temp2 > temp1)
//         {
//             printf("B\n");
//             printf("temp1 : %d\ntemp2 : %d\n",temp1,temp2);
//             while(map[i][temp1])
//             {
//                 if(map[i + 1][temp1] != '1')
//                 {    
//                     printf("aaa\n");
//                     ft_puterror("Map not closed");
//                 }
//                 temp1++;
//             }
//         }
//         i++;
//         j = 0;   
//     }
// }

void check_wall(char **map)
{
    check_wall_n(map);
    check_wall_s(map);
    check_wall_sides(map);
    // length_diff(map);
}

