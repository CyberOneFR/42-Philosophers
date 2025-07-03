/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:58:50 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/22 21:35:59 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	thread_join(t_env *env, int created)
{
	while (created--)
	{
		if (pthread_join(env->th[created], NULL))
		{
			write(2, "pthread_join error\n", 20);
			return (1);
		}
	}
	return (0);
}
