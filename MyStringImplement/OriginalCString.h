#pragma once
/*
implement in:
OriginalCString.cpp
*/
namespace OString {
	//start of cstring.h method
	void* memcpy(void* destination, const void* source, size_t num);
	void* memmove(void* destination, const void* source, size_t num);
	int memcmp(const void* ptr1, const void* ptr2, size_t num);
	const void* memchr(const void* ptr, int value, size_t num);
	void* memchr(void* ptr, int value, size_t num);
	void* memset(void* ptr, int value, size_t num);
	//memory operate


	char* strcpy(char* destination, const char* source);
	char* strncpy(char* destination, const char* source, size_t num);
	char* strncat(char* destination, const char* source, size_t num);
	char* strcat(char* destination, const char* source);
	int strcmp(const char* str1, const char* str2);
	int strncmp(const char* str1, const char* str2, size_t num);
	size_t strxfrm(char* destination, const char* source, size_t num);
	const char* strchr(const char* str, int character);
	char* strchr(char* str, int character);
	size_t strcspn(const char* str1, const char* str2);
	const char* strpbrk(const char* str1, const char* str2);
	char* strpbrk(char* str1, const char* str2);
	const char* strrchr(const char* str, int character);
	char* strrchr(char* str, int character);
	size_t strspn(const char* str1, const char* str2);
	const char* strstr(const char* str1, const char* str2);
	char* strstr(char* str1, const char* str2);
	char* strtok(char* str, const char* delimiters);
	size_t strlen(const char* str);
	//end of cstring.h method
}