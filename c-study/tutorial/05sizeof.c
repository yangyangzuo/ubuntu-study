#include <stdio.h>
int main(){

    //sizeof关键字
    // 获取变量在内存中占用的字节数
    // sizeof 变量
    // 或者
    // sizeof(变量)

    // 注意:不同的操作系统对于变量内存分配字节数是不同的
    int a = 1;
    int b = sizeof a;

    int c = -1;
    int d = sizeof(c);

    printf("%d\n",b);
    // 4
    // a在内存中的存储,a是正数,原码,反码,补码值相等
    // 00000000 00000000 00000000 00000001

    printf("%d\n",d);
    // 4
    // c在内存中的存储,c是负数,内存中时按照补码的形式来放置的
    // 原码
    // 10000000 00000000 00000000 00000001
    // 反码
    // 11111111 11111111 11111111 11111110
    // 补码
    // 11111111 11111111 11111111 11111111


    // 二进制->10进制的计算
    // 1.二进制的对应位乘以数值然后相加
    // 10001001 = 1*2^7 + 1*2^3 + 1*2^0 = 128 + 8 + 1 = 137
    // 2.先转换为16进制,再对应位乘以数值相加
    // 10001001 = 1000 1001 => 0x89 = 8*16^1 + 9*16^0 = 128 + 9 = 137
    // 2.先转换为8进制,再对应位乘以数值相加
    // 10001001 = 10 001 001=> 0211 = 2*8^2 + 1*8^1 + 1*8^0 = 128  + 8 +1 = 137

    return 0;
} 