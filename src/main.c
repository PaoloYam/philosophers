/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <pyammoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:39:23 by pyammoun          #+#    #+#             */
/*   Updated: 2022/09/05 10:18:00 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int ft_starter(t_info *info)
{
	ft_mallocstruct(info);
	//ft_creationmutex(info);
	ft_creationmutex(info);
	ft_creationphilo(info);
	return(0);
}


int	main(int argc, char **argv) {
	t_info info;
	int i;

	i = 0;
	(void) argv;
	if (argc < 5 || argc > 6) {
		printf("Wrong number of arguments");
		return (0);
	}
	info.nbphilo = ft_atoi(argv[1]);
	info.ttd = (long long) ft_atoi(argv[2]);
	info.tte = (long long) ft_atoi(argv[3]);
	info.tts = (long long) ft_atoi(argv[4]);
	info.musteat = 0;
	if (argv[5])
		info.musteat = ft_atoi(argv[5]);
	if (info.nbphilo < 1 || info.ttd < 1 || info.tte < 1 || info.tts < 1)
		return (0);
	info.dead = 0;
	info.all_eat = 0;
	ft_starter(&info);
	return (0);
}