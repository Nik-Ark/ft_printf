#include "ft_printf.h"

void	ft_putchars(const char c, int i)
{
	while (i--)
		write(1, &c, 1);
}

int		ft_fill_flags(t_list *lst, const char *f, int i)
{
	while (f[i] == '-' || f[i] == '0' || f[i] == ' ')
	{
		if (f[i] == '-')
			lst->minus = 1;
		if (f[i] == '0')
			lst->zero = 1;
		if (f[i] == ' ')
			lst->space = 1;
		i++;
	}
	return (i);
}

int		ft_minchr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			str = ft_strcpy(&str[i], &str[i + 1]);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
