#include "ft_printf.h"

void	ft_list_reset(t_list *lst)
{
	lst->space = 0;
	lst->minus = 0;
	lst->zero = 0;
	lst->width = 0;
	lst->dot = 0;
	lst->precision = 0;
	lst->specifier = 0;
	lst->error = 0;
}

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_atoi(const char *str, int start)
{
	int		i;
	int		nbr;

	i = start;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += (str[i] - '0');
		i++;
	}
	return (nbr);
}

int		ft_isspecifier(char c)
{
	int		ch;

	ch = c + 0;
	if (ch == 99 || ch == 115 || ch == 112 || ch == 100)
		return (ch);
	if (ch == 105 || ch == 117 || ch == 120 || ch == 88 || ch == 37)
		return (ch);
	return (0);
}

int		ft_checklist(int i, t_list *lst)
{
	if (lst->error)
	{
		free(lst);
		return (0);
	}
	free(lst);
	return (i + 1);
}
