/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:05:45 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/04 09:48:19 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	setup(t_env *env, t_settings *set, int philo)
{
	memset(env, 0, sizeof(t_env));
	if (salloc((void **)&env->th, philo * sizeof(pthread_t)) || \
		salloc((void **)&env->mut, philo * sizeof(pthread_mutex_t)) || \
		salloc((void **)&env->data, philo * sizeof(t_thread_data)) || \
		salloc((void **)&env->forks, philo * sizeof(int)) || \
		salloc((void **)&env->sig_mutex, philo * sizeof(pthread_mutex_t)) || \
		salloc((void **)&env->sig, philo * sizeof(int)) || \
		salloc((void **)&env->ctl_mutex, sizeof(pthread_mutex_t)) || \
		salloc((void **)&env->ctl, sizeof(int)) || \
		salloc((void **)&env->print, sizeof(pthread_mutex_t)) || \
		salloc((void **)&env->start, sizeof(t_time)) || \
		data_init(env, set, philo) || mutex_init(env, philo))
	{
		free_env(env);
		return (1);
	}
	memset(env->sig, 0, philo * sizeof(int));
	*env->ctl = 0;
	while (philo-- > 0)
		env->forks[philo] = 1;
	return (0);
}

void	stop_order(t_env *env, int philo)
{
	int	i;

	i = 0;
	while (i < philo)
	{
		pthread_mutex_lock(&env->sig_mutex[i]);
		env->sig[i] = 1;
		pthread_mutex_unlock(&env->sig_mutex[i]);
		++i;
	}
}

int	launch(t_env *env, int philo, int *created)
{
	pthread_mutex_lock(env->ctl_mutex);
	if (populate(env, philo, created))
	{
		gettimeofday(env->start, NULL);
		pthread_mutex_unlock(env->ctl_mutex);
		return (1);
	}
	gettimeofday(env->start, NULL);
	pthread_mutex_unlock(env->ctl_mutex);
	return (0);
}

int	sim_start(t_settings *set, int philo)
{
	int		created;
	t_env	env;

	if (setup(&env, set, philo))
		return (1);
	if (launch(&env, philo, &created))
		return (1);
	pthread_mutex_lock(env.ctl_mutex);
	while (*env.ctl != -1 && *env.ctl < philo)
	{
		pthread_mutex_unlock(env.ctl_mutex);
		usleep(200);
		pthread_mutex_lock(env.ctl_mutex);
	}
	pthread_mutex_unlock(env.ctl_mutex);
	stop_order(&env, philo);
	thread_join(&env, created);
	free_mutex(&env, philo);
	free_env(&env);
	return (0);
}
