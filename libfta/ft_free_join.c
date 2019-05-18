/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:36:30 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/16 14:37:37 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_join(char *new, char *src)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(new, src)))
		return (NULL);
	free(new);
	new = NULL;
	return (tmp);
}
