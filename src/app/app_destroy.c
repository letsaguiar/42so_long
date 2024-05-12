#include "so_long.h"

void	app_destroy(t_application *app)
{
	if (app->win)
	{
		mlx_destroy_window(app->mlx, app->win);
	}
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
	free(app);
}
