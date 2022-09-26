/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:15:06 by pyammoun          #+#    #+#             */
/*   Updated: 2022/09/22 10:15:07 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_creationphilo(t_info *info)
{
	pthread_t th[info->nbphilo];
	int	i;

	i = 0;
	while (i < info->nbphilo)
	{
		if (pthread_create(th + i, NULL, &routine, &info->philo[i]) != 0)
		{
			printf("Error\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < info->nbphilo)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int ft_mallocstruct(t_info *info) {
	int i;

	i = 0;
	info->philo = malloc(sizeof(*info->philo) * info->nbphilo);
	if (!info->philo)
		return (0);
	while (i < info->nbphilo) {
		info->philo[i].id = i;
		info->philo[i].eat_nb = 0;
		info->philo[i].r_fork = &info->fork[i];
		info->philo[i].l_fork = &info->fork[i - 1];
		if (i == 0)
			info->philo[i].l_fork = &info->fork[info->nbphilo - 1];
		info->philo[i].last_meal = 0;
		info->philo[i].info = info;
		//info->philo[i].th = i;
		i++;
	}
	return (1);
}


int ft_creationmutex(t_info *info)
{
	int	i;

	i = 0;
	info->fork = malloc(sizeof(*info->fork) * info->nbphilo);
	while (i < info->nbphilo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}


