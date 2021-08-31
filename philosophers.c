/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:35:29 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/31 12:03:44 by cnavarro         ###   ########.fr       */
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
			ft_strerror("Hilo no creado correctamente", 4); //no puedo usar exit
		i++;
	}
	i = 0;
	while (dat->is_dead == 0)
	{
		if (dat->phil[i].has_problems == 1)
		{
			pthread_mutex_lock(&dat->eat_or_die);
			if ((gettime() - dat->phil[i].last_time_eating) > dat->time_to_die)
				you_died(&dat->phil[i]);
		}
		pthread_mutex_unlock(&dat->eat_or_die);
		i++;
		if (i >= dat->number_of_philo)
			i = 0;
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
