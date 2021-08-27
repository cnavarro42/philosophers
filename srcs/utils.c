/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:44:55 by cnavarro          #+#    #+#             */
/*   Updated: 2021/08/27 17:26:09 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

uint64_t gettime(void)
{
	struct timeval time;
	uint64_t mseconds;

	gettimeofday(&time, NULL);
	mseconds = (uint64_t)((time.tv_sec * 1000) + (time.tv_usec / 1000));

	return (mseconds);
}

void	ft_usleep(uint64_t time)
{
	uint64_t	finish;

	finish = gettime() + time;
	while (gettime() < finish)
		usleep(1);
}
