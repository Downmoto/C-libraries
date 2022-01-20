#include "cstring.h"
#define NULL ((void *)0)

void strCpy(char *des, const char *src)
{
    int i;
    for (i = 0; src[i] != '\0'; ++i)
        des[i] = src[i];
    des[i] = '\0';
}

void strnCpy(char *des, const char *src, unsigned int len)
{
    int i;
    for (i = 0; i < len; ++i)
        des[i] = src[i];
    des[i] = '\0';
}

int strCmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0' && (*s1 - *s2) == 0)
    {s1++; s2++;}

    return (*s1 - *s2);
}

int strnCmp(const char *s1, const char *s2, unsigned int len)
{
    while (*s1 != '\0' && *s2 != '\0' && --len != 0 && (*s1 - *s2) == 0) 
    {s1++; s2++;}

    return (*s1 - *s2);
}

int strLen(const char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; ++i);

    return i;
}

const char *strStr(const char *source, const char *toFind)
{
    int i;
    do
        i = strnCmp(source, toFind, strLen(toFind));
    while (toFind[0] != *source++);

    return (!i) ? --source : NULL;
}

void strCat(char *des, const char *src)
{
    char *i = des + strLen(des);
    for (; (*i = *src); i++, src++);

    *i = '\0';
}