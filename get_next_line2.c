#include "get_next_line.h"

static  t_fd    *ft_add_elem_and_find(t_fd **head, int fd, char *str, int flag)
{
	t_fd	*list;

	list = *head;

	printf("Adress lista v nachale dobavlenia = %p\n", list);//Вот тут выдает 0x0
    while (list && list->fd != fd)
        list = list->next;
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
	printf("dlina ostatka posle obrazania simvolom '\\n' v ft_change_str = %d\n", len);
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

	buf[ret] = '\0';
	len = ft_strlen(cur->str);
	printf("\n\nkolichestvo schitannogo ret = %d\n", ret);
	printf("dlina dinamiceskoy stroky v liste = %d\n", len);
	printf("schitanaya stroka(buf) = %s§\n", buf);
	printf("konechnaya stroka na danniy moment = %s§\n", str);
	if(!(cur->str = ft_strjoin(cur->str, buf)))//leek
		return (NULL);
	printf("dinamicheskay stroka + schitannaya stroka(buf) = %s§\n", cur->str);
	i = 0;
	while (cur->str[i] != '\n' && i < (ret + len))
		i++;
	if (i == (ret + len))
	{
		new = ft_strjoin(str, cur->str);
		printf("novaya konechnaya stroka do koncha razmera shitanoy stroki(buf) = %s§\n", new);
      	free(str);
		if (!(str = (char*)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		free(cur->str);
		if (!(cur->str = (char*)malloc(sizeof(char))))
			return (NULL);
		cur->str[0] = '\0';
	}
	//printf("i = %d\n", i);
	if (cur->str[i] == '\n')
	{
		cur->str[i] = '\0';
		new = ft_strjoin(str, cur->str);
		printf("novaya konechnay stroka do simvola '\\n' = %s§\n", new);
        cur->str = ft_change_str_list(cur->str, i);
        free(str);
		printf("ostatok posle izmeneniya konechnoy stroki = %s§\n", cur->str);
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
    static t_fd		*list = NULL;
	t_fd			*cur;

	printf("BUF_SIZE = %d\n", BUF_SIZE);
    if (!fd || !line)
        return (-1);
	if (!list)
		if (!(list = ft_add_elem_and_find(&list, fd, NULL, 0)))
			return (-6);
    if (!(cur = ft_add_elem_and_find(&list, fd, NULL, 0)))//Был ли уже открыт этот файл или нет
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
			cur->count += 1;
			printf("kolichetvo strok = %d\n", cur->count);
			printf("adress lista pered vihodom is functii = %p\n\n\n", cur);
			return (5);
		}		
    }
	printf("%s\n", str);
    return (0);
}
