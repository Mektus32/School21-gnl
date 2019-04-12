/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:26:42 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/12 20:10:21 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	char	**line;
	int		fd;

	line = (char**)malloc(sizeof(char*));
	if (!(fd = open("test", O_RDONLY)))
		return (-1);
	for (int i = 0; i < 3; i++)
		printf("gnl = %d\n", get_next_line2(fd, line));
	for (int i = 0; i < 1; i++)
		printf("str[%d] = %s\n", i, line[i]);
	return (0);
}