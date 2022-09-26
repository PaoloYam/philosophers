/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:54:01 by pyammoun          #+#    #+#             */
/*   Updated: 2022/09/23 13:54:30 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo	*philou;

	philou = (t_philo*)philo;
	if (philou->id%2 != 0)
		usleep(100);
	printf("%lld\n", philou->last_meal = ft_gettime());
	return (0);
}
