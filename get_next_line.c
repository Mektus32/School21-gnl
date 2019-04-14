#include "get_next_line.h"

t_fd	*ft_add_and_find_elem(t_fd **head, int fd)
{
	t_fd	*list;

	list = *head;
	while (list && list->fd != fd)
		list = list->next;
	if (list && list->fd == fd)
		return (list);
	if (!(list = (t_fd*)malloc(sizeof(t_fd))))
		return (NULL);
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
	len = -1;
	while (new[++len] != '\0')
		new[len] = cur->str[len];
	if (len == cur->ret)
	{
		free(cur->str);
		cur->str = NULL;
	}
	else
	{
		cur->ret -= len--;//Длина остаточной строки
		if (!(tmp = (char*)malloc(sizeof(char) * (cur->ret + 1))))
			return (-1);
		tmplen = 0;
		while (cur->str[++len] != '\0')
			tmp[tmplen++] = cur->str[len];
		free(cur->str);
		cur->str = new;
	}
	line[cur->count++] = new;
	return (0);
}

int     get_next_line(int fd,  char **line)
{
	char				buf[BUF_SIZE + 1];
	static	t_fd		*list;
	t_fd				*cur;

	printf("first place\n");
	if (list && cur->ret > 0)
		if (!(cur = ft_add_and_find_elem(&list, fd)))
			return(-1);
		else if (cur->str && ft_memchr(cur->str, '\n', ft_strlen(cur->str)))
			return (ft_return_line(cur, line));
	printf("second place\n");
	if (!list)
		if (!(list = ft_add_and_find_elem(&list, fd)))
			return (-1);
	printf("third place\n");
	if (!(cur = ft_add_and_find_elem(&list, fd)))
			return(-1);
	printf("forth place\n");
	while ((cur->ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[BUF_SIZE] = '\0';
		printf("ret = %d\n", cur->ret);
		printf("buf = %s", buf);
		if (!cur->str)
			cur->str = ft_strcpy(ft_strnew(cur->ret), buf);
		else
			cur->str = ft_strjoin(cur->str, buf);//leak
		printf("five place str = %s\n", cur->str);
		if (ft_memchr(cur->str, '\n', ft_strlen(cur->str)))
			return (ft_return_line(cur, line));
		printf("six place\n");
	}
	return (0);
}