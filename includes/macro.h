/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 04:49:55 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/16 06:10:16 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

#include "ifmai.h"

typedef enum s_bool
{
	TRUE = 1,
	FALSE = 0
}   t_bool;

t_bool _macro(char *str);
t_bool macrocomp(const char *s1, const char *s2);
t_bool qtorf();
t_bool rtorf();
t_bool nor();
t_bool noq();

#endif