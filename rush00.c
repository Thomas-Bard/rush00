/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbard <tbard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:15:38 by lufontai          #+#    #+#             */
/*   Updated: 2024/08/10 15:58:49 by tbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PAL_00 0
#define PAL_01 1
#define PAL_02 2
#define PAL_03 3
#define PAL_04 4
#define INIT_OK 1
#define INIT_INVALID_PTR -1
#define INIT_INVALID_ARGS -2
#define PAL_IDX_CORNER_TL 0
#define PAL_IDX_CORNER_TR 1
#define PAL_IDX_CORNER_BL 2
#define PAL_IDX_CORNER_BR 3
#define PAL_IDX_SIDE_TOP 4
#define PAL_IDX_SIDE_RIGHT 5
#define PAL_IDX_SIDE_BOTTOM 6
#define PAL_IDX_SIDE_LEFT 7
#define PAL_IDX_FILL 8

struct		s_rect
{
	int		x;
	int		y;
	char	palette[9];
};

void		ft_putchar(char c);

int	ft_load_palette(char pal[9], int n_palette)
{
	char	fill;

	if (!pal)
		return (INIT_INVALID_PTR);
	fill = pal[PAL_IDX_FILL];
	if (n_palette == PAL_00)
		pal = "oooo-|-|";
	if (n_palette == PAL_01)
		pal = "/\\\\/****";
	if (n_palette == PAL_02)
		pal = "AACCBBBB";
	if (n_palette == PAL_03)
		pal = "ACACBBBB";
	if (n_palette == PAL_04)
		pal = "ACCABBBB";
	else
		return (INIT_INVALID_ARGS);
	pal[PAL_IDX_FILL] = fill;
	return (INIT_OK);
}

void	ft_putchar_repeat(char c, int n)
{
	while (n-- > 0)
		ft_putchar(c);
}

void	rush(int x, int y)
{
	if (x > 0)
		ft_putchar('o');
	ft_putchar_repeat('-', x - 2);
	if (x > 1)
		ft_putchar('o');
	while (y > 2)
	{
		ft_putchar('|');
		ft_putchar_repeat(' ', x - 2);
		ft_putchar('|');
		y--;
	}
	if (x > 0 && y > 1)
		ft_putchar('o');
	ft_putchar_repeat('-', x - 2);
	if (x > 1 && y > 1)
		ft_putchar('o');
}

void	rush_bis(struct s_rect *rect)
{
	if (!rect)
		return ;
	if (rect->x > 0)
		ft_putchar(rect->palette[PAL_IDX_CORNER_TL]);
	ft_putchar_repeat('-', rect->x - 2);
	if (rect->x > 1)
		ft_putchar(rect->palette[PAL_IDX_CORNER_TR]);
	while (rect->y > 2)
	{
		ft_putchar(rect->palette[PAL_IDX_SIDE_LEFT]);
		ft_putchar_repeat(rect->palette[PAL_IDX_FILL], rect->x - 2);
		ft_putchar(rect->palette[PAL_IDX_SIDE_RIGHT]);
		rect->y--;
	}
	if (rect->x > 0 && rect->y > 1)
		ft_putchar(rect->palette[PAL_IDX_CORNER_BL]);
	ft_putchar_repeat(rect->palette[PAL_IDX_SIDE_BOTTOM], rect->x - 2);
	if (rect->x > 1 && rect->y > 1)
		ft_putchar(rect->palette[PAL_IDX_CORNER_BR]);
}
