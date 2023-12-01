/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:25:33 by acaplat           #+#    #+#             */
/*   Updated: 2023/12/01 16:14:39 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void open_window(t_mlx *mlx)
{
    mlx->id = mlx_init(WIDTH,HEIGHT,"CUBE",true);
    if(!mlx->id)
        ft_puterror("problem with window");
}