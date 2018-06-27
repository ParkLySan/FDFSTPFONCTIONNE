/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: litoulza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:48:13 by litoulza          #+#    #+#             */
/*   Updated: 2018/06/27 22:00:57 by litoulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** So this is for the zoom, I basically configure key to incrase my 
** values or to decrease them (z *= 2 is z = z * 2. Then multiply 
** by 0.5 is divising by 2)
*/

void		zoom(int keycode, t_fdf *key)
{
	if (keycode == 69 && key->sx * 2 <= 500 && key->sy * 2 <= 500)
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 2;
		key->sy *= 2;
		key->z *= 2;
		draw(key);
	}
	if (keycode == 78 && key->sx * 0.5 >= 1 && key->sy * 0.5 >= 1 &&
		(-key->z * 0.5 >= 1 || key->z * 0.5 >= 1))
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 0.5;
		key->sy *= 0.5;
		key->z *= 0.5;
		draw(key);
	}
}

/*
** This function make the program quit properly
*/

int			cross(void)
{
	exit(0);
	return (0);
}

/*
** This is for making our maps move upside down, to the rignt and to the left.
*/

void		decal(int keycode, t_fdf *key)
{
	if ((keycode >= 123 && keycode <= 126) || keycode == 15)
	{
		mlx_clear_window(key->mlx, key->win);
		if (keycode == 123)
			key->dx -= 10;
		if (keycode == 126)
			key->dy -= 10;
		if (keycode == 124)
			key->dx += 10;
		if (keycode == 125)
			key->dy += 10;
		if (keycode == 15)
			key->check = 0;
		draw(key);
	}
}

/*
** This is our bonus. When u press esc it make us quit, 
** with the '/' our z is getting bigger it means that our map rises.
** With the '*' it's getting lower. With the C the col
** or is changing from light blue to green. Then I call the
** decal function and the zoom function.
*/

int			keyboard(int keycode, t_fdf *key)
{
	if (keycode == 53)
		cross();
	if (keycode == 67)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z++;
		draw(key);
	}
	if (keycode == 75)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z--;
		draw(key);
	}
	if (keycode == 8)
	{
		mlx_clear_window(key->mlx, key->win);
		if (key->check % 11 == 0)
			key->color = 0xFF000000;
		key->color = key->color >> 2;
		draw(key);
	}
	zoom(keycode, key);
	decal(keycode, key);
	return (0);
}

/*
** This is the mlx function, 
** it will create the window and call the draw function.
*/

void		mlx(t_fdf *key)
{
	key->check = 0;
	key->mlx = mlx_init();
	key->win = mlx_new_window(key->mlx, WIDTH, HEIGHT, "Fdf");
	draw(key);
	mlx_key_hook(key->win, keyboard, key);
	mlx_hook(key->win, 17, (1L << 17), cross, key);
	mlx_loop(key->mlx);
}
