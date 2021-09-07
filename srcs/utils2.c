/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:59:08 by cnavarro          #+#    #+#             */
/*   Updated: 2021/09/07 14:04:01 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void	*ft_calloc(size_t n, size_t s)
{
	void	*ptr;

	ptr = malloc(n * s);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, n * s);
	return (ptr);
}

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*cad;
	size_t			i;

	cad = (unsigned char *)str;
	i = 0;
	while (n > i)
	{
		cad[i] = '\0';
		i++;
	}
}

static int	ft_space_spaces(const char *str, int i)
{
	while ((str[i]) == '\t' || (str[i]) == '\n'
		|| (str[i]) == '\v' || (str[i]) == '\f'
		|| (str[i]) == '\r' || (str[i]) == ' ')
		i++;
	return (i);
}

static int	ft_setnumber(const char *str, int i, int neg)
{
	int	n;

	n = 0;
	while ((str[i]) >= '0' && (str[i]) <= '9')
	{
		n = ((n * 10) + (str[i]) - '0');
		i++;
	}
	n = n * neg;
	return (n);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	i;
	int	neg;

	neg = 1;
	i = 0;
	i = ft_space_spaces(str, i);
	if ((str[i]) == '+')
		i++;
	else if ((str[i]) == '-')
	{
		neg = -1;
		i++;
	}
	else if ((str[i]) < '0' || (str[i]) > '9')
		return (0);
	if ((str[i]) < '0' || (str[i]) > '9')
		return (0);
	n = ft_setnumber(str, i, neg);
	return (n);
}
