/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:48:28 by pyammoun          #+#    #+#             */
/*   Updated: 2022/09/26 14:48:41 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*int ft_timechecker(t_info *info)
{
	long long	timestart;

	timestart = ft_gettime();
	while ((ft_gettime() - timestart) <
}*/

int ft_eatchecker(t_info *info)
{
	int i;

	i = 0;
	while (i < info->nbphilo)
	{
		if (info->philo[i].eat_nb == info->musteat)
		{
			info->all_eat = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

/*int ft_deathchecker(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbphilo)
	{
		if (in)
	}
}*/
