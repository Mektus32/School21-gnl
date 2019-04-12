#include "get_next_line.h"

static  t_fd    *ft_add_elem_and_find(t_fd *list, int fd, char *str, int flag)
{
    while (list && list->fd != fd)
        list = list->next;
	printf("list = %p\n", list);//Вот тут выдает 0x0
    if (list)
        if (list->fd == fd)
		{
			list->flag = 0;
            return (list);
		}
	if(!(list = (t_fd*)malloc(sizeof(t_fd))))
        return (NULL);
    list->fd = fd;
	list->str = str;
    if (!(list->str = (char*)malloc(sizeof(char))))
		return (NULL);
	list->str[0] = '\0'; 
    list->flag = flag;
    list->next = NULL;
	list->count = 0;
    return (list);
}

char	*ft_change_str_list(char *str, int i)
{
	int     len;
    char    *tmp;
    int     j;

    //i++;//?
    len = ft_strlen(&(str[++i]));
	printf("len ft_change_str_list = %d\n", len);
    tmp = (char*)malloc(sizeof(char) * (len + 1));
    j = 0;
    tmp[len] = '\0';
    while (str[i] != '\0')
        tmp[j++] = str[i++];
    free(str);
    return (tmp);
}
   

char	*ft_fill_line(char *str, t_fd *cur, char *buf, int ret)
{
	char	*new = NULL;
	int		i;
	int		len;

	len = ft_strlen(cur->str);
	printf("\n\n\nlen in ft_fill_line = %d\n", len);
	printf("buf in ft_fill_line = %s\n", buf);
	printf("str in ft_fill_line = %s\n", str);
	if(!(cur->str = ft_strjoin(cur->str, buf)))//leek
		return (NULL);
	printf("cur->str in ft_fill_line = %s\n", cur->str);
	i = 0;
	while (cur->str[i] != '\n' && i < (ret + len))
		i++;
	if (i == (ret + len))
	{
		new = ft_strjoin(str, cur->str);
		printf("new in ft_fill_line = %s\n", new);
      	free(str);
		if (!(str = (char*)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		free(cur->str);
		if (!(cur->str = (char*)malloc(sizeof(char))))
			return (NULL);
		cur->str[0] = '\0';
	}
	printf("i = %d\n", i);
	if (cur->str[i] == '\n')
	{
		cur->str[i] = '\0';
		new = ft_strjoin(str, cur->str);
		printf("new in ft_fill_line = %s\n", new);
        cur->str = ft_change_str_list(cur->str, i);
		printf("cur->str in ft_fill_line -> change_str = %s\n", cur->str);	
        free(str);
		if (!(str = (char*)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		cur->flag = 1;
	}
    //printf("nedlist = %p\n", cur);
    return (new);
}

int     get_next_line2(int fd, char **line)
{
    int				ret;
    char			buf[BUF_SIZE + 1];
    char			*str;
    static t_fd		*list;
    t_fd			*cur;

    if (!fd || !line)
        return (-1);
    if (!(cur = ft_add_elem_and_find(list, fd, NULL, 0)))//Был ли уже открыт этот файл или нет
        return (-2);
	str = NULL;
    if (!(str = (char*)malloc(sizeof(char))))
        return (-3);
    while ((ret = read(cur->fd, buf, BUF_SIZE)))
    {
        if(!(str = ft_fill_line(str, cur, buf, ret)))
            return (-4);
        if (cur->flag)
		{
			line[cur->count] = str;
			cur->count++;// += 1;
			printf("cur->count = %d\n", cur->count);
			printf("endfunct pointer list = %p\n", cur);
			return (5);
		}		
    }
	printf("%s\n", str);
    return (0);
}
