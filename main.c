/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:56:06 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/11 22:00:58 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "draw.h"

int	main(void)
{
	t_game	game;

	memset(&game, 0, sizeof(t_game));
	init_dummy_map(&game);
	if (!start_draw(&game))
	{
		printf("Error: Failed to initialize drawing engine\n");
		return (1);
	}
	return (0);
}
