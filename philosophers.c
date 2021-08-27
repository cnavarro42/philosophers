/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:35:29 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/26 19:22:44 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

int	main(int argc, char **argv)
{
	t_datos *dat;
	int i;
	

	dat = ft_calloc(sizeof(t_datos), 1);
	arg_errors(argc, argv);
	fill_dat(argc, argv, dat);
	i = 0;
	while (i < dat->number_of_philo)
	{
		fill_philo(dat, &dat->phil[i], i);
		if (0 != pthread_create(&dat->philo[i], NULL, philo_routine, &dat->phil[i]))
			ft_strerror("Hilo no creado correctamente", 4);
		i++;
	}
	i = 0;
	while (i < dat->number_of_philo)
	{
		pthread_join(dat->philo[i], NULL);
		i++;
	}
	return (0);
	free(dat);
}
