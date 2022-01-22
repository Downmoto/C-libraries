#ifndef SHACO_STRING_H_
#define SHACO_STRING_H_

#include <iostream>

namespace shaco
{
    class String
    {        
        char* m_str;
        unsigned m_len;

        void cStrCpy(char* des, const char* src);
        unsigned cStrLen(const char* src);

    public:
        // basic constructors and destructor declaration
        
        String();
        String(const char* str);
        String(const String& src);
        ~String();

        // Capacity
        unsigned length() const;
        void clear();
        bool empty() const;
        
        // = overloads

        String& operator=(const char* str);
        String& operator=(const String& src);
        String& operator=(char c);

        // Element access

        const char* operator[](unsigned index) const;
        const char* at(unsigned index) const;
        const char* back() const;
        const char* front() const;

        // String operations
        unsigned find(const char* str, unsigned npos = 0);
        unsigned find(const String& src, unsigned npos = 0);
        unsigned find(char c, unsigned npos = 0);

        unsigned rfind(const char *str, unsigned npos = 0);
        unsigned rfind(const String &src, unsigned npos = 0);
        unsigned rfind(char c, unsigned npos = 0);

        String substr(unsigned start, unsigned end);

        friend std::ostream& operator<<(std::ostream& os, const String& str);
    };
}

#endif