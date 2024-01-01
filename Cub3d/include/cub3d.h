/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:50:01 by iris              #+#    #+#             */
/*   Updated: 2024/01/02 00:28:10 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <get_next_line.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

typedef enum e_identifier
{
	NO, 
	SO,
	WE,
	EA,
	F,
}	t_edentifier;

typedef struct s_elements
{
	char	*path_to_north_texture;
	char	*path_to_south_texture;
	char	*path_to_west_texture;
	char	*path_to_east_texture;
}	t_elements;

typedef struct s_map
{
	char	**content;
	char	**dup_content;
	int		length_x;
	int		length_y;
	int		player_x;
	int		player_y;
	int		n_count;
	int		s_count;
	int		e_count;
	int		w_count;
}	t_map;

//CHARACTERS.C

int		check_characters(t_map *map);
int		check_sides_wall(t_map *map);
int		check_first_last_walls(t_map *map);

//MAP.C

char	**floodfill(char **content, int y, int x);
int		count_lines(char **content);
void	map_init(t_map *map);
char	**read_map(int fd);

//MAP_UTILS.C

char	**create_dup_map(t_map *map);
int		check_map_after_ff(char **map_after_ff);

//PARSING.C

int		parsing(int argc, char **argv);
int		is_input_correct(int argc, char *map);

//PARSING_UTILS.C

size_t	ft_strlen_protect(char *s);
size_t	ft_strlcpy_protect(char *dst, char *src, size_t dstsize);
char	*ft_strjoin_free(char *s1, char *s2);

//ELEMENTS.C

int		check_elements_in_map(char **map);
bool	check_Elements(char *line);

//ERROR.C

int		check_errors(t_map *map);
int		has_map_errors(t_map *map);

//FREE.C

void	free_map_2d(char **map_copy);


#endif