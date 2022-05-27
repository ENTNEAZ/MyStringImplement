#pragma once
#include "MyString.h"
/*
implement in:
MyStringUtils.cpp
*/
namespace MyStringUtils {
	int stoi(const MyString& str, size_t* idx = 0, int base = 10);
	long stol(const MyString& str, size_t* idx = 0, int base = 10);
	long long stoll(const MyString& str, size_t* idx = 0, int base = 10);
	unsigned long stoul(const MyString& str, size_t* idx = 0, int base = 10);
	unsigned long long stoull(const MyString& str, size_t* idx = 0, int base = 10);

	float stof(const MyString& str, size_t* idx = 0);
	double stod(const MyString& str, size_t* idx = 0);
	long double stold(const MyString& str, size_t* idx = 0);

	MyString to_string(unsigned long long val);
	MyString to_string(long long val);
	MyString to_string(long double val);

	//自定义辅助函数
	int toNum(char a);
	long long strToInteger(const MyString& str, int base = 10, bool isPositive = true);
	unsigned long long strToUnsignedInteger(const MyString& str, int base = 10);
	long double strToDouble(const MyString& str, bool isPositive = true);
	bool checkLegal(char a, int base);
}