/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:50:58 by hamdas            #+#    #+#             */
/*   Updated: 2023/01/10 12:21:30 by mal-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<math.h>
# include	<limits.h>
# include   "../libft/libft.h"
# include	"../mlx/mlx.h"
# define NUM_TEXTURES 4
# define WIDTH 1200
# define NUM_RAYS WIDTH
# define TILE 64
# define WIDTH 1200
# define HEIGHT 800
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define TOP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ESC 53

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define PI 3.14159265
# define TWO_PI 6.28318530

// colors used in drawing & utlis 
//Regular text
# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

//Regular bold text
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"

//Regular underline text
# define UBLK "\e[4;30m"
# define URED "\e[4;31m"
# define UGRN "\e[4;32m"
# define UYEL "\e[4;33m"
# define UBLU "\e[4;34m"
# define UMAG "\e[4;35m"
# define UCYN "\e[4;36m"
# define UWHT "\e[4;37m"

//Regular background
# define BLKB "\e[40m"
# define REDB "\e[41m"
# define GRNB "\e[42m"
# define YELB "\e[43m"
# define BLUB "\e[44m"
# define MAGB "\e[45m"
# define CYNB "\e[46m"
# define WHTB "\e[47m"

//High intensty background 
# define BLKHB "\e[0;100m"
# define REDHB "\e[0;101m"
# define GRNHB "\e[0;102m"
# define YELHB "\e[0;103m"
# define BLUHB "\e[0;104m"
# define MAGHB "\e[0;105m"
# define CYNHB "\e[0;106m"
# define WHTHB "\e[0;107m"

//High intensty text
# define HBLK "\e[0;90m"
# define HRED "\e[0;91m"
# define HGRN "\e[0;92m"
# define HYEL "\e[0;93m"
# define HBLU "\e[0;94m"
# define HMAG "\e[0;95m"
# define HCYN "\e[0;96m"
# define HWHT "\e[0;97m"

//Bold high intensity text
# define BHBLK "\e[1;90m"
# define BHRED "\e[1;91m"
# define BHGRN "\e[1;92m"
# define BHYEL "\e[1;93m"
# define BHBLU "\e[1;94m"
# define BHMAG "\e[1;95m"
# define BHCYN "\e[1;96m"
# define BHWHT "\e[1;97m"

//Reset
# define RESET "\e[0m"

// structures of variables used in drawing & utils
typedef struct s_aux_ray
{
	int		found_wall_hit;
	float	wall_hit_x;
	float	wall_hit_y;
	int		wall_content;
	float	next_touchx;
	float	next_touchy;
	float	xto_check;
	float	yto_check;
	float	hit_distance;
}			t_aux_ray;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction;
	int		side_direction;
	int		walk_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
	int		orientation;
}			t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

// Note change the color
typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
	int		status;
}		t_rgb;

typedef struct s_collor
{
	t_rgb	cell_rgb;
	t_rgb	floor_rgb;
	int		cell;
	int		floor;
	int		status;
}		t_collor;

typedef struct s_map_info
{
	int	height;
	int	width;
}		t_map_info;

typedef struct s_ray
{
	float		ray_angle;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	int			was_hit_vertical;
	int			wall_hit_cotent;
}				t_ray;

typedef struct s_utils_ray
{
	float		x_intercept;
	float		y_intercept;
	float		x_step;
	float		y_step;
	int			is_ray_facing_up;
	int			is_ray_facing_down;
	int			is_ray_facing_left;
	int			is_ray_facing_right;
}			t_utils_ray;

typedef struct s_projection
{
	float		perp_dist;
	float		proj_wall_height;
	int			wall_strip_height;
	int			wall_top_pixel;
	int			wall_bottom_pixel;
	int			x;
	int			y;
	int			texture_offset_x;
	int			texture_off_sety;
	int			tex_num;
	int			distance_from_top;
	uint32_t	texel_color;
}			t_projection;

typedef struct s_pos
{
	int		y;
	int		x;
}			t_pos;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	t_pos	pos;
}			t_data;

typedef struct s_img
{
	t_data	no;
	t_data	we;
	t_data	so;
	t_data	ea;
}			t_img;

typedef struct s_cub3d
{
	t_player	player;
	t_ray		rays[NUM_RAYS];
	char		***path_texture;
	char		***colors_cf;
	char		**map;
	char		**map_content;
	t_data		img;
	t_img		sprites;
	t_mlx		s_mlx;
	uint32_t	*textures[NUM_TEXTURES];
	t_collor	collors;
	t_map_info	map_info;
	double		dist_proj_plane;
}			t_cub3d;

//funcation for parcening

int				invalid_arg(int argc, char **argv);
int				error_msg(char	*msg, t_cub3d *cub3d);
int				check_map(char *map_path, t_cub3d *cub3d);
char			**remove_empty_line(char **map_content);
char			**get_map(char *map_path);
int				ft_strlen_split(char **split);
char			*ft_free_triple(char ***str);
char			*ft_free_split(char **str);
int				ft_strcmp(const char *s1, const char *s2);
char			***valid_ceilling_and_floor_color(char **map_content);
char			*ft_split_rev(char **split);
t_collor		check_color(char ***colors);
int				verify_collor(t_rgb *rgb, char **collors);
char			***valid_texture(char **map_content);
int				file_exist(char *map_path);
int				check_extenstion(char *map_name, char *extention);
int				texture_file_exist(char ***texture);
int				valid_characters(char **map);
char			**store_map_blueprint(char **content_map);
int				valid_edge(char **map);
void			free_struct(t_cub3d *cub3d);

// defining all the functions used in drawing & utils
// drawing files

void			get_values_projection(t_cub3d *cub, t_projection *var);
void			draw_ceiling(t_cub3d *cub, t_projection var);
void			draw_floor(t_cub3d *cub, t_projection var);
void			get_texture_offset(t_cub3d *cub, t_projection *var);
void			generate3d_projection(t_cub3d *cub);
void			ft_mlx_pixel_put(t_data *img_data, int x, int y, int color);
unsigned int	get_color(t_data *data, int x, int y);
void			change_color_intesity(uint32_t *color, float factor);
void			find_horz_intersection(t_aux_ray *aux, t_utils_ray *utils,
					t_cub3d *cub);
t_aux_ray		ray_horizontal(t_cub3d *cub, t_utils_ray *utils, float angle);
void			find_vert_intersection(t_aux_ray *aux, t_utils_ray *utils,
					t_cub3d *cub);
t_aux_ray		ray_vertical(t_cub3d *cub, t_utils_ray *utils, float angle);
void			get_ray_distance(t_cub3d *cub, t_aux_ray *horz,
					t_aux_ray *vert);
void			get_values_of_ray(t_ray *ray, t_utils_ray utils,
					t_aux_ray horz, t_aux_ray vert);
void			cast_ray(float ray_angle, int id, t_cub3d *cub);
void			cast_all_rays(t_cub3d *cub);
void			draw_gaming(t_cub3d *cub);

// utlis files 
int				is_inside_map(float x, float y, t_cub3d *cub);
int				map_has_wall_at(t_cub3d *cub, float x, float y);
int				get_lenght(t_cub3d *cub, float line);
void			sprites(t_data *img, void *mlx, char *path);
void			build_main_img(t_cub3d *cub);
void			start_textures(t_cub3d *cub);
int				get_color_mlx(t_rgb color);
int				is_ray_facing_down(float angle);
int				is_ray_racing_up(float angle);
int				is_ray_facing_right(float angle);
int				is_ray_facing_left(float angle);
void			setup(t_cub3d *cub);
void			offset_inverse(t_ray ray, int *offset_texture_x);
float			normalize_angle(float angle);
float			distance_inbetween(float x1, float y1, float x2, float y2);

int				close_win(t_cub3d *cub);
void			free_mlx_all(t_cub3d *cub);
void			free_images(t_cub3d *cub);

int				action(int keycode, t_cub3d *cub);
int				action_loop(t_cub3d *cub);

#endif
