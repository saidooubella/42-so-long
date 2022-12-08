/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:49:24 by soubella          #+#    #+#             */
/*   Updated: 2022/10/30 15:24:09 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>

# include "get_next_line.h"

typedef struct s_map
{
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
	int				forward;
	t_map			*map;
	size_t			collected_keys;
	size_t			moves_count;
	size_t			window_height;
	size_t			window_width;
	size_t			taile_height;
	size_t			taile_width;
	size_t			fire_index;
	void			*player_foreward;
	void			*player_backward;
	void			*window;
	void			*grass;
	void			*door_open;
	void			*door_close;
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

void		render_cell(t_game *game, char cell, size_t x, size_t y);
void		render_player(t_game *game);
int			map_in_range(t_map *map, size_t x, size_t y);
void		free_map(t_map *map);
void		game_end(t_game *game);
int			map_in_range(t_map *map, size_t x, size_t y);
void		parsing_part_six(t_parsing_state *state);
void		proccess_line(t_parsing_state *state, t_map *map);
void		map_parsing(t_parsing_state *state, int argc, char *filename);
t_map		*map_validation_and_generation(t_parsing_state *state);
void		parsing_part_one(t_parsing_state *state);
void		parsing_part_two(t_parsing_state *state);
void		parsing_part_three(t_parsing_state *state);
void		parsing_part_four(t_parsing_state *state);
void		parsing_part_five(t_parsing_state *state);
int			in_fire_spot(t_map *map);
void		render_cell(t_game *game, char cell, size_t x, size_t y);
void		render_player(t_game *game);
int			game_loop_handler(t_game *game);
int			key_down_handler(int key_code, t_game *game);
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
