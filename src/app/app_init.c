#include "so_long.h"
#include "libft.h"

t_application	*app_init(int width, int height, char *title)
{
	t_application	*app;

	app = ft_calloc(1, sizeof (t_application));
	app->mlx = mlx_init();
	if (!app->mlx)
		return (NULL);
	app->win = mlx_new_window(app->mlx, width, height, title);
	if (!app->win)
	{
		app_destroy(app);
		return (NULL);
	}
	app->width = width;
	app->height = height;
	return (app);
}
