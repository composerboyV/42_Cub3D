/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:59:42 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/03 16:48:00 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	move_player(t_game *game)
{
	move_forward(game);
	move_backward(game);
	move_left(game);
	move_right(game);
	rotate_left(game);
	rotate_right(game);
}
