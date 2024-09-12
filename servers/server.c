/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:49:06 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/17 14:19:57 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*ft_strjoin_char(char const *s1, char c)
{
	char	*new_str;
	int		i;

	if (!s1)
		return (0);
	new_str = (char *)malloc(ft_strlen(s1) + 2);
	if (new_str == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = c;
	i++;
	new_str[i] = '\0';
	return (new_str);
}

void	ft_join(char **print, char c)
{
	*print = ft_strjoin_char(*print, c);
	if (c == '\0')
	{
		ft_printf("%s\n", *print);
		free(*print);
		*print = ft_strdup("");
	}
}

void	action(int sigsent)
{
	static unsigned char	buff;
	static char				*print;
	static int				i;

	if (print == NULL)
		print = ft_strdup("");
	buff |= (sigsent == SIGUSR1) << (7 - i);
	i++;
	if (i == 8)
	{
		ft_join(&print, buff);
		i = 0;
		buff = 0;
	}
}

int	main(void)
{
	ft_printf("L'ID client est %i\n", getpid());
	signal(SIGUSR2, action);
	signal(SIGUSR1, action);
	while (1)
		pause();
	return (0);
}
