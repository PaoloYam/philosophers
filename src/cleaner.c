/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:26:18 by pyammoun          #+#    #+#             */
/*   Updated: 2022/09/29 18:26:21 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_cleanmutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbphilo)
	{
		pthread_mutex_destroy(&info->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&info->writing);
}

void	ft_free(t_info *info)
{
	free(info->fork);
	free(info->philo);
}

void	ft_cleaning(t_info *info)
{
	ft_cleanmutex(info);
	ft_free(info);
}
