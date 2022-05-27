#include "MyStringUtils.h"

int MyStringUtils::toNum(char a)
{
    if (a >= '0' && a <= '9') {
        return a - '0';
    }
    if (a >= 'a' && a <= 'z') {
        return (a - 'a') + 10;
    }
    if (a >= 'A' && a <= 'Z') {
        return (a - 'A') + 10;
    }
    return INT32_MAX;
}

long long MyStringUtils::strToInteger(const MyString& str, int base, bool isPositive)
{
    //对于存在非法字符的 返回值为0
    if (base < 2 || base > 36) {
        return 0;
        //小于2的进制无意义，大于36的进制无法用字母与数字表示
    }
    long long sum = 0;
    size_t lengthOfStr = str.length();
    for (size_t i = 0; i < lengthOfStr; i++)
    {
        long long temp = MyStringUtils::toNum(str[lengthOfStr - 1 - i]);
        if (temp >= base) {
            return 0;//错误 以base为基数的数字不会出现超过base的数字
        }
        sum += temp * (int)(pow(base, i));
    }
    return sum * ((isPositive)?1:-1);
}

unsigned long long MyStringUtils::strToUnsignedInteger(const MyString& str, int base)
{
    //对于存在非法字符的 返回值为0
    if (base < 2 || base > 36) {
        return 0;
        //小于2的进制无意义，大于36的进制无法用字母与数字表示
    }
    unsigned long long sum = 0;
    size_t lengthOfStr = str.length();
    for (size_t i = 0; i < lengthOfStr; i++)
    {
        unsigned long long temp = MyStringUtils::toNum(str[lengthOfStr - 1 - i]);
        if (temp >= base) {
            return 0;//错误 以base为基数的数字不会出现超过base的数字
        }
        sum += temp * (int)(pow(base, i));
    }
    return sum;
}

long double MyStringUtils::strToDouble(const MyString& str, bool isPositive)
{
    //形如xxxxxxxxx.xxxxxxxx
    //对于存在非法字符的 返回值为0
    
    long double sum = 0;
    size_t lengthOfStr = str.length();
    //先找小数点位置
    size_t dotPos = 0;
    for (dotPos = 0; dotPos < lengthOfStr; dotPos++)
    {
        if (str[dotPos] == '.') {
            break;
        }
    }
    //将小数点前面的数字构造成一个字符串 加入sum
    MyString beforeDot(str, 0, dotPos);
    sum += MyStringUtils::strToUnsignedInteger(beforeDot, 10);

    for (size_t i = dotPos + 1; i < lengthOfStr; i++)
    {
        sum += MyStringUtils::toNum(str[i]) / pow(10, i - dotPos);
    }

    return sum * ((isPositive) ? 1 : -1);
}

bool MyStringUtils::checkLegal(char a, int base)
{
    int temp = MyStringUtils::toNum(a);
    return (temp >= base) ? false : true;
}

int MyStringUtils::stoi(const MyString& str, size_t* idx, int base)
{
    return (int)MyStringUtils::stoll(str, idx, base);
}

long MyStringUtils::stol(const MyString& str, size_t* idx, int base)
{
    return (long)MyStringUtils::stoll(str, idx, base);
}

long long MyStringUtils::stoll(const MyString& str, size_t* idx, int base)
{
    size_t lengthOfStr = str.length();
    size_t firstNumAppear = 0;//指向第一个合法的字符(不包括"0x"等)
    for (firstNumAppear = 0; firstNumAppear < lengthOfStr; firstNumAppear++)
    {
        if (checkLegal(str[firstNumAppear], base)) {
            break;
        }
    }
    bool isPositive = true;//判断一下正负
    if (firstNumAppear != 0 && str[firstNumAppear - 1] == '-') {
        isPositive = false;
    }
    //有可能是形如"0x" "0b" "0o"的形式
    //尝试读取"0x" "0b" "0o"头
    if (str[firstNumAppear] == '0' && firstNumAppear + 2 < lengthOfStr) {//结尾"0b1"形式才合法 "0b"并不合法 因此要有两个字符的空余
        switch (base)
        {
        case 2:
            if (str[firstNumAppear + 1] == 'b' || str[firstNumAppear + 1] == 'B') {
                firstNumAppear += 2;
            }
            break;
        case 8:
            if (str[firstNumAppear + 1] == 'o' || str[firstNumAppear + 1] == 'O') {
                firstNumAppear += 2;
            }
            break;
        case 16:
            if (str[firstNumAppear + 1] == 'x' || str[firstNumAppear + 1] == 'X') {
                firstNumAppear += 2;
            }
            break;
        default:
            break;
        }
    }

    size_t firstNumDisappear = 0;
    for (firstNumDisappear = firstNumAppear + 1; firstNumDisappear < lengthOfStr; firstNumDisappear++)
    {
        if (!checkLegal(str[firstNumDisappear], base)) {
            break;
        }
    }
    if (idx != nullptr) {
        *idx = firstNumDisappear;
    }
    //idx指向第一个不合法的字符
    //[firstNumAppear,firstNumDisappear)中间的字符是合法的
    MyString temp(str, firstNumAppear, firstNumDisappear - firstNumAppear);
    return MyStringUtils::strToInteger(temp, base, isPositive);
}

unsigned long MyStringUtils::stoul(const MyString& str, size_t* idx, int base)
{
    return (unsigned long)MyStringUtils::stoull(str, idx, base);
}

unsigned long long MyStringUtils::stoull(const MyString& str, size_t* idx, int base)
{
    size_t lengthOfStr = str.length();
    size_t firstNumAppear = 0;//指向第一个合法的字符(不包括"0x"等)
    for (firstNumAppear = 0; firstNumAppear < lengthOfStr; firstNumAppear++)
    {
        if (checkLegal(str[firstNumAppear], base)) {
            break;
        }
    }
    //有可能是形如"0x" "0b" "0o"的形式
    //尝试读取"0x" "0b" "0o"头
    if (str[firstNumAppear] == '0' && firstNumAppear + 2 < lengthOfStr) {//结尾"0b1"形式才合法 "0b"并不合法 因此要有两个字符的空余
        switch (base)
        {
        case 2:
            if (str[firstNumAppear + 1] == 'b' || str[firstNumAppear + 1] == 'B') {
                firstNumAppear += 2;
            }
            break;
        case 8:
            if (str[firstNumAppear + 1] == 'o' || str[firstNumAppear + 1] == 'O') {
                firstNumAppear += 2;
            }
            break;
        case 16:
            if (str[firstNumAppear + 1] == 'x' || str[firstNumAppear + 1] == 'X') {
                firstNumAppear += 2;
            }
            break;
        default:
            break;
        }
    }

    size_t firstNumDisappear = 0;
    for (firstNumDisappear = firstNumAppear + 1; firstNumDisappear < lengthOfStr; firstNumDisappear++)
    {
        if (!checkLegal(str[firstNumDisappear], base)) {
            break;
        }
    }
    if (idx != nullptr) {
        *idx = firstNumDisappear;
    }
    //idx指向第一个不合法的字符
    //[firstNumAppear,firstNumDisappear)中间的字符是合法的
    MyString temp(str, firstNumAppear, firstNumDisappear - firstNumAppear);
    return MyStringUtils::strToUnsignedInteger(temp, base);
}

float MyStringUtils::stof(const MyString& str, size_t* idx)
{
    return (float)MyStringUtils::stold(str, idx);
}

double MyStringUtils::stod(const MyString& str, size_t* idx)
{
    return (double)MyStringUtils::stold(str, idx);
}

long double MyStringUtils::stold(const MyString& str, size_t* idx)
{
    size_t lengthOfStr = str.length();
    size_t firstNumAppear = 0;//指向第一个合法的字符(不包括"0x"等)
    for (firstNumAppear = 0; firstNumAppear < lengthOfStr; firstNumAppear++)
    {
        if (checkLegal(str[firstNumAppear], 10)) {
            break;
        }
    }
    bool isPositive = true;//判断一下正负
    if (firstNumAppear != 0 && str[firstNumAppear - 1] == '-') {
        isPositive = false;
    }
    size_t firstNumDisappear = 0;
    for (firstNumDisappear = firstNumAppear + 1; firstNumDisappear < lengthOfStr; firstNumDisappear++)
    {
        if (!checkLegal(str[firstNumDisappear], 10) && str[firstNumDisappear] != '.') {
            break;
        }
    }
    if (idx != nullptr) {
        *idx = firstNumDisappear;
    }
    //idx指向第一个不合法的字符
    //[firstNumAppear,firstNumDisappear)中间的字符是合法的
    MyString temp(str, firstNumAppear, firstNumDisappear - firstNumAppear);
    return MyStringUtils::strToDouble(temp, isPositive);
}
