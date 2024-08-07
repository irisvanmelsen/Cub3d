/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 14:50:01 by iris          #+#    #+#                 */
/*   Updated: 2024/06/06 18:06:44 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>
# include <stdio.h>

# include <MLX42.h>
# include "libft.h"

// PRINTF COLOUR CODES
# define C_RED "\033[31m"
# define C_BLACK "\033[30m"
# define C_RED "\033[31m"
# define C_GREEN "\033[32m"
# define C_YELLOW "\033[33m"
# define C_BLUE "\033[34m"
# define C_MAGENTA "\033[35m"
# define C_CYAN "\033[36m"
# define C_WHITE "\033[37m"
# define C_RESET "\033[0m"
// SCREEN
# define HEIGHT 1200
// # define HALF_HEIGHT HEIGHT / 2
# define HALF_HEIGHT 600
# define WIDTH 1800
// # define HALF_WIDTH WIDTH / 2
# define HALF_WIDTH 900

// # define HALF_SCREENSIZE HEIGHT / 2 * WIDTH
# define HALF_SCREENSIZE 1080000

// MINIMAP
// # define MINI_HEIGHT HEIGHT / 5
# define MINI_HEIGHT 240
// # define MINI_WIDTH WIDTH / 5
# define MINI_WIDTH 360

// COLOURS
# define LIGHTGREEN 175225175255
# define EUCALYPTUS 95133117255
# define MINT 152251152255
# define PISTACHIO 147197114225

// MATH
# define PI 3.1415926
# define TILE 10
# define Y 0
# define X 1
# define PASSED '2'

//ERROR MSGS
# define VALID_CHARS "10NSEW2"
# define DOUBLE_ELEMENT "ERROR too many elements! encountered.\n"
# define FLOOD_FAIL "Invalid char in map OR unwalled floor detected\n"
# define MAP_ALLOC_FAIL "Error allocating the map array either a malloc fail\n\
or more likeley extra text/tokens below the map\n"
# define MAP_WALL_FAIL	"map is not properly walled off :(\n"

typedef struct s_cub3d	t_cub3d;

typedef enum e_rgb
{
	R,
	G,
	B,
}	t_rgb;

typedef enum e_error
{
	ERROR_CHARACTER,
	ERROR_MLX,
	ERROR_IMAGE,
	ERROR_ALLOCATION,
	ERROR_LOAD,
}	t_error;

typedef enum e_identifier
{
	FAILED,
	NO,
	SO,
	WE,
	EA,
	F,
	C,
}	t_edentifier;

typedef enum e_stepdir
{
	NEGATIVE = -1,
	POSITIVE = 1,
}	t_stepdir;

typedef enum e_wallside
{
	HORIZONTAL,
	VERTICAL,
}	t_wallside;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_int_vector
{
	int	x;
	int	y;
}	t_int_vector;

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	uint32_t		floor_colour;
	uint32_t		ceiling_colour;
	double			tex_pos;
	double			wallx;
	int				texx;
	mlx_texture_t	*used_tex;
	int				side;
	int				texture_y;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	uint8_t			a;

}	t_textures;

typedef struct s_player
{
	t_vector	pos;
	t_cub3d		*data;
	t_vector	dir;
	t_vector	plane;
}	t_player;

typedef struct s_map
{
	char		**file_content;
	char		**dup_content;
	char		**content;
	int			length_y;
	int			length_x;
	int			player_x;
	int			player_y;
	int			player_count;
	char		dir_char;
}	t_map;

typedef struct s_minimap
{
	mlx_image_t	*image;
	mlx_image_t	*border;
	mlx_t		*mlx;
	char		**og_map;
	int			scaler;
	int			mm_height;
	int			map_height;
	t_cub3d		*cub3d;
	char		**mm_array;
	uint32_t	colour;
}	t_minimap;

typedef struct s_raycast_data
{
	t_vector		raydir;
	t_vector		delta_dist;
	t_vector		side_dist;
	t_int_vector	map_stepdir;
	t_int_vector	maptile;
	double			perp_dist;
	double			step;
	int				side_hit;
	t_map			*map;
	t_cub3d			*data;
	t_textures		*textures;
	t_textures		*texture;
	t_player		*player;
}	t_raycast_data;

struct s_cub3d
{
	t_map				*map;
	t_player			player;
	mlx_t				*mlx;
	t_raycast_data		*raycast;
	mlx_image_t			*background;
	mlx_image_t			*wall;
	t_minimap			*minimap;
	t_textures			textures;
};

//CUBED.C

void		main_game_loop(void *param);

//init.c
void		init_raycast_data(t_raycast_data *raycast, t_cub3d *data);
t_cub3d		*init_cub3d_data(void);

/////////////////////////////PARSER////////////////////////////////////
//PARSING.C
bool		parsing(int argc, char **argv, t_cub3d *cub3d, t_map *map);

//MAP.C

bool		map_init(t_map *map, int map_start_index);
bool		is_map_walled(char **map, size_t mapheight);
bool		valid_char(char c);
bool		outer_walls_check(char **map);
bool		top_bottom_check(char *map);
bool		is_str_in_bounds(char *str, int i);
bool		is_map_in_bounds(char **map, int y, int x);
size_t		end_of_mapline(char *str);

//CHARACTERS.C

void		find_max_lengths(char **map, int *length_x, int *length_y);
int			only_one_player_symbol(t_map *map);
bool		is_player_char(char c);

//PARSING_UTILS.C
size_t		ft_strlen_protect(char *s);
size_t		ft_strlcpy_protect(char *dst, char *src, size_t dstsize);
char		*ft_strjoin_free(char *s1, char *s2);
bool		free_line_if_empty(char *line);

//ELEMENTS.C
bool		check_elements_in_map(char **map);
bool		load_element(t_cub3d *cub3d, char *path, int id);
int			parse_and_load_textures(t_cub3d *cub3d, char **map);

//ELEMENTS_UTILS.C
uint32_t	get_rgba(int r, int g, int b, int a);
bool		parse_colours(char *path, int id, t_textures *s_textures);
bool		all_elements_loaded(t_textures *checkme);
int			which_element(char *line);
char		*skip_path_prefix(char *line, int id);

//ERROR.C
bool		has_map_errors(t_map *map);
char		*get_error_name(t_error error);
bool		print_error(char *str);

//FREE.C
void		free_map_2d(char **map_copy);
void		free_all(t_cub3d *data);

//MOVEMENT.C
void		cub3d_loop(void	*param);
void		move(t_player *player, t_vector dir, bool	subtract, t_vector \
			*newpos);
void		change_dir(t_player	*player, bool looking_right);
void		rotate_vector(t_vector *vector, double angle);
t_vector	rotate_vec_return(t_vector vector, double angle);
int			keypress_check(t_cub3d	*m, t_vector *player_pos);
void		mouse_rotation(t_cub3d *m);

//MOVEMENT_UTILS.C
void		rotate_vector(t_vector *vector, double angle);
t_vector	rotate_vec_return(t_vector vector, double angle);
void		if_newpos_is_zero(t_cub3d *m, t_vector newpos);

/////////////////////////////SETUP////////////////////////////////////

//PIXEL_SETUP.C
void		cub3d_memset(void *b, int colour, size_t len);
int			background_setup(mlx_image_t *background);

//MLX_SETUP.C
void		mlx_window_setup(void);
int			mlx_image_setup(t_cub3d *cub3d);
void		game_setup(t_cub3d *cub3d);
void		draw_line(t_raycast_data *raycast, int x, t_textures *texture);

// void	player_setup(t_cub3d *cub3d);
void		set_initial_look_dirs(t_player *player, char dir_char);

//mouse move

void		*mouse_move(double xpos, double ypos, void	*param);
void		*escape(mlx_key_data_t keydata, void *param);
void		cub3d_loop(void	*param);

////////RAYCASTING///////////////////
void		raycaster(void *param);
void		keep_lookin(t_raycast_data *raycast);
t_vector	calc_delta_dist(t_vector raydir);
void		init_raycast_data(t_raycast_data *raycast, t_cub3d *data);
double		calc_perp_dist_and_wallx(t_raycast_data *raycast, t_player *player);
void		calc_side_dist(t_raycast_data *raycast, t_player *player);

//RAYCASTING_UTILS
void		coordinate_on_textures(t_raycast_data *ray, t_textures *texture);

//MINIMAP.C
bool		start_minimap(t_cub3d *cub3d);
char		**compare_maps(t_minimap *minimap, char **mm_array, t_cub3d *cub3d);
void		draw_mm(char **mm_array, t_minimap *minimap);
void		mm_update(t_cub3d *cub3d, t_minimap *minimap);

//MINIMAP_IMAGES.C
void		fill_the_image(t_minimap *minimap, int x, int y);
void		fill_colours(char **mm_array, t_minimap *minimap, int y, int x);
void		fill_wall_backgr(char **mm_array, t_minimap *minimap);
void		setup_border(t_minimap *minimap);
void		check_char_mm(char **mm_array, t_cub3d *cub3d, int y);
char		**setup_minimap_arr(void);

//TEXTURES.C
void		init_minimap(t_cub3d *cub3d);
int			calc_height_minimap(char **mini_map);
void		load_textures_in(t_cub3d *cub3d);
uint32_t	texture_colours(t_textures *texture, double x, double y);

#endif
