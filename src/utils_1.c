/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <luis-fif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:50:12 by luis-fif          #+#    #+#             */
/*   Updated: 2024/10/16 18:14:50 by luis-fif         ###   ########.fr       */
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

t_head	*creat_head(t_head *head)
{
	head = malloc(sizeof(t_head));
	if (!head)
		return (NULL);
	head->next = NULL;
	return (head);
}

t_token *create_list(t_head *head, t_token *list)
{
	t_token *new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if(!new_token)
		return (NULL);
	new_token->next = NULL;
	new_token->token = NULL;
	if (list == NULL)
		head->next = new_token;
	else
		list->next = new_token;
	return (new_token);
}

void double_quotes(const char *str, int *i, t_token *list)
{
	int j;
	int k;
	
	j = ++(*i);
	while (str[*i] && str[*i] != '\"')
		(*i)++;
	list->token = (char *)malloc(sizeof(char) * ((*i) - j + 1));
	if (!list->token)
		return ;
	k = 0;
	while (j < *i)
	{
		if (str[j] == '$')
			list->double_quotes = true;
		list->token[k++] = str[j++];
	}
	list->token[k] = '\0';
	(*i)++;
}



void simple_quotes(const char *str, int *i, t_token *list) {
    int j;
	int k;

	j = ++(*i);
	while (str[*i] && str[*i] != '\'')
		(*i)++;
    
    list->token = (char *)malloc(sizeof(char) * ((*i) - j + 1));
    if (!list->token)
        return;
    
    k = 0;
    while (j < *i) {
        list->token[k++] = str[j++];
    }
    list->token[k] = '\0';
    (*i)++;
}


void normal_text(const char *str, int *i, t_token *list)
{
	int j;
	int k;

	j = *i;
	while (str[*i] && str[*i] != '\'' && str[*i] != '\"' && str[*i] != ' ')
		(*i)++;
	list->token = (char *)malloc(sizeof(char) * ((*i) - j + 1));
	if (!list->token)
        return;
    k = 0;
    while (j < *i)
        list->token[k++] = str[j++];
    list->token[k] = '\0';
}

void	avance(char *str, int *i)
{
	while ((str[*i] <= 32 || str[*i] >= 127) && str[*i])
		(*i)++;
}

t_head	*ft_tokens(const char *str) 
{
	int i;
	t_token *list;
	t_head *head;

	i = 0;
	list = NULL;
	avance((char *)str, &i);
	//printf("i: %d\n", i);
	if ((head = creat_head(head)) == NULL)
		return (NULL);
	while (str[i])
	{
		if((list = create_list(head, list)) == NULL)
			return (NULL);
		if (str[i] == '\"' && str[i + 1] != '\"')
			double_quotes(str, &i, list);
		//printf("i: %d\n", i);
		else if (str[i] == '\'' && str[i + 1] != '\'')
			simple_quotes(str, &i, list);
		else
			normal_text(str, &i, list);
		//printf("i: %d\n", i);
		i++;
	}
	return (head);
}

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

void test_print(t_head *head)
{
    t_token *current = head->next; // Começa do primeiro token
    while (current != NULL) // Enquanto não voltar ao início
    {
        printf("%s\n", current->token);
        current = current->next;
    }
}


int prompt(void)
{
    char *input;
	t_head *tokens;

	input = readline("minishell>");
	if (input == NULL) // Detectar Ctrl-D
    {
        exit(0);
    }
    if (input && *input)
    {
        add_history(input);
		tokens = ft_tokens(input);
		if (tokens == NULL)
		{
			fprintf(stderr, "Erro ao alocar memória para tokens.\n");
			free(input);
			return (1);
		}
		
		test_print(tokens);

		free(input); 

		// Libera os tokens
		/*t_token *temp;
		while (tokens != NULL) // Enquanto houver tokens
		{
			temp = tokens->next;
			free(tokens);
			tokens = temp;
		}*/
		free(tokens);
	}
    return (0);
}



