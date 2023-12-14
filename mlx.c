/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:25:33 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/14 19:16:32 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_square(t_mlx *mlx,int x,int y)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < 63)
    {
        while(j < 63)
        {
            mlx_put_pixel(mlx->img,x + i,y + j, 0x000000FF);
            j++;
        }
        i++;
        j = 0;
    }
}

void draw_square_bis(t_mlx *mlx,int x,int y)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < 63)
    {
        while(j < 63)
        {
            mlx_put_pixel(mlx->img,x + i,y + j, 0xFFFFFFFF);
            j++;
        }
        i++;
        j = 0;
    }
}

void draw_character(t_mlx *mlx,int x,int y)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < 16)
    {
        while(j < 16)
        {
            mlx_put_pixel(mlx->img, (x + 24) + i,(y + 24) + j,0xFF0000FF);
            j++;
        }
        i++;
        j = 0;
    }
}

void delete_character(t_mlx *mlx,int x,int y)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < 16)
    {
        while(j < 16)
        {
            mlx_put_pixel(mlx->img, (x + 24) + i,(y + 24) + j,0x00000000);
            j++;
        }
        i++;
        j = 0;
    }
}

// int check_collision(t_mlx *mlx)
// {
//     int x = (int)(mlx->player->position.x + 0.5);
//     int y = (int)(mlx->player->position.y + 0.5);

//     if(mlx->cub->map[x][y] == '1')
//         return(1);
//     return(0);
// }

void open_window(t_mlx *mlx)
{
    bool success;
    
    mlx->id = mlx_init(WIDTH,HEIGHT,"CUBE",true);
    if(!mlx->id)
        ft_puterror("problem with window");
    mlx->img = mlx_new_image(mlx->id,WIDTH,HEIGHT);
    mlx_image_to_window(mlx->id,mlx->img,0,0);
    mlx_key_hook(mlx->id,event,mlx);
    success = mlx_loop_hook(mlx->id,loop,mlx);
    if(!success)
        ft_puterror("loop hook failed");
    mlx_loop(mlx->id);
    mlx_terminate(mlx->id);
}
