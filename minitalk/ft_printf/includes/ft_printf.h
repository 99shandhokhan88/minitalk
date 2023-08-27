/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:48:04 by vzashev           #+#    #+#             */
/*   Updated: 2023/08/27 19:13:32 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_num(int nb);
int	ft_convert_add(unsigned long nb, char *s);
int	ft_print_point(unsigned long nb, char *s);
int	ft_print_unsign(unsigned int nb);
int	ft_print_hex(unsigned int nb, char *s);
int	ft_print_only(int c);
int	ft_check_type(va_list args, const char str);
int	ft_printf(const char *str, ...);

#endif
