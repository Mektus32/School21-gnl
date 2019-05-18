/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:54:44 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/17 17:11:20 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 50

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int		get_next_line(const int fd, char **line);

#endif
