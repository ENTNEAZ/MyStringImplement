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
    int sum = 0;
    size_t lengthOfStr = str.length();
    for (size_t i = 0; i < lengthOfStr; i++)
    {
        int temp = MyStringUtils::toNum(str[lengthOfStr - 1 - i]);
        if (temp >= base) {
            return 0;//错误 以base为基数的数字不会出现超过base的数字
        }
        sum += temp * (int)(pow(base, i));
    }
    return sum * ((isPositive)?1:-1);
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
