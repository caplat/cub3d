/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:50:43 by acaplat           #+#    #+#             */
/*   Updated: 2023/11/21 18:09:21 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


static void fill(char **map,t_point cur,int horizontale,int verticale)
{
    t_point size;

    size.x = verticale;
    size.y = horizontale;
    // printf("\nx : %d\ny : %d\n",cur.x,cur.y);
    // printf("pos :%c\n",map[cur.x][cur.y]);
    if((map[cur.x][cur.y] != '0' && map[cur.x][cur.y] != 'N' 
        && map[cur.x][cur.y] != 'S' && map[cur.x][cur.y] != 'E'
        && map[cur.x][cur.y] != 'W') || cur.y < 0 || cur.y >= size.y 
        || cur.x < 0 || cur.x >= size.x)
        return;
        // return(ft_puterror("map not closed"));
    map[cur.x][cur.y] = 'F';
    fill(map,(t_point){cur.x - 1,cur.y},horizontale,verticale);
    fill(map,(t_point){cur.x + 1,cur.y},horizontale,verticale); 
    fill(map,(t_point){cur.x,cur.y - 1},horizontale,verticale);
    fill(map,(t_point){cur.x,cur.y + 1},horizontale,verticale);        
}

void flood_fill(char **map,t_point begin,int horizontale,int verticale)
{
    t_point size;

    size.x = verticale;
    size.y = horizontale;
    printf("Size: %d, %d\n", size.x, size.y);
    fill(map,begin,horizontale,verticale);
}

t_point find_start(char **map)
{
    int i;
    int j;
    t_point begin;

    i = 1;
    j = 0;
    begin.x = 0;
    begin.y = 0;
    while(map[i])
    {
        while((map[i][j] != 'S' || map[i][j] != 'N' || map[i][j] != 'E' || map[i][j] != 'W') && map[i][j])
        {
            if(map[i][j + 1] == 'S' || map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W')
            {
                begin.x = i;
                begin.y = j;
                return(begin);
            }
            j++;
        }
        i++;
        j = 0;   
    }
    return(begin);
}
