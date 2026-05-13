/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esjalabe <esjalabe@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 13:40:34 by esjalabe          #+#    #+#             */
/*   Updated: 2026/05/13 15:56:22 by esjalabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

void	printn(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buf[i] != '\n')
	{
		write(1, &buf[i], 1);
		i += 1;
	}
}

void	print(char *buf)
{
	int	i;

	i = 0;
	printf("\nbuf dans print|%s|\n", buf);
	while (i < BUFFER_SIZE && buf[i] != '\n')
	{
		write(1, &buf[i], 1);
		i += 1;
	}
	printf("\n|buf[i] dans print %c|\n", buf[i]);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	int	i;
	int	j;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	i = 0;
	j = read(fd, buf, BUFFER_SIZE);
	if (buf[i] != '\n')
	{
		while (BUFFER_SIZE == j)
		{
			printf("\nj dans gnl %d\n", j);
			print(buf);
			j = read(fd, buf, BUFFER_SIZE);
		}
	}
	else
	{
		printn(buf);
		return (&buf[i]);
	}
	return (&buf[i]);
}

int	main()
{
	int	fd;

	fd = open("orange.txt", O_RDONLY);
	get_next_line(fd); // orange
	//get_next_line(fd); // pomme
	//get_next_line(fd); // poire 
}
