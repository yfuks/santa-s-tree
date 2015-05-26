/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   santa.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 14:38:35 by yfuks             #+#    #+#             */
/*   Updated: 2015/05/26 15:14:23 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SANTA_H
# define SANTA_H

# include <stdio.h>
# include <libft.h>
# include <sys/ioctl.h>
# include <libft.h>
# include <term.h>
# include <termios.h>
# include <curses.h>
# include <stdlib.h>

# define CLEAR_TERM	"\033[?1049h\033[H"
# define REPUT_TERM	"\033[?1049l"

# define KEY_ARROW		27
# define KEY_ESC		27
# define KEY_NEWLINE	10
# define KEY_SPACE		32

typedef struct		s_env
{
	struct termios	term;
	struct winsize	win_size;
	char			buffer[3];
	int				width;
	int				height;
}					t_env;

int					get_term(t_env *e);
int					set_term_cano(t_env *e);
int					reset_term(t_env *e);
int					key_hook(t_env *e);
int					keyhook(char buffer[3]);
int					get_size(t_env *e);
void				draw_tree(t_env *e);
void				put_string(char *str, int x, int y);
void				put_cursor(int x, int y);

#endif
