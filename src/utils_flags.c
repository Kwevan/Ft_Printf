/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:44:40 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/14 14:35:33 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_parse(char *rest, va_list args, int *len)
{
	int		pos;
	int		f_len;
	char	*s_flags;
	t_flags	flags;
	int		(*functions[9])(va_list, t_flags);

	f_len = 0;
	ft_init_functions(functions);
	while (rest[f_len] && !(ft_index(TYPE_FIELD, rest[f_len]) + 1))
		f_len++;
	if (!(s_flags = ft_strndup(rest, f_len + 1)))
		return (0);
	ft_init_flags(args, &flags, s_flags, ft_index("csp%", rest[f_len]) + 1);
	free(s_flags);
	if ((pos = ft_index(TYPE_FIELD, rest[f_len])) + 1)
	{
		*len += functions[pos](args, flags);
		ft_move(rest, rest + f_len + 1);
	}
	else
		*len += functions[8](args, flags);
	return (0);
}
