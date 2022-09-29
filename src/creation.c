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
	int	i;

	i = 0;
	info->start_time = ft_gettime();
	while (i < info->nbphilo)
	{
		if (pthread_create(&info->philo[i].th, NULL,
				&routine, &info->philo[i]) != 0)
			return (0);
		i++;
	}
	ft_deathchecker(info);
	i = 0;
	while (i < info->nbphilo)
	{
		if (pthread_join(info->philo[i].th, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_mallocstruct(t_info *info)
{
	int	i;

	i = 0;
	info->philo = malloc(sizeof(*info->philo) * info->nbphilo);
	if (!info->philo)
		return (0);
	while (i < info->nbphilo)
	{
		info->philo[i].id = i;
		info->philo[i].eat_nb = 0;
		info->philo[i].r_fork = i;
		if (info->nbphilo == 1)
			info->philo[i].l_fork = -1000;
		else if (i == 0)
			info->philo[i].l_fork = info->nbphilo - 1;
		else
			info->philo[i].l_fork = i - 1;
		info->philo[i].last_meal = ft_gettime();
		info->philo[i].info = info;
		i++;
	}
	return (1);
}

int	ft_creationmutex(t_info *info)
{
	int	i;

	i = 0;
	info->fork = malloc(sizeof(*info->fork) * info->nbphilo);
	if (!info->fork)
		return (0);
	while (i < info->nbphilo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&info->writing, NULL) != 0)
		return (0);
	return (1);
}
