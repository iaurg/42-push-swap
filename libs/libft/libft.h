/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:38:35 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/03 06:19:32 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char		*ft_itoa(int n);
int			ft_atoi(const	char *nptr);
long		ft_atol(const	char *nptr);
int			ft_isdigit(int c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// printf
int	ft_printf(const char *type, ...);
int	ft_parse_flag(const char *format, va_list ap);
int	ft_printf_c(int c);
int	ft_printf_s(char *s);
int	ft_printf_p(size_t number);
int	ft_printf_d(int number);
int	ft_printf_i(int number);
int	ft_printf_u(unsigned int number);
int	ft_printf_x(unsigned int number, char flag);
#endif
