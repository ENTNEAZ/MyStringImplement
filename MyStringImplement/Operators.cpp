#include "MyString.h"
#include "CharNode.h"
#include <iostream>

void MyString::operator=(const char* s)
{
	this->deleteAllCharNode();
	size_t lengthOfS = MyString::strlen(s);
	for (size_t i = 0; i < lengthOfS; i++)
	{
		this->addCharNode(new CharNode(s[i]));
	}
}
char MyString::operator[](int index)
{
	CharNode* item = this->getCharNodeHead();
	for (int i = 0; i < index; i++)
	{
		if (item == nullptr) {
			return '\0';
		}
		item = item->getNext();
	}
	return item->getContent();
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
