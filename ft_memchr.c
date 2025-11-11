/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:04:34 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/08 11:54:49 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *) s;
	while (i < n && temp)
	{
		if (temp[i] == c)
			return ((void *)&temp[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <stdlib.h>
// int    main(int arc, char **arv)
// {
//     if (arc < 2)
//     {
//         printf("please take two arguments\n");
//         return (0);
//     }
//     printf("result or : %s\nmy result : %s\n",    
// (char*)memchr(arv[1], arv[2][0], atoi(arv[3])), 
// (char*)ft_memchr(arv[1], arv[2][0], atoi(arv[3])));
//     return (0);
// }