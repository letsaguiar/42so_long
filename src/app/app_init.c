#include "so_long.h"
#include "libft.h"

t_app	*app_init(int width, int height, char *title)
{
	t_app	*app;

	app = ft_calloc(1, sizeof (t_app));
	if (!app)
		return (NULL);
	app->mlx = mlx_init();
	if (!app->mlx)
	{
		app_destroy(app);
		return (NULL);
	}
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
