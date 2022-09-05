/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igbocha3 <igbocha3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 07:04:32 by igbocha3          #+#    #+#             */
/*   Updated: 2022/09/04 02:26:52 by igbocha3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

# define PLAYER1 "./img/player1.xpm"
# define PLAYER2 "./img/player2.xpm"
# define PAPER "./img/paper.xpm"
# define EXIT "./img/exit.xpm"
# define WATER "./img/water.xpm"
# define GROUND "./img/ground.xpm"

typedef struct s_game
{
	char	**map;
	int		p_x;
	int		p_y;
	int		col;
	int		player;
	int		steps;
	int		exit;
	void	*mlx;
	void	*mlx_w;
	void	*img;
	int		width_map;
	int		height_map;
}			t_game;

void	struct_init(t_game *game);
void	window_init(t_game *game);
int		parse(char *file, t_game *game);
void	check_map(t_game *game);
void	check_file(char *file, t_game *game);
void	check_map_struct(t_game *game);
void	check_borders(t_game *game);
void	check_comps(t_game *game);
void	count_comps(t_game *game);
int		exit_game(t_game *game);
int		move(int key, t_game *game);
void	create_map(t_game *game);
void	send_to_print(t_game *game, int x, int y);
void	print_image(t_game *game, char *path, int x, int y);
int		check_move(int x, int y, t_game *game);
void	first_line_check(char *tmp, int fd, t_game *game);
void	rest_line_check(char *tmp, int fd, char *str, t_game *game);
void	parse_error(t_game *game);
void	file_error(t_game *game);
void	map_struct_error(t_game *game);
void	map_border_error(t_game *game);
void	map_comps_error(t_game *game);
void	map_empty_line_error(t_game *game, char *str, char *temp);
void	window_mlx_error(t_game *game);
void	params_number_error(void);
void	free_all(t_game *game, char *str, char *temp);
void	free_arrays(char *str, char *temp);
void	free_struct(t_game *game);

#endif