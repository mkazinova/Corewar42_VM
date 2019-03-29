/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virt_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:42:30 by msnow-be          #+#    #+#             */
/*   Updated: 2019/03/29 13:46:25 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "virt_m.h"
#include <locale.h>

/*
** Checks if final player numbers are adequate
*/

_Bool			bad_player_numbers(t_list *champs)
{
	int max = lst_len(champs);
	while (champs)
	{
		t_champ *ch = (t_champ *)champs->content;
		if (ch->player_num > max || ch->player_num < 1 ||
			ch->player_num > MAX_PLAYERS)
		{
			ft_putendl("Error: bad player numbers!");
			return (1);
		}
		champs = champs->next;
	}
	return (0);
}

t_list			*get_champs(int argc, char **argv, int *i)
{
	t_list *champions = NULL;
	while (*i < argc)
	{
		if (!(get_next_champion(argv, i, &champions)))
		{
			clear_champions(&champions);
			return (NULL);
		}
		*i += 1;
	}
	return (champions);
}

void			show_usage_and_exit(void)
{
	ft_putstr("Usage: ./corewar [-dump N] [-show flags]");
	ft_putendl("[-a] [-n N] <champion1.cor> <...>");
	ft_putendl("\t-a\t\t: Prints output from \"aff\" (Default is to hide it)");
	ft_putendl("\t-d N\t\t: Dumps memory after N cycles then exits");
	ft_putendl("\t-show flags\t: Can be used together to enable several");
	ft_putendl("\t\t\t\t- c : Show cycles");
	ft_putendl("\t\t\t\t- d : Show death");
	ft_putendl("\t\t\t\t- l : Show lives");
	ft_putendl("\t\t\t\t- o : Show operations");
	ft_putendl("\t\t\t\t- v : Show NCurses Visualization");
	exit(0);
}

int				main(int argc, char **argv)
{
	setlocale(LC_CTYPE, "C-UTF-8");
	int i = 1;
	t_debug_mode *debug;
	if (argc == 1 || !(debug = get_debug_mode(argv, &i)))
		show_usage_and_exit();

	t_list *champs;
	if (!(champs = get_champs(argc, argv, &i)) || bad_player_numbers(champs))
	{
		clean_all(0, &champs, &debug);
		return (0);
	}
	t_war war = initialize_corewar(champs);
	if (!(war.cars = initialize_cars(champs, &war)))
	{
		clean_all(0, &champs, &debug);
		return (0);
	}
	corewar(&war, champs, debug);
	clean_all(&war, &champs, &debug);
	return (0);
}
