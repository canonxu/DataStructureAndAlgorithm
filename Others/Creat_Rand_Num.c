
/*
#include <stdio.h>
#include <stdlib.h>

//直接调用rand()生成的随机数是一次性的，即第一次运行输出41 18467 6334，以后每次运行输出都是41 18467 6334。
//这样的随机数值生成一下，以后若干次再运行都沿用第一次的生成数据。才运用时要谨慎使用！
//生成随机数的范围为0-RAND_MAX,在<stdlib>中定义了RAND_MAX的值，为2147483647（2^31 - 1）--int范围（-2^31+1 - 2^31）

int main()
{
    int x1 = rand();
    int x2 = rand();
    int x3 = rand();
    printf("%d %d %d ", x1, x2, x3);
    return 0;
}
*/

//生成0-100的随机数，则rand%100即可
//生成10-100的随机数，则10+rand%90即可

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//以上一次性输出与srand()函数有关。在调用rand()函数产生随机数前，必须先利用srand()设好随机数种子（seed）。
// 如果未用srand()设随机数种子, rand()在调用时会自动设随机数种子为1。上例就是因为没有设置随机数种子，每次随机数种子都自动设成相同值1所以rand()所产生的随机数值都一样。

//srand()函数定义 ： void srand ((unsigned int) seed);
//通常可以利用geypid()或time(0)的返回值来当做seed。如果你用time(0)的话，要加入头文件#include<time.h>
//time(0)返回当前的Unix时间戳：定义为从格林威治时间1970年01月01日00时00分00秒(北京时间1970年01月01日08时00分00秒)起至现在的总秒数
//time(0)%(60)获得当前秒数
//time%(60*60)/60
//time%(60*60*24)/3600为格林威治时间的小时  (time%(60*60*24)/3600 + 8)%24 转换成北京时间的小时

//第一次输出3430 6567 19015, 第二次输出3564 21268 30550, 第三次输出3662 16040 9419

int main()
{
    srand((unsigned int) time(0)); //只需添加#include<time.h>和srand((unsigned int) time(0))即可。 //若将此行time(0)改成常数如1，则每次输出都一样
    int x1 = rand();
    int x2 = rand();
    int x3 = rand();
    printf("%d %d %d", x1, x2, x3);

    return 0;


}
