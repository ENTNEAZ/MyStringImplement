#include "MyString.h"

//http://www.cplusplus.com/reference/string/string/


CharNode* MyString::myStringToCharList(const MyString& transfer)
{
	CharNode* item = transfer.getCharNodeHead();
	if (item == nullptr) {
		return nullptr;
	}
	CharNode* toAddHead = new CharNode(item->getContent());
	item = item->getNext();
	CharNode* toAddItem = toAddHead;
	//copy list
	while (item != nullptr) {
		toAddItem->setNext(new CharNode(toAddItem, nullptr, item->getContent()));
		toAddItem = toAddItem->getNext();
		item = item->getNext();
	}
	return toAddHead;
}

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

void MyString::insertCharList(size_t insertBeforePos, CharNode* insertHead)
{
	if (insertHead == nullptr) {
		return;
	}

	CharNode* insertEnd = insertHead;
	while (insertEnd->getNext() != nullptr) {
		insertEnd = insertEnd->getNext();
	}

	CharNode* end = this->head;
	for (size_t i = 0; i < insertBeforePos; i++)
	{
		end = end->getNext();
	}

	CharNode* start = nullptr;

	if (this->head == nullptr) {//这就是个空的字符串
		this->head = insertHead;
		return;
	}

	if (end == nullptr) {
		start = this->head;
		while (start->getNext() != nullptr) {
			start = start->getNext();
		}
	}
	else {
		start = end->getBefore();
	}
	

	//插入序列头和断开处头部连接
	if (start == nullptr) {
		this->head = insertHead;
		insertHead->setBefore(nullptr);
	}
	else {
		start->setNext(insertHead);
		insertHead->setBefore(start);
	}
	
	//插入序列尾和断开处尾部连接
	if (end == nullptr) {
		insertEnd->setNext(nullptr);
	}
	else {
		end->setBefore(insertEnd);
		insertEnd->setNext(end);
	}
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

MyString& MyString::append(const MyString& str)
{
	return *this += str;
}

MyString& MyString::append(const MyString& str, size_t subpos, size_t sublen)
{
	CharNode* item = str.getCharNodeHead();
	for (size_t i = 0; i < subpos; i++)
	{
		item = item->getNext();
	}

	for (size_t i = 0; i < sublen; i++)
	{
		this->addCharNode(new CharNode(item->getContent()));
		item = item->getNext();
	}
	return *this;
}

MyString& MyString::append(const char* s)
{
	return *this += s;
}

MyString& MyString::append(const char* s, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		this->addCharNode(new CharNode(s[i]));
	}
	return *this;
}

MyString& MyString::append(size_t n, char c)
{
	for (size_t i = 0; i < n; i++)
	{
		this->addCharNode(new CharNode(c));
	}
	return *this;
}

void MyString::push_back(char c)
{
	*this += c;
}

MyString& MyString::assign(const MyString& str)
{
	*this = str;
	return *this;
}

MyString& MyString::assign(const MyString& str, size_t subpos, size_t sublen)
{
	this->deleteAllCharNode();
	CharNode* item = str.getCharNodeHead();
	for (size_t i = 0; i < subpos; i++)
	{
		item = item->getNext();
	}

	for (size_t i = 0; i < sublen; i++)
	{
		this->addCharNode(new CharNode(item->getContent()));
		item = item->getNext();
	}
	return *this;
}

MyString& MyString::assign(const char* s)
{
	this->deleteAllCharNode();
	*this += s;
	return *this;
}

MyString& MyString::assign(const char* s, size_t n)
{
	this->deleteAllCharNode();
	for (size_t i = 0; i < n; i++)
	{
		this->addCharNode(new CharNode(s[i]));
	}
	return *this;
}

MyString& MyString::assign(size_t n, char c)
{
	this->deleteAllCharNode();
	for (size_t i = 0; i < n; i++)
	{
		this->addCharNode(new CharNode(c));
	}
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	CharNode* head = MyString::myStringToCharList(str);
	this->insertCharList(pos, head);
	return *this;
}
