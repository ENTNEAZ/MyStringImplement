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

MyString& MyString::operator+(const MyString& str)
{
	if (this == &str) {
		//自己加自己会导致死循环
		MyString a = str;
		return *this + a;
	}
	else {
		CharNode* item = str.getCharNodeHead();
		while (item != nullptr) {
			this->addCharNode(new CharNode(item->getContent()));
			item = item->getNext();
		}
		return *this;
	}
}

MyString& MyString::operator+(const char* s)
{
	size_t length = OString::strlen(s);
	for (size_t i = 0; i < length; i++)
	{
		this->addCharNode(new CharNode(s[i]));
	}
	return *this;
}

MyString& MyString::operator+(char c)
{
	this->addCharNode(new CharNode(c));
	return *this;
}

MyString& MyString::operator+=(const MyString& str)
{
	return *this + str;
}

MyString& MyString::operator+=(const char* s)
{
	return *this + s;
}

MyString& MyString::operator+=(char c)
{
	return *this + c;
}


std::ostream& operator<<(std::ostream& out, MyString& str)
{
	CharNode* item = str.getCharNodeHead();
	while (item != nullptr) {
		out << item->getContent();
		item = item->getNext();
	}
	return out;
}
