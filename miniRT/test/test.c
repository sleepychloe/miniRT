#include "./mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_width;
	int		img_height;
	int	*data;
	int	bpp;
	int	line;
	int	endian;

}	t_mlx;
/*
int	main(void)
{	
	char	*relative_path = "./north.xpm";
	int	row;
	int	col;
	int	color;
	int	*result;
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 500, 500, "Hello, world!");  
	mlx.img = mlx_xpm_file_to_image(mlx.mlx, relative_path, &mlx.img_width, &mlx.img_height);
	mlx.data = (int *)mlx_get_data_addr(mlx.mlx, &mlx.bpp, &mlx.line, &mlx.endian);
	result = (int *)malloc(sizeof(int) * (mlx.img_width * mlx.img_height));
	row = -1;
	while (++row < mlx.img_height)
	{
		col = -1;
		while (++col < mlx.img_width)
		{
			result[mlx.img_width * row + col] = mlx.data[mlx.img_width * row + col];
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_destroy_image(mlx.mlx, mlx.img);
	mlx_loop(mlx.mlx);
}
*/

int	*load_image(t_mlx *mlx, char *relative_path)
{
	int	row;
	int	col;
	int	*result;

	if (!(mlx->img = mlx_xpm_file_to_image(mlx->mlx, relative_path, &mlx->img_width, &mlx->img_height)))
		return (0);
	mlx->data = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line, &mlx->endian);
	result = (int *)malloc(sizeof(int) * (mlx->img_width * mlx->img_height));
	row = -1;
	while (++row < mlx->img_height)
	{
		col = -1;
		while (++col < mlx->img_width)
		{
			result[mlx->img_width * row + col] = mlx->data[mlx->img_width * row + col];
		}
	}
	//mlx_destroy_image(mlx->mlx, mlx->img);
	return (result);
}

int	main(void)
{	
	char	*relative_path = "./north.xpm";
	int	*result;
	t_mlx	mlx;
	int	row;
	int	col;
	int	color;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 500, 500, "Hello, world!");
	mlx.img = mlx_new_image(mlx.mlx, 500, 500);
	mlx.data = (int *)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line, &mlx.endian);
	
	result = load_image(&mlx, relative_path);
	row = -1;
	while (++row < mlx.img_height)
	{
		col = -1;
		while (++col < mlx.img_width)
		{
			mlx.data[mlx.img_width * row + col] = result[mlx.img_width * row + col];
			printf("%d\n", mlx.data[mlx.img_width * row + col]);
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
