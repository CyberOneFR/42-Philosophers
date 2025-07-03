/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:19:34 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/24 18:45:58 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	mutex_init_print(t_env *env, int philo)
{
	if (pthread_mutex_init(env->print, NULL))
	{
		write(2, "pthread_mutex_init error\n", 26);
		while (philo-- > 0)
		{
			pthread_mutex_destroy(&env->sig_mutex[philo]);
			pthread_mutex_destroy(&env->mut[philo]);
		}
		return (1);
	}
	if (pthread_mutex_init(env->ctl_mutex, NULL))
	{
		write(2, "pthread_mutex_init error\n", 26);
		while (philo-- > 0)
		{
			pthread_mutex_destroy(&env->sig_mutex[philo]);
			pthread_mutex_destroy(&env->mut[philo]);
		}
		pthread_mutex_destroy(env->print);
		return (1);
	}
	return (0);
}

int	mutex_init_sig(t_env *env, int philo)
{
	int	i;

	i = 0;
	while (i < philo)
	{
		if (pthread_mutex_init(&env->sig_mutex[i], NULL))
		{
			write(2, "pthread_mutex_init error\n", 26);
			while (i-- > 0)
				pthread_mutex_destroy(&env->sig_mutex[i]);
			while (philo-- > 0)
				pthread_mutex_destroy(&env->mut[philo]);
			return (1);
		}
		++i;
	}
	return (0);
}

int	mutex_init(t_env *env, int philo)
{
	int	i;

	i = 0;
	while (i < philo)
	{
		if (pthread_mutex_init(&env->mut[i], NULL))
		{
			write(2, "pthread_mutex_init error\n", 26);
			while (i-- > 0)
				pthread_mutex_destroy(&env->mut[i]);
			return (1);
		}
		++i;
	}
	if (mutex_init_sig(env, philo))
		return (1);
	if (mutex_init_print(env, philo))
		return (1);
	return (0);
}
