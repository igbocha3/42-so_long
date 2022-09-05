/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igbocha3 <igbocha3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 07:04:25 by igbocha3          #+#    #+#             */
/*   Updated: 2022/09/04 01:17:02 by igbocha3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_init(t_game *game)
{
	game->map = NULL;
	game->player = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->col = 0;
	game->steps = 0;
	game->exit = 0;
	game->width_map = 0;
	game->height_map = 0;
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		window_mlx_error(game);
	game->mlx_w = mlx_new_window(game->mlx, game->width_map * 64,
			game->height_map * 64, "so_long");
	if (!game->mlx_w)
		window_mlx_error(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
		if (!game)
			return (0);
		struct_init(game);
		check_file(argv[1], game);
		window_init(game);
		create_map(game);
		mlx_hook(game->mlx_w, 2, 1L << 0, move, game);
		mlx_hook(game->mlx_w, 17, (1L << 17), exit_game, game);
		mlx_loop(game->mlx);
	}
	else
		params_number_error();
	return (0);
}
