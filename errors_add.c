/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igbocha3 <igbocha3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 07:04:10 by igbocha3          #+#    #+#             */
/*   Updated: 2022/09/04 02:14:07 by igbocha3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_error(t_game *game)
{
	free(game);
	perror("ERROR: PARSING FAILURE\n");
	exit (1);
}

void	file_error(t_game *game)
{
	free(game);
	perror("ERROR: WRONG FILE EXTENTION\n");
	exit (1);
}

void	window_mlx_error(t_game *game)
{
	free_struct(game);
	perror("ERROR: MLX WINDOW FAILURE\n");
	exit (1);
}

void	params_number_error(void)
{
	perror("ERROR: WRONG PARAMETRS NUMBER\n");
	exit (1);
}
