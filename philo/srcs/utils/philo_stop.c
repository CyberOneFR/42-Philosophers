/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:40:30 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/04 09:48:10 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_stop(t_thread_data *arg)
{
	pthread_mutex_lock(arg->ctl_mutex);
	++*arg->ctl;
	pthread_mutex_unlock(arg->ctl_mutex);
	pthread_exit(0);
}
