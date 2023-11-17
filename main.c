/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:50:31 by derblang          #+#    #+#             */
/*   Updated: 2023/11/17 18:17:01 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int main(int argc, char **argv)
{
    t_cub cub;

    (void)cub;
    printf("Hey\n");
    check_args(argc);
    check_file_extension(argv[1]);
    cub.map = read_map(argv[1]);
    if(cub.map != NULL)
        print_arr(cub.map);
    check_map(cub.map);
    check_wall(cub.map);
    return 0;
}