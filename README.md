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

```C
void strCpy(char *des, const char *src)
{
    int i;
    for (i = 0; src[i] != '\0'; ++i)
        des[i] = src[i];
    des[i] = '\0';
}
```

## C++ String
My own implementation of the C++ string library.

```C++
String&
String::operator=(const char* str)
{
    if (m_str) delete [] m_str;

    m_len = cStrLen(str);
    m_str = new char[m_len + 1];

    cStrCpy(m_str, str);
}
```
