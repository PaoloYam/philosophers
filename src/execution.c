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


int ft_eating(t_philo *philo)
{
	int i;

	i = 0;
	pthread_mutex_lock(philo->r_fork);
}


void	*routine(void *philo)
{
	t_philo	*philou;

	philou = (t_philo*)philo;
	philou->last_meal = ft_gettime();
	if (philou->id%2 != 0)
		usleep(500);
	ft_eating(philou);/*while (philou->info->all_eat != 1 && philou->info->dead != 1)
	{


	}*/
	printf("%lld\n", philou->last_meal = ft_gettime());
	return (0);
}
