/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:57:28 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:29:27 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	rtn = (void *)malloc(size * count);
	if (rtn == NULL)
		return (NULL);
	ft_bzero(rtn, count * size);
	return (rtn);
}
/*
int	main(void)
{
	size_t	elem = 5;
	size_t	elem_size = sizeof(int);

	int	*arr = (int *)ft_calloc(elem, elem_size);
	size_t i = 0;

	while(i < elem)
	{
		printf("arr[%zu]: %d\n", i, arr[i]);
		i++;
	}
	free(arr);
	return (0);
}*/
