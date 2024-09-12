/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:19:22 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/17 14:24:43 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	killing_func(int pid, unsigned char octet)
{
	int				i;
	unsigned char	octet_tmp;

	octet_tmp = octet;
	i = 8;
	while (i-- > 0)
	{
		octet_tmp = octet >> i;
		if (octet_tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(400);
	}
}

int	main(int argc, char **argv)
{
	int		client_id;
	char	*str_to_send;
	int		i;

	if (argc != 3)
	{
		ft_printf("Usage : %s <pid> <string> \n", argv[0]);
		return (0);
	}
	client_id = ft_atoi(argv[1]);
	str_to_send = argv[2];
	i = 0;
	while (str_to_send[i])
	{
		killing_func(client_id, (unsigned char)str_to_send[i]);
		i++;
	}
	killing_func(client_id, (unsigned char) '\0');
	ft_printf("Il s'est ecrit %i caracteres\n", i);
	return (0);
}
