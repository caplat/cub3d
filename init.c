/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:43:08 by derblang          #+#    #+#             */
/*   Updated: 2023/11/17 15:24:11 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init(t_cub *cub)
{
    cub->map = NULL;
    cub->north_texture = NULL;
    cub->south_texture = NULL;
    cub->west_texture = NULL;
    cub->east_texture = NULL;
    cub->ceiling_texture = NULL;
    cub->floor_texture = NULL;
}

