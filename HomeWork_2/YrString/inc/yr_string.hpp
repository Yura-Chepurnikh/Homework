#pragma once

#include <iostream>
#include <initializer_list>
#include <ostream>

class YrString {
public:
    YrString();
    YrString(const YrString& other);
    YrString(YrString&& other) noexcept;
    YrString(const char* str);
    YrString(const char* str, size_t n);
    YrString(size_t n, char character) noexcept;
    YrString(const char* startOfRange, const char* endOfRange);
    YrString(std::initializer_list<char> list);
    YrString(std::initializer_list<char> list, size_t pos, size_t len = std::string::npos);
    // !!! I ALSO HAVE TO WRITE AN ALLOCATOR !!!
    ~YrString();

    size_t Size();
    bool IsEmpty();

    char Front();
    char Back();

    void Append(const char* str);
    void Insert(size_t pos, const char* str);
    void Erase(size_t startPos, size_t len);
    void Replace(size_t startPos, size_t len, const char* str);
    void Clear();

    YrString operator+(const YrString& other);
    bool operator==(const YrString& other);
    friend std::ostream& operator<<(std::ostream& stream, const YrString& obj);

    void Display();
private:
    size_t length;
    char* strPtr;
};