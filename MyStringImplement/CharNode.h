#pragma once


class CharNode {
public:
	CharNode();
	CharNode(char content);
	CharNode(CharNode* before, CharNode* after, char content);
	CharNode(CharNode* onlyContent);
	void setContent(char content);
	char getContent();
	void setBefore(CharNode* before);
	void setNext(CharNode* after);
	CharNode* getBefore();
	CharNode* getNext();
private:
	CharNode* before;
	CharNode* next;
	char content;
};


