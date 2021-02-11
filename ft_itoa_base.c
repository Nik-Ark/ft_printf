#include "ft_printf.h"

char	*ft_itoa_base(unsigned int nbr, const char spec, int base)
{
	char	*num;
	int		len;
	int		nb;

	num = NULL;
	len = 0;
	nb = 0;
	len = ft_len_num(nbr, base);
	if (!(num = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	num[len] = '\0';
	if (nbr == 0)
	{
		num[0] = '0';
		return (num);
	}
	while (nbr != 0)
	{
		len--;
		nb = nbr % base;
		num[len] = ft_convert_num(nb, spec);
		nbr /= base;
	}
	return (num);
}

char	*ft_itoa_base_long(long int nbr, const char spec, int base)
{
	char		*num;
	int			len;
	long int	nb;

	num = NULL;
	len = 0;
	nb = 0;
	len = ft_len_num_long(nbr, base);
	if (!(num = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	num[len] = '\0';
	if (nbr == 0)
	{
		num[0] = '0';
		return (num);
	}
	while (nbr != 0)
	{
		len--;
		nb = nbr % base;
		num[len] = ft_convert_num(nb, spec);
		nbr /= base;
	}
	return (num);
}

int		ft_len_num_long(long int nbr, int base)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int		ft_len_num(unsigned int nbr, int base)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char	ft_convert_num(unsigned int nb, const char spec)
{
	char	*nums_x;
	char	*nums_xx;
	char	*nums_u;

	nums_x = "0123456789abcdef";
	nums_xx = "0123456789ABCDEF";
	nums_u = "0123456789";
	if (spec == 'x')
		return (nums_x[nb]);
	else if (spec == 'X')
		return (nums_xx[nb]);
	else
		return (nums_u[nb]);
}
