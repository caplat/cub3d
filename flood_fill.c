/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:50:43 by acaplat           #+#    #+#             */
/*   Updated: 2023/11/27 18:42:59 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void fill(char **map,t_point cur,int horizontale,int verticale)
{
    
    t_point size;

    size.x = verticale;
    size.y = horizontale;
    if((map[cur.x][cur.y] != ' ') || cur.y < 0 || cur.y >= size.y
        || cur.x < 0 || cur.x >= size.x)
        return;
    if(map[cur.x][cur.y] == ' ' && ((cur.x > 0 && map[cur.x - 1][cur.y] != '1' 
        && map[cur.x - 1][cur.y] != ' ' && map[cur.x - 1][cur.y] != 'F') 
        || ( cur.x < size.x - 1 && map[cur.x + 1][cur.y] != '1' 
        && map[cur.x + 1][cur.y] != ' ' && map[cur.x + 1][cur.y] != 'F') 
        || (cur.y > 0 && map[cur.x][cur.y - 1] != '1' && map[cur.x][cur.y - 1] 
        != ' ' && map[cur.x][cur.y - 1] != 'F') || (cur.y < size.y - 1 
        && map[cur.x][cur.y + 1] != '1' && map[cur.x][cur.y + 1] != ' ' 
        && map[cur.x][cur.y + 1] != 'F')))
    {    
        printf("\nx : %d\ny : %d\n",cur.x,cur.y);
        // printf("->%c\n",map[cur.x][cur.y + 1]);
        ft_puterror("space not closed");
    }
    map[cur.x][cur.y] = 'F';
    fill(map,(t_point){cur.x - 1,cur.y},horizontale,verticale);
    fill(map,(t_point){cur.x + 1,cur.y},horizontale,verticale); 
    fill(map,(t_point){cur.x,cur.y - 1},horizontale,verticale);
    fill(map,(t_point){cur.x,cur.y + 1},horizontale,verticale);      
}

void flood_fill(char **map,int horizontale,int verticale)
{
    t_point begin;
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            if(map[i][j] == ' ')
            {
                begin.x = i;
                begin.y = j;
                fill(map,begin,horizontale,verticale);
            }
            j++;
        }
        i++;
        j = 0;
    }
    print_arr(map);
}

