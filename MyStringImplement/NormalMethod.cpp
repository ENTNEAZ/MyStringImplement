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
		//Ŀǰitem�����һ��
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
		//itemָ�������β
		while (item->getBefore() != nullptr) {
			item = item->getBefore();
			delete item->getNext();
		}
		//itemָ�������head
		delete item;
		this->head = nullptr;
	}
}

void MyString::copyFrom(const MyString& toCopy)
{
	this->deleteAllCharNode();
	CharNode* toCopyItem = toCopy.getCharNodeHead();
	while (toCopyItem != nullptr) {
		//��������headΪnullptr��� deleteAllCharNode()�Ѿ�����
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
	//����ʹ�������� ����������Ӧ�����ڴ��пɷ���Ĵ�С
	//�˷����������������
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
	//����ʹ�õ������� ÿ�θ��µ�ʱ������·����˴�С
	//�˷���������
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
	return *this + str;
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
	return *this + s;
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
