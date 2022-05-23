#pragma once
#ifndef MyString

class MyString {
public:
	static void* memcpy(void* destination, const void* source, size_t num);
	static void* memmove(void* destination, const void* source, size_t num);
	static char* strcpy(char* destination, const char* source);
	static char* strncpy(char* destination, const char* source, size_t num);
};

#endif // !MyString
