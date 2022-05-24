#include "MyString.h"
#include "CharNode.h"

MyString::MyString()
{
	this->head = new CharNode(nullptr, nullptr, '\0');
}