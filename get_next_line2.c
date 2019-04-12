#include "get_next_line.h"

static  t_fd    *ft_add_elem_and_find(t_fd *list, int fd, char *str, int flag)
{
    while (list && list->fd != fd)
        list = list->next;
    //printf("test4\n");
    //printf("list2 = %p\n", list);
    if (list)
    {
        //printf("testif\n");
        if (list->fd == fd)
            return (list);
    }
   	//printf("test3\n list->fd = %d fd = %d", list->fd, fd);
    //printf("test2\n");
    if(!(list = (t_fd*)malloc(sizeof(t_fd))))
        return (NULL);
    //printf("test1\n");
    list->fd = fd;
    list->str = str;
    list->flag = 0;
    list->next = NULL;
    return (list);
}

char    *ft_fill_line(char *str, t_fd *list, char *buf, int ret)
{
    list->flag = 1;
    return (NULL);
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
	//printf("gnl test1 p = %p\n", list);
    if (!(cur = ft_add_elem_and_find(list, fd, NULL, 0)))
        return (-1);
    //printf("gnl text0\n");
	//printf("gnl test1 str = %p\n", str);
    if (!(str = (char*)malloc(sizeof(char))))
        return (-1);
	//printf("gnl test2\n");
    while ((ret = read(cur->fd, buf, BUF_SIZE)))
    {
        if(!(str = ft_fill_line(str, cur, buf, ret)))
            return (-1);
        if (cur->flag)
            return (1);        
    }
    return (0);
}