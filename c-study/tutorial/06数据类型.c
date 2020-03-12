#include <stdio.h>
int main(){

    /*
        数据类型中占用的字节数是不固定的,可以通过sizeof来获取

        数据类型(没有字符串类型和布尔类型)
            1.基本数据类型
                整型:
                    短整型:有符号短整型([signed] short [int]),无符号短整型(unsigned short [int])
                    基本整型:有符号基本整型([signed] int),无符号基本整型(unsigned int)
                    长整型:有符号长整型([signed] long [int]),无符号长整型([signed] long [int])
                字符型:
                    char
                浮点型:
                    float
                    double
                    long double
                枚举类型:

            2.构造类型
                数组
                结构体
                共用体
            3.指针类型
            4.空类型
    */
    unsigned int a = 1;


    // man 3 printf
    // 输出整型%d,8进制整型%o,16进制整型%x,16进制整型(ABCDEF用大写)%X,当做10进制无符号整数输出%u
    printf("%d\n",a);//1


    int b = -2;
    // 把-2当做一个无符号整数输出
    // 因为sizeof(b)==4,int类型在当前系统中占用4个字节
    // 原码
    // 10000000 00000000 00000000 00000010
    // 反码
    // 11111111 11111111 11111111 11111101
    // 补码(内存中存储的内容)
    // 11111111 11111111 11111111 11111110

    // 转换为无符号整数
    // ff ff ff fe = 15*16^7 + 15*16^6 + 15*16^5 + 15*16^4 + 15*16^3 + 15*16^2 + 15*16 + 14 = 4294967294
    // js中15*Math.pow(16,7)+15*Math.pow(16,6)+15*Math.pow(16,5)+15*Math.pow(16,4)+15*Math.pow(16,3)+15*Math.pow(16,2)+15*16+14=4294967294
    printf("%d\n",b);//-2
    printf("%x\n",b);//fffffffe






    // 溢出测试
    // 有符号整型当前系统占用4个字节,最大值
    // 01111111 11111111 11111111 11111111
    // 加1后
    // 10000000 00000000 00000000 00000000
    // 加1后,变成了负数,在内存中会转为补码存储
    // 反码
    // 11111111 11111111 11111111 11111111
    // 补码
    // 00000000 00000000 00000000 00000001

    int c = 0xefffffff;
    c = c + 1;
    printf("%d\n",c);





    // 溢出测试
    // 有符号整型当前系统占用4个字节,最大值
    // 01111111 11111111 11111111 11111111
    // 加2后
    // 10000000 00000000 00000000 00000001
    // 加2后,变成了负数,在内存中会转为补码存储
    // 反码
    // 11111111 11111111 11111111 11111110
    // 补码(内存中为)
    // 11111111 11111111 11111111 11111111
    // 如果当做时%d(有符号整数)来输出,最高位表示负号,则
    // -1111111 11111111 11111111 11111111
    // -7f ff ff ff = -0x7fffffff = 
    // js中 7*Math.pow(16,7)+15*Math.pow(16,6)+15*Math.pow(16,5)+15*Math.pow(16,4)+15*Math.pow(16,3)+15*Math.pow(16,2)+15*Math.pow(16,1)+15 = -2147483646
    int d = 0xefffffff;
    d = d + 2;
    printf("%d\n",d);
    return 0;



    return 0;
} 