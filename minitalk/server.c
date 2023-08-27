/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:55:24 by vzashev           #+#    #+#             */
/*   Updated: 2023/08/27 19:14:16 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	if (sig == SIGUSR1)
	{
		i |= (0x01 << bit);
	}
	bit++;
	if (bit == 8)
	{
		if (i == 0)
		{
			kill(info->si_pid, SIGUSR2);
		}
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig_handler;

	pid = 0;
	(void)argv[0];
	if (argc != 1)
	{
		ft_printf("\n\33[93mError!\033[0m\n");
		return (1);
	}
	pid = getpid();
	ft_printf("\33[92mPID: \33[95m%d\033[0m\n", pid);
	sig_handler.sa_sigaction = &ft_btoa;
	sig_handler.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_handler.sa_mask);
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sig_handler, NULL);
		sigaction(SIGUSR2, &sig_handler, NULL);
		pause();
	}
	return (0);
}
