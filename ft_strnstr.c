/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:46:37 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/08 11:53:09 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (little == NULL)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		y = 0;
		while (big[i + y] == little[y] && i < len)
		{
			if (little[y] == '\0')
				return ((char *)&big[i]);
			y++;
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <bsd/string.h>
// // int main()
// // {
// // 	printf("le resultat est %s\n", ft_strnstr("hello world", "ll", 5));
// // }
// int    main(int arc, char **arv)
// {
//     if (arc < 2)
//     {
//         printf("please take tow arguments\n");
//         return (0);
//     }
//     printf("result or : %s\n", strnstr(arv[1], arv[2], atoi(arv[3])));
//     printf("result me : %s\n", ft_strnstr(arv[1], arv[2], atoi(arv[3])));
//     return (0);
// }