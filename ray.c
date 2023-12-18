/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:12:31 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/18 18:02:01 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ray_casting(t_mlx *mlx)
{
    int step_x;
    int step_y;
    // int side;
    int hit = 0;
    // int dist;
 

    mlx->delta.x = sqrt(1 + (pow((double)mlx->player->pdy,2) / pow((double)mlx->player->pdx,2)));
    mlx->delta.y = sqrt(1 + (pow((double)mlx->player->pdx,2) / pow((double)mlx->player->pdy,2)));
    mlx->map.x = (int)round(mlx->player->position.y);
    mlx->map.y = (int)round(mlx->player->position.x);
    if(mlx->player->angle > M_PI && mlx->player->angle < 2 * M_PI)
    {
        //gauche
        step_x = -1;
        mlx->side_dist.x = (mlx->player->position.y - mlx->map.x) * mlx->delta.x;
    }
    else
    {
        //droite
        step_x = 1;
        mlx->side_dist.x = (mlx->map.x + 1 - mlx->player->position.y) * mlx->delta.x;
    }
    if((mlx->player->angle > 3 * (M_PI / 2) && mlx->player->angle < 2 * M_PI) || mlx->player->angle < (M_PI / 2))
    {
        //bas
        step_y = -1;
        mlx->side_dist.y = (mlx->player->position.x - mlx->map.y) * mlx->delta.y;
    }
    else
    {
        //haut
        step_y = 1;
        mlx->side_dist.y = (mlx->map.y + 1 - mlx->player->position.x) * mlx->delta.y;
    }
    // while(hit == 0)
    // {
    //     if(mlx->side_dist.x < mlx->side_dist.y)
    //     {
    //         mlx->side_dist.x += mlx->delta.x;
    //         mlx->map.x += step_x;
    //         // side = 0;
    //     }
    //     else
    //     {
    //         mlx->side_dist.y += mlx->delta.y;
    //         mlx->map.y += step_y;
    //         // side = 1;
    //     }
    //     if(mlx->cub->map[mlx->map.y][mlx->map.x] == '1')
    //         hit = 1;     
    // }
    // if(side == 0)
    // {
        // dist = ((mlx->map.x - mlx->player->position.y) + (1 - step_x) / 2) / mlx->player->pdy;
    //     printf("fewfewf");
    // }
    // else
    // {
    //     dist = ((mlx->map.y - mlx->player->position.x) + (1 - step_y) / 2) / mlx->player->pdx;
    // }
}