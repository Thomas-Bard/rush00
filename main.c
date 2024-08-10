/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarollan <sarollan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 09:26:19 by lufontai          #+#    #+#             */
/*   Updated: 2024/08/10 12:12:04 by sarollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	nbr;
	int	i;

	sign = 1;
	i = 0;
	nbr = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
			i++;
		}
		if (str[i] == '+')
			i++;
	}
	while (str[i] && is_numeric(str[i]))
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	nbr *= sign;
	return (nbr);
}

int	main(int argc, char **argv)
{
	rush(1, 1);
}
