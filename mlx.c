/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:25:33 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/06 17:39:43 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void draw_square(t_mlx *mlx,int x,int y)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < 64)
    {
        while(j < 64)
        {
            mlx_put_pixel(mlx->img,x + i,y + j, 0xD3D3D3);
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
            mlx_put_pixel(mlx->img, (x + 32) + i,(y + 32) + j,0xFF0000FF);
            j++;
        }
        i++;
        j = 0;
    }
}

static void draw_map(t_mlx *mlx,t_cub *cub)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(cub->map[i])
    {
        while(cub->map[i][j])
        {
            if(cub->map[i][j] == '1')
                draw_square(mlx,j * 64,i * 64);
            if(cub->map[i][j] == 'N' || cub->map[i][j] == 'S' 
                || cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
            {
                draw_character(mlx,j * 64, i * 64);
            }
            j++;
        }
        i++;
        j = 0;
    }
}


void open_window(t_mlx *mlx,t_cub *cub,t_player *player)
{
    (void)cub;
    bool success;
    
    mlx->id = mlx_init(WIDTH,HEIGHT,"CUBE",true);
    if(!mlx->id)
        ft_puterror("problem with window");
    mlx->img = mlx_new_image(mlx->id,WIDTH,HEIGHT);
    mlx_image_to_window(mlx->id,mlx->img,0,0);
    draw_map(mlx,cub);
    mlx_key_hook(mlx->id,event,mlx);
    success = mlx_loop_hook(mlx->id,update_player_position,player);
    if(!success)
        ft_puterror("loop hook failed");
    mlx_loop(mlx->id);
    mlx_terminate(mlx->id);
}
