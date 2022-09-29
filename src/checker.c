/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:48:28 by pyammoun          #+#    #+#             */
/*   Updated: 2022/09/29 16:43:48 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*int ft_timechecker(t_info *info)
{
	long long	timestart;

	timestart = ft_gettime();
	while ((ft_gettime() - timestart) <
}*/

int	ft_eatchecker(t_info *info)
{
	int	i;

	i = 0;
	if (info->musteat == -1)
		return (0);
	while (i < info->nbphilo)
	{
		if (info->philo[i].eat_nb < info->musteat)
			return (0);
		i++;
	}
	info->all_eat = 1;
	return (1);
}

int	ft_deathchecker(t_info *info)
{
	int		i;
	t_philo	p;

	i = 0;
	while (!info->all_eat && !info->dead)
	{
		i = -1;
		while (++i < info->nbphilo)
		{
			p = info->philo[i];
			if (ft_gettime() - p.last_meal > info->ttd)
			{
				info->dead = 1;
				ft_print_action(&p, 5);
				return (1);
			}
		}
	}
	return (0);
}
