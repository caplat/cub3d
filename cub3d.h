/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:47 by derblang          #+#    #+#             */
/*   Updated: 2023/11/28 17:03:18 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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

//init

void init(t_cub *cub);

//map

char **read_map(char *file);
void check_map(char **map);

//check

void check_args(char argc);
int	ft_open_fd(char *filename);
void check_file_extension(char *file);

//utils

int count_line(char **map);
void print_arr(char **arr);
void free_arr(char **map);
int countchar(char c,char **map);
void check_map_closure(char **map,t_point var,int temp);

//flood_fill

t_point find_start(char **map);
void flood_fill(char **map,int horizontale,int verticale);
void fill_bis(char **map,t_point cur,t_cub *cub,t_point start);

//wall

void check_wall(char **map,t_cub *cub);

#endif
