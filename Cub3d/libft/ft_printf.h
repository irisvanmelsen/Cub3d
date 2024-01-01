/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:01:47 by ivan-mel          #+#    #+#             */
/*   Updated: 2022/11/09 15:11:15 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	putnbr(int nb);
int	putun(unsigned int nb);
int	printchar(char c);
int	printstr(char *str);
int	printhexalow(unsigned long nb, char const *str);
int	printhexaup(unsigned long nb, char const *str);

#endif