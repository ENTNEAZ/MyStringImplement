#pragma once
#ifndef MyString

class MyString {
public:
	static void* memcpy(void* destination, const void* source, size_t num);
	static void* memmove(void* destination, const void* source, size_t num);
	static char* strcpy(char* destination, const char* source);
	static char* strncpy(char* destination, const char* source, size_t num);
	static char* strncat(char* destination, const char* source, size_t num);
	static char* strcat(char* destination, const char* source);
	static int memcmp(const void* ptr1, const void* ptr2, size_t num);
	static int strcmp(const char* str1, const char* str2);
	static int strncmp(const char* str1, const char* str2, size_t num);
	static size_t strxfrm(char* destination, const char* source, size_t num);
	static const void* memchr(const void* ptr, int value, size_t num);
	static void* memchr(void* ptr, int value, size_t num);
};

#endif // !MyString
