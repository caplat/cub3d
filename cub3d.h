/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:47 by derblang          #+#    #+#             */
/*   Updated: 2023/12/01 18:35:15 by acaplat          ###   ########.fr       */
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

typedef struct s_mlx
{
    mlx_t *id;
}   t_mlx;

typedef struct s_player
{
    t_point position;
    double direction;
}   t_player;

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

void open_window(t_mlx *mlx);

#endif
