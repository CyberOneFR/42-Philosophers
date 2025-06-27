/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:35:33 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/27 20:54:45 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	*thread_routine(t_thread_data *arg)
{
	t_time	time;
	t_time	last;
	int		limit;

	limit = 0;
	gettimeofday(&time, NULL);
	gettimeofday(&last, NULL);
	pthread_mutex_lock(arg->ctl_mutex);
	pthread_mutex_unlock(arg->ctl_mutex);
	pthread_mutex_lock(arg->sig_mutex);
	if (arg->id % 2 == 0)
		usleep(500);
	while (*arg->sig != 1)
	{
		pthread_mutex_unlock(arg->sig_mutex);
		if (limit >= arg->settings->limit)
			philo_stop(arg);
		if (try_live(arg, &last, &limit))
			pthread_exit(0);
		pthread_mutex_lock(arg->sig_mutex);
	}
	pthread_mutex_unlock(arg->sig_mutex);
	pthread_exit(0);
}

int	try_live(t_thread_data *arg, t_time *last, int *limit)
{
	if (arg->id % 2 == 0)
	{
		if (fleft(arg, last))
			return (1);
		if (fright(arg, last))
			return (1);
	}
	else
	{
		if (fright(arg, last))
			return (1);
		if (fleft(arg, last))
			return (1);
	}
	if (check_death(arg, last))
		return (1);
	if (eat(arg, last, limit))
		return (1);
	return (0);
}

int	fleft(t_thread_data *arg, t_time *last)
{
	pthread_mutex_lock(arg->sig_mutex);
	while (*arg->sig != 1)
	{
		pthread_mutex_unlock(arg->sig_mutex);
		pthread_mutex_lock(arg->left_mutex);
		if (*arg->left_fork)
		{
			*arg->left_fork = 0;
			pthread_mutex_unlock(arg->left_mutex);
			plog(arg, "has taken a fork");
			return (0);
		}
		pthread_mutex_unlock(arg->left_mutex);
		if (dsleep(100, arg, last))
			return (1);
		pthread_mutex_lock(arg->sig_mutex);
	}
	pthread_mutex_unlock(arg->sig_mutex);
	return (1);
}

int	fright(t_thread_data *arg, t_time *last)
{
	pthread_mutex_lock(arg->sig_mutex);
	while (*arg->sig != 1)
	{
		pthread_mutex_unlock(arg->sig_mutex);
		pthread_mutex_lock(arg->right_mutex);
		if (*arg->right_fork)
		{
			*arg->right_fork = 0;
			pthread_mutex_unlock(arg->right_mutex);
			plog(arg, "has taken a fork");
			return (0);
		}
		pthread_mutex_unlock(arg->right_mutex);
		if (dsleep(100, arg, last))
			return (1);
		pthread_mutex_lock(arg->sig_mutex);
	}
	pthread_mutex_unlock(arg->sig_mutex);
	return (1);
}

int	eat(t_thread_data *arg, t_time *last, int *limit)
{
	plog(arg, "is eating");
	++*limit;
	gettimeofday(last, NULL);
	if (dsleep(arg->settings->eat * 1000, arg, last))
		return (1);
	pthread_mutex_lock(arg->left_mutex);
	*arg->left_fork = 1;
	pthread_mutex_unlock(arg->left_mutex);
	pthread_mutex_lock(arg->right_mutex);
	*arg->right_fork = 1;
	pthread_mutex_unlock(arg->right_mutex);
	if (*limit >= arg->settings->limit)
		return (0);
	plog(arg, "is sleeping");
	if (dsleep(arg->settings->sleep * 1000, arg, last))
		return (1);
	plog(arg, "is thinking");
	return (0);
}
