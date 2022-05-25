#include "MyString.h"


CharNode* MyString::getCharNodeHead() const
{
	return this->head;
}

void MyString::addCharNode(CharNode* toAdd)
{
	if (this->head == nullptr) {
		this->head = toAdd;
		this->head->setBefore(nullptr);
		this->head->setNext(nullptr);
	}
	else {
		CharNode* item = head;
		while (item->getNext() != nullptr) {
			item = item->getNext();
		}
		//目前item是最后一个
		item->setNext(toAdd);
		toAdd->setBefore(item);
		toAdd->setNext(nullptr);
	}
}

void MyString::deleteAllCharNode()
{
	CharNode* item = this->head;
	if (item == nullptr) {
		return;
	} 
	else {
		while (item->getNext() != nullptr) {
			item = item->getNext();
		}
		//item指向链表的尾
		while (item->getBefore() != nullptr) {
			item = item->getBefore();
			delete item->getNext();
		}
		//item指向链表的head
		delete item;
		this->head = nullptr;
	}
}

void MyString::copyFrom(const MyString& toCopy)
{
	this->deleteAllCharNode();
	CharNode* toCopyItem = toCopy.getCharNodeHead();
	while (toCopyItem != nullptr) {
		//不必在意head为nullptr情况 deleteAllCharNode()已经处理
		this->addCharNode(new CharNode(toCopyItem));
		toCopyItem = toCopyItem->getNext();
	}
	return;
}

size_t MyString::size()
{
	CharNode* item = this->head;
	size_t num = 0;
	while (item != nullptr) {
		item = item->getNext();
		num++;
	}
	return num;
}

size_t MyString::length()
{
	return this->size();
}

size_t MyString::max_size()
{
	//由于使用了链表 因此最大上线应当是内存中可分配的大小
	//此方法对这个类无意义
	return 0;
}

void MyString::resize(size_t n)
{
	this->deleteAllCharNode();
	for (size_t i = 0; i < n; i++)
	{
		this->addCharNode(new CharNode('\0'));
	}
}

void MyString::resize(size_t n, char c)
{
	this->deleteAllCharNode();
	for (size_t i = 0; i < n; i++)
	{
		this->addCharNode(new CharNode(c));
	}
}

void MyString::clear()
{
	this->deleteAllCharNode();
}

bool MyString::empty()
{
	if (this->head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void MyString::shrink_to_fit()
{
	//由于使用的是链表 每次更新的时候就重新分配了大小
	//此方法无意义
	return;
}

char& MyString::at(size_t pos)
{
	CharNode* item = this->getCharNodeHead();
	for (int i = 0; i < pos; i++)
	{
		if (item == nullptr) {
			throw "Out of index";
		}
		item = item->getNext();
	}
	return item->getContent();
}

const char& MyString::at(size_t pos) const
{
	CharNode* item = this->head;
	for (int i = 0; i < pos; i++)
	{
		if (item == nullptr) {
			throw "Out of index";
		}
		item = item->getNext();
	}
	return item->getContent();
}

char& MyString::back()
{
	CharNode* item = this->head;
	if (this->head == nullptr) {
		throw "Empty String";
	}
	else {
		while (item->getNext() != nullptr) {
			item = item->getNext();
		}
		return item->getContent();
	}
}

const char& MyString::back() const
{
	CharNode* item = this->head;
	if (this->head == nullptr) {
		throw "Empty String";
	}
	else {
		while (item->getNext() != nullptr) {
			item = item->getNext();
		}
		return item->getContent();
	}
}

char& MyString::front()
{
	if (this->head == nullptr) {
		throw "Empty String";
	}
	else {
		return this->head->getContent();
	}
}

const char& MyString::front() const
{
	if (this->head == nullptr) {
		throw "Empty String";
	}
	else {
		return this->head->getContent();
	}
}
