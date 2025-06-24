/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:35:02 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/24 18:45:41 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	data_init(t_env *env, t_settings *set, int philo)
{
	int	i;

	i = 0;
	while (i < philo)
	{
		env->data[i].left_fork = &env->forks[i];
		env->data[i].left_mutex = &env->mut[i];
		env->data[i].right_fork = &env->forks[(i + 1) % philo];
		env->data[i].right_mutex = &env->mut[(i + 1) % philo];
		env->data[i].sig_mutex = &env->sig_mutex[i];
		env->data[i].sig = &env->sig[i];
		env->data[i].settings = set;
		env->data[i].print = env->print;
		env->data[i].id = i + 1;
		env->data[i].philo = philo;
		env->data[i].ctl_mutex = env->ctl_mutex;
		env->data[i].ctl = env->ctl;
		env->data[i].start = env->start;
		++i;
	}
	return (0);
}
