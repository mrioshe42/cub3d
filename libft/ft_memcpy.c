/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:32:45 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:21:47 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*temp_dst;
	const char	*temp_src;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	temp_dst = (char *)dst;
	temp_src = (const char *)src;
	while (n--)
		temp_dst[n] = temp_src[n];
	return (dst);
}
/*
int	main(void)
{
	char	s[] = "Hello";
	char	d[10];

	printf("Before: %s\n", d);
	ft_memcpy(d, s, sizeof(s));
	printf("After: %s", d);
	return(0);
}*/
