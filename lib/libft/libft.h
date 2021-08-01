#ifndef LIBFT_H
# define LIBFT_H
# include "../libex/libex.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <errno.h>
# ifndef T_LIST
#  define T_LIST
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
# endif
# ifndef LOGGING_H
#  define LOGGING_H
#  define RESET "\033[0m"
#  define BOLD "\033[1m"
#  define BLACK "\033[30m"
#  define RED "\033[31m"
#  define GREEN "\033[32m"
#  define YELLOW "\033[33m"
#  define BLUE "\033[34m"
#  define MAGENTA "\033[35m"
#  define CYAN "\033[36m"
#  define WHITE "\033[37m"
#  define BOLDBLACK "\033[1m\033[30m"
#  define BOLDRED "\033[1m\033[31m"
#  define BOLDGREEN "\033[1m\033[32m"
#  define BOLDYELLOW "\033[1m\033[33m"
#  define BOLDBLUE "\033[1m\033[34m"
#  define BOLDMAGENTA "\033[1m\033[35m"
#  define BOLDCYAN "\033[1m\033[36m"
#  define BOLDWHITE "\033[1m\033[37m"
# endif

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_list **lst, t_list *newobj);
void	ft_putstr_fd(char *s, int fd);
t_list	*ft_lstnew(void *content);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
t_list	*ft_lstlast(t_list *lst);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isascii(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
int		ft_isprint(int c);
void	ft_putendl_fd(char *s, int fd);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize(t_list *lst);
int		ft_toupper(int c);
char	**ft_split(char const *s, char c);
void	ft_lstadd_front(t_list **lst, t_list *newobj);
char	*ft_strrchr(const char *s, int c);
int		ft_isalpha(int c);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *s);
int		ft_isalnum(int c);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
char	*ft_itoa(int n);
int		ft_tolower(int c);

#endif
