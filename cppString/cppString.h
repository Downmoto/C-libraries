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
        
        // = overloads

        String& operator=(const char* str);
        String& operator=(const String& src);

        // [] overload

        const char operator[](unsigned index) const;

        friend std::ostream& operator<<(std::ostream& os, const String& str);
    };
}

#endif