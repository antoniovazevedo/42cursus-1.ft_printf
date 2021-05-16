#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>

void    tolower_test(void)
{
    unsigned char c;
    
    printf("\nLet's test\t\tft_tolower\n");
    c = 'A';
    if (tolower(c) != ft_tolower(c))
        printf("\t❌ 1/2 : Expected \"%c\" and got \"%c\"\n", tolower(c), ft_tolower(c));

    c = 'z';
    if (tolower(c) != ft_tolower(c))
        printf("\t❌ 2/2 : Expected \"%c\" and got \"%c\"\n", tolower(c), ft_tolower(c));
    printf("\n\tDone testing\tft_tolower\n\n");
}

void toupper_test(void)
{
    unsigned char c;

    printf("\nLet's test\t\tft_toupper\n");
    c = 'a';
    if (toupper(c) != ft_toupper(c))
        printf("\t❌ 1/2 : Expected \"%c\" and got \"%c\"\n", toupper(c), ft_toupper(c));

    c = 'Z';
    if (toupper(c) != ft_toupper(c))
        printf("\t❌ 2/2 : Expected \"%c\" and got \"%c\"\n", toupper(c), ft_toupper(c));
    printf("\n\tDone testing\tft_toupper\n\n");
}

void isprint_test(void)
{
    unsigned char c;

    printf("\nLet's test\t\tft_isprint\n");
    c = 'a';
    if (isprint(c) != ft_isprint(c))
        printf("\t❌ 1/4 : Expected %d and got %d\n", isprint(c), ft_isprint(c));

    c = ' ';
    if (isprint(c) != ft_isprint(c))
        printf("\t❌ 2/4 : Expected %d and got %d\n", isprint(c), ft_isprint(c));

    c = 127;
    if (isprint(c) != ft_isprint(c))
        printf("\t❌ 3/4 : Expected %d and got %d\n", isprint(c), ft_isprint(c));

    c = 0;
    if (isprint(c) != ft_isprint(c))
        printf("\t❌ 4/4 : Expected %d and got %d\n", isprint(c), ft_isprint(c));
    printf("\n\tDone testing\tft_isprint\n\n");
}

void isascii_test(void)
{
    char c;

    printf("\nLet's test\t\tft_isascii\n");
    c = 127;
    if (isascii(c) != ft_isascii(c))
        printf("\t❌ 1/2 : Expected %d and got %d\n", isascii(c), ft_isascii(c));

    c = -127;
    if (isascii(c) != ft_isascii(c))
        printf("\t❌ 2/2 : Expected %d and got %d\n", isascii(c), ft_isascii(c));
    printf("\n\tDone testing\tft_isascii\n\n");
}

void isalnum_test(void)
{
    unsigned char c;

    printf("\nLet's test\t\tft_isalnum\n");
    c = 'a';
    if (isalnum(c) != ft_isalnum(c))
        printf("\t❌ 1/3 : Expected %d and got %d\n", isalnum(c), ft_isalnum(c));

    c = '6';
    if (isalnum(c) != ft_isalnum(c))
        printf("\t❌ 2/3 : Expected %d and got %d\n", isalnum(c), ft_isalnum(c));

    c = '~';
    if (isalnum(c) != ft_isalnum(c))
        printf("\t❌ 3/3 : Expected %d and got %d\n", isalnum(c), ft_isalnum(c));
    printf("\n\tDone testing\tft_isalnum\n\n");
}

void isdigit_test(void)
{
    unsigned char c;

    printf("\nLet's test\t\tft_isdigit\n");
    c = 'a';
    if (isdigit(c) != ft_isdigit(c))
        printf("\t❌ 1/3 : Expected %d and got %d\n", isdigit(c), ft_isdigit(c));

    c = '6';
    if (isdigit(c) != ft_isdigit(c))
        printf("\t❌ 2/3 : Expected %d and got %d\n", isdigit(c), ft_isdigit(c));

    c = '~';
    if (isdigit(c) != ft_isdigit(c))
        printf("\t❌ 3/3 : Expected %d and got %d\n", isdigit(c), ft_isdigit(c));
    printf("\n\tDone testing\tft_isdigit\n\n");
}

void isalpha_test(void)
{
    unsigned char c;

    printf("\nLet's test\t\tft_isalpha\n");
    c = 'a';
    if (isalpha(c) != ft_isalpha(c))
        printf("\t❌ 1/3 : Expected %d and got %d\n", isalpha(c), ft_isalpha(c));

    c = '6';
    if (isalpha(c) != ft_isalpha(c))
        printf("\t❌ 2/3 : Expected %d and got %d\n", isalpha(c), ft_isalpha(c));

    c = '~';
    if (isalpha(c) != ft_isalpha(c))
        printf("\t❌ 3/3 : Expected %d and got %d\n", isalpha(c), ft_isalpha(c));
    printf("\n\tDone testing\tft_isalpha\n\n");
}

void strlen_test(void)
{
    char *str;

    printf("\nLet's test\t\tft_strlen\n");
    str = "abc";
    if (strlen(str) != ft_strlen(str))
        printf("\t❌ 1/3 : Expected %lu and got %d\n", strlen(str), (int) ft_strlen(str));

    str = "ftgyiujo1 sad";
    if (strlen(str) != ft_strlen(str))
        printf("\t❌ 2/3 : Expected %lu and got %d\n", strlen(str), (int) ft_strlen(str));

    str = "";
    if (strlen(str) != ft_strlen(str))
        printf("\t❌ 3/3 : Expected %lu and got %d\n", strlen(str), (int) ft_strlen(str));

    printf("\n\tDone testing\tft_strlen\n\n");
}

void strlcat_test(void)
{
    char dst[10];
    dst[0] = 'm';
    dst[1] = 'e';
    dst[2] = 'o';
    dst[3] = 'w';
    dst[4] = '\0';

    char dst2[10];
    dst2[0] = 'm';
    dst2[1] = 'e';
    dst2[2] = 'o';
    dst2[3] = 'w';
    dst2[4] = '\0';

    char *src;
    src = "woof";

    printf("\nLet's test\t\tft_strlcat\n");

    size_t ret;
    size_t ft_ret;

    ret = strlcat("", "", 0);
    ft_ret = ft_strlcat("", "", 0);

    printf("\tstrlcat\n\t-\n\tdst: %s\n\tret: %i\n\n", dst, (int)ret);
    printf("\tft_strlcat\n\t-\n\tdst: %s\n\tret: %i\n", dst2, (int)ft_ret);

    printf("\n\tDone testing\tft_strlcat\n\n");
}

void strlcpy_test(void)
{
    char dst[10];
    dst[0] = 'm';
    dst[1] = 'e';
    dst[2] = 'o';
    dst[3] = 'w';
    dst[4] = '\0';

    char dst2[10];
    dst2[0] = 'm';
    dst2[1] = 'e';
    dst2[2] = 'o';
    dst2[3] = 'w';
    dst2[4] = '\0';

    char *src;
    src = "woof";

    printf("\nLet's test\t\tft_strlcpy\n");

    size_t ret;
    size_t ft_ret;

    ret = strlcpy(dst, src, 3);
    ft_ret = ft_strlcpy(dst2, src, 3);

    printf("\tstrlcpy\n\t-\n\tdst: %s\n\tret: %i\n\n", dst, (int)ret);
    printf("\tft_strlcpy\n\t-\n\tdst: %s\n\tret: %i\n", dst2, (int)ft_ret);

    printf("\n\tDone testing\tft_strlcpy\n\n");
}

void strchr_test(void)
{
    char *str;

    printf("\nLet's test\t\tft_strchr\n");
    str = "abc";
    if (strchr(str, 'a') != ft_strchr(str, 'a'))
        printf("\t❌ 1/4 : Expected %c and got %c\n", *strchr(str, 'a'), *ft_strchr(str, 'a'));

    str = "abc";
    if (strchr(str, 'd') != ft_strchr(str, 'd'))
        printf("\t❌ 2/4 : Expected %c and got %c\n", *strchr(str, 'a'), *ft_strchr(str, 'a'));

    str = "12312";
    if (!!ft_strchr(str, '9'))
        printf("\t❌ 3/4 : Expected null");

    str = "meow";
    if (strchr(str, '\0') != ft_strchr(str, '\0'))
        printf("\t❌ 4/4 : Expected %c and got %c\n", *strchr(str, '\0'), *ft_strchr(str, '\0'));

    printf("\n\tDone testing\tft_strchr\n\n");
}

void strrchr_test(void)
{
    char *str;

    printf("\nLet's test\t\tft_strrchr\n");
    str = "abcax";
    if (*(strrchr(str, 'a') + 1) != *(ft_strrchr(str, 'a') + 1))
        printf("\t❌ 1/4 : Expected %c and got %c\n", *(strrchr(str, 'a') + 1), *(ft_strrchr(str, 'a') + 1));

    str = "     hah123 axklk ";
    if (*(strrchr(str, 'a') + 1) != *(ft_strrchr(str, 'a') + 1))
        printf("\t❌ 2/4 : Expected %c and got %c\n", *(strrchr(str, 'a') + 1), *(ft_strrchr(str, 'a') + 1));

    str = "12312";
    if (!!ft_strrchr(str, '9'))
        printf("\t❌ 3/4 : Expected null");

    str = "meow";
    if (*(strrchr(str, '\0') - 1) != *(ft_strrchr(str, '\0') - 1))
        printf("\t❌ 4/4 : Expected %c and got %c\n", *(strrchr(str, '\0') - 1), *(ft_strrchr(str, '\0') - 1));

    printf("\n\tDone testing\tft_strrchr\n\n");
}

void strnstr_test(void)
{
    printf("\nLet's test\t\tft_strnstr\n");
    if (strnstr("meow meow", "me", 10) != ft_strnstr("meow meow", "me", 10))
        printf("\t❌ 1/8 : Expected %s and got %s\n", strnstr("meow meow", "me", 10), ft_strnstr("meow meow", "me", 10));

    if (strnstr(" meow meow  ", "w", 10) != ft_strnstr(" meow meow  ", "w", 10))
        printf("\t❌ 2/8 : Expected %s and got %s\n", strnstr(" meow meow  ", "w", 10), ft_strnstr(" meow meow  ", "w", 10));

    if (strnstr("meow meow", "abc", 10) != ft_strnstr("meow meow", "abc", 10))
        printf("\t❌ 3/8 : Expected %s and got %s\n", strnstr("meow meow", "abc", 10), ft_strnstr("meow meow", "abc", 10));

    if (strnstr("meow meow", "mex", 10) != ft_strnstr("meow meow", "mex", 10))
        printf("\t❌ 4/8 : Expected %s and got %s\n", strnstr("meow meow", "mex", 10), ft_strnstr("meow meow", "mex", 10));
    
    if (strnstr("meow woof", "woof", 4) != ft_strnstr("meow woof", "woof", 4))
        printf("\t❌ 5/8 : Expected %s and got %s\n", strnstr("meow woof", "woof", 4), ft_strnstr("meow woof", "woof", 4));

    if (strnstr("meow woof", "", 4) != ft_strnstr("meow woof", "", 4))
        printf("\t❌ 6/8 : Expected %s and got %s\n", strnstr("meow woof", "", 4), ft_strnstr("meow woof", "", 4));

    if (strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 9) != ft_strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 9))
        printf("\t❌ 7/8 : Expected %s and got %s\n", strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 9), ft_strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 9));

    if (strnstr("lorem ipsum dolor sit amet", "dolor", 15) != ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15))
        printf("\t❌ 8/8 : Expected %s and got %s\n", strnstr("lorem ipsum dolor sit amet", "dolor", 15), ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));

    printf("\n\tDone testing\tft_strnstr\n\n");
}

void strncmp_test(void)
{
    printf("\nLet's test\t\tft_strncmp\n");
    if (ft_strncmp("meow", "woof", 6) >= 0)
        printf("\t❌ 1/7 : Expected < 0\n");

    if (ft_strncmp("meow", "woof", 0) != 0)
        printf("\t❌ 2/7 : Expected 0\n");

    if (ft_strncmp("meow", "meow", 4) != 0)
        printf("\t❌ 3/7 : Expected 0\n");

    if (ft_strncmp("meow", "me", 6) <= 0)
        printf("\t❌ 4/7 : Expected > 0\n");

    if (ft_strncmp("meow", "ow", 10) >= 0)
        printf("\t❌ 5/7 : Expected < 0\n");

    if (ft_strncmp("meow", "ow", 2) >= 0)
        printf("\t❌ 6/7 : Expected < 0\n");

    if (ft_strncmp("AAAAAAAAA1", "AAAAAAAAA2", 3) != 0)
        printf("\t❌ 7/7 : Expected 0\n");

    printf("\n\tDone testing\tft_strncmp\n\n");
}

void atoi_test(void)
{
    char *str;

    printf("\nLet's test\t\tft_atoi\n");
    str = "123";
    if (atoi(str) != ft_atoi(str))
        printf("\t❌ 1/11 : Expected %d and got %d\n", atoi(str), (int)ft_atoi(str));

    str = "-123";
    if (atoi(str) != ft_atoi(str))
        printf("\t❌ 2/11 : Expected %d and got %d\n", atoi(str), (int)ft_atoi(str));

    str = "   123";
    if (atoi(str) != ft_atoi(str))
        printf("\t❌ 3/11 : Expected %d and got %d\n", atoi(str), (int)ft_atoi(str));

    str = "   +123  s";
    if (atoi(str) != ft_atoi(str))
        printf("\t❌ 4/11 : Expected %d and got %d\n", atoi(str), (int)ft_atoi(str));

    str = "   -123abc";
    if (atoi(str) != ft_atoi(str))
        printf("\t❌ 5/11 : Expected %d and got %d\n", atoi(str), (int)ft_atoi(str));

    str = "  - 123";
    if (atoi(str) != ft_atoi(str))
        printf("\t❌ 6/11 : Expected %d and got %d\n", atoi(str), (int)ft_atoi(str));

    str = "---123";
    if (atoi(str) != ft_atoi(str))
        printf("\t❌ 7/11 : Expected %d and got %d\n", atoi(str), (int)ft_atoi(str));

    str = "-2147483648";
    if (atoi(str) != ft_atoi(str))
        printf("\t❌ 8/11 : Expected %d and got %d\n", atoi(str), (int)ft_atoi(str));

    str = "2147483647";
    if (atoi(str) != ft_atoi(str))
        printf("\t❌ 9/11 : Expected %d and got %d\n", atoi(str), (int)ft_atoi(str));

	printf("%li\n", LONG_MAX);
    str = "-922337203685477580";
    //if (atoi(str) != ft_atoi(str))
        printf("\t❌ 10/11 : Expected %d and got %d\n", atoi(str), (int)ft_atoi(str));

    str = "9999999999999999999";
   // if (atoi(str) != ft_atoi(str))
        printf("\t❌ 11/11 : Expected %d and got %d\n", atoi(str), (int)ft_atoi(str));

        printf("\n\tDone testing\tft_atoi\n\n");
}

void memset_test(void)
{
    char str1[10];
    char str2[10];
    char *ret1;
    char *ret2;
    
    printf("\nLet's test\tmemset\n");

    ret1 = memset(str1, 'a', 5);
    ret2 = ft_memset(str2, 'a', 5);

    printf("\tmemset\n\t-\n\tstr: %s\n\tret: %s\n\n", str1, ret1);
    printf("\tft_memset\n\t-\n\tstr: %s\n\tret: %s\n", str2, ret2);

    printf("\n\tDone testing\tmemset\n\n");
}

void bzero_test(void)
{
    char str1[10];
    char str2[10];
    str1[0] = 'm';
    str1[1] = 'e';
    str1[2] = 'o';
    str1[3] = 'w';
    str1[4] = '\0';

    str2[0] = 'm';
    str2[1] = 'e';
    str2[2] = 'o';
    str2[3] = 'w';
    str2[4] = '\0';

    printf("\nLet's test\tbzero\n");

    bzero(str1, 3);
    ft_bzero(str2, 3);

    printf("\tbzero\n\t-\n\tstr: %s\n\n", str1);
    printf("\tft_bzero\n\t-\n\tstr: %s\n\n", str2);

    printf("\n\tDone testing\tbzero\n\n");
}

void memcpy_test(void)
{
    char dst1[10];
    dst1[0] = 'm';
    dst1[1] = 'e';
    dst1[2] = 'o';
    dst1[3] = 'w';
    dst1[4] = '\0';

    char dst2[10];
    dst2[0] = 'm';
    dst2[1] = 'e';
    dst2[2] = 'o';
    dst2[3] = 'w';
    dst2[4] = '\0';

    char *src = "woof56789";
   

    char *ret1;
    char *ret2;

    printf("\nLet's test\tmemcpy\n");

    ret1 = memcpy(dst1, src, sizeof(char) * 5);
    ret2 = ft_memcpy(dst2, src, sizeof(char) * 5);

    // ret1 = memcpy(dst1, src, sizeof(int) * 5);
    // ret2 = ft_memcpy(dst2, src, sizeof(int) * 5);
    // int src[10] = {8, 3, 11, 61, -22, 7, -6, 2, 13, 47};
    // int dst1[5];
    // int dst2[5];
    // for (int i = 0; i < 5; i++)
    //     printf("dst1[%i] = %i\n", i, dst1[i]);
    // printf("\n");
    // for (int i = 0; i < 5; i++)
    //     printf("dst2[%i] = %i\n", i, dst2[i]);

    printf("\tmemcpy\n\t-\n\tstr: %s\n\tret: %s\n\n", dst1, ret1);
    printf("\tft_memcpy\n\t-\n\tstr: %s\n\tret: %s\n", dst2, ret2);

    printf("\n\tDone testing\tmemcpy\n\n");
}

void memccpy_test(void)
{
    char dst1[10];
    dst1[0] = 'm';
    dst1[1] = 'e';
    dst1[2] = 'o';
    dst1[3] = 'w';
    dst1[4] = '\0';

    char dst2[10];
    dst2[0] = 'm';
    dst2[1] = 'e';
    dst2[2] = 'o';
    dst2[3] = 'w';
    dst2[4] = '\0';

    char *src = "wfof56789";

    char *ret1;
    char *ret2;

    printf("\nLet's test\tmemccpy\n");

    ret1 = memccpy(dst1, src, 'f', 2);
    ret2 = ft_memccpy(dst2, src, 'f', 2);

    printf("\tmemccpy\n\t-\n\tstr: %s\n\tret: %s\n\n", dst1, ret1);
    printf("\tft_memccpy\n\t-\n\tstr: %s\n\tret: %s\n", dst2, ret2);

    printf("\n\tDone testing\tmemccpy\n\n");
}

void memmove_test(void)
{
   
}


void substr_test(void)
{
    printf("\nLet's test\tsubstr\n");

    char *substr;
    char *str = "01234";

    substr = ft_substr(str, 10, 10);

    printf("\tret: %s\n", substr);

    printf("\n\tDone testing\tsubstr\n\n");
}

void strjoin_test(void)
{
    printf("\nLet's test\tstrjoin\n");

    char *new_str;
    char *str1 = "meow";
    char *str2 = "woof";

    new_str = ft_strjoin(str1, str2);

    printf("\tret: %s\n", new_str);

    printf("\n\tDone testing\tstrjoin\n\n");
}


void strtrim_test(void)
{
    printf("\nLet's test\tstrtrim\n");

    char *new_str;
    char *str = "       Xx lorem ipsum dolor sit amet !";
    char *set = " ";

    new_str = ft_strtrim(str, set);
    printf("\tret: %s\n", new_str);

    printf("\n\tDone testing\tstrtrim\n\n");
}

void split_test(void)
{
    printf("\nLet's test\tsplit\n");

    char *str = "meow,woof,,a,grrr,,,,";
    char **list;
    int i;
    i = 0;

    printf("\n%s\n\n", str);
    list = ft_split(str, ',');

    while (i < 5)
    {
        printf("%s\n", list[i]);
        i++;
    }

    printf("\n\tDone testing\tsplit\n\n");
}

void itoa_test(void)
{
    printf("\nLet's test\titoa\n");

    printf("0:\t%s\n", ft_itoa(0));
    printf("5:\t%s\n", ft_itoa(5));
    printf("10:\t%s\n", ft_itoa(10));
    printf("200:\t%s\n", ft_itoa(200));
    printf("2001:\t%s\n", ft_itoa(2001));
    printf("-5:\t%s\n", ft_itoa(-5));
    printf("-500:\t%s\n", ft_itoa(-500));
    printf("-623:\t%s\n", ft_itoa(-623));
    printf("156:\t%s\n", ft_itoa(156));
    printf("-0:\t%s\n", ft_itoa(-0));
    printf("%i:\t%s\n", INT_MIN, ft_itoa(INT_MIN));
    printf("%i:\t%s\n", INT_MAX, ft_itoa(INT_MAX));

    printf("\tDone testing\titoa\n\n");
}


char strmapidemo(unsigned int i, char c)
{
    if (i >= 0)
        return c + 2;
    return c;
}

void strmapi_test(void)
{
    printf("\nLet's test\tstrmapi\n");

    char *str = "abcef";
    char (*fptr)(unsigned int, char);

    fptr = &strmapidemo;

    printf("%s => %s\n", str, ft_strmapi(str, fptr));
    printf("\tDone testing\tstrmapi\n\n");
}

void ft_putchar_fd_test(void)
{
    int fd;

    fd = open("42", O_WRONLY | O_CREAT | S_IRUSR | S_IWUSR);

    if (fd == -1)
    {
        printf("error\n");
        return;
    }
    ft_putchar_fd('c', fd);
}

void ft_putstr_fd_test(void)
{
    int fd;

    fd = open("42", O_WRONLY | O_CREAT | S_IRUSR | S_IWUSR);

    if (fd == -1)
    {
        printf("error\n");
        return;
    }
    // ft_putstr_fd("meow woof", fd);
    // ft_putendl_fd("meow woof", fd);
    ft_putnbr_fd(-1123123123, fd);
}

int main(void)
{
    // tolower_test();
    // toupper_test();
    // isprint_test();
    // isascii_test();
    // isalnum_test();
    // isalpha_test();
    // isdigit_test();
    // strlen_test();
    // strlcat_test();
    // strlcpy_test();
    // strchr_test();
    // strrchr_test();
    // strnstr_test();
    // strncmp_test();
     atoi_test();
    // memset_test();
    // bzero_test();
    // memcpy_test();
    // memccpy_test();
    // memmove_test();
    // substr_test();
    // strjoin_test();
    // strtrim_test();
    // split_test();
    //itoa_test();
    // strmapi_test();
    // ft_putchar_fd_test();
    // ft_putstr_fd_test();
}
