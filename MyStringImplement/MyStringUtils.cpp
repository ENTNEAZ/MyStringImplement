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
    //���ڴ��ڷǷ��ַ��� ����ֵΪ0
    if (base < 2 || base > 36) {
        return 0;
        //С��2�Ľ��������壬����36�Ľ����޷�����ĸ�����ֱ�ʾ
    }
    long long sum = 0;
    size_t lengthOfStr = str.length();
    for (size_t i = 0; i < lengthOfStr; i++)
    {
        long long temp = MyStringUtils::toNum(str[lengthOfStr - 1 - i]);
        if (temp >= base) {
            return 0;//���� ��baseΪ���������ֲ�����ֳ���base������
        }
        sum += temp * (int)(pow(base, i));
    }
    return sum * ((isPositive)?1:-1);
}

unsigned long long MyStringUtils::strToUnsignedInteger(const MyString& str, int base)
{
    //���ڴ��ڷǷ��ַ��� ����ֵΪ0
    if (base < 2 || base > 36) {
        return 0;
        //С��2�Ľ��������壬����36�Ľ����޷�����ĸ�����ֱ�ʾ
    }
    unsigned long long sum = 0;
    size_t lengthOfStr = str.length();
    for (size_t i = 0; i < lengthOfStr; i++)
    {
        unsigned long long temp = MyStringUtils::toNum(str[lengthOfStr - 1 - i]);
        if (temp >= base) {
            return 0;//���� ��baseΪ���������ֲ�����ֳ���base������
        }
        sum += temp * (int)(pow(base, i));
    }
    return sum;
}

long double MyStringUtils::strToDouble(const MyString& str, bool isPositive)
{
    //����xxxxxxxxx.xxxxxxxx
    //���ڴ��ڷǷ��ַ��� ����ֵΪ0
    
    long double sum = 0;
    size_t lengthOfStr = str.length();
    //����С����λ��
    size_t dotPos = 0;
    for (dotPos = 0; dotPos < lengthOfStr; dotPos++)
    {
        if (str[dotPos] == '.') {
            break;
        }
    }
    //��С����ǰ������ֹ����һ���ַ��� ����sum
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
    size_t firstNumAppear = 0;//ָ���һ���Ϸ����ַ�(������"0x"��)
    for (firstNumAppear = 0; firstNumAppear < lengthOfStr; firstNumAppear++)
    {
        if (checkLegal(str[firstNumAppear], base)) {
            break;
        }
    }
    bool isPositive = true;//�ж�һ������
    if (firstNumAppear != 0 && str[firstNumAppear - 1] == '-') {
        isPositive = false;
    }
    //�п���������"0x" "0b" "0o"����ʽ
    //���Զ�ȡ"0x" "0b" "0o"ͷ
    if (str[firstNumAppear] == '0' && firstNumAppear + 2 < lengthOfStr) {//��β"0b1"��ʽ�źϷ� "0b"�����Ϸ� ���Ҫ�������ַ��Ŀ���
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
    //idxָ���һ�����Ϸ����ַ�
    //[firstNumAppear,firstNumDisappear)�м���ַ��ǺϷ���
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
    size_t firstNumAppear = 0;//ָ���һ���Ϸ����ַ�(������"0x"��)
    for (firstNumAppear = 0; firstNumAppear < lengthOfStr; firstNumAppear++)
    {
        if (checkLegal(str[firstNumAppear], base)) {
            break;
        }
    }
    //�п���������"0x" "0b" "0o"����ʽ
    //���Զ�ȡ"0x" "0b" "0o"ͷ
    if (str[firstNumAppear] == '0' && firstNumAppear + 2 < lengthOfStr) {//��β"0b1"��ʽ�źϷ� "0b"�����Ϸ� ���Ҫ�������ַ��Ŀ���
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
    //idxָ���һ�����Ϸ����ַ�
    //[firstNumAppear,firstNumDisappear)�м���ַ��ǺϷ���
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
    size_t firstNumAppear = 0;//ָ���һ���Ϸ����ַ�(������"0x"��)
    for (firstNumAppear = 0; firstNumAppear < lengthOfStr; firstNumAppear++)
    {
        if (checkLegal(str[firstNumAppear], 10)) {
            break;
        }
    }
    bool isPositive = true;//�ж�һ������
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
    //idxָ���һ�����Ϸ����ַ�
    //[firstNumAppear,firstNumDisappear)�м���ַ��ǺϷ���
    MyString temp(str, firstNumAppear, firstNumDisappear - firstNumAppear);
    return MyStringUtils::strToDouble(temp, isPositive);
}
