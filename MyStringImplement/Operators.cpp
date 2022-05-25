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

const char& MyString::operator[](size_t pos) const
{
	return this->at(pos);
}


char& MyString::operator[](size_t pos)
{
	return this->at(pos);
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
