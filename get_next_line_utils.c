#include "get_next_line.h"

void	*ft_bzero(void *ptr, size_t num)
{
	size_t			i;
	unsigned char	*p;

	p = ptr;
	i = 0;
	while (i != num)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_strlen(const char *text)
{
	int	count;

	count = 0;
	if (!text)
		return 0;
	while (text[count])
		count++;
	return (count);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*arr;

	if (size != 0 && nmemb > ((size_t) - 1) / size)
		return (NULL);
	arr = (size_t *)malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

void	*ft_memcpy(void *dest, const void *str, size_t num)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*d;
	p = dest;
	d = (unsigned char *)str;
	i = 0;
	if (!dest || !str)
    	return (NULL);
	while (i < num)
	{
		p[i] = d[i];
		i++;
	}
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (!(char)c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	if (!str)
		return (NULL);
	dup = ((char *)malloc(ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, str, ft_strlen(str) + 1);
	return (dup);
}

unsigned int	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	leng_dst;
	unsigned int	leng_src;
	size_t			i;

	i = 0;
	leng_dst = ft_strlen(dst);
	leng_src = ft_strlen(src);
	if (size == 0)
		return (leng_src);
	else if (size <= leng_dst)
		return (leng_src + size);
	while ((i < (size - leng_dst - 1)) && (src[i] != 0))
	{
		dst[leng_dst + i] = src[i];
		i++;
	}
	dst[leng_dst + i] = 0;
	return (leng_dst + leng_src);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char    *cp;
    int     l_s1;
    int     l_s2;

    if (!s1)
        s1 = "";
    if (!s2)
        s2 = "";
    l_s1 = ft_strlen(s1);
    l_s2 = ft_strlen(s2);
    cp = (char *)ft_calloc((l_s1 + l_s2 + 1), sizeof(char));
    if (!cp)
        return (NULL);
    ft_strlcat(cp, s1, l_s1 + 1);
    ft_strlcat(cp, s2, l_s1 + l_s2 + 1);
    return (cp);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cp;
	size_t		i;
	size_t	len_str;

	i = 0;
	len_str = ft_strlen(s);
	if (!s)
		return(NULL);
	if (start >= len_str)
		return (ft_strdup(""));
	if (len > len_str - start)
		len = len_str - start;
	cp = (char *)malloc(len + 1);
	if (!cp)
		return (NULL);
	while (i < len)
	{
		cp[i] = s[start++];
		i++;
	}
	cp[i] = 0;
	return (cp);
}

