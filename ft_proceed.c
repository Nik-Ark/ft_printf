#include "ft_printf.h"

int		ft_proceed(const char *format, va_list *args)
{
	int		i;
	int		start;
	int		total;

	i = -1;
	start = 0;
	total = 0;
	while (format[++i] && ++total)
		if (format[i] == '%')
		{
			total--;
			write(1, &format[start], (++i - start - 1));
			if (!(start = ft_parse(format, args, i, &total)))
				return (-1);
			i = start - 1;
		}
	if (i > start)
		write(1, &format[start], (i - start));
	return (total);
}

int		ft_parse(const char *format, va_list *args, int i, int *total)
{
	t_list	*lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	ft_list_reset(lst);
	i = ft_fill_flags(lst, format, i);
	while (!(lst->specifier = ft_isspecifier(format[i])))
	{
		if (format[i] >= '0' && format[i] <= '9' && lst->dot == 1)
			lst->precision = ft_atoi(format, i);
		if (format[i] >= '0' && format[i] <= '9' && lst->dot == 0)
			lst->width = ft_atoi(format, i);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
		if ((lst->specifier = ft_isspecifier(format[i])))
			break ;
		lst->dot = format[i] == '.' ? 1 : lst->dot;
		if (format[i] == '*' && lst->dot == 1)
			lst->precision = va_arg(*args, int);
		if (format[i] == '*' && lst->dot == 0)
			lst->width = va_arg(*args, int);
		i++;
	}
	*total += ft_output(args, lst);
	return (ft_checklist(i, lst));
}

int		ft_output(va_list *args, t_list *lst)
{
	int		total;
	char	specifier;

	lst->dot = lst->precision < 0 ? 0 : lst->dot;
	lst->precision = lst->precision < 0 ? 0 : lst->precision;
	lst->minus = lst->width < 0 ? (lst->minus + 1) : lst->minus;
	lst->width = lst->width < 0 ? (lst->width * (-1)) : lst->width;
	if (lst->minus)
	{
		lst->space = 0;
		lst->zero = 0;
	}
	specifier = (char)lst->specifier;
	total = specifier == 'c' ? ft_putchar(args, lst) : 0;
	total = specifier == 's' ? ft_putstr(args, lst) : total;
	total = specifier == 'x' ? ft_put_x(args, lst, 'x') : total;
	total = specifier == 'X' ? ft_put_x(args, lst, 'X') : total;
	total = specifier == 'u' ? ft_put_u(args, lst, 'u') : total;
	total = specifier == 'i' ? ft_put_i(args, lst) : total;
	total = specifier == 'd' ? ft_put_i(args, lst) : total;
	total = specifier == 'p' ? ft_put_p(args, lst) : total;
	total = specifier == '%' ? ft_put_per(lst) : total;
	if (total == -1)
		lst->error = 1;
	return (total);
}

int		ft_putchar(va_list *args, t_list *lst)
{
	char	c;

	lst->width = lst->width > 1 ? lst->width - 1 : 0;
	c = (char)va_arg(*args, int);
	lst->minus ? write(1, &c, 1) : ft_putchars(' ', lst->width);
	lst->minus ? ft_putchars(' ', lst->width) : write(1, &c, 1);
	return (lst->width + 1);
}

int		ft_putstr(va_list *args, t_list *lst)
{
	char	*str;
	int		len;
	int		len_0;

	if (!(str = va_arg(*args, char *)))
		str = "(null)";
	len = ft_strlen(str);
	lst->precision = lst->dot == 0 ? len : lst->precision;
	lst->precision = lst->precision > len ? len : lst->precision;
	len_0 = lst->zero && lst->width > lst->precision ?
	lst->width - lst->precision : 0;
	lst->width = !(len_0) && lst->width > lst->precision ?
	lst->width - lst->precision : 0;
	lst->zero ? ft_putchars('0', len_0) : 0;
	lst->minus ? write(1, str, lst->precision) : ft_putchars(' ', lst->width);
	lst->minus ? ft_putchars(' ', lst->width) : write(1, str, lst->precision);
	return (lst->width + lst->precision + len_0);
}
