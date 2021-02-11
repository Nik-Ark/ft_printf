#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_list
{
	int		space;
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		specifier;
	int		error;
}					t_list;

int					ft_printf(const char *format, ...);
int					ft_proceed(const char *format, va_list *args);
void				ft_list_reset(t_list *lst);
int					ft_strchr(char *str, int c);
int					ft_strlen(const char *str);
int					ft_parse(const char *format, va_list *args,
					int i, int *total);
int					ft_output(va_list *args, t_list *lst);
int					ft_putchar(va_list *args, t_list *lst);
int					ft_atoi(const char *str, int start);
int					ft_putstr(va_list *args, t_list *lst);
int					ft_isspecifier(const char c);
int					ft_put_x(va_list *args, t_list *lst, const char spec);
char				*ft_itoa_base(unsigned int nbr, const char spec, int base);
int					ft_len_num(unsigned int nbr, int base);
char				ft_convert_num(unsigned int nb, const char spec);
void				ft_putchars(const char c, int i);
int					ft_put_u(va_list *args, t_list *lst, const char spec);
int					ft_put_i(va_list *args, t_list *lst);
char				*ft_itoa(int n);
int					ft_put_p(va_list *args, t_list *lst);
char				*ft_itoa_base_long(long int nbr, const char spec, int base);
int					ft_len_num_long(long int nbr, int base);
int					ft_fill_flags(t_list *lst, const char *f, int i);
int					ft_minchr(char *str);
char				*ft_strcpy(char *dst, char *src);
int					ft_put_per(t_list *lst);
int					ft_checklist(int i, t_list *lst);

#endif
