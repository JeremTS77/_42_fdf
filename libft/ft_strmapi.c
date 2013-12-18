/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:19:30 by aaubin            #+#    #+#             */
/*   Updated: 2013/11/21 06:32:39 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Prototype
	char * ft_strmapi(char const *s, char(*f)(unsigned int, char));
Description
	Applique la fonction f à chaque caractère de la chaine de
	caractères passée en paramètre en précisant son index pour
	créer une nouvelle chaine “fraiche” (avec malloc(3)) résultant
	des applications successives de f.
Param.
	#1 La chaine de caractères sur laquelle itérer.
	#2 La fonction à appeler sur chaque caractère de s en précisant son index.
Retour
	La chaine “fraiche” résultant des applications successives de f.
Fonctions
	libc malloc(3)
*/
char *	ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	counter;
	char			*new_str;

	if ( s == NULL )
		return (NULL);
	if ( f == NULL )
		return (ft_strdup(s));
	len = ft_strlen (s);
	new_str = ft_strnew (len);
	counter = 0;
	while ( counter < len )
	{
		new_str[counter] = (*f)(counter, s[counter]);
		counter++;
	}
	return (new_str);
}
