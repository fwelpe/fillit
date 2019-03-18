/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:17:05 by rberon-s          #+#    #+#             */
/*   Updated: 2019/01/27 13:41:33 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define FALSECHECK(e) if(!e) return (0)
# define FREE_N_NULL(p) free(p); p = NULL
# define CH(x) ((*x)[4] == '\n' ? 0 : 1)
# define RETURNULL(t) if (!t) return (NULL)
# define AUTONO(t, r) if (!t) r = 0; RETURNULL(t)
# define AUTOYES(t, r) if (!t) r = 1; RETURNULL(t)

typedef struct	s_tetr
{
	struct s_tetr	*prev;
	struct s_tetr	*next;
	int				x[4];
	int				y[4];
}				t_tetr;

void			goup(t_tetr *t);
int				count(t_tetr *t);
t_tetr			*read_file(char *filename);
int				place(t_tetr *t, int n);
void			makemap(t_tetr *tetr, int n);
t_tetr			*ft_tldel(t_tetr *t1, char **line);
t_tetr			*goup_all(t_tetr *s);
t_tetr			*validate(t_tetr *t);

#endif
