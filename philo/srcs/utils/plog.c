/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 00:06:32 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/04 09:44:47 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	plog(t_thread_data *arg, char *msg)
{
	t_time	time;

	pthread_mutex_lock(arg->ctl_mutex);
	if (*arg->ctl >= 0)
	{
		pthread_mutex_lock(arg->print);
		gettimeofday(&time, NULL);
		printf("%lu %d %s\n", delta_utime(arg->start, &time) \
			/ 1000, arg->id, msg);
		pthread_mutex_unlock(arg->print);
	}
	pthread_mutex_unlock(arg->ctl_mutex);
}
