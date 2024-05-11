#include "so_long.h"
#include "libft.h"
#include <mlx.h>

static void	render_background(t_game *game, t_image *buffer)
{
	image_insert(buffer, game->background, 0, 0);
}

static void	render_tiles(t_game *game, t_image *buffer)
{
	for (int x = 0; x < map_get_width(game->map); x++)
		for (int y = 0; y < map_get_height(game->map); y++)
			if (map_get_position(game->map, x, y)->value == '1')
				image_insert(buffer, game->tile, x * 48, y * 48);
}

int	event_frame_render(t_game *game)
{
	t_image	*back_buffer;

	back_buffer = image_init(
		game,
		map_get_width(game->map) * 48,
		map_get_height(game->map) * 48
	);
	if (!back_buffer)
	{
		game_destroy(game);
		ft_printf("Error: Minilibx Error");
		exit(MLX_ERROR);
	}

	render_background(game, back_buffer);
	render_tiles(game, back_buffer);

	mlx_put_image_to_window(game->mlx, game->win, back_buffer->img, 0, 0);
	image_destroy(game, back_buffer);
	return (0);
}
