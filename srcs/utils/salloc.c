/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:18:45 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/23 03:26:26 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	salloc(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!ptr)
	{
		write(2, "malloc error\n", 14);
		return (1);
	}
	return (0);
}
