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

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	if (&lhs == &rhs) {
		//自己加自己会导致死循环
		MyString a = rhs;
		return lhs + a;
	}
	else {
		MyString copy = lhs;
		CharNode* item = rhs.getCharNodeHead();
		while (item != nullptr) {
			copy.addCharNode(new CharNode(item->getContent()));
			item = item->getNext();
		}
		return copy;
	}
}

MyString operator+(const MyString& lhs, const char* rhs)
{
	MyString copy = lhs;
	size_t length = OString::strlen(rhs);
	for (size_t i = 0; i < length; i++)
	{
		copy.addCharNode(new CharNode(rhs[i]));
	}
	return copy;
}

MyString operator+(const char* lhs, const MyString& rhs)
{
	MyString temp(lhs);
	return temp + rhs;
}

MyString operator+(const MyString& lhs, const char rhs)
{
	MyString temp(lhs);
	temp.addCharNode(new CharNode(rhs));
	return temp;
}

MyString operator+(const char lhs, const MyString& rhs)
{
	MyString temp;
	temp = lhs;
	return temp + rhs;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return (lhs.compare(rhs) == 0) ? true : false;
}

bool operator==(const char* lhs, const MyString& rhs)
{
	return (rhs.compare(lhs) == 0) ? true : false;
}

bool operator==(const MyString& lhs, const char* rhs)
{
	return (lhs.compare(rhs) == 0) ? true : false;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}

bool operator!=(const char* lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}

bool operator!=(const MyString& lhs, const char* rhs)
{
	return !(lhs == rhs);
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return (lhs.compare(rhs) < 0) ? true : false;
}

bool operator<(const char* lhs, const MyString& rhs)
{
	return (rhs.compare(lhs) > 0) ? true : false;
}

bool operator<(const MyString& lhs, const char* rhs)
{
	return (lhs.compare(rhs) < 0) ? true : false;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return lhs < rhs || lhs == rhs;
}

bool operator<=(const char* lhs, const MyString& rhs)
{
	return lhs < rhs || lhs == rhs;
}

bool operator<=(const MyString& lhs, const char* rhs)
{
	return lhs < rhs || lhs == rhs;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return rhs < lhs;
}

bool operator>(const char* lhs, const MyString& rhs)
{
	return rhs < lhs;
}

bool operator>(const MyString& lhs, const char* rhs)
{
	return rhs < lhs;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return rhs <= lhs;
}

bool operator>=(const char* lhs, const MyString& rhs)
{
	return rhs <= lhs;
}

bool operator>=(const MyString& lhs, const char* rhs)
{
	return rhs <= lhs;
}
