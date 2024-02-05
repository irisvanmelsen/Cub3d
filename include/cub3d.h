/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 14:50:01 by iris          #+#    #+#                 */
/*   Updated: 2024/02/02 21:39:34 by iris          ########   odam.nl         */
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
# include <libft.h>

// SCREEN
# define HEIGHT 900
# define WIDTH 1600

// MATH
# define PI 3.1415926

typedef enum e_error
{
	ERROR_CHARACTER,
	ERROR_MLX,
	ERROR_IMAGE,
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

typedef struct s_elements
{
	char	*path_to_north_texture;
	char	*path_to_south_texture;
	char	*path_to_west_texture;
	char	*path_to_east_texture;
	int		ceiling_column;
	int		floor_column;
}	t_elements;

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
}	t_textures;

typedef struct s_player
{
	float	direction;
	float	position_x;
	float	position_y;

} t_player;

typedef struct s_map
{
	char		**content;
	char		**dup_content;
	int			length_y;
	int			length_x;
	int			player_x;
	int			player_y;
	int			player_count;
}	t_map;

typedef struct s_cub3d
{
	t_map		map;
	t_player	player;
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*wall;
	mlx_image_t	*minimap;
}	t_cub3d;

/////////////////////////////PARSER////////////////////////////////////

//CHARACTERS.C

int			check_characters(t_map *map);
void		search_max_lengths(char **map, int *length_x, int *length_y);
bool		is_player_char(char c);
bool		find_player_pos(t_map *map);

//MAP.C

bool		valid_char(char c);
bool		floodfill(t_map *map, char **dup_map, int y, int x);
void		map_init(t_map *map);
char		**read_map(int fd);

//MAP_UTILS.C

char		**create_dup_map(t_map *map);
int			check_map_after_ff(char **map_after_ff);

//PARSING.C

int			parsing(int argc, char **argv, t_map *map);
int			is_input_correct(int argc, char *map);

//PARSING_UTILS.C

size_t		ft_strlen_protect(char *s);
size_t		ft_strlcpy_protect(char *dst, char *src, size_t dstsize);
char		*ft_strjoin_free(char *s1, char *s2);

//ELEMENTS.C

char		*take_out_prefix_newlines(char *line, int id);
bool		check_elements_in_map(char **map);
int			check_elements(char *line);
bool		use_elements(t_cub3d *cub3d, char *path, int id, \
			t_elements *element);
bool		parse_elements_in_map(t_cub3d *cub3d, char **map);

//ELEMENTS_UTILS.C

uint32_t	get_rgba(int r, int g, int b, int a);
bool		parse_colours(char *path, int id, t_elements *element);

// PATHS.C

bool		get_north_path(t_cub3d *cub3d, t_textures *texture, char *path);
bool		get_south_path(t_cub3d *cub3d, t_textures *texture, char *path);
bool		get_west_path(t_cub3d *cub3d, t_textures *texture, char *path);
bool		get_east_path(t_cub3d *cub3d, t_textures *texture, char *path);

//ERROR.C

int			has_map_errors(t_map *map);
char		*get_error_name(t_error error);
int			print_error(char *str);

//FREE.C

void		free_map_2d(char **map_copy);

/////////////////////////////SETUP////////////////////////////////////

//CUB3D_SETUP.C

void	position_setup(t_cub3d *cub3d);
void	cub3d_setup(t_cub3d *cub3d);

//MLX_SETUP.C

void	mlx_window_setup();
void	mlx_setup(t_cub3d *cub3d);



//mlx running

void	mlx_time(t_map *map);

#endif
