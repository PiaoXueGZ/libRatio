#ifndef _LIBRATIO_H_
#define _LIBRATIO_H_ 1

#include <iostream>
#include <cstdio>

struct ratio
{
    unsigned long long num = 0;
    unsigned long long den = 1;
    bool negative = false;

    ratio() = default;
    ratio(long long num1);
    ratio(long long num1, long long den1);
    ratio(unsigned long long num1, unsigned long long den1, bool isNegative);

    ratio &read(unsigned long long num1, unsigned long long den1, bool isNegative);
    ratio &print();
    ratio &simplify();
    ratio &makeItselfreciprocal();
    ratio reciprocal();

    operator long double() {return (negative ? -1 : 1) * (long double)num / den;}
};

//类外函数定义开始

inline ratio makeRatio(long long num, long long den);
inline ratio makeRatio(unsigned long long num, unsigned long long den, bool negative);

ratio ratioAdd(const ratio &r1, const ratio &r2);
ratio ratioMinus(const ratio &r1, const ratio &r2);
ratio ratioMultiply(const ratio &r1, const ratio &r2);
ratio ratioDivide(const ratio &r1, const ratio &r2);
//类外函数定义结束

//重载操作符开始
//重载输出操作符
std::ostream &operator<<(std::ostream &os, const ratio &r);

//重载输入操作符
std::istream &operator>>(std::istream &is, ratio &r);

//重载加号
ratio operator+(const ratio &r1, const ratio &r2);
ratio operator+=(ratio &r1, const ratio &r2);

//重载减号
ratio operator-(const ratio &r1, const ratio &r2);
ratio operator-=(ratio &r1, const ratio &r2);

//重载负号
ratio operator-(ratio &r1);

//重载乘号
ratio operator*(const ratio &r1, const ratio &r2);
ratio operator*=(ratio &r1, const ratio &r2);

//重载除号
ratio operator/(const ratio &r1, const ratio &r2);
ratio operator/=(ratio &r1, const ratio &r2);

//重载判断符
bool operator==(const ratio &r1, const ratio &r2);
bool operator!=(const ratio &r1, const ratio &r2);
bool operator>(const ratio &r1, const ratio &r2);
bool operator>=(const ratio &r1, const ratio &r2);
bool operator<(const ratio &r1, const ratio &r2);
bool operator<=(const ratio &r1, const ratio &r2);

//重载操作符结束

#endif /*_LIBRATIO_H_*/