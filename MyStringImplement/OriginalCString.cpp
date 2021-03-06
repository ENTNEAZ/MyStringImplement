#include "OriginalCString.h"

//http://www.cplusplus.com/reference/cstring/
using namespace OString;

void* OString::memcpy(void* destination, const void* source, size_t num)
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
		while (num--) {
			*d-- = *s--;
		}

	}
	return destination;
}

void* OString::memmove(void* destination, const void* source, size_t num)
{
	OString::memcpy(destination, source, num);
	return destination;
}

char* OString::strcpy(char* destination, const char* source)
{
	OString::strncpy(destination, source, 0);
	return destination;
}

char* OString::strncpy(char* destination, const char* source, size_t num)
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

char* OString::strncat(char* destination, const char* source, size_t num)
{
	char* endOfDestination = destination;
	while (*endOfDestination != '\0') {
		endOfDestination++;
	}
	OString::strncpy(endOfDestination, source, num);
	return destination;
}

char* OString::strcat(char* destination, const char* source)
{
	OString::strncpy(destination, source, 0);
	return destination;
}

int OString::memcmp(const void* ptr1, const void* ptr2, size_t num)
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

int OString::strcmp(const char* str1, const char* str2)
{
	return OString::strncmp(str1, str2, 0);
}

int OString::strncmp(const char* str1, const char* str2, size_t num)
{
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0' && num != 1) {
		str1++;
		str2++;
		num--;
	}
	return *str1 - *str2;
}

size_t OString::strxfrm(char* destination, const char* source, size_t num)
{
	if (num != 0 && destination != nullptr) {
		OString::strncpy(destination, source, num);
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

const void* OString::memchr(const void* ptr, int value, size_t num)
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

void* OString::memchr(void* ptr, int value, size_t num) {
	return const_cast<void*>(OString::memchr(const_cast<const void*>(ptr), value, num));
}

const char* OString::strchr(const char* str, int character)
{
	char* ptrChar = (char*)str;
	while (*((char*)ptrChar) != '\0') {
		if (*((char*)ptrChar) == character) {
			return ptrChar;
		}
		ptrChar++;
	}
	//如果什么也没找到
	return nullptr;
}

char* OString::strchr(char* str, int character) {
	return const_cast<char*>(OString::strchr(const_cast<const char*>(str), character));
}

size_t OString::strcspn(const char* str1, const char* str2)
{
	size_t scanner = 0;

	for (scanner = 0; str1[scanner] != '\0'; scanner++)
	{
		for (size_t pointer = 0; str2[pointer] != '\0'; pointer++)
		{
			if (str2[pointer] == str1[scanner]) {
				return scanner + 1;
			}
		}
	}
	return scanner;
}

const char* OString::strpbrk(const char* str1, const char* str2)
{
	size_t index = OString::strcspn(str1, str2);
	if (index == OString::strlen(str1)) {
		return nullptr;
	}
	else {
		return str1 + index - 1;
	}
}

char* OString::strpbrk(char* str1, const char* str2) {
	return const_cast<char*>(OString::strpbrk(const_cast<const char*>(str1), str2));
}

const char* OString::strrchr(const char* str, int character)
{
	size_t length = OString::strlen(str);
	for (size_t i = length; i > 0; i--)
	{
		if (str[i - 1] == character) {
			return str + i - 1;
		}
	}
	return nullptr;
}

char* OString::strrchr(char* str, int character) {
	char* ptrChar = (char*)str;
	char* ret = nullptr;
	while (*((char*)ptrChar) != '\0') {
		if (*((char*)ptrChar) == character) {
			ret = ptrChar;
		}
		ptrChar++;
	}
	return ret;
}

size_t OString::strspn(const char* str1, const char* str2)
{
	size_t number = 0;

	for (size_t scanner = 0; str1[scanner] != '\0'; scanner++)
	{
		for (size_t pointer = 0; str2[pointer] != '\0'; pointer++)
		{
			if (str2[pointer] == str1[scanner]) {
				number++;
				break;
			}
		}
	}
	return number;
}

const char* OString::strstr(const char* str1, const char* str2)
{
	size_t lengthStr1 = OString::strlen(str1);
	size_t lengthStr2 = OString::strlen(str2);
	for (size_t i = 0; i < lengthStr1; i++)
	{
		if (*str2 == str1[i]) {
			//有第一个字符匹配了 尝试匹配余下的部分
			bool isSuccess = true;
			for (size_t j = 0; j < lengthStr2; j++)
			{
				if (str2[j] == str1[i + j]) {
					continue;
				}
				else {
					isSuccess = false;
					break;
				}
				if (str1[i + j] == '\0') {
					//str2没读完就到头了 那说明后面肯定没了
					return nullptr;
				}
			}
			if (isSuccess) {
				return str1 + i;
			}
		}
	}
	return nullptr;
}

char* OString::strstr(char* str1, const char* str2) {
	return const_cast<char*>(OString::strstr(const_cast<const char*>(str1), str2));
}

char* OString::strtok(char* str, const char* delimiters)
{
	static size_t lengthOfStr = 0;
	static char* savedStr = nullptr;
	if (str != nullptr) {
		size_t lengthOfDelimiters = OString::strlen(delimiters);
		lengthOfStr = OString::strlen(str);
		savedStr = str;

		//将所有的delimiters都变成'\0'
		for (size_t i = 0; i < lengthOfStr; i++)
		{
			for (size_t j = 0; j < lengthOfDelimiters; j++)
			{
				if (str[i] == delimiters[j]) {
					str[i] = '\0';
					break;
				}
			}
		}
	}
	//将指针指向对应不是'\0'的地方
	while (*savedStr == '\0' && lengthOfStr > 0) {
		lengthOfStr--;
		savedStr++;
	}
	if (lengthOfStr == 0) {
		return nullptr;
	}
	else {
		char* temp = savedStr;
		//调整指向下一个'\0'
		while (*savedStr != '\0' && lengthOfStr > 0) {
			lengthOfStr--;
			savedStr++;
		}
		return temp;
	}
}

void* OString::memset(void* ptr, int value, size_t num)
{
	char* ptrChar = (char*)ptr;
	for (; num != 0; num--) {
		*ptrChar = char(value);
		ptrChar++;
	}
	return ptr;
}

size_t OString::strlen(const char* str)
{
	size_t i = 0;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}
