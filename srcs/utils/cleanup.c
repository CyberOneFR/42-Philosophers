/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:33:55 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/24 18:45:30 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_mutex(t_env *env, int philo)
{
	int	i;

	i = 0;
	while (i < philo)
	{
		pthread_mutex_destroy(&env->mut[i]);
		++i;
	}
	i = 0;
	while (i < philo)
	{
		pthread_mutex_destroy(&env->sig_mutex[i]);
		++i;
	}
	pthread_mutex_destroy(env->print);
	pthread_mutex_destroy(env->ctl_mutex);
}

void	free_env(t_env *env)
{
	free(env->th);
	free(env->mut);
	free(env->data);
	free(env->forks);
	free(env->sig);
	free(env->sig_mutex);
	free(env->print);
	free(env->ctl_mutex);
	free(env->ctl);
	free(env->start);
}
