#pragma once


#include "CharNode.h"
#include <iostream>

class MyString {
public:
	
	//Construct string object
	MyString();
	//default
	explicit MyString(const MyString& toCopy);
	//copy constructor
	MyString(const MyString& str, size_t pos, size_t len);
	//substring constructor
	MyString(const char* s);
	//from c string
	MyString(const char* s,size_t num);
	//from buffer
	MyString(char s, size_t num);
	//fill constructor



	//Method of string object
	CharNode* getCharNodeHead() const;
	void addCharNode(CharNode*);
	void deleteAllCharNode();
	void copyFrom(const MyString& toCopy);



	//operators of string object
	void operator=(const char* s);
	char operator[](const int index) const;
	friend std::ostream& operator<<(std::ostream&, MyString&);


private:
	CharNode* head;
};

