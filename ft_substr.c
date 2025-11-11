/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:01:11 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/10 09:50:49 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	y;

	y = start;
	i = 0;
	if ((start - ft_strlen(s)) < len)
		a = malloc (((start - ft_strlen(s)) + 1) * sizeof(char));
	else
		a = malloc ((len + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	while (i < len && s[y] != '\0')
	{
		a[i] = s[y];
		i++;
		y++;
	}
	a[i] = '\0';
	return (a);
}

// int    main(int arc, char **arv)
// {
//     if (arc < 2)
//     {
//         printf("please take tow arguments\n");
//         return (0);
//     }
//     char *test2 = ft_substr(arv[1], atoi(arv[2]), atoi(arv[3]));
//     printf("result me : %s\n", test2);
//     free(test2);
//     return (0);
// }