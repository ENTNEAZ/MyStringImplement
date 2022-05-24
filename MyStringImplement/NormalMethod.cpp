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
