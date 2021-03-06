#pragma once
/*
implement in:
Constructors.cpp
NormalMethod.cpp
Operators.cpp
StringOperation.cpp
*/

#include "CharNode.h"
#include <iostream>

class MyString {
public:
	static const size_t npos = -1;
	//Construct string object
	//default
	MyString();

	//copy constructor
	MyString(const MyString& toCopy);

	//substring constructor
	MyString(const MyString& str, size_t pos, size_t len);

	//from c string
	MyString(const char* s);

	//from buffer
	MyString(const char* s,size_t num);

	//fill constructor
	MyString(char s, size_t num);
	
	~MyString();


	//Method of string object
	size_t size() const;
	size_t length() const;
	size_t max_size();
	void resize(size_t n);
	void resize(size_t n, char c);
	size_t capacity() const;
	void reserve(size_t n = 0);//无意义
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
	MyString& insert(size_t pos, const MyString& str);
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen);
	MyString& insert(size_t pos, const char* s);
	MyString& insert(size_t pos, const char* s, size_t n);
	MyString& insert(size_t pos, size_t n, char c);
	MyString& erase(size_t pos, size_t len);
	MyString& replace(size_t pos, size_t len, const MyString& str);
	MyString& replace(size_t pos, size_t len, const MyString& str,size_t subpos, size_t sublen);
	MyString& replace(size_t pos, size_t len, const char* s);
	MyString& replace(size_t pos, size_t len, const char* s, size_t n);
	MyString& replace(size_t pos, size_t len, size_t n, char c);
	void swap(MyString& str);
	void pop_back();


	//String operation
	const char* c_str() const;
	const char* data() const;
	size_t find(const MyString& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;
	size_t rfind(const MyString& str, size_t pos) const;
	size_t rfind(const char* s, size_t pos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = -1) const;
	size_t find_first_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;
	size_t find_last_of(const MyString& str, size_t pos) const;
	size_t find_last_of(const char* s, size_t pos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos) const;
	size_t find_first_not_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;
	size_t find_last_not_of(const MyString& str, size_t pos) const;
	size_t find_last_not_of(const char* s, size_t pos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos) const;
	MyString substr(size_t pos = 0, size_t len = npos) const;
	int compare(const MyString& str) const noexcept;
	int compare(size_t pos, size_t len, const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;


	//operators of string object
	void operator=(const char* s);
	void operator=(char s);
	void operator=(const MyString s);
	const char& operator[](size_t pos) const;
	char& operator[] (size_t pos);
	MyString& operator+= (const MyString& str);
	MyString& operator+= (const char* s);
	MyString& operator+= (char c);
	friend std::ostream& operator<<(std::ostream&, const MyString&);
	friend std::istream& operator>>(std::istream&, MyString&);
	static std::istream& getline(std::istream& is, MyString& str, char delim);
	static std::istream& getline(std::istream& is, MyString& str);
	friend MyString operator+ (const MyString& lhs, const MyString& rhs);
	friend MyString operator+ (const MyString& lhs, const char* rhs);
	friend MyString operator+ (const char* lhs, const MyString& rhs);
	friend MyString operator+ (const MyString& lhs, const char rhs);
	friend MyString operator+ (const char lhs, const MyString& rhs);
	friend bool operator== (const MyString& lhs, const MyString& rhs);
	friend bool operator== (const char* lhs, const MyString& rhs);
	friend bool operator== (const MyString& lhs, const char* rhs);
	friend bool operator!= (const MyString& lhs, const MyString& rhs);
	friend bool operator!= (const char* lhs, const MyString& rhs);
	friend bool operator!= (const MyString& lhs, const char* rhs);
	friend bool operator<  (const MyString& lhs, const MyString& rhs);
	friend bool operator<  (const char* lhs, const MyString& rhs);
	friend bool operator<  (const MyString& lhs, const char* rhs);
	friend bool operator<= (const MyString& lhs, const MyString& rhs);
	friend bool operator<= (const char* lhs, const MyString& rhs);
	friend bool operator<= (const MyString& lhs, const char* rhs);
	friend bool operator>  (const MyString& lhs, const MyString& rhs);
	friend bool operator>  (const char* lhs, const MyString& rhs);
	friend bool operator>  (const MyString& lhs, const char* rhs);
	friend bool operator>= (const MyString& lhs, const MyString& rhs);
	friend bool operator>= (const char* lhs, const MyString& rhs);
	friend bool operator>= (const MyString& lhs, const char* rhs);

private:
	static CharNode* myStringToCharList(const MyString& transfer);
	CharNode* getCharNodeHead() const;
	void addCharNode(CharNode*);
	void deleteAllCharNode();
	void copyFrom(const MyString& toCopy);
	void insertCharList(size_t insertBeforePos, CharNode* head);
	CharNode* head;
};

