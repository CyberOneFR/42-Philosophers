/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:17:36 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/23 02:09:34 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	populate(t_env *env, int philo, int *created)
{
	*created = 0;
	while (*created < philo)
	{
		if (pthread_create(&env->th[*created], NULL, (void *)thread_routine, \
			&env->data[*created]))
		{
			write(2, "pthread_create error\n", 22);
			*env->sig = 1;
			pthread_mutex_unlock(env->sig_mutex);
			thread_join(env, *created);
			free_mutex(env, philo);
			free_env(env);
			return (1);
		}
		++*created;
	}
	return (0);
}
