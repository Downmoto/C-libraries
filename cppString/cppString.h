#ifndef SHACO_STRING_H_
#define SHACO_STRING_H_

namespace shaco
{
    class String
    {
        char* m_str;
        int m_len;

        void cStrCpy(char* des, const char* src);
        int cStrLen(const char* src);

        public:
        // basic constructors and destructor declaration
        
        String();
        String(const char* str);
        String(const String& src);
        ~String();
        
        // = overload

        String& operator=(const char* str);
        String& operator=(const String& src);

        // [] overloads to find data in string

        const char operator[](int index) const;
        int operator[](const String& src) const;
        int operator[](const char* src) const;

    };
}

#endif