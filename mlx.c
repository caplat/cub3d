/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:25:33 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/05 19:15:53 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void draw_square(t_mlx *mlx,int x,int y,int flag)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < 64)
    {
        while(j < 64)
        {
            if(flag == 0)
                mlx_put_pixel(mlx->img,x + i,y + j, 0xD3D3D3);
            if(flag == 1)
                mlx_put_pixel(mlx->img,x + i,y + j,0x00FF00FF);
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
    int flag;

    i = 0;
    j = 0;
    flag = 0;
    while(cub->map[i])
    {
        while(cub->map[i][j])
        {
            if(cub->map[i][j] == '1')
                draw_square(mlx,j * 64,i * 64,flag);
            if(cub->map[i][j] == 'N' || cub->map[i][j] == 'S' 
                || cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
            {
                flag = 1;
                draw_square(mlx,j * 64,i * 64,flag);
            }
            flag = 0;
            j++;
        }
        i++;
        j = 0;
    }
}

void open_window(t_mlx *mlx,t_cub *cub)
{
    (void)cub;
    
    mlx->id = mlx_init(WIDTH,HEIGHT,"CUBE",true);
    if(!mlx->id)
        ft_puterror("problem with window");
    mlx->img = mlx_new_image(mlx->id,WIDTH,HEIGHT);
    mlx_image_to_window(mlx->id,mlx->img,0,0);
    draw_map(mlx,cub);
    // draw_square(mlx,0,0,32);
    // draw_square(mlx,32,32,32);
    mlx_loop(mlx->id);
    mlx_terminate(mlx->id);
}
