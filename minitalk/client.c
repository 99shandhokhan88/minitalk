/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:55:15 by vzashev           #+#    #+#             */
/*   Updated: 2023/08/27 19:14:05 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static long int	ft_atoi(const char *mess)
{
	long int	i;
	long int	sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (((mess[i] >= 9) && (mess[i] <= 13)) || (mess[i] == 32))
		i++;
	if (mess[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (mess[i] == '+')
		i++;
	while ((mess[i] >= '0') && (mess[i] <= '9'))
	{
		result *= 10;
		result += mess[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}

void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit <= 7)
	{
		if ((c & (1 << bit)))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(420);
		bit++;
	}
}

void	ft_mess_len(pid_t pid, char *mess)
{
	int	i;

	i = 0;
	while (mess[i] != '\0')
	{
		ft_atob(pid, mess[i]);
		usleep(420);
		i++;
	}
}

void	copy_that(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf("\33[93mMessage recieved: copy that!\033[0m\n");
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_mess_len(pid, argv[2]);
		signal(SIGUSR2, copy_that);
		ft_atob(pid, '\n');
		ft_atob(pid, '\0');
	}
	else if (argc == 2)
	{
		ft_printf("\33[93mError: not enough arguments.\033[0m\n");
		return (1);
	}
	else
	{
		ft_printf("\33[93mError!\033[0m\n");
		return (1);
	}
	return (0);
}
