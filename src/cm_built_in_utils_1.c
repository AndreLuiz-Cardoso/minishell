/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_built_in_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <luis-fif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:51:34 by luis-fif          #+#    #+#             */
/*   Updated: 2024/10/15 14:02:46 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int ft_prev_dir(char *dir)  // Alterado para aceitar um único argumento do tipo char *
{
    char *pwd;
    static char prev_dir[1024] = "";

    if (ft_strlen(prev_dir) == 0)
    {
		pwd = getcwd(NULL, 0);
        ft_strncpy(prev_dir, pwd, ft_strlen(pwd) + 1);
		free(pwd);
	}
	if (strcmp(dir, "-") == 0)
    {
		pwd = getcwd(NULL, 0);
        chdir(prev_dir);
		ft_print(prev_dir);
		//printf("%s\n", prev_dir);
		ft_strncpy(prev_dir, pwd, ft_strlen(pwd) + 1);
		free(pwd);
	}
	else
    {
		pwd = getcwd(NULL, 0);
		ft_strncpy(prev_dir, pwd, ft_strlen(pwd) + 1);
		free(pwd); 
        chdir(dir);
    }
    return (0);
}