#include "get_next_line.h"

static	char	*ft_fill_str(char *str, int ret, char *buf, int *flag)
{
	char	*new;
	int		i;

	buf[ret] = '\0';
	//Сначала делать merge динамического массива с buf, потом уже этот массив со строкой str
	i = 0;
	while (buf[i] != '\n' && i < ret)
		i++;
	if (i == ret)
	{
		new = ft_strjoin(str, buf);
		free(str);
		//str = NULL;//Надо ли?
	}
	else
	{
		// Создать динамический статический массив под остаток от buf после ft_strjoin, при полном вхождении его очищать
		//buf[i] = '\0';
		new = ft_strjoin(str, buf);
		free(str);
		//str = NULL;//Надо ли?
		*flag = 1;
	}
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	char	*str;
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		flag;

	flag = 0;
	str = NULL;
	if (!fd || !line) // если line = NULL?
		return (-1);
	if(!(str = (char*)malloc(sizeof(char))))
		return (-1);
	str[0] = '\0';
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		str = ft_fill_str(str, ret, buf, &flag);
		if (flag)
			break ;
	}
	*line = str;
	printf("%s\n", *line);
	// str = NULL;
	// while ((ret = read(fd, buf, BUF_SIZE)))
	// {
	// 	str = ft_fill_str(str, ret, buf, &flag);
	// 	if (flag)
	// 		break ;
	// }
	// *line = str;
	// printf("%s", *line);
	return (1);
}