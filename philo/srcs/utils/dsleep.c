/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 00:07:43 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/30 15:20:59 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dsleep(ulong usecond, t_thread_data *arg, t_time *last)
{
	t_time	begin;
	t_time	time;

	gettimeofday(&begin, NULL);
	gettimeofday(&time, NULL);
	while (delta_utime(&begin, &time) < usecond)
	{
		pthread_mutex_lock(arg->sig_mutex);
		if (*arg->sig == 1)
		{
			pthread_mutex_unlock(arg->sig_mutex);
			return (1);
		}
		pthread_mutex_unlock(arg->sig_mutex);
		usleep(100);
		if (check_death(arg, last))
			return (1);
		gettimeofday(&time, NULL);
	}
	return (0);
}
