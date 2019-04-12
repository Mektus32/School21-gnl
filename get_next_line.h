#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUF_SIZE 10

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <io.h>
#include <stdio.h>
#include "libft.h"

typedef	struct		s_fd
{
	int				fd;
	char			*str;
	struct s_fd		*next;
}					t_fd;

int		get_next_line(const int fd, char **line);

#endif