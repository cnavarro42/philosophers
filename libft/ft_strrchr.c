/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:32:19 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/10 16:32:59 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	if (str[i] == '\0' && c == '\0')
	{
		return ((char *)str);
	}
	while (str[i] != '\0')
	{
		if (str[i] == c)
			j = i;
		i++;
	}
	if (str[i] == 0 && c == 0)
		return ((char *)&str[i]);
	if (j >= 0)
		return ((char *)str + j);
	return (NULL);
}
