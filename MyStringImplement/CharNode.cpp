#include "CharNode.h"

CharNode::CharNode()
{
	this->before = nullptr;
	this->next = nullptr;
	this->content = '\0';
}

CharNode::CharNode(char* before, char* after, char content)
{
	this->before = before;
	this->next = after;
	this->content = content;
}

void CharNode::setContent(char content)
{
	this->content = content;
}

char CharNode::getContent()
{
	return this->content;
}

void CharNode::setBefore(char* before)
{
	this->before = before;
}

void CharNode::setNext(char* after)
{
	this->next = after;
}

char* CharNode::getBefore()
{
	return this->before;
}

char* CharNode::getNext()
{
	return this->next;
}
