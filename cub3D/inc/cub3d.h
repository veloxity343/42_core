/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:05:57 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/14 11:10:13 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"

typedef enum e_err
{
	ERR_ARGS,
	ERR_MALC,
	ERR_CUB,
	ERR_MAP,
	ERR_MAP7,
	ERR_MAP8,
	ERR_MAP_LAST,
	ERR_MAP_DIR,
	ERR_MAP9,
	ERR_MAP_CHAR,
	ERR_SING_PLAYER,
	ERR_PLA_POS,
	ERR_TEXT,
	ERR_TEXT_MAP,
	ERR_TEXT_COL,
	ERR_TEXT_PATH,
	ERR_RGB,
	ERR_RGB_VAL,
	ERR_MLX_IMG,
	ERR_MLX_WIN,
	ERR_MLX_INIT
}			t_err;

#endif
