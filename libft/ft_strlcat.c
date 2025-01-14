/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:53:32 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:23:36 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else
	{
		while (src[j] && (dst_len + j) < dstsize)
			dst[i++] = src[j++];
		if ((dst_len + j) == dstsize && dst_len < dstsize)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (src_len + dst_len);
	}
}
/*
int	main(void)
{
	char	s[] = "world";
	char	d[20] = "hello ";
	size_t	n = ft_strlcat(d, s, sizeof(d));
	printf("Copied n: %zu\n", n);
	printf("After: %s", d);
	return (0);
}*/
