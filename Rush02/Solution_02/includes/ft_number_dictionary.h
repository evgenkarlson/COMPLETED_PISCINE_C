/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_dictionary.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:48:05 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/17 10:48:05 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUMBER_DICTIONARY_H
# define FT_NUMBER_DICTIONARY_H

# include "ft_boolean.h"
# include "ft_short_types.h"

# define INVALID -1
# define ENGLISH_DICT "numbers.dict"

typedef struct	s_dict_entry
{
	ULNG	value;
	char	*str;
	t_bool	normal;
}				t_dict_entry;

typedef struct	s_dict
{
	char			*path;
	t_bool			valid;
	int				size;
	t_dict_entry	*entries;
}				t_dict;

typedef enum {
	none,
	generic,
	invalid_number,
	fail_convert,
	dict_parsing
}	t_error;

typedef enum
{
	parsing_ok,
	empty_line,
	failed,
	reached_eof
}	t_parse_error;

t_dict			ft_load_default_dictionary(void);
t_dict			ft_load_dictionary(char *path);
void			ft_free_dictionary(t_dict *dict);

void			ft_read_line(t_dict_entry *entr, int fd, t_parse_error *err);
char			*ft_clean_line(char *str);
t_parse_error	ft_process_line(t_dict_entry *entry, char *line, UINT length);
int				ft_count_valid_line(char *path);
t_bool			ft_load_valid_line(char *path, int size, t_dict *dict);

void			ft_swap_dictionary_entry(t_dict_entry *a, t_dict_entry *b);
void			ft_update_normal_flag(t_dict *dict);
void			ft_do_sort_dict(t_dict *dict, int start, int end,
								int (*func)(t_dict_entry*, t_dict_entry*));
void			ft_sort_dictionary(t_dict *dict);

int				ft_sort_dict_f_normal(t_dict_entry *a, t_dict_entry *b);
int				ft_sort_dict_f_value(t_dict_entry *a, t_dict_entry *b);

#endif
