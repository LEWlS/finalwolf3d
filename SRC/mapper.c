/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:37:57 by lbonnete          #+#    #+#             */
/*   Updated: 2020/01/22 15:10:26 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/wolf3d.h"

static int	get_char_map_help(int width)
{
	if (width)
		return (1);
	return (0);
}

int			get_char_map(int fd, t_var *info)
{
	char	*line;
	int		len;
	int		i;
	size_t	width;

	ft_putendl("b1");
	width = 0;
	len = 0;
	i = -1;
	while ((get_next_line(fd, &line)) == 1)
	{
		ft_putendl("b2");
		if (i == -1)
		{
			ft_putendl("b3");
			width = ft_strlen(line);
			if (width < 5)
				return (0);
			ft_putendl("b4");
		}
		else if (width != ft_strlen(line))
			return (0);
		if (verti_check(line) || !(info->map = realloc_map(info->map, ++len))
		|| !(info->map[++i] = ft_strdup(line)))
			return (0);
		ft_putendl("b5");
		ft_strdel(&line);
	}
	ft_putendl("b6");
	return (get_char_map_help(width));
}

int			ft_reader(char *name, t_var *info)
{
	int fd;
	ft_putendl("a1");
	if (-1 == (fd = open(name, O_RDONLY)))
	{
		close(fd);
		return (0);
	}
	ft_putendl("a2");
	if (get_char_map(fd, info) == 0)
	{
		close(fd);
		destroy_tab(&(info->map));
		return (0);
	}
	ft_putendl("a3");
	close(fd);
	return (1);
}
