//
// Created by Paolo Yammouni on 9/26/22.
//
#include "philo.h"

int	main(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	printf("Temps : %ld", time.tv_sec);
	return (0);
}