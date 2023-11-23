/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:50:43 by acaplat           #+#    #+#             */
/*   Updated: 2023/11/23 11:25:11 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void fill(char **map,t_point cur,int horizontale,int verticale)
{
    
    t_point size;
    // int count;

    // count = 0;
    size.x = verticale;
    size.y = horizontale;
    // printf("\nx : %d\ny : %d\n",cur.x,cur.y);
    // if(cur.x == 0 && cur.y == 0)
    //     count++;
    if((map[cur.x][cur.y] != '0' && map[cur.x][cur.y] != 'N' 
        && map[cur.x][cur.y] != 'S' && map[cur.x][cur.y] != 'E'
        && map[cur.x][cur.y] != 'W') || cur.y < 0 || cur.y >= size.y
        || cur.x < 0 || cur.x >= size.x)
        return;
    map[cur.x][cur.y] = 'F';
    fill(map,(t_point){cur.x - 1,cur.y},horizontale,verticale);
    fill(map,(t_point){cur.x + 1,cur.y},horizontale,verticale); 
    fill(map,(t_point){cur.x,cur.y - 1},horizontale,verticale);
    fill(map,(t_point){cur.x,cur.y + 1},horizontale,verticale);       
}

// static int fill_bis(char **map,t_point cur,int horizontale,int verticale)
// {
//     t_point size;
//     int result;

//     size.x = verticale;
//     size.y = horizontale;
//     result = 1;
//     if((map[cur.x][cur.y] != 'F' /*&& map[cur.x][cur.y] != 'N' 
//         && map[cur.x][cur.y] != 'S' && map[cur.x][cur.y] != 'E'
//         && map[cur.x][cur.y] != 'W'*/) || cur.y < 1 || cur.y >= size.y - 1
//         || cur.x < 0 || cur.x >= size.x)
//         return(0);
//     map[cur.x][cur.y] = '0';
//     result += fill_bis(map,(t_point){cur.x - 1,cur.y},horizontale,verticale);
//     result += fill_bis(map,(t_point){cur.x + 1,cur.y},horizontale,verticale); 
//     result += fill_bis(map,(t_point){cur.x,cur.y - 1},horizontale,verticale);
//     result += fill_bis(map,(t_point){cur.x,cur.y + 1},horizontale,verticale);
//     return(result);        
// }

// static void fill_all(char **map,int horizontale,int verticale)
// {
//     int i;
//     int j;
//     int res;
//     int res_bis;
//     t_point begin;

//     i = 0;
//     j = 0;
//     res = 0;
//     res_bis = 0;
//     while(map[i])
//     {
//         while(map[i][j])
//         {
//             if(map[i][j] == '0')
//             {
//                 begin.x = i;
//                 begin.y = j;
//                 res = fill(map,begin,horizontale,verticale);
//                 res_bis = fill(map,begin,horizontale,verticale);
//                 if(res != res_bis)
//                     ft_puterror("Map not closed");
//             }
//             j++;
//         }
//         i++;
//         j = 0;
//     }
// }

void flood_fill(char **map,t_point begin,int horizontale,int verticale)
{
    // t_point begin;

    // begin.x = 1;
    // begin.y = 1;
    fill(map,begin,horizontale,verticale);
    // printf("count : %d\n",count);
    // printf("result : %d\n",result);
    // print_arr(map);
    // res = fill_bis(map,begin,horizontale,verticale);
    // printf("res : %d\n",res);
    // print_arr(map);
    // if(res != result)
    //     ft_puterror("Wall not closed");
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
