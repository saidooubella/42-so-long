/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:49:24 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 15:23:34 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>

# include "get_next_line.h"

# define IDLE		0
# define RUNNING	1
# define DEAD		2

# define HORIZONTAL	0
# define VERTICAL	1

# define FIRE_SLOW_DOWN 15

typedef struct s_sprite
{
	void	**normal;
	void	**reverse;
	size_t	count;
}	t_sprite;

typedef struct s_animatable
{
	void	**frames;
	size_t	index;
	size_t	count;
}	t_animatable;

typedef struct s_fire_state
{
	int		orientation;
	int		backward;
	size_t	x;
	size_t	y;
}	t_fire_state;

typedef struct s_map
{
	t_fire_state	*fire_states;
	size_t			fire_count;
	size_t			keys_count;
	size_t			player_x;
	size_t			player_y;
	size_t			height;
	size_t			width;
	char			**map;
}	t_map;

typedef struct s_game
{
	t_animatable	*door;
	t_animatable	*fire;
	t_sprite		*dead;
	t_sprite		*idle;
	t_sprite		*run;
	size_t			index;
	int				player_state;
	int				forward;
	t_map			*map;
	size_t			collected_keys;
	size_t			moves_count;
	size_t			window_height;
	size_t			window_width;
	size_t			taile_height;
	size_t			taile_width;
	size_t			fire_index;
	size_t			loop_index;
	void			*window;
	void			*grass;
	void			*wall;
	void			*key;
	void			*mlx;
}	t_game;

typedef struct s_parsing_state
{
	t_state_holder	file_state;
	size_t			map_width;
	size_t			map_height;
	size_t			line_number;
	size_t			fire_count;
	size_t			keys_count;
	size_t			player_x;
	size_t			player_y;
	size_t			line_width;
	size_t			state_index;
	size_t			index;
	char			*filename;
	char			*line;
	int				prev_is_wall;
	int				has_player;
	int				has_exit;
	int				fd;
}	t_parsing_state;

void		update_fire_satate(t_fire_state *state, char cell);
void		*current_sprite_frame(t_game *game, t_sprite *sprite);
void		render_cell(t_game *game, char cell, size_t x, size_t y);
void		render_player(t_game *game, t_sprite *sprite);
int			map_in_range(t_map *map, size_t x, size_t y);
void		free_map(t_map *map);
void		free_sprite(t_sprite *sprite, void *mlx);
void		free_animatable(t_animatable *animatable, void *mlx);
void		game_end(t_game *game);
int			map_in_range(t_map *map, size_t x, size_t y);
void		parsing_part_six(t_parsing_state *state);
void		init_fire_state(t_fire_state *fire_state, size_t index, int col);
void		proccess_line(t_parsing_state *state, t_map *map);
void		map_parsing(t_parsing_state *state, int argc, char *filename);
t_map		*map_validation_and_generation(t_parsing_state *state);
t_sprite	*current_sprite(t_game *game);
void		parsing_part_one(t_parsing_state *state);
void		parsing_part_two(t_parsing_state *state);
void		parsing_part_three(t_parsing_state *state);
void		parsing_part_four(t_parsing_state *state);
void		parsing_part_five(t_parsing_state *state);
void		write_moves_on_screen(t_game *game);
void		update_elements_frames(t_game *game, t_sprite *sprite);
int			in_fire_spot(t_map *map);
char		get_new_fire_cell(t_fire_state *state, t_map *map);
void		update_fire_satate(t_fire_state *state, char cell);
void		*current_sprite_frame(t_game *game, t_sprite *sprite);
void		render_cell(t_game *game, char cell, size_t x, size_t y);
void		render_player(t_game *game, t_sprite *sprite);
int			game_loop_handler(t_game *game);
int			key_down_handler(int key_code, t_game *game);
int			key_up_handler(int key_code, t_game *game);
int			exit_handler(t_game *game);
void		init_parsing_state(t_parsing_state *state, int argc,
				char *filename);
int			validate_path(t_map *map, size_t player_x, size_t player_y);
char		*validate_and_open_file(char *filename, t_state_holder *file_state,
				int *fd, int readln);
void		validate_arguments(int argc);
void		init_map_content(t_parsing_state *state, t_map *map);
t_map		*init_map(t_parsing_state *state);

#endif
