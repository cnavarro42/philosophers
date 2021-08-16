/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:57:57 by iibarra-          #+#    #+#             */
/*   Updated: 2021/08/10 16:30:01 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	contador;
	int	longitud;

	if (!str)
		return ;
	contador = 0;
	while (str[contador] != '\0')
	{
		contador++;
	}
	longitud = contador;
	contador = 0;
	while (contador < longitud)
	{
		write(fd, &str[contador], 1);
		contador++;
	}
}
