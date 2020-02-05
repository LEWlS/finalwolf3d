/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealers4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:04:28 by lewis             #+#    #+#             */
/*   Updated: 2020/02/05 16:11:52 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf3d.h"



void	move_diag(t_input *input)
{
	input->diag = 0;
	if (input->up && input->straf_right && !input->down && !input->straf_left)
	{
		input->diag = 1;
	}
	else if (input->up && input->straf_left && !input->down && !input->straf_right)
	{
		input->diag = 2;
	}
	else if (input->down && input->straf_left && !input->up && !input->straf_right)
	{
		input->diag = 3;
	}
	else if (input->down && input->straf_right && !input->up && !input->straf_left)
	{
		input->diag = 4;
	}
}
void	diag(t_var *info, t_input input)
{
	if (input.diag == 1)
	{
		input.diag_x = info->dirx * (0.707) - info->diry * (-0.707);
		input.diag_y = info->dirx * (-0.707) + info->diry * (0.707);
		if (info->map[(int)(info->posx + input.diag_x
		* info->movespeed)][(int)(info->posy)] !=
		'#' && hitboxx(info, input.diag_x, input.diag_y))
			info->posx += input.diag_x * info->movespeed;
		if (info->map[(int)(info->posx)][(int)(info->posy + input.diag_y
		* info->movespeed)] != '#' && hitboxy(info, input.diag_x, input.diag_y))
			info->posy += input.diag_y * info->movespeed;
	}
	if (input.diag == 2)
	{
		input.diag_x = info->dirx * (0.707) - info->diry * (0.707);
		input.diag_y = info->dirx * (0.707) + info->diry * (0.707);
		if (info->map[(int)(info->posx + input.diag_x
		* info->movespeed)][(int)(info->posy)] !=
		'#' && hitboxx(info, input.diag_x, input.diag_y))
			info->posx += input.diag_x * info->movespeed;
		if (info->map[(int)(info->posx)][(int)(info->posy + input.diag_y
		* info->movespeed)] != '#' && hitboxy(info, input.diag_x, input.diag_y))
			info->posy += input.diag_y * info->movespeed;
	}
	if (input.diag == 3)
	{
		input.diag_x = info->dirx * (-0.707) - info->diry * (0.707);
		input.diag_y = info->dirx * (0.707) + info->diry * (-0.707);
		if (info->map[(int)(info->posx + input.diag_x
		* info->movespeed)][(int)(info->posy)] !=
		'#' && hitboxx(info, input.diag_x, input.diag_y))
			info->posx += input.diag_x * info->movespeed;
		if (info->map[(int)(info->posx)][(int)(info->posy + input.diag_y
		* info->movespeed)] != '#' && hitboxy(info, input.diag_x, input.diag_y))
			info->posy += input.diag_y * info->movespeed;
	}
	if (input.diag == 4)
	{
		input.diag_x = info->dirx * (-0.707) - info->diry * (-0.707);
		input.diag_y = info->dirx * (-0.707) + info->diry * (-0.707);
		if (info->map[(int)(info->posx + input.diag_x
		* info->movespeed)][(int)(info->posy)] !=
		'#' && hitboxx(info, input.diag_x, input.diag_y))
			info->posx += input.diag_x * info->movespeed;
		if (info->map[(int)(info->posx)][(int)(info->posy + input.diag_y
		* info->movespeed)] != '#' && hitboxy(info, input.diag_x, input.diag_y))
			info->posy += input.diag_y * info->movespeed;
	}
}