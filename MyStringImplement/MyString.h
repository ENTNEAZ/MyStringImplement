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
	~MyString();


	//Method of string object
	size_t size();
	size_t length();
	size_t max_size();//无意义
	void resize(size_t n);
	void resize(size_t n, char c);
	void clear();
	bool empty();
	void shrink_to_fit();//无意义
	char& at(size_t pos);
	const char& at(size_t pos) const;
	char& back();
	const char& back() const;
	char& front();
	const char& front() const;


	//operators of string object
	void operator=(const char* s);
	const char& operator[](size_t pos) const;
	char& operator[] (size_t pos);
	friend std::ostream& operator<<(std::ostream&, MyString&);


private:
	CharNode* getCharNodeHead() const;
	void addCharNode(CharNode*);
	void deleteAllCharNode();
	void copyFrom(const MyString& toCopy);
	CharNode* head;
};

