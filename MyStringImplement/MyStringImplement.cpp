﻿// MyStringImplement.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "MyString.h"

using namespace std;
int main()
{
    //memcpy
    char c[] = "abcdefghijk";
    MyString::memcpy(c+2,c,2);
    cout << c << endl;


    //strncpy
    char str1[100] = "Sample string";
    char str2[40];
    char str3[40];
    MyString::strncpy(str2, str1, 2);
    MyString::strncpy(str3, "copy successful",10);
    cout << str2 << endl << str3 << endl;


    //strncat
    MyString::strncat(str1, " hahaha", 7);
    cout << str1 << endl;


    //memcmp
    MyString::strcpy(str1,"abcde");
    MyString::strcpy(str2, "abcdf");
    cout << str1 << '\t' << str2 << endl;
    cout << MyString::memcmp(str1, str2, 3) << '\t' << MyString::memcmp(str1, str2, 10) << endl;
    
    
    //strcmp
    cout << str1 << '\t' << str2 << endl;
    cout << MyString::strcmp(str1, str2) << endl;

    return 0;
}
