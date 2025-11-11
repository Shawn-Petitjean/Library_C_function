/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:13:33 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/10 16:47:21 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_noset(char a, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

static int	*ft_strlen_order(char const *s1, char const *set)
{
	int	start;
	int	end;
	int	i;
	int	*res;

	i = 0;
	res = malloc(2 * sizeof (int));
	while (s1[i] != '\0' && ft_noset(s1[i], set) == 1)
		i++;
	start = i;
	i = ft_strlen(s1);
	i -= 1;
	while (s1[i] != '\0' && ft_noset(s1[i], set) == 1)
		i--;
	end = i + 1;
	res[0] = start;
	res[1] = end;
	if (res[0] >= res[1])
		return (NULL);
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	int		*len;
	int		i;
	int		y;

	len = ft_strlen_order(s1, set);
	if (!len)
		return (a = malloc(1));
	a = ft_calloc(((len[1] - len[0] + 1)), sizeof(char));
	printf ("%d\n%d\n", len[1], len[0]);
	if (!a)
		return (NULL);
	i = len[0];
	y = 0;
	while (s1[i] != '\0' && i < len[1])
	{
		a[y] = s1[i];
		y++;
		i++;
	}
	free(len);
	return (a);
}

// int	main()
// {
//     char *test2 = NULL;
// 	test2 = ft_strtrim(" jawdbn dauwbda awbd abdad ", " ");
// 	printf ("%s\n", test2);
//     free(test2);
//     return (0);
// }