#include "MyString.h"
#include "OriginalCString.h"

//http://www.cplusplus.com/reference/string/string/
const char* MyString::c_str() const
{
	size_t length = this->length();
	char* c = new char[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		c[i] = (*this)[i];
	}
	c[length] = '\0';
	return c;
}

const char* MyString::data() const
{
	return this->c_str();
}

size_t MyString::find(const MyString& str, size_t pos) const
{
	return this->find(str.c_str(), pos);
}

size_t MyString::find(const char* s, size_t pos) const
{
	const char* thisChar = this->c_str();
	const char* retPointer = OString::strstr(thisChar + pos, s);
	if (retPointer == nullptr) {
		return -1;
	}
	return retPointer - thisChar;
	//TODO: 可能有内存溢出风险
}

size_t MyString::find(const char* s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return this->find(temp, pos);
}

size_t MyString::find(char c, size_t pos) const
{
	MyString temp;
	temp = c;
	return this->find(temp, pos);
}

