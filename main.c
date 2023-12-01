/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:50:31 by derblang          #+#    #+#             */
/*   Updated: 2023/12/01 16:45:15 by acaplat          ###   ########.fr       */
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

    init(&cub);
    check_args(argc);
    check_file_extension(argv[1]);
    cub.map = read_map(argv[1]);
    if(cub.map != NULL)
        print_arr(cub.map);
    find_dim(cub.map, &cub);
    printf("\nverticale : %d\nhorizontale : %d\n",cub.verticale,cub.horizontale);
    check_wall(cub.map,&cub);
    flood_fill(cub.map,cub.horizontale,cub.verticale);
    printf("\n");
    print_arr(cub.map);
    free_arr(cub.map);
    open_window(&mlx);
    mlx_loop(mlx.id);
    mlx_terminate(mlx.id);
    return 0;
}