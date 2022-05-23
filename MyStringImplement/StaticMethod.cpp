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
