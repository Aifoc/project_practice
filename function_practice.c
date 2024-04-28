#include <stdio.h>
#include <math.h>
// 1. 写一个函数可以判断一个数是不是素数。
// 2. 写一个函数判断一年是不是闰年。
// 3. 写一个函数，实现一个整形有序数组的二分查找。
// 4. 写一个函数，每调用一次这个函数，就会将 num 的值增加1。

//递归练习
// 接受一个整型值（无符号），按照顺序打印它的每一位。
// 编写函数不允许创建临时变量，求字符串的长度
// 求n的阶乘。（不考虑溢出）
// 求第n个斐波那契数。（不考虑溢出）

//判断自然数是否为质数
int determine_prime (int n)
//质数只有1和它自己作为因数，也就是只有两个因数。（1不是质数）
//1:通常算法就是把所有小于n本身的自然数数(排除1,0)都除以它，只要出现整除的情况那么n就不是质数。时间复杂度O(n)
//2:但是通过分析质数和合数在因数分布上的区别发现合数的因数一定会在sqrt(n)周边都存在。
    //那么只要判断其中一边是否出现整除现象就可以知道n是否是质数了。时间复杂度O(sqrt(n))
//3:由于一切偶数都能被2整除，所以偶数中除了2都可以被排除，可以只判断奇数n的另一半是否存在整除现象就可以了。复杂度O(sqrt(n)/2)
//质数的分布有一定特点，那就是当n>=5时，质数一定存在在6的倍数左右，利用这个规律可以判断质数
{
//实现算法3
if (3 <= n)
{
    if (n/2 != 0)//偶数都可以被2整除
    {
        int half_n = (int)sqrt(n);//将n开方，该函数会返回double类型，所以在函数前面加上(int)可以修改类型，会把小数后面的截断
        for (int i = 2; i <= half_n; i++)//把n除以sqrt(n)之后的所有数(除了1)，只要没有模为0的情况就是质数
        {
            if (n%i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
else if (1 == n)//1不是质数因为我们希望每一个整数都是用质数以独一无二的方式组合得到的，而1乘1一直等于1，其唯一性被破坏了
{
    return 0;
}
else//剩下的3和2都是质数
{
    return 1;
}
}
//算法答案:https://blog.csdn.net/sinat_26811377/article/details/96584293


//判断闰年
int determine_leap_year (int year)
//平年为非4的倍数以及100的倍数，闰年为4的倍数和400的倍数
{
    if(year%400 != 0 && year%100 == 0)//100的倍数是平年，但是要排除400的倍数
    {
        return 0;
    }
    else
    {
        if(year%4 == 0)//排除特殊情况后，只要是4的倍数就是闰年
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}


//查找整型有序数组中的n
int dichotomy_search(int* arr,int arr_number,int n)
//使用二分法查找有序整型数组中的n已经在branch_and_loop_practice中写过一次
//因为数组传入函数是以指针形式传递的，而只有指针形式无法知道数组的元素数量，所以需要在调用的时候就告诉函数元素数量
{
    int sort = arr_number/2;//索引值
    int step = arr_number/2;//步进值
    int activate = 1;
    if (n <= arr[arr_number-1] && n >= arr[0])//当n不超出数组的范围时
    {    
        while (activate)
            {
                if (n < arr[sort])//当n小于中间值时
                {
                    if(step > 3)//只有当步进>3时除2才不会等于0，需要让步进至少为1
                    {
                        step = step/2;//更新步进值，通过将先前的步进值/2的方式
                        sort = sort - step;//让索引减去步进值
                    }
                    else//如果步进值已经小于3，那么就直接将索引-1
                    {
                        sort -= 1;
                    }
                }
                else if (n > arr[sort])//当n大于中间值时
                {
                    if(step > 3)//只有当步进>3时除2才不会等于0，需要让步进至少为1
                    {
                        step = step/2;//更新步进值，通过将先前的步进值/2的方式
                        sort = sort + step;//让索引加上步进值
                    }
                    else//如果步进值已经小于3，那么就直接将索引+1
                    {
                        sort += 1;
                    }
                }                
                else
                {
                    printf("\nn => %d\n",arr[sort]);
                    return arr[sort];
                }

            }
    }
    else
    {
        printf("\nThe n number is exceeds the array range\n");
        return -1;
    }
}


//步进器
void stepper (int* parameter)
{
    *parameter += 1;
}

int main ()
{
    // {
    //     //判断质数
    //     int n = 11;
    //     if (determine_prime(n) == 1)
    //         printf("number %d is prime\n",n);
    //     else
    //         printf("number %d is not prime\n",n);
    // }
    // {
    //     //判断闰年
    //     int year = 2024;
    //     if (determine_leap_year(year) == 1)
    //         printf("year %d is leap year\n",year);
    //     else
    //         printf("year %d is not leap year\n",year);        
    // }
    // {
    //     //二分法找数组中元素
    //     int n = 11;//设定要找的n
    //     int arr[100] = {0};//初始化整型数组
    //     for (int i = 0;i < 100;i++)//创建有序数组
    //     {
    //         arr[i] = i;
    //         //printf("%d,",arr[i]);
    //     }
    //     dichotomy_search(arr,100,n);
    // }
    {
        //步进
        int n = 10;
        stepper (&n);
        printf("%d\n",n);
        for(int i=1; i<10; i++)
        {
            stepper(&n);
            printf("%d ",n);
        }
        printf("\n%d\n",n);
    }

    return 0;
}