// MyStringImplement.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "MyString.h"

using namespace std;
int main()
{
    char c[] = "abcdefghijk";
    MyString::memcpy(c+2,c,2);
    cout << c << endl;

    char str1[] = "Sample string";
    char str2[40];
    char str3[40];
    MyString::strcpy(str2, str1);
    MyString::strcpy(str3, "copy successful");
    cout << str2 << endl << str3;

    return 0;
}

