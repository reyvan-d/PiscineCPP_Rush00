/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 06:43:14 by reyvan-d          #+#    #+#             */
/*   Updated: 2017/05/27 06:45:19 by reyvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETRO_H
#define RETRO_H

#include <curses.h>

int WIN_KEY_PRESSED;
int WIN_WIDTH = 90;
int WIN_HEIGHT = 30;
int WIN_CURSX = WIN_WIDTH / 2;
int WIN_CURSY = WIN_HEIGHT / 2;
int WIN_STARTX = 0;
int WIN_STARTY = 0;
WINDOW *GAME_WIN;

#endif
