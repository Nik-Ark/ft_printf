#include "ft_printf.h"

int		ft_put_x(va_list *args, t_list *lst, const char spec)
{
	char	*num;
	int		len_num;
	int		len_0;

	if (!(num = ft_itoa_base((unsigned int)va_arg(*args, int), spec, 16)))
		return (-1);
	if (num[0] == '0' && lst->dot && lst->precision == 0)
		num[0] = '\0';
	len_num = ft_strlen(num);
	lst->zero = lst->zero && lst->width > len_num ? lst->width - len_num : 0;
	len_0 = lst->dot && lst->precision <= len_num ?
	0 : lst->precision - len_num;
	len_0 = lst->dot ? len_0 : lst->zero;
	lst->width = lst->width - (len_0 + len_num) > 0
	? lst->width - (len_0 + len_num) : 0;
	lst->minus ? ft_putchars('0', len_0) : ft_putchars(' ', lst->width);
	lst->minus ? write(1, num, len_num) : ft_putchars('0', len_0);
	lst->minus ? ft_putchars(' ', lst->width) : write(1, num, len_num);
	free(num);
	return (lst->width + len_0 + len_num);
}

int		ft_put_u(va_list *args, t_list *lst, const char spec)
{
	char	*num;
	int		len_num;
	int		len_0;

	if (!(num = ft_itoa_base((unsigned int)va_arg(*args, int), spec, 10)))
		return (-1);
	if (num[0] == '0' && lst->dot && lst->precision == 0)
		num[0] = '\0';
	len_num = ft_strlen(num);
	lst->zero = lst->zero && lst->width > len_num ? lst->width - len_num : 0;
	len_0 = lst->dot && lst->precision <= len_num ?
	0 : lst->precision - len_num;
	len_0 = lst->dot ? len_0 : lst->zero;
	lst->width = lst->width - (len_0 + len_num) > 0 ?
	lst->width - (len_0 + len_num) : 0;
	lst->minus ? ft_putchars('0', len_0) : ft_putchars(' ', lst->width);
	lst->minus ? write(1, num, len_num) : ft_putchars('0', len_0);
	lst->minus ? ft_putchars(' ', lst->width) : write(1, num, len_num);
	free(num);
	return (lst->width + len_0 + len_num);
}

int		ft_put_i(va_list *args, t_list *lst)
{
	char	*num;
	int		len_num;
	int		len_0;
	int		min;

	if (!(num = ft_itoa(va_arg(*args, int))))
		return (-1);
	if (num[0] == '0' && lst->dot && lst->precision == 0)
		num[0] = '\0';
	len_num = ft_strlen(num);
	min = ft_minchr(num);
	lst->zero = lst->zero && lst->width > len_num ? lst->width - len_num : 0;
	len_0 = lst->dot && lst->precision <= len_num - min ?
	0 : lst->precision - (len_num - min);
	len_0 = lst->dot ? len_0 : lst->zero;
	lst->width = lst->width - (len_0 + len_num) > 0 ?
	lst->width - (len_0 + len_num) : 0;
	lst->minus ? write(1, "-", min) : ft_putchars(' ', lst->width);
	lst->minus ? ft_putchars('0', len_0) : write(1, "-", min);
	lst->minus ? write(1, num, len_num - min) : ft_putchars('0', len_0);
	lst->minus ? ft_putchars(' ', lst->width) : write(1, num, len_num - min);
	free(num);
	return (lst->width + len_0 + len_num);
}

int		ft_put_p(va_list *args, t_list *lst)
{
	char	*num;
	int		len_num;
	int		len_0;

	if (!(num = ft_itoa_base_long(va_arg(*args, long int), 'x', 16)))
		return (-1);
	len_num = lst->dot && !(lst->precision) ? 0 : ft_strlen(num);
	len_0 = lst->precision > len_num ? lst->precision - len_num : 0;
	lst->width = lst->width > (len_num + 2) ? lst->width - (len_num + 2) : 0;
	lst->width = lst->width < len_0 ? 0 : lst->width - len_0;
	lst->minus ? write(1, "0x", 2) : ft_putchars(' ', lst->width);
	lst->minus ? ft_putchars('0', len_0) : write(1, "0x", 2);
	lst->minus ? write(1, num, len_num) : ft_putchars('0', len_0);
	lst->minus ? ft_putchars(' ', lst->width) : write(1, num, len_num);
	free(num);
	return (len_0 + lst->width + len_num + 2);
}

int		ft_put_per(t_list *lst)
{
	int		len_0;

	len_0 = lst->zero ? lst->width - 1 : 0;
	lst->width = lst->width > 1 ? lst->width - 1 : 0;
	lst->width = len_0 ? 0 : lst->width;
	lst->minus ? write(1, "%", 1) : ft_putchars('0', len_0);
	lst->minus ? ft_putchars(' ', lst->width) : ft_putchars(' ', lst->width);
	lst->minus ? 0 : write(1, "%", 1);
	return (len_0 + lst->width + 1);
}
