#include "MyString.h"
#include "CharNode.h"

MyString::MyString()
{
	this->head = nullptr;
}

MyString::MyString(MyString& toCopy)
{
	this->head = nullptr;
	this->copyFrom(toCopy);
}

MyString::MyString(const char* s)
{
	size_t lengthOfS = MyString::strlen(s);
	for (size_t i = 0; i < lengthOfS; i++)
	{
		this->addCharNode(new CharNode(s[i]));
	}
}

