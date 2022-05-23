#include "MyString.h"

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
	while (*source != '\0' && num != 0) {
		*destinationTemp = *source;
		source++;
		destinationTemp++;
		num--;
	}
	*destinationTemp = '\0';//д��'\0'
	return destination;
}
