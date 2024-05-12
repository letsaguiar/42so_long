#include "so_long.h"

t_application	*app_init(t_application *app, int width, int height, char *title)
{
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
