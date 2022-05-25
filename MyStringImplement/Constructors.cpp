#include "MyString.h"
#include "CharNode.h"
#include "OriginalCString.h"


//http://www.cplusplus.com/reference/string/string/string/
MyString::MyString()
{
	this->head = nullptr;
}

MyString::MyString(const MyString& toCopy)
{
	this->head = nullptr;
	this->copyFrom(toCopy);
}

MyString::MyString(const MyString& str, size_t pos, size_t len)
{
	MyString temp;
	temp.copyFrom(str);
	this->head = nullptr;
	for (size_t i = 0; i < len; i++)
	{
		this->addCharNode(new CharNode(temp[1]));
	}
	
}

MyString::MyString(const char* s)
{
	this->head = nullptr;
	size_t lengthOfS = OString::strlen(s);
	for (size_t i = 0; i < lengthOfS; i++)
	{
		this->addCharNode(new CharNode(s[i]));
	}
}

MyString::MyString(const char* s, size_t num)
{
	this->head = nullptr;
	for (size_t i = 0; i < num; i++)
	{
		this->addCharNode(new CharNode(s[i]));
	}
}

MyString::MyString(char s, size_t num)
{
	this->head = nullptr;
	for (size_t i = 0; i < num; i++)
	{
		this->addCharNode(new CharNode(s));
	}
}

