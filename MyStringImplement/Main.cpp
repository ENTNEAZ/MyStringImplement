// Main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
#include "MyString.h"
#include "MyStringUtils.h"
#include "OriginalCString.h"
using namespace std;
int main()
{
	
	//memcpy
	char ca[] = "abcdefghijk";
	OString::memcpy(ca + 2, ca, 2);
	cout << ca << endl;//ababefghijk

	//strncpy
	char str1[100] = "Sample string";
	char str2[40];
	char str3[40];
	OString::strncpy(str2, str1, 2);
	OString::strncpy(str3, "copy successful",10);
	cout << str2 << endl << str3 << endl;//S copy succ


	//strncat
	OString::strncat(str1, " hahaha", 7);
	cout << str1 << endl;//Sample string hahah


	//memcmp
	OString::strcpy(str1,"abcde");
	OString::strcpy(str2, "abcdf");
	cout << str1 << '\t' << str2 << endl;//abcde   abcdf
	cout << OString::memcmp(str1, str2, 3) << '\t' << OString::memcmp(str1, str2, 10) << endl;//0       -1
	
	
	//strcmp
	cout << str1 << '\t' << str2 << endl;//abcde   abcdf
	cout << OString::strcmp(str1, str2) << endl;//-1


	//memchr
	OString::strcpy(str1, "Example string");
	char* pch = (char*)OString::memchr(str1, 'p', strlen(str1));
	cout << "found in " << pch - str1 + 1 << endl;//found in 5


	//strchr
	OString::strcpy(str1, "Example string");
	pch = (char*)OString::strchr(str1, 'p');
	cout << "found in " << pch - str1 + 1 << endl;//found in 5


	//strcspn
	OString::strcpy(str1, "fcba73");
	OString::strcpy(str2, "1234567890");
	cout << OString::strcspn(str1, str2) << endl;//5


	//strpbrk
	OString::strcpy(str1, "fcaba73123");
	cout << OString::strpbrk(str1, str2) << endl;//73123

	//strrchr
	OString::strcpy(str1, "f3a3sdf");
	cout << OString::strrchr(str1, '3') << endl;//3a3sdf


	//strspn
	OString::strcpy(str1, "129th");
	OString::strcpy(str2, "1234567890");
	size_t t = strspn(str1, str2);
	cout << "The initial number has " << t << " digits." << endl;//The initial number has 3 digits.


	//strstr
	cout << OString::strstr("This is a simple string", "simple") << endl;//simple string


	//strtok
	OString::strcpy(str1, "- This, a sample string.");
	pch = OString::strtok(str1, " ,.-");
	while (pch != nullptr)
	{
	    printf("%s\n", pch);
	    pch = OString::strtok(NULL, " ,.-");
	}

	/*
		This
		a
		sample
		string
	*/

	//memset
	OString::strcpy(str1, "almost every programmer should know memset!");
	OString::memset(str1, '-', 6);
	cout << str1 << endl;//------ every programmer should know memset!


	//=================================================
	//MyString
	//=================================================

	MyString a = "aaaaaaaaa";
	cout << a << endl;//aaaaaaaaa
	cout << a[4] << endl;//a

	MyString b = "bbbbbbbbb";
	cout << b << endl;//bbbbbbbbb

	cout << a + b << endl;//aaaaaaaaabbbbbbbbb
	
	MyString c = a + b;
	cout << c << endl;//aaaaaaaaabbbbbbbbb
	c = (c + c);
	c += c;
	cout << c << endl;//aaaaaaaaabbbbbbbbbaaaaaaaaabbbbbbbbbaaaaaaaaabbbbbbbbbaaaaaaaaabbbbbbbbb

	a = "aaa";
	b = "bbb";
	c = "";
	c.insert(0, a + b);
	cout << a << '\t' << b << endl;//aaa     bbb
	cout << c << endl;//aaabbb

	MyString d(c, 2, 4);
	cout << d.insert(1,a,0,3) << endl;//aaaabbb


	d = "01234567";
	d.erase(2, 3);
	cout << d << endl;//01567

	a = "this is a test string.";
	b = "n example";
	c = "sample phrase";
	d = "useful.";

	a.replace(9, 5, b);
	cout << a << endl;
	a.replace(19, 6, c, 7, 6);
	cout << a << endl;
	a.replace(8, 10, "just a");
	cout << a << endl;
	a.replace(8, 6, "a shorty", 7);
	cout << a << endl;
	a.replace(22, 1, 3, '!');
	cout << a << endl;
	a.pop_back();
	cout << a << endl;
	/*
		this is an example string.
		this is an example phrase.
		this is just a phrase.
		this is a short phrase.
		this is a short phrase!!!
		this is a short phrase!!
	*/


	a = "aabbccddeeffgg";
	cout << a.find(*new MyString("gg"), 5) << endl;//12
	cout << a.rfind("0", a.length()) << endl;//18446744073709551615(npos)

	MyString str("Please, replace the vowels in this sentence by asterisks.");
	size_t found = str.find_first_of("aeiou");
	while (found != -1)
	{
	    str[found] = '*';
	    found = str.find_first_of("aeiou", found + 1);
	}
	cout << str << endl;//Pl**s*, r*pl*c* th* v*w*ls *n th*s s*nt*nc* by *st*r*sks.


	str = "0123456789*1234abc89*";
	cout << str.find_last_of("abcdef", str.length()) << endl;//17

	cout << str.substr(8, 13) << endl;//89*1234abc89*
	cout << str.compare("0123456789*1234abc89*") << endl;//0
	cout << (str == "0123456789*1234abc89*") << endl;//1
	cout << (MyString("alpha") < MyString("beta")) << endl;//1
	
	cout << "Please input string:";
	cin >> str;//123123123
	cout << "your input:" << str << endl;//123123123
	MyString::getline(cin, str, 'a');//Jelly Fisha
	cout << "your input:" << str << endl;//Jelly Fish

	size_t i = 0;
	cout << MyStringUtils::strToInteger("ffff", 16, true) << endl;//65535
	cout << MyStringUtils::stoi("xzv-0xffff", nullptr, 16) << endl;//-65535

	cout << setprecision(30) << MyStringUtils::strToDouble("123456.123", true) << endl;//123456.123000000006868503987789
	cout << setprecision(30) << MyStringUtils::stold("1232456abdf", &i) << endl;//1232456
	cout << i << endl;//7

	cout << MyStringUtils::to_string(1145141919810ULL) << endl;//1145141919810
	cout << MyStringUtils::to_string(-1145141919810) << endl;//-1145141919810
	cout << setprecision(30) << MyStringUtils::to_string(-1145141919810.1L) << endl;//-1145141919810.1000976562
	return 0;
}

