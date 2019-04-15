/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:18:50 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/15 14:23:58 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd	*ft_add_and_find_elem(t_fd **head, int fd)
{
	t_fd	*list;

	list = *head;
	while (list && list->next && list->fd != fd)
		list = list->next;
	if (list && list->fd == fd)
		return (list);
	if (!list)
	{
		if (!(list = (t_fd*)malloc(sizeof(t_fd))))
			return (NULL);
	}
	else if (!list->next)
	{
		if (!(list->next = (t_fd*)malloc(sizeof(t_fd))))
			return (NULL);
		list = list->next;
	}
	list->fd = fd;
	list->str= NULL;
	list->ret = 0;
	list->count = 0;
	list->next = NULL;
	return (list);
}

int		ft_return_line(t_fd *cur, char **line)
{
	int		len;
	char	*new;
	char	*tmp;
	int		tmplen;

	len = 0;
	while (cur->str[len] != '\n')
		len++;
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (-1);
	new[len] = '\0';
	tmplen = -1;
	while (++tmplen < len)
		new[tmplen] = cur->str[tmplen];
	if (len == cur->ret)
	{
		free(cur->str);
		cur->str = NULL;
	}
	else
	{
		cur->ret = ft_strlen(cur->str) - len;//Длина остаточной строки
		if (!(tmp = (char*)malloc(sizeof(char) * (cur->ret + 1))))
			return (-1);
		tmplen = 0;
		while (cur->str[++len] != '\0')
			tmp[tmplen++] = cur->str[len];
		free(cur->str);
		cur->str = tmp;
	}
	line[cur->count++] = new;
	//printf("zakonchenaya stroka = %s\n", new);
	//printf("ostatok stroki = %s\n", cur->str);
	return (1);
}

int     get_next_line(int fd,  char **line)
{
	char				buf[BUFF_SIZE + 1];
	static	t_fd		*list;
	t_fd				*cur;

	if (list && list->ret > 0)
	{
		if (!(cur = ft_add_and_find_elem(&list, fd)))
			return(-1);
		else if (cur->str && ft_memchr(cur->str, '\n', ft_strlen(cur->str)))
			return (ft_return_line(cur, line));
	}
	if (!list)
		if (!(list = ft_add_and_find_elem(&list, fd)))
			return (-1);
	if (!(cur = ft_add_and_find_elem(&list, fd)))
			return(-1);
	while ((cur->ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[BUFF_SIZE] = '\0';
		//printf("schitannaya stroka = %s\n", buf);
		if (!cur->str)
			cur->str = ft_strcpy(ft_strnew(cur->ret), buf);
		else
			cur->str = ft_strjoin(cur->str, buf);//leak
		//printf("stroka posle sliayania = %s\n", cur->str);
		if (ft_memchr(cur->str, '\n', ft_strlen(cur->str)))
			return (ft_return_line(cur, line));
	}
	return (1);
}
