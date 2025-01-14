/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:30:50 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:21:06 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	s = ptr;
}
/*
int	main(void)
{
	char c[] = "Hello";

	printf("Before: %s\n", c);
	ft_bzero(c, 5);
	printf("After: %s", c);
	return (0);	
}*/
