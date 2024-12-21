/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:05:55 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/12 16:21:42 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
// #include <stdio.h>
// #include <limits.h>

// #define ANSI_COLOR_RED     "\x1b[31m"
// #define ANSI_COLOR_GREEN   "\x1b[32m"
// #define ANSI_COLOR_RESET   "\x1b[0m"

// int main() {
//     int ft_ret, org_ret;

//     // Test 1: Basic string with %%
//     ft_ret = ft_printf("Hello, World!%%\n");
//     org_ret = printf("Hello, World!%%\n");
// 	printf("ft: %d, org: %d\n", ft_ret, org_ret);
// 	printf("--------------\n");

//     // Test 2: Character
//     ft_ret = ft_printf("Char: %c\n", 'a');
//     org_ret = printf("Char: %c\n", 'a');
// 	printf("ft: %d, org: %d\n", ft_ret, org_ret);
// 	printf("--------------\n");

//     // Test 3: String
//     ft_ret = ft_printf("String: %s\n", "abcde");
//     org_ret = printf("String: %s\n", "abcde");
// 	printf("ft: %d, org: %d\n", ft_ret, org_ret);
// 	printf("--------------\n");

//     // Test 4: Pointer
//     int i;
//     ft_ret = ft_printf("Pointer: %p, %p\n", &i, "");
//     org_ret = printf("Pointer: %p, %p\n", &i, "");
// 	printf("ft: %d, org: %d\n", ft_ret, org_ret);
// 	printf("--------------\n");

//     // Test 5: Integer
//     ft_ret = ft_printf("Int: %d, %i\n", -5, 10);
//     org_ret = printf("Int: %d, %i\n", -5, 10);
// 	printf("ft: %d, org: %d\n", ft_ret, org_ret);
// 	printf("--------------\n");

//     // Test 6: Unsigned integer
//     ft_ret = ft_printf("Unsigned int: %u, %u\n", 1200, -300);
//     org_ret = printf("Unsigned int: %u, %u\n", 1200, -300);
// 	printf("ft: %d, org: %d\n", ft_ret, org_ret);
// 	printf("--------------\n");

//     // Test 7: Lowercase hex
//     ft_ret = ft_printf("Lower hex: %x, %x, %x\n", 42, -17, 0x1f);
//     org_ret = printf("Lower hex: %x, %x, %x\n", 42, -17, 0x1f);
// 	printf("ft: %d, org: %d\n", ft_ret, org_ret);
// 	printf("--------------\n");

//     // Test 8: Uppercase hex
//     ft_ret = ft_printf("Upper hex: %X, %X, %X\n", 42, -17, 0x1f);
//     org_ret = printf("Upper hex: %X, %X, %X\n", 42, -17, 0x1f);
// 	printf("ft: %d, org: %d\n", ft_ret, org_ret);
// 	printf("--------------\n");

//     // Test 9: Control characters
//     ft_ret = ft_printf("\001\002\007\v\010\f\r\n");
//     org_ret = printf("\001\002\007\v\010\f\r\n");
// 	printf("ft: %d, org: %d\n", ft_ret, org_ret);
// 	printf("--------------\n");

//     // Test 10: Mixed formats
//     ft_ret = ft_printf("%c%s%p%d%i%u%x%X\n",
// 						42, "42", NULL, 42, 42, 42, 42, 42);
//     org_ret = printf("%c%s%p%d%i%u%x%X\n",
// 						42, "42", NULL, 42, 42, 42, 42, 42);
// 	printf("ft: %d, org: %d\n", ft_ret, org_ret);
// 	printf("--------------\n");

//     // Test 11: Integer limits
//     ft_ret = ft_printf("%d, %d, %d\n", INT_MAX, INT_MIN, 0);
//     org_ret = printf("%d, %d, %d\n", INT_MAX, INT_MIN, 0);
// 	printf("ft: %d, org: %d\n", ft_ret, org_ret);
// 	printf("--------------\n");

//     // Test 12: Null string
//     ft_ret = ft_printf("%s\n", (char *)NULL);
//     org_ret = printf("%s\n", (char *)NULL);
// 	printf("ft: %d, org: %d\n", ft_ret, org_ret);
// 	printf("--------------\n");

//     return (0);
// }

static int	formats(va_list *ap, const char fmt)
{
	char	*s;

	if (fmt == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (fmt == 's')
	{
		s = va_arg(*ap, char *);
		if (!s)
			s = "(null)";
		return (ft_putstr(s));
	}
	else if (fmt == 'p')
		return (ft_putptr((uintptr_t)va_arg(*ap, void *)));
	else if (fmt == 'd' || fmt == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (fmt == 'u')
		return (ft_putnbr_ui(va_arg(*ap, unsigned int)));
	else if (fmt == 'x')
		return (ft_puthex(va_arg(*ap, int), TRUE));
	else if (fmt == 'X')
		return (ft_puthex(va_arg(*ap, int), FALSE));
	else if (fmt == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	ssize_t	result;
	size_t	len;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			result = formats(&ap, *++fmt);
		else
			result = ft_putchar(*fmt);
		if (result < 0)
			return (result);
		len += result;
		fmt++;
	}
	va_end(ap);
	return (len);
}
