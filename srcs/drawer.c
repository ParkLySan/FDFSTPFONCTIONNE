/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: litoulza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:46:55 by litoulza          #+#    #+#             */
/*   Updated: 2018/06/27 20:59:26 by litoulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** First function to draw the pixels of the lines one by one.
** It will just draw one line, so it will be called later on an other function.
*/

void	draw_line(t_fdf *draw, int *tabxy, int x, int y)
{
	int		tabx[2];
	int		taby[2];
	int		e[2];
	int		x0;
	int		y0;

	x0 = tabxy[0];
	y0 = tabxy[1];
	tabx[0] = abs(x - x0);
	tabx[1] = x0 < x ? 1 : -1;
	taby[0] = abs(y - y0);
	taby[1] = y0 < y ? 1 : -1;
	e[0] = (tabx[0] > taby[0] ? tabx[0] : -taby[0]) / 2;
	while (x0 != x || y0 != y)
	{
		mlx_pixel_put(draw->mlx, draw->win, x0, y0, draw->color);
		e[1] = e[0];
		e[1] > -tabx[0] ? e[0] -= taby[0] : 1 == 1;
		e[1] > -tabx[0] ? x0 += tabx[1] : 1 == 1;
		e[1] < taby[0] ? e[0] += tabx[0] : 1 == 1;
		e[1] < taby[0] ? y0 += taby[1] : 1 == 1;
	}
}

/*
** Here I'm going to check if my line is correct, I add some colors, width and height size to have something nice.
*/

void	check_draw(t_fdf *draw)
{
	if (draw->check == 0)
	{
		draw->z = -5;
		draw->dx = WIDTH * 0.4;
		draw->dy = 20;
		draw->sx = (WIDTH * 0.7) / (draw->chars - 1);
		draw->sy = (HEIGHT * 0.5) / (draw->lines - 1);
		draw->color = 0x00FFFFFF;
	}
	draw->check++;
}

/*
** Now I'll draw all the lines using the first function. I use a double tab with absciss and ordinate (x and y) to have a 2 dimension map 
** who looks like a 3 dimension map ! I just need to call that function.
*/

void	draw_lines(t_fdf *draw, int x, int y)
{
	int		tabxy[2];

	tabxy[0] = draw->dx + (x - y);
	tabxy[1] = draw->dy + draw->map[y / draw->sy][x / draw->sx] * draw->z
		+ x + y;
	if (x / draw->sx < draw->chars - 1 && y / draw->sy < draw->lines)
	{
		draw_line(draw, tabxy, draw->dx + ((x + draw->sx) - y),
		draw->dy + draw->map[y / draw->sy][x / draw->sx + 1] * draw->z +
		(x + draw->sx) + y);
	}
	if (y / draw->sy < draw->lines - 1 && x / draw->sx < draw->chars)
	{
		draw_line(draw, tabxy, draw->dx + (x - (y + draw->sy)),
		draw->dy + draw->map[y / draw->sy + 1][x / draw->sx] * draw->z +
		x + (y + draw->sy));
	}
}

/*
**	Now I'll call my functions in one final function. Then I'll just have to call draw to write my map.
*/

void	draw(t_fdf *draw)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	check_draw(draw);
	while (x / draw->sx < draw->chars || y / draw->sy < draw->lines - 1)
	{
		if (x / draw->sx == draw->chars)
		{
			x = 0;
			y += draw->sy;
		}
		draw_lines(draw, x, y);
		x += draw->sx;
	}
}
