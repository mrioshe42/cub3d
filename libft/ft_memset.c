/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:25:21 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:20:29 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t			i;
	unsigned char	*block;

	i = 0;
	block = (unsigned char *)ptr;
	while (i < len)
	{
		block[i] = value;
		i++;
	}
	ptr = block;
	return (ptr);
}
/*

int	main(void)
{
	char str[] = "hello";
	
	printf("Before: %s\n", str);
	ft_memset(str, '*', 5);
	printf("After: %s", str);
	return (0);
}*/
