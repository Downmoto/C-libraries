# C-libraries
## C strings
My own implementations of commonly used cstring functions.

 - strCpy
 - strnCpy
 - strCmp
 - strnCmp
 - strLen
 - strStr
 - strCat

```
void strCpy(char *des, const char *src)
{
    int i;
    for (i = 0; src[i] != '\0'; ++i)
        des[i] = src[i];
    des[i] = '\0';
}
```
