#include "MyString.h"


//http://www.cplusplus.com/reference/cstring/

void* MyString::memcpy(void* destination, const void* source, size_t num)
{
	if ((char*)source + num < destination || (char*)destination + num < source) {
		//��������û���ص� ֱ�Ӹ���
		const char* s = (char*)source;
		char* d = (char*)destination;
		while (num--) {
			*d = *s;
			d++;
			s++;
		}
	}
	else {
		//Ҫд��Ĳ������ص�
		//��Ҫ����д��
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
	while (*source != '\0' && num != 1) {//��һ���ռ��'\0' ͬʱ֧����0ȫ������
		*destinationTemp = *source;
		source++;
		destinationTemp++;
		num--;
	}
	*destinationTemp = '\0';//д��'\0'
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
		//����source�ĳ��� ������'\0'
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
	//���ʲôҲû�ҵ�
	return nullptr;
}

void* MyString::memchr(void* ptr, int value, size_t num) {
	return const_cast<void *>(MyString::memchr(const_cast<const void*>(ptr), value, num));
}

const char* MyString::strchr(const char* str, int character)
{
	char* ptrChar = (char*)str;
	while (*((char*)ptrChar) != '\0') {
		if (*((char*)ptrChar) == character) {
			return ptrChar;
		}
		ptrChar++;
	}
	//���ʲôҲû�ҵ�
	return nullptr;
}

char* MyString::strchr(char* str, int character) {
	return const_cast<char*>(MyString::strchr(const_cast<const char*>(str), character));
}

size_t MyString::strcspn(const char* str1, const char* str2)
{
	size_t scanner = 0;

	for (scanner = 0; str1[scanner] != '\0' ; scanner++)
	{
		for (size_t pointer = 0;  str2[pointer] != '\0'; pointer++)
		{
			if (str2[pointer] == str1[scanner]) {
				return scanner + 1;
			}
		}
	}
	return scanner;
}

const char* MyString::strpbrk(const char* str1, const char* str2)
{
	size_t index = MyString::strcspn(str1, str2);
	if (index == MyString::strlen(str1)) {
		return nullptr;
	}
	else {
		return str1 + index -1;
	}
}

char* MyString::strpbrk(char* str1, const char* str2) {
	return const_cast<char*>(MyString::strpbrk(const_cast<const char*>(str1), str2));
}

const char* MyString::strrchr(const char* str, int character)
{
	size_t length = MyString::strlen(str);
	for (size_t i = length - 1; i >= 0; i--)
	{
		if (str[i] == character) {
			return str + i;
		}
	}
	return nullptr;
}

char* MyString::strrchr(char* str, int character) {
	return const_cast<char*>(MyString::strchr(const_cast<const char*>(str), character));
}

char* strrchr(char* str, int character) {
	return const_cast<char*>(MyString::strrchr(const_cast<const char*>(str), character));
}

size_t MyString::strspn(const char* str1, const char* str2)
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

const char* MyString::strstr(const char* str1, const char* str2)
{
	size_t lengthStr1 = MyString::strlen(str1);
	size_t lengthStr2 = MyString::strlen(str2);
	for (size_t i = 0; i < lengthStr1; i++)
	{
		if (*str2 == str1[i]) {
			//�е�һ���ַ�ƥ���� ����ƥ�����µĲ���
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
					//str2û����͵�ͷ�� ��˵������϶�û��
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

char* MyString::strstr(char* str1, const char* str2) {
	return const_cast<char*>(MyString::strstr(const_cast<const char*>(str1), str2));
}

char* MyString::strtok(char* str, const char* delimiters)
{
	static size_t lengthOfStr = 0;
	static char* savedStr = nullptr;
	if (str != nullptr) {
		size_t lengthOfDelimiters = MyString::strlen(delimiters);
		lengthOfStr = MyString::strlen(str);
		savedStr = str;

		//�����е�delimiters�����'\0'
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
	//��ָ��ָ���Ӧ����'\0'�ĵط�
	while (*savedStr == '\0' && lengthOfStr > 0) {
		lengthOfStr--;
		savedStr++;
	}
	if (lengthOfStr == 0) {
		return nullptr;
	}
	else {
		char* temp = savedStr;
		//����ָ����һ��'\0'
		while (*savedStr != '\0' && lengthOfStr > 0) {
			lengthOfStr--;
			savedStr++;
		}
		return temp;
	}
}

void* MyString::memset(void* ptr, int value, size_t num)
{
	char* ptrChar = (char*)ptr;
	for (; num != 0; num--) {
		*ptrChar = char(value);
		ptrChar++;
	}
	return ptr;
}

size_t MyString::strlen(const char* str)
{
	size_t i = 0;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}
