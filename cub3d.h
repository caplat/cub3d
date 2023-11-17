/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:47 by derblang          #+#    #+#             */
/*   Updated: 2023/11/17 18:09:05 by acaplat          ###   ########.fr       */
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
    char *north_texture;
    char *south_texture;
    char *west_texture;
    char *east_texture;
    char *ceiling_texture;
    char *floor_texture; 

} t_cub;

//map

char **read_map(char *file);
void check_map(char **map);

//check

void check_args(char argc);
int	ft_open_fd(char *filename);
void check_file_extension(char *file);

//utils

void print_arr(char **arr);

//wall

void check_wall(char **map);

#endif
