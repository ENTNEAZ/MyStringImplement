#include "CharNode.h"

CharNode::CharNode()
{
	this->before = nullptr;
	this->next = nullptr;
	this->content = '\0';
}

CharNode::CharNode(char content)
{
	this->before = nullptr;
	this->next = nullptr;
	this->content = content;
}

CharNode::CharNode(CharNode* before, CharNode* after, char content)
{
	this->before = before;
	this->next = after;
	this->content = content;
}

CharNode::CharNode(CharNode* onlyContent)
{
	this->before = nullptr;
	this->next = nullptr;
	this->content = onlyContent->getContent();
}


void CharNode::setContent(char content)
{
	this->content = content;
}

char CharNode::getContent()
{
	return this->content;
}

void CharNode::setBefore(CharNode* before)
{
	this->before = before;
}

void CharNode::setNext(CharNode* after)
{
	this->next = after;
}

CharNode* CharNode::getBefore()
{
	return this->before;
}

CharNode* CharNode::getNext()
{
	return this->next;
}
