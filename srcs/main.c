/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:48:25 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/23 03:26:34 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_settings	set;
	int			philo;

	if (argc < 5)
	{
		write(2, "too few arguments minimum 4 required\n", 38);
		return (1);
	}
	if (argc > 6)
	{
		write(2, "too many arguments maximum 5 required\n", 39);
		return (1);
	}
	else if (check_args(argc, argv) || parse_args(argc, argv, &set, &philo))
	{
		write(2, "invalid arguments\n", 19);
		return (1);
	}
	if (sim_start(&set, philo))
		return (1);
	return (0);
}
