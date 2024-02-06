/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 14:50:01 by iris          #+#    #+#                 */
/*   Updated: 2024/01/26 17:06:38 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>

# include <MLX42.h>
# include "libft.h"
# include "tmp_merlin.h"


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

typedef struct s_map
{
	char	**content;
	char	**dup_content;
	int		length_y;
	int		length_x;
	int		player_x;
	int		player_y;
	int		player_count;
}	t_map;

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
bool		use_elements(char *path, int id, t_elements *element);
bool		parse_elements_in_map(char **map);

//ELEMENTS_UTILS.C

uint32_t	get_rgba(int r, int g, int b, int a);
bool		parse_colours(char *path, int id, t_elements *element);

// PATHS.C

bool		get_north_path(t_textures *texture, char *path);
bool		get_south_path(t_textures *texture, char *path);
bool		get_west_path(t_textures *texture, char *path);
bool		get_east_path(t_textures *texture, char *path);

//ERROR.C

int			has_map_errors(t_map *map);

//FREE.C

void		free_map_2d(char **map_copy);



//mlx running

void	mlx_time(t_map *map);

#endif
