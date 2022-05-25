// MyStringImplement.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "MyString.h"

using namespace std;
int main()
{
    
    ////memcpy
    //char c[] = "abcdefghijk";
    //MyString::memcpy(c+2,c,2);
    //cout << c << endl;


    ////strncpy
    //char str1[100] = "Sample string";
    //char str2[40];
    //char str3[40];
    //MyString::strncpy(str2, str1, 2);
    //MyString::strncpy(str3, "copy successful",10);
    //cout << str2 << endl << str3 << endl;


    ////strncat
    //MyString::strncat(str1, " hahaha", 7);
    //cout << str1 << endl;


    ////memcmp
    //MyString::strcpy(str1,"abcde");
    //MyString::strcpy(str2, "abcdf");
    //cout << str1 << '\t' << str2 << endl;
    //cout << MyString::memcmp(str1, str2, 3) << '\t' << MyString::memcmp(str1, str2, 10) << endl;
    //
    //
    ////strcmp
    //cout << str1 << '\t' << str2 << endl;
    //cout << MyString::strcmp(str1, str2) << endl;


    ////memchr
    //MyString::strcpy(str1, "Example string");
    //char* pch = (char*)MyString::memchr(str1, 'p', strlen(str1));
    //cout << "found in " << pch - str1 + 1 << endl;


    ////strchr
    //MyString::strcpy(str1, "Example string");
    //pch = (char*)MyString::strchr(str1, 'p');
    //cout << "found in " << pch - str1 + 1 << endl;


    ////strcspn
    //MyString::strcpy(str1, "fcba73");
    //MyString::strcpy(str2, "1234567890");
    //cout << MyString::strcspn(str1, str2) << endl;


    ////strpbrk
    //MyString::strcpy(str1, "fcaba73123");
    //cout << MyString::strpbrk(str1, str2) << endl;

    ////strrchr
    //MyString::strcpy(str1, "f3a3sdf");
    //cout << MyString::strrchr(str1, '3') << endl;


    ////strspn
    //MyString::strcpy(str1, "129th");
    //MyString::strcpy(str2, "1234567890");
    //size_t i = strspn(str1, str2);
    //cout << "The initial number has " << i << " digits." << endl;


    ////strstr
    //cout << MyString::strstr("This is a simple string", "simple") << endl;


    ////strtok
    //MyString::strcpy(str1, "- This, a sample string.");
    //pch = MyString::strtok(str1, " ,.-");
    //while (pch != nullptr)
    //{
    //    printf("%s\n", pch);
    //    pch = MyString::strtok(NULL, " ,.-");
    //}


    ////memset
    //MyString::strcpy(str1, "almost every programmer should know memset!");
    //MyString::memset(str1, '-', 6);
    //cout << str1 << endl;

    MyString a = "aaaaaaaaa";
    cout << a << endl;
    cout << a[4] << endl;

    MyString b = "bbbbbbbbb";
    cout << b << endl;

    cout << a + b << endl;
    
    MyString c = a + b;
    cout << c << endl;
    c = c + c;
    c += c;
    cout << c << endl;

    a = "aaa";
    b = "bbb";
    c = "";
    c.insert(0, a + b);
    cout << a << '\t' << b << endl;
    cout << c << endl;
    return 0;
}

