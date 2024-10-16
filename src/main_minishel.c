/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minishel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-fif <luis-fif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:48:28 by luis-fif          #+#    #+#             */
/*   Updated: 2024/10/14 18:31:45 by luis-fif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int	main(void)
{
	//signal(SIGINT, signal_handler);
	//print_ascii();
	print_header();
	while (1)
	{
		prompt();
	}
	return (0);
}