#include "get_next_line.h"

static  t_fd    *ft_add_elem_and_find(t_fd *list, int fd, char *str, int flag)
{
    while (list && list->fd != fd)
        list = list->next;
    if (list)
    {
        //printf("testif\n");
        if (list->fd == fd)
            return (list);
    }
    if(!(list = (t_fd*)malloc(sizeof(t_fd))))
        return (NULL);
    list->fd = fd;
    if (!(list->str = (char*)malloc(sizeof(char))))
		return (NULL);
	list->str[0] = '\0';//Или при null 
    list->flag = 0;
    list->next = NULL;
    return (list);
}

char	*ft_change_str_list(char *str, int i)
{
	int     len;
    char    *tmp;
    int     j;

    i++;//?
    len = ft_strlen(&(str[i]));
    tmp = (char*)malloc(sizeof(char) * (len + 1));
    j = 0;
    tmp[len] = '\0';
    while (str[i] != '\0' && tmp[j] != '\0' && j < len)
        tmp[j++] = str[i++];
    free(str);
    return (tmp);
}
   

char	*ft_fill_line(char *str, t_fd *cur, char *buf, int ret)
{
	char	*new;
	int		i;
	int		len;

	buf[ret] = '\0';
	len = ft_strlen(cur->str);
	if(!(cur->str = ft_strjoin(cur->str, buf)))//leek
		return (NULL);
	i = 0;
	while (cur->str[i] != '\n' && i < (ret + len))
		i++;
	if (i == (ret + len))
	{
        //printf("\n %p \n", new);
        //printf("str = %s, cur->str = %s", str, cur->str);
		new = ft_strjoin(str, cur->str);
        //printf("\n %p \n", new);
		free(str);
		free(cur->str);
	}
	else
	{
		cur->str[i] = '\0';
		new = ft_strjoin(str, cur->str);
        cur->str = ft_change_str_list(cur->str, i);
        free(str);
	}
    printf("%s", new);
    return (new);
}

int     get_next_line2(int fd, char **line)
{
    int     ret;
    char    buf[BUF_SIZE + 1];
    char    *str;
    static t_fd    *list = NULL;
    t_fd           *cur;

    if (!fd || !line)
        return (-1);
    if (!(cur = ft_add_elem_and_find(list, fd, NULL, 0)))
        return (-2);
	str = NULL;
    if (!(str = (char*)malloc(sizeof(char))))
        return (-3);
    printf("gnl test0\n");
    while ((ret = read(cur->fd, buf, BUF_SIZE)))
    {
        if(!(str = ft_fill_line(str, cur, buf, ret)))
            return (-4);
        if (cur->flag)
            return (5);        
    }
    return (0);
}