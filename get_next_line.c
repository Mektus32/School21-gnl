/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:31:16 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/11 20:53:51 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	char	*ft_fill_str(char *str, int ret, char *buf, int flag)
{
	int		len;

	return (0);

}

int				get_next_line(int fd, char **line)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*str;
	int		flag;

	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		str = ft_fill_str(str, ret, buf, flag);
	}
	return (0);
}

int				main(void)
{
	int		ret;
	int		fd;
	char	**line;

	printf("%zu", ft_strlen("12314124")) 
//	if (!fd = open("test", O_RDONLY))
		return (1);
	get_next_line(fd,  line);
}
