/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 01:32:26 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/30 15:01:59 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_thread_data *arg, t_time *last)
{
	t_time	time;

	gettimeofday(&time, NULL);
	if (delta_utime(last, &time) > (ulong)(arg->settings->die * 1000))
	{
		pthread_mutex_lock(arg->ctl_mutex);
		if (*arg->ctl != -1)
		{
			*arg->ctl = -1;
			pthread_mutex_unlock(arg->ctl_mutex);
			pthread_mutex_lock(arg->print);
			gettimeofday(&time, NULL);
			printf("%lu %d %s\n", delta_utime(arg->start, &time) \
				/ 1000, arg->id, "died");
			pthread_mutex_unlock(arg->print);
			return (1);
		}
		pthread_mutex_unlock(arg->ctl_mutex);
		return (1);
	}
	return (0);
}
