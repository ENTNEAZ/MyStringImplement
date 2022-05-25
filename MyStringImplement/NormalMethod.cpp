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

	if (this->head == nullptr) {//����Ǹ��յ��ַ���
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
	

	//��������ͷ�ͶϿ���ͷ������
	if (start == nullptr) {
		this->head = insertHead;
		insertHead->setBefore(nullptr);
	}
	else {
		start->setNext(insertHead);
		insertHead->setBefore(start);
	}
	
	//��������β�ͶϿ���β������
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

//insert���뵽posǰ��
MyString& MyString::insert(size_t pos, const MyString& str)
{
	CharNode* head = MyString::myStringToCharList(str);
	this->insertCharList(pos, head);
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	MyString temp(str,subpos,sublen);
	CharNode* head = MyString::myStringToCharList(temp);
	this->insertCharList(pos, head);
	return *this;
}

MyString& MyString::insert(size_t pos, const char* s)
{
	MyString temp(s);
	CharNode* head = MyString::myStringToCharList(temp);
	this->insertCharList(pos, head);
	return *this;
}

MyString& MyString::insert(size_t pos, const char* s, size_t n)
{
	MyString temp(s, n);
	CharNode* head = MyString::myStringToCharList(temp);
	this->insertCharList(pos, head);
	return *this;
}

MyString& MyString::insert(size_t pos, size_t n, char c)
{
	MyString temp(c, n);
	CharNode* head = MyString::myStringToCharList(temp);
	this->insertCharList(pos, head);
	return *this;
}

MyString& MyString::erase(size_t pos, size_t len)
{
	if (pos >= this->length() || len == 0) {
		return *this;
	}

	CharNode* item = this->head;
	for (size_t i = 0; i < pos; i++)
	{
		item = item->getNext();
	}

	//itemָ����Ҫɾ�������ݵĵ�һ���ַ�
	CharNode* end = item;
	while (end->getNext() != nullptr && len > 1) {//len > 1����item�Ѿ�ռλ��1�� 
		end = end->getNext();
		len--;
	}
	if (item == this->head) {
		this->head = end->getNext();
		if (end->getNext() != nullptr) {
			end->getNext()->setBefore(nullptr);
		}
	}
	else {
		item->getBefore()->setNext(end->getNext());
		if (end->getNext() != nullptr) {
			end->getNext()->setBefore(item->getBefore());
		}
	}
	//ɾ��item��end֮ǰ����������
	if (item == end) {
		//ֻ��һ��Ҫɾ��
		delete end;
	}
	else {
		//�������ϲ�����item = item->getNext();
		do
		{
			item = item->getNext();
			delete item->getBefore();
		} while (item != end);
		delete end;
	}
	
	return *this;
}

MyString& MyString::replace(size_t pos, size_t len, const MyString& str)
{
	this->erase(pos, len);
	this->insert(pos, str);
	return *this;
}

MyString& MyString::replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen)
{
	this->erase(pos, len);
	this->insert(pos, str, subpos, sublen);
	return *this;
}

MyString& MyString::replace(size_t pos, size_t len, const char* s)
{
	this->erase(pos, len);
	this->insert(pos, s);
	return *this;
}

MyString& MyString::replace(size_t pos, size_t len, const char* s, size_t n)
{
	this->erase(pos, len);
	this->insert(pos, s, n);
	return *this;
}

MyString& MyString::replace(size_t pos, size_t len, size_t n, char c)
{
	this->erase(pos, len);
	this->insert(pos, n, c);
	return *this;
}
