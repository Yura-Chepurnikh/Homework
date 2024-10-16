#include "../inc/yr_string.hpp"
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <stdexcept>

YrString::YrString() : strPtr(nullptr), length(0) { }

YrString::YrString(const YrString& other) : length(other.length) {
    strPtr = new char[length + 1];
    for (size_t i = 0; i < length; ++i) {
        strPtr[i] = other.strPtr[i];
    }
    strPtr[length] = '\0';
}

YrString::YrString(YrString&& other) noexcept : strPtr(other.strPtr), length(other.length) {
    other.strPtr = nullptr;
    other.length = 0;
}

YrString::YrString(const char* chars) { 
    if (chars == nullptr) {
        throw std::invalid_argument("Null pointer!!!");
    }

    int length = 0;
    const char* temp = chars;
    while (*temp != '\0') {
        length++; 
        temp++;
    }

    strPtr = new char[length + 1];
    for (size_t i = 0; i < length; ++i) {
        strPtr[i] = chars[i];
    }
    strPtr[length] = '\0';
} 

YrString::YrString(const char* character, size_t n) : length(n) {
    if (character == nullptr) {
        throw std::invalid_argument("Null pointer!!!");
    }
    strPtr = new char[length + 1];
    for (size_t i = 0; i < n; ++i) {
        strPtr[i] = character[i];
    }
    strPtr[length] = '\0';
}

YrString::YrString(const char* startOfRange, const char* endOfRange) {
    if (startOfRange == nullptr || endOfRange == nullptr ||
        startOfRange >= endOfRange) {
        throw std::invalid_argument("Invalid range!!!");
    }

    length = endOfRange - startOfRange;
    strPtr = new char[length + 1];

    for (size_t i = 0; i < length; ++i) {
        strPtr[i] = startOfRange[i];
    }
    strPtr[length] = '\0';
}

YrString::YrString(std::initializer_list<char> list) : length(list.size()) {
    strPtr = new char[length + 1];
    size_t k = 0;
    for (char item : list) {
        strPtr[k++] = item;
    }
    strPtr[length] = '\0';
}

YrString::YrString(std::initializer_list<char> list, size_t pos, size_t len) {
    const char* ptr = list.begin();
    length = (pos + len > list.size()) ?
        list.size() - pos : len;
    strPtr = new char[length + 1];
    for (size_t i = 0; i < length; ++i) {
        strPtr[i] = ptr[pos + i];
    }
    strPtr[length] = '\0';
}

void YrString::Display() {
    if (strPtr) {
        std::cout << "String: " << strPtr << std::endl;
    } else {
        std::cout << "String is null !" << std::endl;
    }
}

YrString::~YrString() {
    delete[] strPtr;
}

size_t YrString::Size() {
    return length;
}

bool YrString::IsEmpty() {
    return !strPtr ? true : false;
}

char YrString::Front() {
    return strPtr[0];
}

char YrString::Back() {
    return strPtr[Size() - 1];
}

YrString YrString::operator+(const YrString &other) {
    char* concatenate = new char[length + other.length + 1];
    char* ptr = concatenate;

    for (size_t i = 0; i < length; ++i) {
        *ptr++ = strPtr[i];
    }

    for (size_t i = 0; i < length; ++i) {
        *ptr++ = other.strPtr[i];
    }

    *ptr = '\0';

    return YrString(concatenate);
}

bool YrString::operator==(const YrString &other) {
    return strPtr == other.strPtr ? true : false;
}

std::ostream& operator<<(std::ostream& stream, const YrString& obj) {
    if (obj.strPtr) {
        stream << obj.strPtr;
    } else {
        stream << "null";
    }
    return stream;
}

std::ostream& operator<<(std::ostream& stream, int builtInType) {
    stream << static_cast<double>(builtInType);
    return stream;
}

int main() {
    const char* arr = "Hello, World !!!";
    const char* arr1 = &arr[0];
    const char* arr2 = &arr[3];
    /* !!! WHY  YrString yrString('a', 6); DON'T WORK !!! */
    YrString yrString(arr1, arr2);

    YrString other = yrString;

    other.Display();
    yrString.Display();


    YrString obj({'a', 'b', 'c', 'd', 'e'});
    obj.Display();

    YrString obj2({'a', 'b', 'c', 'd', 'e'}, 1, 3);
    obj2.Display();

    std::cout << obj.Size() << std::endl;
    std::cout << obj.IsEmpty() << std::endl;

    std::cout << obj.Front() << std::endl;
    std::cout << obj.Back() << std::endl;


    std::cout << obj + obj << std::endl;
    
    std::cout << (obj == obj2);


    return 0;
}  