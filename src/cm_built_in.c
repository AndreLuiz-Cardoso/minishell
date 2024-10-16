/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <luis-fif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:41:24 by luis-fif          #+#    #+#             */
/*   Updated: 2024/10/16 15:36:09 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin_cmd(char **tokens)
{
	if (ft_strcmp(tokens[0], "pwd") == 0)
		builtin_pwd(tokens);
	else if (ft_strcmp(tokens[0], "cd") == 0)
		builtin_cd(tokens); // Certifique-se de passar o argumento corretamente
	else if (ft_strcmp(tokens[0], "echo") == 0)
		ft_echo(tokens);
	else
		printf("zsh: command not found: %s\n", tokens[0]);
	return (0);
}



int ft_echo(char **args)
{
    int i = 1;
    int newline = 1;

    // Verificar por flag '-n'
    if (args[1] && ft_strcmp(args[1], "-n") == 0)
    {
        newline = 0;
        i = 2; // Pular o argumento '-n'
    }

    while (args[i] != NULL)
    {
        printf("%s", args[i]);
        if (args[i + 1] != NULL)
            printf(" ");
        i++;
    }
    
    if (newline)
        printf("\n");
    
    return (0);
}


/*void builtin_exit(char *status)s
{
	int exit_status;
	
	if(status != NULL)
		exit_status = ft_atoi(status);
	else
		exit_status = 0;
	exit(exit_status);
}*/


void	builtin_ls(void)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(".");
	if (dir == NULL)
	{
		perror("opendir");
		return ;
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
			printf("%s  ", entry->d_name);
	}
	if (closedir(dir) != 0)
		perror("closedir");
}






void builtin_cd(char **tokens)
{
	
	if (tokens[1] == NULL)
	{
        // Sem argumentos, talvez queira ir para o diretório HOME
        char *home = getenv("HOME");
        if (home)
            chdir(home);
        else
            perror("cd");
    } 
	else if (tokens[2] != NULL)
        ft_print("cd: too many arguments\n");
	else
	{
		if (ft_prev_dir(tokens[1]) != 0)
			perror("cd");
    
    }

    // Supondo que tokens foi alocado dinamicamente, libere aqui
  ////  free_tokens(tokens);
}

int builtin_pwd(char **tokens)
{
    char *pwd;

    if (tokens[1])
    {
        //printf("pwd: too many arguments\n");
		ft_print("pwd : too many arguments\n");
	////	free_tokens(tokens);
		return (-1);
    }
    pwd = getcwd(NULL, 0);
    if (pwd != NULL)
    {
		//ft_print("%s\n", pwd);
		ft_print(pwd);
		ft_print("\n");
		free(pwd);
	}
	else
	{
		 perror("pwd");
	}
 ////   free_tokens(tokens);
	return (0);
}

/*void	builtin_exit(int status)
{
	exit(status);
}*/