/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:28:15 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/14 18:58:13 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void rotate(t_mlx *mlx)
{
    if(mlx_is_key_down(mlx->id, MLX_KEY_LEFT))
    {
        mlx->player->angle += 0.1;
        if(mlx->player->angle > 2 * M_PI)
            mlx->player->angle -= 2 * M_PI;
        mlx->player->pdx = cosf(mlx->player->angle);
        mlx->player->pdy = sinf(mlx->player->angle);
    }
    if(mlx_is_key_down(mlx->id, MLX_KEY_RIGHT))
    {
        mlx->player->angle -= 0.1;
        if(mlx->player->angle < 0)
            mlx->player->angle += 2 * M_PI;
        mlx->player->pdx = cosf(mlx->player->angle);
        mlx->player->pdy = sinf(mlx->player->angle);
    }
    printf("player angle : %f\npdx : %f\npdy : %f\n",mlx->player->angle,mlx->player->pdx,mlx->player->pdy);
}

void event(mlx_key_data_t event,void *content)
{
    t_mlx *mlx;

    (void)event;
    mlx = content;
    if(mlx_is_key_down(mlx->id, MLX_KEY_ESCAPE))
        mlx_close_window(mlx->id);
    rotate(mlx);
    
}

static void draw_map(t_mlx *mlx)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(mlx->cub->map[i])
    {
        while(mlx->cub->map[i][j])
        {
            if(mlx->cub->map[i][j] == '1')
                draw_square(mlx,j * 64,i * 64);
            if(mlx->cub->map[i][j] == '0' || mlx->cub->map[i][j] == 'N' || mlx->cub->map[i][j] == 'S' 
                || mlx->cub->map[i][j] == 'E' || mlx->cub->map[i][j] == 'W')
                draw_square_bis(mlx,j * 64, i * 64);
            j++;
        }
        i++;
        j = 0;
    }
}

static void draw_vec_dir(t_mlx *mlx)
{
    mlx_put_pixel(mlx->img, ((mlx->player->position.y + 0.5) + (mlx->player->pdy) * 1) * 64, 
        ((mlx->player->position.x + 0.5) + (mlx->player->pdx) * 1) * 64, 0xFFFF00FF);
}

void loop(void *param)
{
    t_mlx *mlx;
    // float old_posx;

    mlx = param;
    draw_map(mlx);
    draw_character(mlx,(mlx->player->position.y * 64),(mlx->player->position.x * 64));
    if(mlx_is_key_down(mlx->id, MLX_KEY_S))
    {
        delete_character(mlx,(mlx->player->position.y * 64),(mlx->player->position.x * 64));
        mlx->player->position.x += 0.1;
        draw_character(mlx,(mlx->player->position.y * 64),(mlx->player->position.x * 64));
    }
    if(mlx_is_key_down(mlx->id, MLX_KEY_W))
    {
        delete_character(mlx,(mlx->player->position.y * 64),(mlx->player->position.x * 64));
        mlx->player->position.x -= 0.1;
        draw_character(mlx,(mlx->player->position.y * 64),(mlx->player->position.x * 64));
    }
    if(mlx_is_key_down(mlx->id, MLX_KEY_D))
    {
        delete_character(mlx,(mlx->player->position.y * 64),(mlx->player->position.x * 64));
        mlx->player->position.y += 0.1;
        draw_character(mlx,(mlx->player->position.y * 64),(mlx->player->position.x * 64));
    }
    if(mlx_is_key_down(mlx->id, MLX_KEY_A))
    {
        delete_character(mlx,(mlx->player->position.y * 64),(mlx->player->position.x * 64));
        mlx->player->position.y -= 0.1;
        draw_character(mlx,(mlx->player->position.y * 64),(mlx->player->position.x * 64));
    }
    draw_vec_dir(mlx);
}



