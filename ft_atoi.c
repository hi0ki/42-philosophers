/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:05:24 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/06/04 16:05:25 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int						i;
	int						j;
	unsigned long long int	result;

	i = 0;
	result = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t')
		j++;
	i = j;
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			return (ERROR);
		j++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}
