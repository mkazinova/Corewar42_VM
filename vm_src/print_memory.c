/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:10:15 by msnow-be          #+#    #+#             */
/*   Updated: 2019/03/29 13:43:55 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "op.h"
#include "virt_m.h"
#include <ncurses.h>

void	ft_putnbr_hex(int octet, int rem)
{
	char *base = "0123456789abcdef";
	if (rem > 1)
		ft_putnbr_hex(octet >> 4, rem - 1);
	write(1, base + (octet % 16), 1);
}

void	print_memory(const void *addr, int start, size_t size)
{
	unsigned char const	*ptr = addr;
	size_t i = 0;
	while (i < size)
	{
		ft_putnbr_hex(*(ptr + get_pos(start + i)), 2);
		write(1, " ", 1);
		i++;
	}
}

void	print_dump_memory(const void *addr)
{
	unsigned char const *ptr = addr;
	size_t i = 0;
	while (i < MEM_SIZE)
	{
		size_t a = 0;
		ft_printf("%#06x :", i + a);
		while (a < 32 && a + i < MEM_SIZE)
		{
			ft_putnbr_hex(*(ptr + i + a), 2);
			write(1, " ", 1);
			a++;
		}
		write(1, "\n", 1);
		i += 32;
	}
}
