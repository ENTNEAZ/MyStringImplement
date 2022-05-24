#pragma once
#ifndef CharNode

class CharNode {
public:
	CharNode();
	CharNode(char* before, char* after, char content);
	void setContent(char content);
	char getContent();
	void setBefore(char* before);
	void setNext(char* after);
	char* getBefore();
	char* getNext();
private:
	char* before;
	char* next;
	char content;
};

#endif // !CharNode
