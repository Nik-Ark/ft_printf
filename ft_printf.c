#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;

	total = 0;
	va_start(args, format);
	total = ft_proceed(format, &args);
	va_end(args);
	return (total);
}
