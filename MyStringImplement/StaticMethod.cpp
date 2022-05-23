#include "MyString.h"

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
