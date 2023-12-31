/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramd <abouramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:05:14 by abouramd          #+#    #+#             */
/*   Updated: 2023/08/11 10:05:15 by abouramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_BONUS_H
# define PARS_BONUS_H

# include "cub_bonus.h"

typedef struct s_pars
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*floor;
	int		*ceil;
	char	**map;
	char	**file_content;
	size_t	player_x;
	size_t	player_y;
	char	field_of_view;
}			t_pars;

/* print error in stderr */
void		put_err(const char *str, const char *str2);

/* check file name */
int			check_file_name(const char *str, char *ext, char *err);

/* init the data */
void		set_null(t_pars *f, t_global *d);

/* check path */
int			check_file(t_pars *ptr, const char *str);

/* start read the file */
int			check_content(t_pars *ptr);

/* t_pars free */
void		free_pars(t_pars *pars);

/* check the map */
int			check_map(t_pars *ptr, char **s);

/* fill data */
int			fill_data(t_global *f, t_pars *ptr);

/* destroy image */
void		ft_destroy_image(t_global *f);

/* animation setup */
int			ft_animation_pars(t_global *f);

/* get the path of the xpm file */
int			get_path(char **ptr, char *str, char *s);
size_t		skip_white_space(char *str, size_t index);

#endif // PARS_H
