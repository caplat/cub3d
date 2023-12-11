/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:28:15 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/11 16:01:52 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void event(mlx_key_data_t event,void *content)
{
    t_mlx *mlx;

    (void)event;
    mlx = content;
    if(mlx_is_key_down(mlx->id, MLX_KEY_ESCAPE))
    {
        mlx_close_window(mlx->id);
    }
}

void update_player_position(void *param)
{
    t_mlx *mlx;
    // float old_posx;

    mlx = param;
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
}

void draw_map(void *param)
{
    t_mlx *mlx;
    int i;
    int j;

    i = 0;
    j = 0;
    mlx = param;
    while(mlx->cub->map[i])
    {
        while(mlx->cub->map[i][j])
        {
            if(mlx->cub->map[i][j] == '1')
                draw_square(mlx,j * 64,i * 64);
            j++;
        }
        i++;
        j = 0;
    }
}
