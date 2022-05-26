#include "MyString.h"
#include "CharNode.h"
#include "OriginalCString.h"
#include <iostream>

void MyString::operator=(const char* s)
{
	this->deleteAllCharNode();
	size_t lengthOfS = OString::strlen(s);
	for (size_t i = 0; i < lengthOfS; i++)
	{
		this->addCharNode(new CharNode(s[i]));
	}
}

void MyString::operator=(char s)
{
	this->deleteAllCharNode();
	this->addCharNode(new CharNode(s));
}

void MyString::operator=(const MyString s)
{
	this->copyFrom(s);
}

const char& MyString::operator[](size_t pos) const
{
	return this->at(pos);
}


char& MyString::operator[](size_t pos)
{
	return this->at(pos);
}

MyString MyString::operator+(const MyString& str)
{
	if (this == &str) {
		//自己加自己会导致死循环
		MyString a = str;
		return *this + a;
	}
	else {
		MyString copy = *this;
		CharNode* item = str.getCharNodeHead();
		while (item != nullptr) {
			copy.addCharNode(new CharNode(item->getContent()));
			item = item->getNext();
		}
		return copy;
	}
}

MyString MyString::operator+(const char* s)
{
	MyString copy = *this;
	size_t length = OString::strlen(s);
	for (size_t i = 0; i < length; i++)
	{
		copy.addCharNode(new CharNode(s[i]));
	}
	return copy;
}

MyString MyString::operator+(char c)
{
	MyString copy = *this;
	copy.addCharNode(new CharNode(c));
	return copy;
}

MyString& MyString::operator+=(const MyString& str)
{
	*this = *this + str;
	return *this;
}

MyString& MyString::operator+=(const char* s)
{
	*this = *this + s;
	return *this;
}

MyString& MyString::operator+=(char c)
{
	*this = *this + c;
	return *this;
}


std::ostream& operator<<(std::ostream& out, MyString str)
{
	CharNode* item = str.getCharNodeHead();
	while (item != nullptr) {
		out << item->getContent();
		item = item->getNext();
	}
	return out;
}
