/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 14:50:01 by iris          #+#    #+#                 */
/*   Updated: 2024/02/12 16:50:31 by ivan-mel      ########   odam.nl         */
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

// SCREEN
# define HEIGHT 1200
# define WIDTH 1800

// MINIMAP
# define MINI_HEIGHT HEIGHT / 5
# define MINI_WIDTH WIDTH / 5

// COLOURS
# define LIGHTCORAL 240, 128, 128, 255
# define LAVENDER 230, 230, 250, 255
# define LIGHTPINK 255, 182, 193, 255
# define MISTYROSE 225, 228, 225, 225

// MATH
# define PI 3.1415926
# define HALF_SCREENSIZE HEIGHT / 2 * WIDTH
# define TILE 10
# define Y 0
# define X 1

#define PASSED '2'

//ERROR MSGS

#define VALID_CHARS "10NSEW2"
#define DOUBLE_ELEMENT "ERROR Double element! encountered.\n"
#define FLOOD_FAIL "Invalid char in map OR unwalled floor detected"
#define MAP_ALLOC_FAIL "Error allocating the map"

typedef struct s_cub3d	t_cub3d;

typedef enum e_error
{
	ERROR_CHARACTER,
	ERROR_MLX,
	ERROR_IMAGE,
	ERROR_ALLOCATION,
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

typedef	struct s_vector
{
	double x;
	double y;
}	t_vector;

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	uint32_t		floor_colour;
	uint32_t		ceiling_colour;

}	t_textures;

typedef struct s_player
{
	// float	direction;
	// float	view;
	t_vector	pos;
	t_cub3d	*data;

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
	t_cub3d		*cub3d;
} t_minimap;

typedef struct s_raycast_data
{
	t_vector	raydir;
	t_vector	delta_dist;

	double	eucli_distX;
	double	eucli_distY;
	double	perp_dist;

	double	side_distX;
	double	side_distY;

	int		stepX;
	int		stepY;

	int		mapX;
	int		mapY;

	int		side_hit;
	t_map	*map;
	t_cub3d	*data;

	double	wallhit_co_ord;
}	t_raycast_data;

struct s_cub3d
{
	t_map				*map;
	t_player			player;
	mlx_t				*mlx;
	t_raycast_data		*raycast;
	mlx_image_t			*background; //should be with textures imo
	mlx_image_t			*wall;
	// mlx_image_t			*minimap;
	t_minimap			*minimap;
	t_textures			textures;
};
//CUBED.C


int	cubed(int argc, char **argv);

//init.c
void	init_cub3d_data(t_cub3d *cub3d, t_map *map, t_raycast_data *raycast);


/////////////////////////////PARSER////////////////////////////////////
//MAP.C

bool		map_init(t_cub3d *cub3d, t_map *map, int map_start_index);

//CHARACTERS.C

void		find_max_lengths(char **map, int *length_x, int *length_y);
int			only_one_player_symbol(t_map *map);
bool		is_player_char(char c);

//PARSING.C
bool		parsing(int argc, char **argv, t_cub3d *cub3d, t_map *map);


//PARSING_UTILS.C

size_t		ft_strlen_protect(char *s);
size_t		ft_strlcpy_protect(char *dst, char *src, size_t dstsize);
char		*ft_strjoin_free(char *s1, char *s2);
bool		free_line_if_empty(char *line);

//ELEMENTS.C

bool		check_elements_in_map(char **map);
void		load_element(t_cub3d *cub3d, char *path, int id);
int			parse_and_load_textures(t_cub3d *cub3d, char **map);
bool		load_wall_img(char *path, mlx_texture_t **texture);


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

/////////////////////////////SETUP////////////////////////////////////

//PIXEL_SETUP.C
void	cub3d_memset(void *b, int colour, size_t len);
int		background_setup(mlx_image_t *background);

//MLX_SETUP.C

void	mlx_window_setup();
int		mlx_image_setup(t_cub3d *cub3d);
void	game_setup(t_cub3d *cub3d);
void	draw_line(t_raycast_data *raycast, int x);

//PLAYER_SETUP.C

// void	player_setup(t_cub3d *cub3d);
void	set_initial_look_dirs(t_player *player, char dir_char);

//mouse move

void	*mouse_move(double xpos, double ypos, void	*param);
void	*escape(mlx_key_data_t keydata, void *param);
void	cub3d_loop(void	*param);
void	change_dir(void	*param);

// RAYCAST.c

void	raycaster(void *param);
void	keep_lookin(t_raycast_data *raycast);

void	init_raycast_data(t_raycast_data *raycast, t_cub3d *data);

//MINIMAP.C

bool	start_minimap(t_cub3d *cub3d);
char	**compare_maps(char **mm_array, char **mini_map, int player_x, int player_y);

#endif
