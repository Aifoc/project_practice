#include <stdio.h>
#include <string.h>
// 1. 计算 n的阶乘。
// 2. 计算 1!+2!+3!+……+10!
// 3. 在一个有序数组中查找具体的某个数字n。（讲解二分查找）
// 4. 编写代码，演示多个字符从两端移动，向中间汇聚。
// 5. 编写代码实现，模拟用户登录情景，并且只能登录三次。（只允许输入三次密码，如果密码正确则
// 提示登录成，如果三次均输入错误，则退出程序。

//n的阶乘(不支持浮点数)
int factorial (int n)//如果参数中已经声明为整型的话，即使调用的时候输入浮点也会向下取整
{
    if (n > 0)//排除负数和0的情况
    {
    int y = 1;
        for(n;n > 0;n--)//循环乘
        {
            y = y*n;
        }
    return y;
    }
    else if (n == 0)//0! = 1
    {
        return 1;
    }
    else//负数没有阶乘
    {
        return 0;
    }

}

//计算Σ(i=1,n)i!的值(不支持浮点数)
int sigma_factorial (int n)
{
    if (n >= 1)//因为最小从1开始，所以只有大于等于1的n才能使用该函数
    {
        int y = 0;
        for (int i = 1; i < n+1; i++)//循环加上阶乘
        {
            y = factorial(i)+ y;
        }
        return y;
    }
    else
    {
        return 0;
    }
}

//用二分法查找有序数组中数字n
int find_arrnumber (int* arr ,int arr_length,int n)//传入想要找到的数字和相应的数组
//由于数组的存储机制是只记录首元素的地址信息，所以将数组作为参数传给函数时并不是把全部的数组元素都传递进去，
//而是只传首元素地址，这就意味着函数接收到的是地址信息，而不是单元素变量一样可以传值
//所以函数参数中的数组形参其实全都是指针，在函数下对数组形参进行操作时应将其视为指针
{
    //int arr_len = sizeof(arr) / sizeof(int);//算出数组的长度
    //由于只有数组的地址无法算出数组的长度，所以函数要求直接传递数组的长度
    int active = 1;
    int test_arrnum = 0;
    int arr_sort = arr_length/2;
    int step = arr_length/2;
    if (n < arr[arr_length-1])//当要找的数字不超过数组中最大的数字时运行（索引0是第一位，所以要把元素总量-1索引最后一位）
    {
        while (active)
        {
            if (n > arr[arr_sort])//根据长度计算出中间元素的值
            //指针后面[n]其实是偏移量的意思，整数就是向右偏移，负数就是向左偏移，
            //如果指针已经指向数组第一个元素那么负数偏移会报错
            {
                arr_sort = arr_sort+(step)/2;//更新索引
                if (step > 3)//因为上面把步进除了2，所以为了保证至少有1的步进需要让step的值不小于3
                {
                    step = step/2;//更新步进
                }
                test_arrnum = arr[arr_sort];//观察当前索引值
            }
            else if (n < arr[arr_sort])
            {
                arr_sort = arr_sort-(step)/2;//更新索引
                if (step > 3)
                {
                    step = step/2;//更新步进
                }
                test_arrnum = arr[arr_sort];//观察当前索引值
            }
            else//当n=索引的值时退出循环
                active = 0;
        }
        printf("\n%d => %d\n",n,arr[arr_sort]);
        return arr[arr_sort];//把索引的值返回
    }
    else
    {
        printf("\nThe n is greater than beigst number in array\n");
    }
}


//登录系统，三次错误退出程序
int login (char *user_name,char *user_password)
{
    int frequency = 3;//初始化验证次数
    char password[20];//初始化密码空间
    while (1)
    {
        printf ("Hello %s please enter the password\n->",user_name);
        scanf ("%s",password);//把用户输入的密码放入密码指针中
        char* d_password = password;//将密码放到密码指针，以和用户密码进行对比
        if (strcmp(d_password,user_password) == 0)//使用strcmp比对用户输入的密码是否和传入密码一致
            {
                printf("login success,welcome %s\n",user_name);
                return 1;
            }
        else
        {
            if(frequency != 0)//当尝试次数不为0时
            {
                frequency = frequency - 1;  //把验证次数-1
                printf("The password is wrong,please enter again,you still have %d more chances\n",frequency);
            }
            else//尝试次数为0时退出程序
            {
                printf("login failed\n");
                return 0;
            }
        }
    }
}



int main ()
{
    // {
    //     //阶乘
    //     int n = 0;
    //     if (factorial(n))
    //         printf("The factorial of %d  is %d\n",n,factorial(n));//因为函数有返回值，所以可以直接printf
    //     else
    //         printf("please enter int type number\n");
    // }
    // {
    //     //西格玛阶乘
    //     int n = 10;
    //     if (sigma_factorial(n))
    //         printf("sigma(i=1,%d)i! = %d\n",n,sigma_factorial(n));
    //     else
    //         printf("please enter a number greader than zero\n");
    // }
    // {
    //     //二分法找n
    //     int n = 5;//设定要找的n
    //     int arr[10] = {0};//初始化整型数组
    //     for (int i = 0;i < 10;i++)//创建有序数组
    //     {
    //         arr[i] = i;
    //         printf("%d,",arr[i]);
    //     }
    //     find_arrnumber(arr,10,n);
    // }
    {
        //登录系统
        char name[] = "admin";
        char password[] = "12345678";
        login(name,password);
    }

    return 0;
}