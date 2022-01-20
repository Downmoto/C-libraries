#include "cppString.h"

namespace shaco
{
    void 
    String::cStrCpy(char *des, const char *src)
    {
        int i;
        for (i = 0; src[i] != '\0'; ++i)
            des[i] = src[i];
    }

    int
    String::cStrLen(const char* src)
    {
        int len;
        for (len = 0; src[len] != '\0'; ++len);
        return len;
    }

    String::String()
    {
        m_str = nullptr;
        m_len = 0;
    }

    String::~String()
    {
        delete [] m_str;
    }

    String::String(const char* str)
    {
        m_len = cStrLen(str);
        m_str = new char[m_len + 1];

        cStrCpy(m_str, str);
    }

    String::String(const String& src)
    {
        m_len = src.m_len;
        m_str = new char[m_len + 1];

        cStrCpy(m_str, src.m_str);
    }


    String&
    String::operator=(const char* str)
    {
        if (m_str) delete [] m_str;

        m_len = cStrLen(str);
        m_str = new char[m_len + 1];

        cStrCpy(m_str, str);
    }

    String&
    String::operator=(const String& src)
    {
        if (m_str) delete [] m_str;

        m_len = src.m_len;
        m_str = new char[m_len + 1];
        
        cStrCpy(m_str, src.m_str);
    }

    const char
    String::operator[](int index) const
    {
        if (!m_str) 
            throw "Uninitialized String";
        
        if (index >= m_len)
            throw "Index out of bounds";
            
        return m_str[index];
    }

    int
    String::operator[](const String& src) const
    {

    }
}