#pragma once


#include "CharNode.h"
#include <iostream>

class MyString {
public:
	
	//Construct string object
	MyString();
	//default
	MyString(const MyString& toCopy);
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
	MyString& append(const MyString& str);
	MyString& append(const MyString& str, size_t subpos, size_t sublen);
	MyString& append(const char* s);
	MyString& append(const char* s, size_t n);
	MyString& append(size_t n, char c);
	void push_back(char c);
	MyString& assign(const MyString& str);
	MyString& assign(const MyString& str, size_t subpos, size_t sublen);
	MyString& assign(const char* s);
	MyString& assign(const char* s, size_t n);
	MyString& assign(size_t n, char c);
	//insert插入到pos的前面
	MyString& insert(size_t pos, const MyString& str);
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen);
	MyString& insert(size_t pos, const char* s);
	MyString& insert(size_t pos, const char* s, size_t n);
	MyString& insert(size_t pos, size_t n, char c);



	//operators of string object
	void operator=(const char* s);
	void operator=(const MyString s);
	const char& operator[](size_t pos) const;
	char& operator[] (size_t pos);
	friend std::ostream& operator<<(std::ostream&, MyString);
	MyString operator+ (const MyString& str);
	MyString operator+ (const char* s);
	MyString operator+ (char c);
	MyString& operator+= (const MyString& str);
	MyString& operator+= (const char* s);
	MyString& operator+= (char c);


private:
	static CharNode* myStringToCharList(const MyString& transfer);
	CharNode* getCharNodeHead() const;
	void addCharNode(CharNode*);
	void deleteAllCharNode();
	void copyFrom(const MyString& toCopy);
	void insertCharList(size_t insertBeforePos, CharNode* head);
	CharNode* head;
};

