/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:50:31 by derblang          #+#    #+#             */
/*   Updated: 2023/11/21 17:01:06 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void find_dim(char **map,t_cub *cub)
{
    int j;

    j = 0;
    cub->verticale = count_line(map);
    while(map[0][j])
        j++;
    cub->horizontale = j;
}

int main(int argc, char **argv)
{
    t_cub cub;
    t_point begin;

    init(&cub);
    check_args(argc);
    check_file_extension(argv[1]);
    cub.map = read_map(argv[1]);
    if(cub.map != NULL)
        print_arr(cub.map);
    find_dim(cub.map, &cub);
    printf("\nverticale : %d\nhorizontale : %d\n",cub.verticale,cub.horizontale);
    begin = find_start(cub.map);
    printf("\nx : %d\ny : %d\n",begin.x,begin.y);
    flood_fill(cub.map,begin,cub.horizontale,cub.verticale);
    print_arr(cub.map);
    free_arr(cub.map);
    return 0;
}