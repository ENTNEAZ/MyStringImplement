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

size_t MyString::rfind(const MyString& str, size_t pos) const
{
	const char* tempStr = str.c_str();
	size_t temp = this->rfind(tempStr, pos);
	delete[] tempStr;
	return temp;
}

size_t MyString::rfind(const char* s, size_t pos) const
{
	const char* cstr = this->c_str();
	if (pos > this->length() - 1) {
		pos = this->length() - 1;
	}
	size_t lengthS = OString::strlen(s);
	for (size_t i = pos + 1; i > 0; i--)
	{
		if (*s == cstr[i - 1]) {
			//匹配到一个相同的字符
			bool isSuccess = true;
			for (size_t j = 0; j < lengthS; j++)
			{
				if (cstr[i + j - 1] == '\0' || cstr[i + j - 1] != s[j]) {
					isSuccess = false;
					break;
				}
			}

			if (isSuccess) {
				return i - 1;
			}
		}
	}

	//整个过程都没找到
	return -1;
}

size_t MyString::rfind(const char* s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return this->rfind(temp, pos);
}

size_t MyString::rfind(char c, size_t pos) const
{
	MyString temp(c, 1);
	return this->rfind(temp, pos);
}

size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	const char* strChar = str.c_str();
	size_t temp = this->find_first_of(strChar, pos);
	delete[] strChar;
	return temp;
}

size_t MyString::find_first_of(const char* s, size_t pos) const
{
	size_t lengthOfThis = this->length();
	size_t lengthOfS = OString::strlen(s);
	for (size_t i = pos; i < lengthOfThis; i++)
	{
		for (size_t j = 0; j < lengthOfS; j++)
		{
			if ((*this)[i] == s[j]) {
				return i;
			}
		}
	}

	return -1;
}

size_t MyString::find_first_of(const char* s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return this->find_first_of(temp, pos);
}

size_t MyString::find_first_of(char c, size_t pos) const
{
	MyString temp(c, 1);
	return this->find_first_of(temp, pos);
}

size_t MyString::find_last_of(const MyString& str, size_t pos) const
{
	const char* strChar = str.c_str();
	size_t temp = this->find_last_of(strChar, pos);
	delete[] strChar;
	return temp;
}

size_t MyString::find_last_of(const char* s, size_t pos) const
{
	size_t lengthOfS = OString::strlen(s);
	if (pos > this->length() - 1) {
		pos = this->length() - 1;
	}
	for (size_t i = pos + 1; i > 0; i--)
	{
		for (size_t j = 0; j < lengthOfS; j++)
		{
			if ((*this)[i - 1] == s[j]) {
				return i - 1;
			}
		}
	}

	return -1;
}

size_t MyString::find_last_of(const char* s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return this->find_last_of(temp, pos);
}

size_t MyString::find_last_of(char c, size_t pos) const
{
	MyString temp(c, 1);
	return this->find_last_of(temp, pos);
}

size_t MyString::find_first_not_of(const MyString& str, size_t pos) const
{
	const char* strChar = str.c_str();
	size_t temp = this->find_first_not_of(strChar, pos);
	delete[] strChar;
	return temp;
}

size_t MyString::find_first_not_of(const char* s, size_t pos) const
{
	size_t lengthOfThis = this->length();
	size_t lengthOfS = OString::strlen(s);
	for (size_t i = pos; i < lengthOfThis; i++)
	{
		for (size_t j = 0; j < lengthOfS; j++)
		{
			if ((*this)[i] != s[j]) {
				return i;
			}
		}
	}

	return -1;
}

size_t MyString::find_first_not_of(const char* s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return this->find_first_not_of(temp, pos);
}

size_t MyString::find_first_not_of(char c, size_t pos) const
{
	MyString temp(c, 1);
	return this->find_first_not_of(temp, pos);
}

size_t MyString::find_last_not_of(const MyString& str, size_t pos) const
{
	const char* strChar = str.c_str();
	size_t temp = this->find_last_not_of(strChar, pos);
	delete[] strChar;
	return temp;
}

size_t MyString::find_last_not_of(const char* s, size_t pos) const
{
	size_t lengthOfS = OString::strlen(s);
	if (pos > this->length() - 1) {
		pos = this->length() - 1;
	}
	for (size_t i = pos + 1; i > 0; i--)
	{
		for (size_t j = 0; j < lengthOfS; j++)
		{
			if ((*this)[i - 1] != s[j]) {
				return i - 1;
			}
		}
	}

	return -1;
}

size_t MyString::find_last_not_of(const char* s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return this->find_last_not_of(temp, pos);
}

size_t MyString::find_last_not_of(char c, size_t pos) const
{
	MyString temp(c, 1);
	return this->find_last_not_of(temp, pos);
}

MyString MyString::substr(size_t pos, size_t len) const
{
	const char* thisStr = this->c_str();
	if (pos + len > this->length()) {
		len = this->length() - pos;
	}
	MyString temp(&thisStr[pos], len);
	delete[] thisStr;
	return temp;
}

