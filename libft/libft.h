/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:06:38 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/27 13:26:08 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

/*
** Part I
*/

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *text, const char *pattern);
char			*ft_strnstr(const char *text, const char *pattern, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *nptr);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** Part II
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** Bonus
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Other functions
*/

int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isblank(int c);
int				ft_isspace(int c);
int				ft_isxdigit(int c);
void			*ft_memdup(const void *src, size_t n);
char			*ft_itoa_base(int n, int base);

/*
**	Binary search tree
*/

typedef struct	s_btree
{
	void			*content;
	size_t			content_size;
	struct s_btree	*left;
	struct s_btree	*right;
	size_t			height;
}				t_btree;

t_btree			*ft_btree_new(void const *content, size_t content_size);
void			ft_btree_preorder(t_btree *root, void (*f)(void *, size_t));
void			ft_btree_inorder(t_btree *root, void (*f)(void *, size_t));
void			ft_btree_postorder(t_btree *root, void (*f)(void *, size_t));
void			ft_btree_insert(t_btree **root, void *content,
		size_t content_size, int (*cmpf)(void *, size_t, void *, size_t));
void			*ft_btree_search(t_btree *root, void *content,
		size_t content_size, int (*cmpf)(void *, size_t, void *, size_t));

/*
**	Dynamic Vector
**	--------------
**	Right now, the vector stores pointers to data; it does not copy data;
**		when destroyed, it does not deallocate memory for data
*/

typedef struct	s_vector
{
	void	**v;
	size_t	size;
	size_t	capacity;
}				t_vector;

t_vector		*ft_vector_init(int capacity);
void			ft_vector_destroy(t_vector **v);
int				ft_vector_push_back(t_vector *v, void *e);
int				ft_vector_delete(t_vector *v, int index);

/*
**	get_next_line
**	-------------
*/

# define BUFF_SIZE 32

typedef struct	s_file_pool
{
	int		fd;
	char	*text;
}				t_file_pool;

int				get_next_line(int const fd, char **line);

/*
**	Structures for describing vectors of various dimensions (2, 3 and 4)
*/

typedef struct	s_2d_vector
{
	double	x;
	double	y;
}				t_2d_vector;

t_2d_vector		ft_2d_translate(t_2d_vector v, double tx, double ty);
t_2d_vector		ft_2d_rotate(t_2d_vector v, double theta);
t_2d_vector		ft_2d_scale(t_2d_vector v, double sx, double sy);

typedef struct	s_3d_vector
{
	double	x;
	double	y;
	double	z;
}				t_3d_vector;

t_3d_vector		ft_3d_translate(t_3d_vector v, double tx, double ty, double tz);
t_3d_vector		ft_3d_rotate_x(t_3d_vector v, double theta);
t_3d_vector		ft_3d_rotate_y(t_3d_vector v, double theta);
t_3d_vector		ft_3d_rotate_z(t_3d_vector v, double theta);
t_3d_vector		ft_3d_scale(t_3d_vector v, double sx, double sy, double sz);

typedef struct	s_4d_vector
{
	double	x;
	double	y;
	double	z;
	double	t;
}				t_4d_vector;

/*
**	Matrix [... maybe use built-in matrices...]
*/

typedef struct	s_matrix
{
	double	**m;
	int		rows;
	int		cols;
}				t_matrix;

t_matrix		*matrix_create(int rows, int cols);
void			matrix_destroy(t_matrix *mat);

#endif
