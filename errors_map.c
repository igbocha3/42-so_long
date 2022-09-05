/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igbocha3 <igbocha3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 07:04:00 by igbocha3          #+#    #+#             */
/*   Updated: 2022/09/04 02:12:26 by igbocha3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_struct_error(t_game *game)
{
	free_struct(game);
	perror("ERROR: ASSYMETRIC MAP\n");
	exit(1);
}

void	map_border_error(t_game *game)
{
	free_struct(game);
	perror("ERROR: MAP IS NOT CLOSED\n");
	exit(1);
}

void	map_comps_error(t_game *game)
{
	free_struct(game);
	perror("ERROR: WRONG COMPONENT OR NUMBER OF COMPONENTS\n");
	exit(1);
}

void	map_empty_line_error(t_game *game, char *str, char *temp)
{
	free_all(game, str, temp);
	perror("ERROR: MAP IS NOT VALID\n");
	exit (1);
}
