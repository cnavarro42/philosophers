/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:34:38 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/10 16:28:33 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenint(int n)
{
	int	len;

	len = 0;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static int	ft_iterative_power(int nb, int power)
{
	int	cnb;

	cnb = nb;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		while (power > 1)
		{
			cnb = cnb * nb;
			power--;
		}
	}
	return (cnb);
}

static void	ft_fillret(int n, int len, char *ret, int i)
{
	while (len > 0)
	{
		if (len > 1)
		{
			ret[i] = n / ft_iterative_power(10, (len - 1)) + '0';
			n = n % ft_iterative_power(10, (len - 1));
		}
		else
			ret[i] = n + '0';
		len--;
		i++;
	}
	ret[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("0"));
	ret = malloc(sizeof(char) * ft_lenint(n) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		ret = malloc(sizeof(char) * ft_lenint(n) + 2);
		if (!ret)
			return (NULL);
		ret[0] = '-';
		n = n * -1;
		i++;
	}
	else
		ret = malloc(sizeof(char) * ft_lenint(n) + 1);
	if (!ret)
		return (NULL);
	ft_fillret(n, ft_lenint(n), ret, i);
	return (ret);
}
