/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:39:35 by trabut            #+#    #+#             */
/*   Updated: 2020/01/22 15:33:21 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf3d.h"

void	destroy_tab(char ***tab)
{
	int i;

	i = 0;
	if (tab)
	{
		if (*tab)
		{
			while ((*tab)[i])
			{
				free((*tab)[i]);
				(*tab)[i] = 0;
				i++;
			}
			free(*tab);
			*tab = 0;
		}
	}
}

char	**realloc_map(char **map, int len)
{
	int		i;
	char	**ret;

	ft_putendl("c1");
	if (!(ret = (char **)malloc(sizeof(char *) * len + 1)))
		return (0);
	ft_putendl("c2");
	ret[len] = NULL;
	ft_putendl("c3");
	printf("%p\n",map);
	if (len > 1)
	{
		ft_putendl("c4");
		i = 0;
		while (i < len)
		{
			ft_putendl("c5d");
			ft_putnbr(i);
			ft_putendl(map[i]);
			ft_putendl("c55");
			if (!(ret[i] = ft_strdup(map[i])))
				return (0);
			ft_putendl("c6");
			i++;
		}
		ft_putendl("c7");
		free(ret[i - 1]);
		ft_putendl("c8");
		destroy_tab(&map);
	}
	return (ret);
}

int 	hitboxx(t_var *info, double dirx)
{
	if (dirx > 0 && (info->map[(int)(info->posx + 0.17)][(int)(info->posy)] == '#'))
		return (0);
	if (dirx < 0 && (info->map[(int)(info->posx - 0.17)][(int)(info->posy)] == '#'))
		return (0);
	return (1);
}

int 	hitboxy(t_var *info, double diry)
{
	if (diry > 0 && (info->map[(int)(info->posx)][(int)(info->posy + 0.17)] == '#'))
		return (0);
	if (diry < 0 && (info->map[(int)(info->posx)][(int)(info->posy - 0.17)] == '#'))
		return (0);
	return (1);
}
