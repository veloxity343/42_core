/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itbl_reset_ani.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:29:03 by stan              #+#    #+#             */
/*   Updated: 2024/02/14 17:29:03 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_itbl_reset_ani(t_itbl *itbl)
{
	itbl->sprite_idx = 0;
	itbl->frame_tick = 0;
}
