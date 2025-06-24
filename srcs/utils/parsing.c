/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:00:44 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/23 17:08:17 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str, int *ret)
{
	int	sign;
	int	nbr;
	int	of;

	of = 0;
	sign = 1;
	nbr = 0;
	while (*str == ' ' || *str == '	')
		++str;
	while (*str == '+' || *str == '-')
	{
		sign = 44 - *str;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (__builtin_smul_overflow(nbr, 10, &nbr) || \
		__builtin_sadd_overflow(nbr, *str - '0', &nbr))
			of = 1;
		++str;
	}
	__builtin_smul_overflow(nbr, sign, ret);
	return (of);
}

int	only_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		++i;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc == 5)
		return (only_digit(argv[1]) || only_digit(argv[2]) || \
				only_digit(argv[3]) || only_digit(argv[4]));
	else if (argc == 6)
		return (only_digit(argv[1]) || only_digit(argv[2]) || \
				only_digit(argv[3]) || only_digit(argv[4]) || \
				only_digit(argv[5]));
	else
		printf("wtf you just experienced a solar attack !!\n");
	return (1);
}

int	parse_args(int argc, char **argv, t_settings *set, int *philo)
{
	if (argc >= 5)
	{
		if (ft_atoi(argv[1], philo))
			return (1);
		if (ft_atoi(argv[2], &set->die))
			return (1);
		if (ft_atoi(argv[3], &set->eat))
			return (1);
		if (ft_atoi(argv[4], &set->sleep))
			return (1);
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[5], &set->limit))
			return (1);
	}
	else
		set->limit = 0x7FFFFFFF;
	return (0);
}
