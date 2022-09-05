/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igbocha3 <igbocha3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 07:03:41 by igbocha3          #+#    #+#             */
/*   Updated: 2022/09/04 02:25:30 by igbocha3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_line_check(char *tmp, int fd, t_game *game)
{
	if (!tmp || tmp[0] != '1')
	{
		free(game);
		close(fd);
		perror("ERROR: FIRST ELEMENT SHOULD BE WALL or MAP IS NOT VALID\n");
		exit (1);
	}
}

void	rest_line_check(char *tmp, int fd, char *str, t_game *game)
{
	if (tmp != NULL && tmp[0] != '1')
	{
		free_all(game, str, tmp);
		close(fd);
		perror("ERROR: FIRST ELEMENT SHOULD BE WALL or MAP IS NOT VALID\n");
		exit (1);
	}
}

void	check_map(t_game *game)
{
	check_map_struct(game);
	check_borders(game);
	check_comps(game);
	count_comps(game);
}

void	check_file(char *f, t_game *game)
{
	int	i;

	i = ft_strlen(f) - 4;
	if (f[i] == '.' && f[i + 1] == 'b' && f[i + 2] == 'e' && f[i + 3] == 'r')
	{
		if (parse(f, game) == -1)
			parse_error(game);
		check_map(game);
	}
	else
		file_error(game);
}
