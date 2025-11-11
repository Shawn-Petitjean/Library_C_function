/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:15:38 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/10 16:53:14 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t n, size_t l)
{
	char	*a;
	size_t	i;

	i = 0;
	if ((n * l) > 2147483647 || (!n || !l))
		return (NULL);
	a = malloc(n * l);
	if (!a)
		return (NULL);
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
	return ((void *) a);
}

// int main()
// {
// 	printf("%s\n", (char *)ft_calloc(4, 4));
// }