/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <luis-fif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:50:12 by luis-fif          #+#    #+#             */
/*   Updated: 2024/10/16 10:22:54 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*este ft_strtok aponta para o proximo argumento a cada vez que é chamado*/
/*char	*ft_strtok(char *str, const char *delim)
{
	static char	*next;
	char		*token;

	if (str)
		next = str;
	if (!next)
		return (NULL);
	while (*next && ft_strchr(delim, *next))
		next++;
	if (*next == '\0')
		return (NULL);
	token = next;
	while (*next && !ft_strchr(delim, *next))
		next++;
	if (*next)
		*next++ = '\0';
	return (token);
}*/







/*int	count_words(const char *str)
{
	int i = 0;
	int count = 0;
	int in_word = 0;

	while (str[i])
	{
		while (str[i] == ' ' && str[i] == '\t')
			i++;
		if (str[i] == 34)
		{
			while (str[i] != 34 && str[i])
				i++;
			i++;
			count++;
		}
		if (str[i] > 32 && str[i] < 127)
		{
			while (str[i] != 32)
				i++;
			count++;
		}
		i++;
	}
	printf("words: %d\n", count);
	return (count);
}*/



#include <stdio.h>

/*int count_words(const char *str) {
    int i = 0;
    int count = 0;
    int in_quotes = 0;

    while (str[i]) {
        while (str[i] == ' ' || str[i] == '\t')
            i++;

        if (str[i] == '"' || str[i] == '\'')
		{
            char quote_char = str[i];
            in_quotes = 1;
            i++;
            count++;
            while (str[i] != quote_char && str[i])
                i++;
            if (str[i] == quote_char)
                i++;
            in_quotes = 0;
        } 
		else if (!in_quotes && str[i] != '\0')
		{
            count++;
            while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
                i++;
        }
		else
            i++;
    }
    printf("words: %d\n", count);
    return count;
}*/


int count_words(const char *str) 
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (!str[i] > 32 && ! str[i] < 127)
		i++;
	if (str[i] == 34 || str[i] == 39)
	{

	}
}

#include <stddef.h>

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}



/*char	**ft_strtok(char *str)
{
	int 	i = 0, j = 0, start = 0;
	bool	in_quotes = false;
	int 	word_count = count_words(str); 
	char	**tokens = (char **)malloc(sizeof(char*) * (word_count + 1));

	if (!tokens)
		return NULL;

	while (str[i] && j < word_count)
	{
		while (str[i] && ft_strchr(delim, str[i]) && !in_quotes)
			i++;
		start = i;
		while (str[i] && (!ft_strchr(delim, str[i]) || in_quotes))
		{
			if (str[i] == '\"' || str[i] == '\'')
				in_quotes = !in_quotes;
			i++;
		}
		tokens[j] = (char *)malloc(i - start + 1);
		if (!tokens[j])
			return NULL;
		ft_strncpy(tokens[j], &str[start], i - start);
		tokens[j][i - start] = '\0';
		j++;
	}
	tokens[j] = NULL;
	return (tokens);
}*/




/*Função para liberar a memória alocada para os tokens*/
void	free_tokens(char **tokens)
{
	int i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/*void	test_print(char *token)
{
	for (int i = 1; token != NULL; i++)
	{
		printf("teste_Token %d: %s\n", i, token);
		token = ft_strtok(NULL, " "); // Pegar o próximo token
	}
}*/



int prompt(void)
{
    char *input;
    char **tokens;

    input = readline("minishell>");
    if (input == NULL) // Detectar Ctrl-D
    {
       // ft_print("Ctrl-D detectado, saindo...\n");
        exit(0);
    }
    if (input && *input)
    {
        add_history(input);
		count_words(input);
		free(input); 
		/*tokens = ft_strtok(input);
		// Desalocar input após o uso
		if (tokens == NULL)
		{
			ft_print("Erro ao alocar memória.\n");
			return (1);
		}
		is_builtin_cmd(tokens);*/
		// Desalocar tokens após o uso
	}
    return (0);
}

