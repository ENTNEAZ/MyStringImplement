#include "MyString.h"


//http://www.cplusplus.com/reference/cstring/

void* MyString::memcpy(void* destination, const void* source, size_t num)
{
	if ((char*)source + num < destination || (char*)destination + num < source) {
		//两个区域没有重叠 直接覆盖
		const char* s = (char*)source;
		char* d = (char*)destination;
		while (num--) {
			*d = *s;
			d++;
			s++;
		}
	}
	else {
		//要写入的部分有重叠
		//需要倒着写入
		char* d = (char*)((char*)destination + num - 1); /* offset of pointer is from 0 */
		const char* s = (char*)((char*)source + num - 1);
		while (num--){
			*d-- = *s--;
		}

	}
	return destination;
}

void* MyString::memmove(void* destination, const void* source, size_t num)
{
	MyString::memcpy(destination, source, num);
	return destination;
}

char* MyString::strcpy(char* destination, const char* source)
{
	MyString::strncpy(destination, source, 0);
	return destination;
}

char* MyString::strncpy(char* destination, const char* source, size_t num)
{
	char* destinationTemp = destination;
	while (*source != '\0' && num != 1) {//留一个空间给'\0' 同时支持填0全部复制
		*destinationTemp = *source;
		source++;
		destinationTemp++;
		num--;
	}
	*destinationTemp = '\0';//写入'\0'
	return destination;
}

char* MyString::strncat(char* destination, const char* source, size_t num)
{
	char* endOfDestination = destination;
	while (*endOfDestination != '\0') {
		endOfDestination++;
	}
	MyString::strncpy(endOfDestination,source,num);
	return destination;
}

char* MyString::strcat(char* destination, const char* source)
{
	MyString::strncpy(destination, source, 0);
	return destination;
}

int MyString::memcmp(const void* ptr1, const void* ptr2, size_t num)
{
	char* cPtr1 = (char*)ptr1;
	char* cPtr2 = (char*)ptr2;
	while (num-- != 0) {
		if (*cPtr1 != *cPtr2) {
			break;
		}
		else {
			cPtr1++;
			cPtr2++;
		}
	}
	return *cPtr1 - *cPtr2;
}

int MyString::strcmp(const char* str1, const char* str2)
{
	return MyString::strncmp(str1, str2, 0);
}

int MyString::strncmp(const char* str1, const char* str2, size_t num)
{
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0' && num != 1) {
		str1++;
		str2++;
		num--;
	}
	return *str1 - *str2;
}

size_t MyString::strxfrm(char* destination, const char* source, size_t num)
{
	if (num != 0 && destination != nullptr) {
		MyString::strncpy(destination, source, num);
		return num;
	}
	else {
		//返回source的长度 不包括'\0'
		size_t size = 0;
		while (*source != '\0') {
			size++;
			source++;
		}
		return size;
	}
}

const void* MyString::memchr(const void* ptr, int value, size_t num)
{
	char* ptrChar = (char*)ptr;
	while (*((char*)ptrChar) != '\0' && num != 0) {
		if (*((char*)ptrChar) == value) {
			return (void*)ptrChar;
		}
		ptrChar++;
	}
	//如果什么也没找到
	return nullptr;
}

void* MyString::memchr(void* ptr, int value, size_t num) {
	return const_cast<void *>(MyString::memchr(const_cast<const void*>(ptr), value, num));
}