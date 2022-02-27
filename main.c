/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceduard2 <ceduard2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:16:39 by ceduard2          #+#    #+#             */
/*   Updated: 2022/02/26 20:29:35 by ceduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

typedef struct s_data
{
	void	*img_ptr;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*addr;

	addr = data->addr + (y * data->line_length + x * (data->bbp / 8));
	*(unsigned int *)addr = color;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "new window");
	img.img_ptr = mlx_new_image(mlx_ptr, 300, 300);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bbp, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 150, 150, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return(0);
}
