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

int	*load_image(char *relative_path)
{
	int	row;
	int	col;
	int	*result;
	t_mlx	img;

	if (!(img.img = mlx_xpm_file_to_image(img.mlx, relative_path, &img.img_width, &img.img_height)))
		return (0);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.line, &img.endian);
	result = malloc(sizeof(int) * (img.img_width * img.img_height));
	row = -1;
	while (++row < img.img_height)
	{
		col = -1;
		while (++col < img.img_width)
		{
			result[img.img_width * row + col] = (int)img.data[img.img_width * row + col];
		}
	}
	mlx_destroy_image(img.mlx, img.img);
	return (result);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int	*dst;

	dst = mlx->data + (x * mlx->bpp / 8) + (y * mlx->line);
	*(unsigned int *)dst = color;
}

int	main(void)
{	
	char	*relative_path = "./test.xpm";
	int	*result;
	t_mlx	mlx;
	int	row;
	int	col;
	int	color;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 500, 500, "Hello, world!");
	mlx.img = mlx_new_image(mlx.mlx, 500, 500);
	mlx.data = (int *)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line, &mlx.endian);
	result = load_image(relative_path);
	row = 0;
	col = 0;
	while (row < 500)
	{
		while (col < 500)
		{
			mlx.data[500 * row + col] = result[64 * ((64 * row/500)) + (64 * col/500)];
			printf("%d\n", mlx.data[500 * row + col]);
			col++;
		}
		col = 0;
		row++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	free(result);
	mlx_loop(mlx.mlx);
}
