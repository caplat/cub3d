/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:50:31 by derblang          #+#    #+#             */
/*   Updated: 2023/12/12 12:35:03 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

static void find_dim(char **map,t_cub *cub)
{
    int i;
    int j;

    i = 0;
    j = 0;
    cub->verticale = count_line(map);
    while(map[i])
    {
        while(map[i][j])
            j++;
        if(cub->horizontale < j)
            cub->horizontale = j;
        i++;
        j = 0;
    }
    if(cub->horizontale == 0 && cub->verticale == 0)
        ft_puterror("map is empty");
}

int main(int argc, char **argv)
{
    t_cub cub;
    t_mlx mlx;
    t_player player;

    init(&cub);
    check_args(argc);
    check_file_extension(argv[1]);
    cub.map = read_map(argv[1]);
    check_map(cub.map);
    find_pos(cub.map,&player);
    mlx.player = &player;
    // player.fov[0] = player.direction - (M_PI / 6);
    // player.fov[1] = player.direction + (M_PI / 6);
    if(cub.map != NULL)
        print_arr(cub.map);
    find_dim(cub.map, &cub);
    printf("\nverticale : %d\nhorizontale : %d\n",cub.verticale,cub.horizontale);
    mlx.cub = &cub;
    check_wall(cub.map,&cub);
    flood_fill(cub.map,cub.horizontale,cub.verticale);
    printf("\n");
    print_arr(cub.map);
    open_window(&mlx);
    free_arr(cub.map);
    return 0;
}
