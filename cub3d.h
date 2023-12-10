/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:47 by derblang          #+#    #+#             */
/*   Updated: 2023/12/10 16:57:16 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "./MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_cub
{
    char **map;
    int horizontale;
    int verticale;
}  t_cub;

typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct s_player
{
    t_point position;
    double direction;
    // double fov[2];
}   t_player;

typedef struct s_mlx
{
    mlx_t *id;
    mlx_image_t* img;
    t_player *player;
}   t_mlx;

//init

void init(t_cub *cub);

//map

char **read_map(char *file);
void check_map(char **map);
void find_pos(char **map,t_player *player);

//check

void check_args(char argc);
int	ft_open_fd(char *filename);
void check_file_extension(char *file);

//utils

int count_line(char **map);
void print_arr(char **arr);
void free_arr(char **map);
char ** map_cpy(char **map,int verticale);

//flood_fill

t_point find_start(char **map);
void flood_fill(char **map,int horizontale,int verticale);
void fill_bis(char **map,t_point cur,t_cub *cub);

//wall

void check_wall(char **map,t_cub *cub);

//mlx

void open_window(t_mlx *mlx,t_cub *cub,t_player *player);
void draw_character(t_mlx *mlx,int x,int y);

//event

void event(mlx_key_data_t keycode,void *content);
void update_player_position(void *param);

#endif
