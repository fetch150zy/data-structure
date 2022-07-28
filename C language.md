# C基础



## 数据类型

### 整型

-   **有符号整型**

    |      *有符号整型*      | *十进制输出格式化* | *八进制格式化输出* | *十六进制格式化输出* |
    | :--------------------: | :----------------: | :----------------: | :------------------: |
    |   *signed short int*   |       *%hd*        |    *%ho(%#ho)*     |     *%hx(%#hx)*      |
    |      *signed int*      |        *%d*        |     *%o(%#o)*      |      *%x(%#x)*       |
    |   *signed long int*    |       *%ld*        |    *%lo(%#lo)*     |     *%lx(%#lx)*      |
    | *signed long long int* |       *%lld*       |   *%llo(%#llo)*    |    *%llx(%#llx)*     |

    >   **tips:**	%X和%x均可实现十六进制输出（一个是大写形式，一个是小写形式）

    

-   **无符号整型**

    |       *无符号整型*       | *十进制格式化输出* | *八进制格式化输出* | *十六进制格式化输出* |
    | :----------------------: | :----------------: | :----------------: | :------------------: |
    |   *unsigned short int*   |       *%hu*        |       *%ho*        |        *%hx*         |
    |      *unsigned int*      |        *%u*        |        *%o*        |         *%x*         |
    |   *unsigned long int*    |       *%lu*        |       *%lo*        |        *%lx*         |
    | *unsigned long long int* |       *%llu*       |       *%llo*       |        *%llx*        |

    

### 浮点型

-   **浮点型格式化**

    |   *浮点数*    | *格式化输出* | *指数形式* | *十六进制* |
    | :-----------: | :----------: | :--------: | :--------: |
    |    *float*    |     *%f*     |    *%e*    |    *%a*    |
    |   *double*    |    *%lf*     |   *%le*    |   *%la*    |
    | *long double* |    *%llf*    |   *%lle*   |   *%lla*   |

    

### 字符型

-   **转义序列**

    | *转义序列* |    *含义*    | *转义序列* |   *含义*   |
    | :--------: | :----------: | :--------: | :--------: |
    |   *\ b*    |    *退格*    |   *\ \*    |  *反斜杠*  |
    |   *\ f*    |    *换页*    |   *\ ‘*    |  *单引号*  |
    |   *\ n*    |    *换行*    |   *\ “*    |  *双引号*  |
    |   *\ r*    |    *回车*    |   *\ ?*    |   *问号*   |
    |   *\ t*    | *水平制表符* |   *\0oo*   | *八进制数* |
    |   *\xhh*   | *十六进制数* |            |            |

    

-   **字符处理函数**

    |   *函数名*    | *如果是下列参数时返回值为真* |
    | :-----------: | :--------------------------: |
    | *isalnum( )*  |         *字母或数字*         |
    | *isalpha( )*  |            *字母*            |
    | *isblank( )*  |  *空格、水平制表符或换行符*  |
    | *iscntrl( )*  |          *控制字符*          |
    | *isdigit( )*  |            *数字*            |
    | *isgraph( )*  |  *除空格外的任意可打印字符*  |
    | *islower( )*  |          *小写字母*          |
    | *isprint( )*  |         *可打印字符*         |
    | *ispunct( )*  |          *标点符号*          |
    | *isspace( )*  |          *空白字符*          |
    | *isupper( )*  |          *大写字母*          |
    | *isxdigit( )* |       *十六进制数字符*       |

    >   上面所有函数均在头文件`ctype.h`中

    1.  **_两个字符映射函数_**

        |  *函数名*   |                     *行为*                     |
        | :---------: | :--------------------------------------------: |
        | *tolower()* | *如果是大写字符返回小写字符，否则返回原始参数* |
        | *toupper()* | *如果是小写字符返回大写字符，否则返回原始参数* |

        

### 其它

-   **虚数和复数**

    1.  **_complex.h提供的一些对复数进行基本操作的函数_**

        >   **creal**	         获取复数的实部
        >
        >   **cimag**		   获取复数的虚部
        >
        >   **conj**			  获取复数的共轭
        >
        >   **carg**			 获取复平面上穿过原点和复数在复平面表示的点,的直线和实数轴之间的夹角
        >
        >   **cproj**			返回复数在黎曼球面上的投影

    2.  **_两个虚数宏_**

        `_Complex_I` 和 `I`

    3.  **_Exp_**

        ```c
        complex double a = 3.0 + 4.0 * _Complex_I;
        complex double a = 3.0 + 4.0 * I;
        _Complex double a = 3.0 + 4.0 * _Complex_I;
        _Complex double a = 3.0 + 4.0 * I;
        ```

        

-   **布尔值**

    ```c
    #include <stdbool.h>
    // and you can use bool
    bool flag = false;
    // or use _Bool
    _Bool flag = true;
    ```

    

### 格式化输出

-   **格式**

    | *转换说明* |            *输出*             |
    | :--------: | :---------------------------: |
    | *%a    %A* | *浮点数、十六进制数、p计数法* |
    |    *%c*    |          *单个字符*           |
    | *%d    %i* |       *有符号十进制数*        |
    | *%e    %E* |        *浮点数e计数法*        |
    |    *%f*    |      *浮点数十进制计法*       |
    | *%g    %G* |  *根据值不同自动选择%f或%e*   |
    |    *%o*    |       *无符号八进制数*        |
    | *%x    %X* |      *无符号十六进制数*       |
    |    *%p*    |            *指针*             |
    |    *%s*    |           *字符串*            |
    |    *%u*    |       *无符号十进制数*        |
    |    *%%*    |           *百分号*            |

    

-   **修饰符**

    |  *修饰符*   |                            *含义*                            |
    | :---------: | :----------------------------------------------------------: |
    |   *标记*    |                *- + space 0<br>exp: “%-10d”*                 |
    |   *数字*    |                 *最小字段宽度<br>exp: “%4d”*                 |
    | *<br>.数字* | *精度<br>对于%e和%f转换，表示小数位数<br>对于%g转换，表示有效数字的最大位数<br>对于%s转换，表示打印字符的最大数量<br>对于整型转换，表示打印数字的最小位数，前补0<br>exp: “%5.2f”，字符宽度5，两位小数* |
    |     *h*     |     *表示short int 或 unsigned short int<br>exp: “%hu”*      |
    |    *hh*     |    *表示signed char 或 unsigned char的值<br>exp: “%hhu”*     |
    |     *j*     | *表示intmax_t或uintmax_t，这些类型定义在stdint.h中<br>exp: “%jd”* |
    | *l and ll*  | *表示long, unsigned long 和 long long, unsigned long long<br>exp: “%ld”    “%llu”* |
    |     *L*     | *和浮点型转换一起使用，表示long double类型的值<br>exp: “%Le”* |
    |     *t*     |       *表示ptrdiff_t（两个指针的差值）<br>exp: “%td”*        |
    |     *z*     |              *表示size_t类型的值<br>exp: “%zd”*              |

    

-   **标记**

    | *标记*  |                            *含义*                            |
    | :-----: | :----------------------------------------------------------: |
    |   *-*   |                   *左对齐， exp: “%-20s”*                    |
    |   *+*   | *有符号值若为正，显示加号，若为负，显示减号<br>exp: “%+6.2f”* |
    | *space* | *有符号值为正，前导空格，为负，值前面显示减号并覆盖一个空格<br>exp: “% 6.2f”* |
    |   *#*   | *%o 前导0，%x 前导0x<br>对于浮点数保证小数点后一定会打印一位* |
    |   *0*   |                           *前导0*                            |

    

### 运算符

-   **逻辑运算符**

    | *逻辑运算符* | *含义* | *iso646.h* |
    | :----------: | :----: | :--------: |
    |     *&&*     |  *与*  |   *and*    |
    |    *\|\|*    |  *或*  |    *or*    |
    |     *!*      |  *非*  |   *not*    |

    **三元运算符**	 `expression ? res1 : res2`



## 函数

### 使用函数

-   **函数原型（函数声明）**

    ```c
    return_type function_name(type args, ...);
    return_type function_name(type, ...);				// 可省略形参名
    ```

    

-   **函数定义**

    ```c
    return_type function_name(type args, ...)
    {
        /* something */
        return val;
    }
    ```

    >   当`return_type`为`void`时返回值为空`return ;`
    >
    >   当`args`为空时参数列表填入`void`

    

-   **函数调用**

    ```c
    return_type return_val = function_name(args, ...);
    ```

    

### 数组作为函数参数

-   **作为参数列表**

    1.  **_函数原型_**

        ```c
        type func(type *ar, type n);
        type func(type *, type);
        type func(type ar[], type n);
        type func(type [], type);		// 一维数组
        
        type func(type (*pt)[4]);
        type func(type pt[][4]);		// 二维数组
        ```

        

    2.  **_函数定义处_**

        ```c
        type func(type *arr, type n);
        type func(type arr[], type n);
        ```

        >   在函数定义处不能省略参数名

        

-   **作为返回值**

    >   谨慎操作，请勿将栈区内存指针作为返回值

    ```c
    type *func(args, ...)
    {
        type arr[] = {...};
        return arr;		// wrong
        type *arr = (type *)malloc(...);
        return arr;		// right
    }
    ```

    

### 函数和指针

-   **定义函数指针**

    ``` c
    void ToUpper(char *);
    int SumN(int *arr);
    void (*ptu)(char *);
    ptu = ToUpper;			// ok
    ptu = SumN;				// wrong
    ```

    >   类型要匹配

    

-   **两种语法**

    ```c
    void ToUpper(char *);
    void ToLower(char *);
    void (*pf)(char *);
    char mis[] = "Nina Metier";
    pf = ToUpper;
    (*pf)(mis); 	// 用法1
    pf = ToLower;
    pf(mis); 		// 用法2
    ```

    >   两种方法是等价的



## 数组

### 一维数组

-   **创建一维数组**

    ```c
    type arr[size];
    ```

    >   `size`必须是常量或常量表达式（如果你不是想使用VLA的话）

    1.  **_初始化数组_**

        ```c
        int powers[8] = {1, 2, 4, 8, 16, 32, 64};				// init the arr, size 8
        const int powers[8] = {1, 2, 4, 8, 16, 32, 64};			// read only
        int vals[4] = {1, 2};									// [1, 2, 0, 0]
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31};	// auto match
        size_t days_size = sizeof(days);
        int arr[6] = {[5] = 21};								/* designated initializer(指定初始化器)
        														   [0, 0, 0, 0, 0, 21] */
        int stuff[] = {1, [6] = 23};							// [1, 0, 0, 0, 0, 0, 23]
        int staff[] = {1, [3] = 4, 9, 10};						// [1, 0, 0, 4, 9, 10]
        ```

        

-   **使用一维数组**

    >   通过下标和指针两种形式

    ```c
    arr[pos], *(arr+pos);
    ```

    

### 二维及多维数组

-   **创建二维数组**

    ```c
    type arr[rows][cols];
    ```

    >   `rows cols`必须是常量或常量表达式

    1.  **_初始化_**

        ```c
        const int arr[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
        }
        int sq[2][3] = { {5, 6}, {7, 8} };				/* 5, 6, 0
        												   7, 8, 0 */
        int sq[2][3] = {5, 6, 7, 8};					/* 5, 6, 7
        												   8, 0, 0 */
        ```

    

-   **使用二维数组**

    >   指针和下标两种形式（具体用法在C进阶部分补充）

    ```c
    arr[rows][cols], *(*(arr+rows)+cols);
    ```

    

### VLA

```c
int sum2d(int rows, int cols, int arr[rows][cols]);
// 在函数原型中可以省略形参名
int sum2d(int, int, int arr[*][*])
```

>   rows cols必须定义在arr前



### 复合字面量

```c
/* 一个普通的数组声明（一维） */
int diva[2] = {10, 20};
// 复合字面量
(int [2]){10, 20};
(int []){1, 2, 3};

// 必须在创建复合字面量时就使用它
int *ptr = (int [2]){1, 2};

/* （二维） */
int (*ptr)[4];
ptr = (int [2][4]){{1, 2, 3, 4}, {5, 6, 7, 8}};
```



## 指针

### 指针和数组

`&(取地址)		*(解引用)`

```c
int arr[10] = {...};
int *ptr = arr;
/* *(ptr + i) = arr[i] = *(arr + i)
   ptr + i = &arr[i] = arr + i */

// 只有是指针变量时才能使用自增运算符
int arr[10];
int *ptr = arr;
ptr++;									// 合法
arr++;									// 不合法
```



### 指针与const

-   **const与数组**

    ```c
    type func(const type arr[]);
    ```

    >   在函数进行参数传递时若不想修改数组的内容可使用const修饰参数
    >
    >   >   只能把非const数据的地址赋给普通指针（c允许，但是更改值是未定义的，c++不允许）
    >   >
    >   >   可以把普通数据的地址赋给const指针
    >   >
    >   >   不要把const数组名作为实参传递给函数

    

-   **指针常量**

    ```c
    int arr[10] = {1, 2};
    int * const pc = arr;
    pc++;								// not allowed
    *(pc) = 100;						// allowed
    ```

    

-   **常量指针**

    ```c
    int arr[10] = {1, 2};
    const int *pc = arr;
    pc++;								// allowed
    *(pc) = 100;						// not allowed
    ```

    

###  指针的兼容性

```c
const int **p;				// 不能通过*p更改所指向的内容
int *p1;
const int n = 10;
p = &p1;
*p = &n;
*p1 = 10;					// 间接的更改了n的值
```

>   在进行两级解引用时，把非const指针赋给const指针也是不安全的



## 字符串

### 表示字符串

-   **定义字符串**

    1.  **_字符串字面量（字符串常量）_**

        ```c
        "i am a string.";
        // exp:
        printf("%s, %p, %c\n", "We", "are", *"space");
        // output: We, 0x1000000f61, s
        ```

        

    2.  **_字符串数组和初始化_**

        ```c
        char string[40] = "Hello, everyone.";
        char string[] = "If you can't think of anything, fake it.";
        char string[40] = {'H', 'e', 'l', 'l', 'o', '\0'};	// 没有'\0'就不是一个字符串而是一个字符数组
        const char *string = "Hello.";
        ```

        

    3.  **_数组和指针_**

        初始化数组把静态存储区的字符串拷贝到数组中
        初始化指针是把字符串的首地址赋给指针

        

    4.  **_字符串数组_**

        ```c
        const char *string[10] = {"hello", "hi"};
        char string[2][10] = {"hello", "hi"};
        ```

        >   推荐第一种写法，节省空间，第二种写法每个字符串都被储存了两遍（如果你不需要更改字符串的值）

    

-   **指针和字符串**

    `string = s （浅拷贝，只拷贝地址）`

    

### 字符串输入

-   **分配空间**

    ```c
    char name[100];
    ```

    

-   **字符串读入函数**

    1.  _**gets fgets gets_s**_

        -   _char \*gets(char *string)_

            ```c
            char string[100];
            gets(string);						// 不安全（已舍弃）
            ```

            

        -   _char *fgets(char *s, int size, FILE *stream)_

            ```c
            #define SIZE 40
            char buff[100];
            fgets(buff, SIZE, stdin);			// fgets会存储\n
            ```

            

        -   _char *gets_s(char *buffer,size_t sizeInCharacters)_

            ```c
            #define SIZE 100
            char buff[100];
            gets_s(buff, SIZE);					// gets_s会舍弃换行符
            ```

            >   当输入太长时使用fgets，其余情况gets_s可完美替换gets

        

    2.  **_scanf_**

        ```c
        char string[100];
        scanf("%10s", string); 
        ```

        >   scanf与gets一样不安全，但是可以使用%nd来限制读入宽度

        

### 字符串输出

-   **puts fputs**

    1.  **_int puts( const char *s)_**

        ```c
        char string[100] = "hello world.";
        puts(string);
        ```

        >   puts函数输出直到'\0'，并在结尾自动加上换行符

        

    2.  **_int fputs(const char *str, FILE *stream)_**

        ```c
        char string[100] = "hello c.";
        fputs(string, stdout);
        ```

        >   fputs不会在结尾自动加上换行符

        

    ***puts与gets配套使用，fgets与fputs配套使用***

    

-   **printf**

    ```c
    char string[100] = "hello c.";
    printf("%s\n", string);
    ```

    >   需要自己加上换行符

    

### 字符串函数

-   **strlen**

    1.  **_unsigned int strlen (char *s)_**

        ```c
        char string[] = "hello.";
        unsigned int lens = strlen(string);
        ```

    

-   **strcat strncat**

    1.  **_char *strcat(char *dest, const char *src)_**

        ```c
        char s1[] = "hello ";
        char s2[] = "hi.";
        strcat(s1, s2);
        // s1 = hello hi.
        ```

        

    2.  **_char *strncat(char *dest, const char *src, size_t n)_**

        ```c
        char s1[] = "hello ";
        char s2[] = "hi.";
        strncat(s1, s2, 1);
        // s1 = hello h
        ```

    

-   **strcmp strncmp**

    1.  **_int strcmp(const char *str1, const char *str2)_**

        ```c
        char str1[] = "ab";
        char str2[] = "aB";
        int res = strcmp(str1, str2);
        // res > 0 (b > B)
        ```

        ~~如果返回值小于 0，则表示 str1 小于 str2~~

        ~~如果返回值大于 0，则表示 str1 大于 str2~~

        ~~如果返回值等于 0，则表示 str1 等于 str2~~

        

    2.  **_int strncmp(const char *str1, const char *str2, size_t n)_**

        ```c
        char str1[] = "ab";
        char str2[] = "aB";
        int res = strcmp(str1, str2, 1);
        // res = 0 (a = a)
        ```

        

-   **strcpy strncpy**

    1.  _**char *strcpy(char *dest, const char *src)**_

        ```c
        char src[10];
        strcpy(src, "hello.");
        // src = "hello."
        ```

        

    2.  **_char *strncpy(char *dest, const char *src, size_t n)_**

        ```c
        char src[10];
        strcpy(src, "hello.", 2);
        // src = "he"
        ```

        

-   **sprintf**

    1.   **_int sprintf(char *str, char * format [, argument, ...])_**

         ```c
         char buf[80];
         sprintf(buf, "The ASCII code of a is %d.", 'a');
         // buf = "The ASCII code of a is 97."
         ```

    

### 字符串转化为数字(stdlib.h)

-   **atoi atof atol**

    1.  **_int atoi (const char * str)_**

        ```c
        char *string = "324";
        int num = atoi(string);
        // num = 324
        ```

        >   double atof (const char * str)
        >
        >   long atol(const char * str)

        

-   **strtol strtoul**

    1.   ___long strtol(const char * restrict nptr, char ** restrict endptr, int base)___

         >   restrict nptr 为要转换的字符串，restrict endptr 为第一个不能转换的字符的指针，base 为字符串所采用的进制

         ```c
         char string[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
         char *pend;
         long int ln1 = strtol(string, &pend, 10);				// 十进制
         long int ln2 = strtol(string, &pend, 16);				// 十六进制
         long int ln3 = strtol(string, &pend, 2);				// 二进制
         ```

         >   unsigned long strtol(const char * restrict nptr, char ** restrict endptr, int base)

         

-   **数字转化为字符串**

    `itoa ftoa sprintf`



## 文件输入/输出

### 与文件进行通信

-   **文件是什么**

    **_两种文件模式： 文本模式， 二进制模式_**

    >   _所有文件内容都以二进制形式存储_
    >
    >   >   _文件最初以二进制编码的字符表示文本，该文件就是文本文件_
    >   >
    >   >   _文件以二进制代表机器语言或数值数据（图片，音乐），该文件就是二进制文件_

    

-   **标准文件**

    **_标准输入 标准输出 标准错误输出_**



### 标准IO

关于exit(0) 和 return(0)
在最初的调用中，return (0) 和 exit(0) 一样
在递归程序中，exit(0) 会直接终止程序

-   **fopen( )函数**

    1.   **_FILE * fopen ( const char * filename, const char * mode )_**

         |       *模式字符串*       |                    *含义*                    |
         | :----------------------: | :------------------------------------------: |
         |          *“r”*           |               *读模式打开文件*               |
         |          *“w”*           |          *写模式打开文件（覆盖写）*          |
         |          *“a”*           |          *写模式打开文件（追加写）*          |
         |          *“r+”*          |          *读写模式打开（更新模式）*          |
         |          *“w+”*          |      *读写模式打开（更新模式），覆盖写*      |
         |          *“a+”*          |      *读写模式打开（更新模式），追加写*      |
         | *“rb” “wb” “ab” “ab+”..* |               *二进制模式打开*               |
         |   *“wx” “wbx” “w+x”..*   | *如果文件已存在或以独占模式打开，则打开失败* |

    

    **_对于UNIX 和 Linux这样只有一个文件类型的系统，二进制模式和非二进制模式一样_**
    _fopen( ) 将返回文件指针 (FILE)_

    

-   **getc putc**

    **_getc( ) putc( ) 与 getchar( ) putchar( ) 类似_**

    >   _int getc ( FILE * stream )_

    >   _int putc ( int character, FILE * stream )_

    **_当stream为stdin，getc = getchar，当stream为stdout，putc = putchar_**

    

-   **fclose( )函数**

    **_fclose( fp )函数关闭指定的文件，必要时刷新缓冲区_**

    >   _int fclose(FILE * stream)_

    _如果成功关闭，返回0,否则返回EOF_

    

-   **指向标准文件的指针**

    | *标准文件* | *文件指针* | *使用的设备* |
    | :--------: | :--------: | :----------: |
    | *标准输入* |  *stdin*   |    *键盘*    |
    | *标准输出* |  *stdout*  |   *显示器*   |
    | *标准错误* |  *stderr*  |   *显示器*   |



### 文件IO

-   **fprintf( ) 和 fscanf( ) 函数**

    >   _int fprintf(FILE *stream, const char *format, ...)_

    >   _int fscanf(FILE *stream, const char * format, ... )_

    

-   **fegts( ) 和 fputs( ) 函数**

    >   _char *fgets(char *buff, int size, FILE *stream)_

    >   _int fputs(const char *buff, FILE *stream)_

    **_tips:    fputs不会在末尾加换行符，fgets保留了换行符_**



### 随机访问

-   **fseek( ) ftell( )**

    >   _int fseek(FILE * stream, long offset, int whence)_

    >   _long ftell(FILE * stream)_

    | 模式       | 偏移量的起始点 |
    | ---------- | -------------- |
    | *SEEK_SET* | *文件开始处*   |
    | *SEEK_SUR* | *当前位置*     |
    | *SEEK_END* | *文件末尾*     |

    ```c
    fseek(fp, 0L, SEEK_SET); 		// 定位至文件开始处
    fseek(fp, 2L, SEEK_CUR); 		// 从文件当前位置前移2个字节
    fseek(fp, -10L, SEEK_END); 		// 从文件结尾处回退10个字节
    ```

    ```c
    FILE *fp = fopen("demo.txt","rb");  
    fseek(fp, 0L, SEEK_END);
    len = ftell(fp)+1;				// 获取文件的长
    ```

    **_tips:    移植性更好的方法是逐字节读取整个文件直到文件末尾来实现SEEK_END**

    

-   **fgetpos( ) 和 fsetpos( ) 函数**

    **_针对大文件_**

    >   _int fgetpos(FILE * restrict stream, fpos_t * restrict pos)_

    >   _int fsetpos(FILE *stream, const fpos_t *pos)_

    

### 其它标准IO函数

|                           函数原型                           |                             解释                             |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
|                _int ungetc(int c, FILE *fp)_                 |                 *用于把指定字符放回输入流中*                 |
|                    _int fflush(FILE *fp)_                    |         *刷新缓冲区，如果fp为空指针，刷新所有缓冲区*         |
| <br>_int setvbuf(FILE * restrict fp, char * restrict buf, int mode, size_t size)_ | *创建指定大小的缓冲区<br>_ IOFBF 完全缓冲<br>_ IOLBF 行缓冲<br>_ IONBF 无缓冲* |
| _size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict fp)_ |                    *把二进制数据写入文件*                    |
| _size_t fread(void * restrict ptr, size_t size, size_t nmemb, FILE * restrict fp)_ |              *从流中读入二进制数据存储到ptr中*               |
|                     _int feof(FILE *fp)_                     |              *检测到文件结尾时，feof返回非0值*               |
|                    _int ferror(FILE *fp)_                    |             *当读写出现错误时，ferror返回非0值*              |
|                  _void clearerr(FILE *fp)_                   |                 *对指定流的错误标志进行重置*                 |
|                    _FILE *tmpfile(void)_                     |             *创建临时文件，在程序结束时就被删除*             |
|                  _char *tmpnam(char *name)_                  | *参数为NULL时返回指向静态数组的指针，该数组包含创建的文件名* |
|              _int remove(char const *filename)_              |                        *删除指定文件*                        |
|       _int rename(char *oldname, char const *newname)_       |                         *更改文件名*                         |



## 结构和其他数据形式

### 定义结构

-   **创建结构及初始化**

    1.   **_创建结构及声明_**

         ```c
         struct name {...};
         struct name a;
         struct name *pa;
         ```

         ```c
         struct name {...}a;
         ```

         

    2.   **_结构体初始化_**

         ```c
         struct person {
             char name[10];
             int age;
         };
         struct person a = {
             "mark",
             18
         };
         ```

         

    3.   **_结构的指定初始化器_**

         ```c
         struct book gift = {
             .value = 25.99,
             .author = "James Broad",
             .title = "Rue for the Toad"
         };
         ```

         

-   **声明结构数组及访问成员**

    ```c
    struct book lib[MAXSIZE];
    lib[0].value;
    lib->value;					// 访问第一个元素的value成员
    ```

    

-   **嵌套结构**

    ```c
    struct person {unsigned int age; char bith[20]; char name[20];};
    struct book {
        person author;
        double value;
    };
    ```

    

### 指向结构的指针

-   **声明和初始化结构指针**

    ```c
    struct guys barney, fellows[20];
    struct guys *him = &barney;
    struct guys *him = fellow;
    ```

**_tips:    如果要用结构存储字符串，用字符数组作为成员比较简单。用指向char的指针也行，但是误用会导致严重后果_**

```c
 struct names {
     char *first;
     char *last;
 };
struct names veep = {"Brad", "Summers"};			// 没问题
struct names person;
scanf("%s", person.first);							// 危险（不要这样使用）
```



-   **结构、指针和malloc**

    >   **_使用malloc分配内存并使用指针存储地址_**

    ```c
    struct names {
        char *first;
        char *last;
    };
    struct names vp;
    vp->first = (char *)malloc(size;
    // 使用后 free
    free(vp->first);
    ```



### 关于结构一些特殊处理

-   **复合字面量和结构**

    ```c
    // exp:
    struct book {char title[10], char author[10], double value;};
    struct book readFirst;
    readFirst = (struct book){"Crime", "Fyodor", 11.25};
    ```

    **_还可以把复合字面量作为函数的参数_**

    

-   **伸缩型数组成员**

    **_数组成员必须是最后一个成员，且至少要有一个成员。使用时可以通过malloc来动态开辟任意大小的数组空间_**

    ```c
    struct demo {int a; int arr[];};
    struct demo *p;
    p = (struct demo *)malloc(sizeof(struct demo) + 5 * sizeof(int));
    p = (struct demo *)malloc(sizeof(struct demo) + 10 * sizeof(int));
    ```

    **_带伸缩型数组成员的结构有一些特殊处理要求_**

    >   _不能用结构进行复制或拷贝_
    >
    >   _不要以按值方式把这种结构传递给结构_
    >
    >   _不要使用带伸缩型数组成员的结构作为数组成员或另一个结构的成员_

    

-   **匿名结构**

    **_通过嵌套格式来实现匿名结构体_**

    ```c
    struct outer {
        int v;
        struct {
            char string[20], name[20];
        };
    };
    ```

    _使用时可以直接把匿名结构体中的成员看成outer的成员使用_

    

-   **把结构内容保存到文件**

    **_一般我们采用二进制格式写入_**

    1.  **使用fprintf( )**

        _效率比较低，可以通过固定字段宽度的格式来解决字段位置问题_

    2.  **使用fwrite( )**

        _一次读写整个记录而非一个字段_

        **_缺点是可能导致数据文件不具有可移植性_**



### 联合union

**_联合（union）是一种数据类型，能在同一个内存空间中存储不同的数据类型（不是同时存储）_**

-   **创建初始化union**

    ```c
    union hold {
        int digit;
        double bigfl;
        char letter;
    };
    union hold a;
    a.letter = 'A';
    union hold b = a;		// 用另一个union来初始化
    union hold c = {8};		// 初始化联合的digit成员
    union hold d = {.bigfl = 12.3};	// 指定初始化器初始化bigfl成员
    ```

    

-   **使用union**

    `.`表示正在使用哪种运算符， 和使用指针访问结构体一样，使用`->`

    

-   **匿名联合**

    >   与匿名结构类似

    ```c
    union data {
        int vp;
        union {double v; char ch;};
    };
    ```



### 枚举enum

**_可以使用枚举类型来声明符号名称表示整型常量_**

-   **创建枚举类型**

    ```c
    enum spectrum {red, orange, yellow, green, blue, violet};
    enum spectrum color;
    ```

    ```c
    color = blue;
    if (color == yellow);
    ...
    ```

    >   _枚举符是int类型，但是枚举变量可以是任意整数类型_

    **_C允许枚举变量使用++运算符，C++不允许，如果要将C代码并入C++程序，必须声明为int类型_**

    

-   **概念及用法**

    1.  **_enum常量_**

        >   _enum成员从技术层面上看就是int类型的常量_

    2.  **_默认值_**

        >   _默认情况下，枚举列表中的常量被赋予0, 1, 2…_

    3.  **_赋值_**

        >   _可以为枚举常量指定整数值_

        ```c
        enum feline {cat, lynx = 10, puma, tiger};
        ```

        **_cat值默认为0, lynx = 10, puma = 11, tiger = 12_**

    4.  **_enum用法_**

        **_枚举类型的目的就是为了提高程序的可读性和可维护性_**

    5.  **_共享名称空间_**

        **_两个不同作用域的同名变量不冲突，两个相同作用域的同名变量冲突_**

        ```c
        struct rect {double x; double y;};
        int rect;							// 不会产生冲突
        ```

        >   _结构，联合，枚举享有相同的名称空间_



### typedef

**_使用typedef可以为某一类型自定义名称_**

-   **与define的不同之处**

    1.  **_typedef创建的符号只受限于类型，不能用于值_**
    2.  **_typedef由编译器解释，不是预处理器_**
    3.  **_typedef更灵活_**

    

-   **使用**

    ```c
    typedef unsigned char byte;
    #define byte unsigned char
    
    typedef struct {...}name;	// 可省略结构标签
    ```



## 位操作

### C按位运算符

-   **按位逻辑运算符**

    | *逻辑运算* | *位操作符* |      *用处*      |
    | :--------: | :--------: | :--------------: |
    | *按位取反* |    *~*     |     *清空位*     |
    |  *按位与*  |    *&*     | *掩码（检查位）* |
    |  *按位或*  |    *\|*    |     *打开位*     |
    | *按位异或* |    *^*     |     *切换位*     |

    

-   **移位运算符**

    1.  _**左移：<<**_

        将其左侧运算对象每一位的值向左移动其右侧运算对象指定的位数  

        左侧运算对象移出左末端位的值丢失， 用0填充空出的位置

    2.  _**右移：>>**_

        将其左侧运算对象每一位的值向右移动其右侧运算对象指定的位数  

        左侧运算对象移出右末端位的值丢。 对于无符号类型， 用0 填充空出的位置  

        对于有符号类型， 其结果取决于机器。 空出的位置可用0填充， 或者用符号位（即， 最左端的位） 的副本填充

        

### 位字段

>   位字段通过结构体来创建

```c
struct box_props {
    bool opaque : 1 ;
    unsigned int fill_color : 3 ;
    unsigned int : 4 ;
    bool show_border : 1 ;
    unsigned int border_color : 3 ;
    unsigned int border_style : 2 ;
    unsigned int : 2 ;
    unsigned int big_bit : 26 ;
}demo;
demo.opaque = 1;			// 确保所赋的值在字段可容纳的范围
```

**_tips:    如果声明总位数超过一个unsigned int 类型大小，会用到下一个unsigned int 类型的存储位置_**

**_并且编译器会自动移动跨界的字段，保持unsigend int 的边界对齐_**

>   当相邻成员的类型相同时，如果它们的位宽之和小于类型的 sizeof 大小，那么后面的成员紧邻前一个成员存储，直到不能容纳为止；
>
>   如果它们的位宽之和大于类型的 sizeof 大小，那么后面的成员将从新的存储单元开始，其偏移量为类型大小的整数倍

>   当相邻成员的类型不同时，不同的编译器有不同的实现方案，GCC会压缩存储，而 VC/VS 不会

>   如果成员之间穿插着非位域成员，那么不会进行压缩



-   **无名位字段**

    ```c
    struct {
        unsigned int field1 : 1 ;
        unsigned int : 2 ;				// 无名位字段
        unsigned int field2 : 1 ;
        unsigned int : 0 ;				// 无名位字段
        unsigned int field3 : 1 ;
    } stuff;
    ```

    **_填充，强迫字段对齐_**



### 对齐特性

_Alignof运算符给出一个类型的对齐要求`size_t d_align = _Alignof(float)`

_Alignas 说明符指定一个变量或类型的对齐值`_Alignas(double) char c1`

对齐动态分配内存`void *aligned_alloc(size_t alignment, size_t size)`





# C进阶



## 预处理

### 编译流程

-   **编译器翻译**

    编译器把源代码中出现的字符映射到源字符集

    编译器定位每个反斜杠后面跟着换行符的实例， 并删除它们

    编译器把文本划分成预处理记号序列、 空白序列和注释序列

    

-   **预处理**

    1.  **_#define_**

        _使用define来定义明示常量（符号常量）_

        ```c
        #define TWO 2
        #define FOUR TWO*TWO
        #define PX printf("X is %d.\n", x)
        #define FMT "X is %d.\n"
        ```

        -   *字符型字符串 和 记号型字符串*

        -   *重定义常量*

            >   **_只有新定义和旧定义完全相同才允许重定义_**
            >
            >   >   _具有相同定义意味着替换体中的记号必须相同_  
            >   >
            >   >   _如果确实需要重定义常量，使用const和作用域规则更容易_

        -   *在 #define中使用参数*

            **_用于创建类函数宏_**

            ```c
            #define SQUARE(X) X*X
            ```

            **_用宏参数创建字符串：#运算符_**

            ```c
            #define PSQR(X) printf("The square of "#X" is %d.\n", ((X)*(X)));
            int t = 5;
            PSQR(t);		// The square of t is 25
            PSQR(5);		// The square of 5 is 25
            ```

            **_预处理器黏合剂：##运算符_**

            ```c
            #define XNAME(n) x##n
            int XNAME(1) = 10;			// x1 = 10
            int XNAME(x) = 20;			// xx = 20
            ```

            **_ 变参宏：… 和 _ _ VA _ ARGS _ _**

            ```c
            #define PR(...) printf(__VA_ARGS__)
            PR("Hello\n");
            PR("weight=%d, shipping=$%.2f\n", wt, sp); 
            ```

            >   _宏生成内联代码，执行效率上比函数高，但是多次调用内存开销大（宏本质上就是插入代码片段）_

            

    2.  **_文件包含：#include_**

        -   *#include的两种形式*

            文件名在尖括号里，告诉预处理器在标准系统目录中查找该文件

            文件名在双引号里，告诉预处理器首先在当前目录中（或文件名指定的其它目录中）查找该文件

        -   *使用头文件*

            **_头文件一般都含有以下内容：_**

            1.  明示常量
            2.  宏函数
            3.  函数声明
            4.  结构模板定义
            5.  类型定义

            >   还可以通过头文件声明外部变量供其它文件共享

            ```c
            int status = 0;				// 该变量具有文件作用域，在源代码文件
            extern int status;			// 在头文件中
            ```

            **_需要使用头文件的另一种情况是：_**

            使用具有文件作用域、 内部链接和const 限定符的变量或数组。 const 防止值被意外修改， static 意味着每个包含  
            该头文件的文件都获得一份副本。 因此， 不需要在一个文件中进行定义式声明， 在其他文件中进行引用式声明。



### 其他命令

-   **#undef**

    **_用于取消已定义的#define指令_**

    ```c
    #define LIMIT 100
    #undef LIMIT
    ```

    >   #define宏的作用域从它在文件中的声明处开始， 直到用#undef指令取消宏为止， 或延伸至文件尾（以二者中先满足的条件作为宏作用域的结  
    >   束） 。 另外还要注意， 如果宏通过头文件引入， 那么#define在文件中的位置取决于#include指令的位置。

    

-   **条件编译**

    1.  **_#ifdef #else #endif_**

        ```c
        #ifdef _LABEL		// 如果该宏已定义，执行 1
        /* ...1 */
        #else				// 否则执行 2
        /* ...2 */
        #endif
        ```

        

    2.  _**#ifndef**_

        >   _与#ifdef逻辑相反，使用类似_

        **_防止相同的宏被重复定义_**

        ```c
        #ifndef _LABEL
        #define _LABEL
        #endif
        ```

        **_防止多次包含同一个文件_**

        ```c
        #ifndef THINGS_H_
        #define THINGS_H_
        /* ... */
        #endif
        ```

        

    3.  _**#if #elif**_

        >   _#if指令很像C语言中的if。 #if后面跟整型常量表达式， 如果表达式为非零， 则表达式为真。 可以在指令中使用C的关系运算符和逻辑运算符_

        ```c
        #if SYS == 1
        /* ... */
        #elif SYS == 0
        /* ... */
        #else
        /* ... */
        #endif
        ```

        -   *另一种方式实现#ifdef*

            ```c
            #if defined (IBMPC)
            /* ... */
            #elif defined (VAX)
            /* ... */
            #else
            /* ... */
            #endif
            ```

            

-    **预定义宏**

     |          宏          |                        含义                        |
     | :------------------: | :------------------------------------------------: |
     |     _ _ DATE _ _     |                    预处理的时间                    |
     |     _ _ FILE _ _     |         表示当前源代码文件名的字符串字面量         |
     |     _ _ LINE _ _     |         表示当前源代码文件中行号的整型常量         |
     |     _ _ STDC _ _     |            设置为1时，表明实现遵循C标准            |
     | _ _ STDC_HOSTED _ _  |            本机环境设置为1,否则设置为0             |
     | _ _ STDC_VERSION _ _ | 支持C99标准设置为199901L；支持C11标准设置为201112L |
     |     _ _ TIME _ _     |                   翻译代码的时间                   |

     

-   **#line #error**

    **_#line指令重置 _ _ LINE _ _ 和 _ _ FILE _ _ 宏报告的行号和文件名_**

    ```c
    #line 1000				// 重置行号
    #line 10 "main.c"		// 重置行号和文件名
    ```

    **_#error指令让预处理器发出一条错误消息，该消息包含指令中的文本，如果可能的话编译应该中断_**

    ```c
    #if __STDC_VERSION__ != 201112L
    #error Not C11
    #endif
    ```

    

-   **#pragma**

    **_#pragma把编译器指令放入了源代码中_**

    ```c
    #pragma c9x on
    _Pragma("nonstandardtreatmenttypeB on");
    #pragma nonstandardtreatmenttypeB on			// 等价
    
    // _Pragma 运算符完成“解字符串”（destringizing） 的工作
    _Pragma("use_bool \"true \"false");
    #pragma use_bool "true "false
    ```

    

    1.  **_#pragma message_**

        _在编译信息输出窗口中输出相应的信息，这对于源代码信息的控制是非常重要_

        ```c
        #ifdef _X86
        #Pragma message(“_X86 macro activated!”)
        #endif
        ```

        

    2.  **_#pragma code_seg_**

        ```c
        #pragma code_seg( ["section-name"[,"section-class"] ] )
        ```

        _设置程序中函数代码存放的代码段，当我们开发驱动程序的时候就会使用到它_

        

    3.  **_#pragma once_**

        _只要在头文件的最开始加入这条指令就能够保证头文件被编译一次_

        

    4.  **_#pragma hdrstop_**

        _表示预编译头文件到此为止，后面的头文件不进行预编译，排除一些头文件_

        

    5.  **_#pragma startup_**

        _单元之间有依赖关系，需要指定编译优先级，通过#pragma startup来指定编译优先级_

        

    6.  **_#pragma resource_**

        ```c
        #pragma resource "*.dfm"
        ```

        _表示把*.dfm 文件中的资源加入工程_

        

    7.  _**#pragma warning**_

        ```c
        #pragma warning( disable : 4507 34; once : 4385; error : 164 )
        
        #pragma warning(disable:4507 34) 	// 不显示 4507 和 34 号警告信息
        #pragma warning(once:4385) 			// 4385 号警告信息仅报告一次
        #pragma warning(error:164) 			// 把 164 号警告信息作为一个错误
        ```

        ```c
        #pragma warning( push [ ,n ] )		// 保存现在所有警告信息的现有警告状态，并把全局警告等级设为n(1-4)
        #pragma warning( pop )				// 向栈中弹出最后一个警告信息，在入栈和出栈之间所作的一切改动取消
        
        #pragma warning( push )
        #pragma warning( disable : 4705 )
        #pragma warning( disable : 4706 )
        #pragma warning( disable : 4707 )
        //.......
        #pragma warning( pop )				// 重新保存所有的警告信息(包括 4705， 4706 和 4707)
        ```

        

    8.  _**#pragma comment**_

        _将一个注释记录放入一个对象文件或可执行文件中_

        ```c
        #pragma comment(lib, "user32.lib")
        // 将 user32.lib 库文件加入到本工程中
        ```

        ```c
        #pragma comment(linker, "/include:__mySymbol")
        ```

        >   _linker:将一个链接选项放入目标文件中,你可以使用这个指令来代替由命令行传入的或  
        >   者在开发环境中设置的链接选项,你可以指定/include 选项来强制包含某个对象_

        

    9.  _**#pragma pack**_

        ```c
        struct TestStruct1 {	//编译器默认进行内存对齐（浪费了存储空间）
            char c1; short s; char c2; int i;
        }; //  c1 00000000, s 00000002, c2 00000004, i 00000008
        
        struct TestStruct2 {	// 小技巧来优化
            char c1; char c2; short s; int i;
        };
        ```

        -   _利用#pragma pack（）来改变编译器的默认对齐方式_

            ```c
            使用指令#pragma pack (n)，编译器将按照 n 个字节对齐
            使用指令#pragma pack ()，编译器将取消自定义字节对齐方式
            ```

            

        ```c
        #pragma pack(push) 				//保存当前对其方式到 packing stack
        
        #pragma pack(push,n)
        #pragma pack(push)
        #pragma pack(n) 				//n=1,2,4,8,16 保存当前对齐方式，设置按 n 字节对齐
        #pragma pack(pop) 				//packing stack 出栈，并将对其方式设置为出栈的对齐方
        ```

        

    

-   **泛型选择**

    >   __Generic(x, int: 0, float: 1, double: 2, default: 3)_



### 内联函数

**_规定了内联函数的定义与调用该函数的代码必须在同一个文件中_**

```c
inline static void eatline() // 内联函数定义/原型
{ 
    ...
}
```

_内联函数应该比较短小。 把较长的函数变成内联并未节约多少时间， 因为执行函数体的时间比调用函数的时间长得多_  

如果程序有多个文件都要使用某个内联函数， 那么这些文件中都必须包含该内联函数的定义。 最简单的做法是， 把内联  

函数定义放入头文件， 并在使用该内联函数的文件中包含该头文件即可。



### const & define

**_const为只读变量，在C语言中使用const修饰的变量仍然为变量_**

-   **const 更加节省空间，避免了不必要的内存分配，同时提高了效率**

    >   _编译器通常不为普通 const 只读变量分配存储空间，而是将它们保存在符号表中_
    >
    >   _const 定义的只读变量在程序运行过程中只有一份拷贝（因为它是全局的只读变量，存放在静态区）_
    >
    >   _#define 定义的宏常量在内存中有若干个拷贝_



## 指针和数组

**_指针是指针，数组是数组_**

### 两种访问形式

-   **指针和数组均可以通过下表和解引用形式来访问元素**

    ```c
    int arr[] = {1, 2, 3};
    int *arr = a;
    
    arr[0], arr[1], arr[2];
    *(arr), *(arr+1), *(arr+2);			// right
    ```

    

-   **指针和数组的区别**

    1.  **_sizeof_**

        ```c
        int *pa, a[10];
        sizeof(pa) == 8;		// 64位操作系统下（寻址能力为8字节）
        sizeof(a) == 40;		// sizeof(int) * 10 = 40
        ```

        

    2.  **_访问流程_**

        当你通过指针变量去访问数组时，先访问内存获取指针的值（即数组首地址），再通过地址指针来访问数据。  

        在定义数组时，编译器在某个地方保存了数组首地址，通过数组名访问数组时，直接计算偏移量然后直接访问。

        

    3.  **_左值与右值_**

        >   _指针变量可以是右值和左值，可以使用自增运算符。数组名是左值，不可改变。_

        

    4.  **_易错_**

        ```c
        // file 1
        int arr[10];
        // file 2
        extern int *arr;			
        ```

        >   _定义为数组，声明为指针和定义为指针，声明为数组均错误。_

        

### 一维二维数组与指针

-   **_一维_**

    ```c
    int arr[10];
    int *p1 = &arr[0];
    int *p2 = arr;
    *(p1 + pos), p1[pos];
    ```

    

    ```c
    int (*p3)[10] = &arr;
    *(*p3 + pos), (*p3)[pos];
    ```

    

-   **_二维_**

    ```c
    int arr[rows][cols];
    int *p1 = &arr[0][0];
    int *p2 = arr[0];
    *(p1+i*cols+j), p1[i*cols+j];
    ```

    

    ```c
    int (*p3)[10] = &arr[0];
    int (*p4)[10] = arr;
    *(*(p3+i)+j), p3[i][j];
    ```

    

    ```c
    int (*p5)[5][10] = &arr;
    *(*(*p5+i)+j), (*p5)[i][j];
    ```



### 指针数组与函数指针

-   **指针数组**

    ```c
    char *pa[5];
    char **ppa;
    ```

    

-   **函数指针**

    ```c
    char* func(char *s);
    char* (*pf)(char *s);
    pf = &func, /* or */ pf = func;
    ```

    1.  **_函数指针数组_**

        ```c
        char* (*pf[5])(char *s);
        pf[0] = &func;
        ```

        

    2.  **_函数指针数组指针_**

        ```c
        char* (*(*pf)[5])(char *s);
        pf[0][0] = &func;
        ```

        

## 内存管理

### 堆 栈 静态区

-   ==静态区==：**保存自动全局变量和 static 变量（包括 static 全局和局部变量）**

    **静态区的内容在总个程序的生命周期内都存在由编译器在编译的时候分配**

    

-   ==栈==：**保存局部变量。栈上的内容只在函数的范围内存在，当函数运行结束**

    **这些内容也会自动被销毁。其特点是效率高，但空间大小有限**

    

-   ==堆==：**由 malloc 系列函数或 new 操作符分配的内存。其生命周期由 free 或 delete 决定。
    在没有释放之前一直存在，直到程序结束。其特点是使用灵活，空间比较大，但容易出错**



### 常见的内存错误

-   **函数的入口检验**

    ```c
    assert(NULL != p); 		// 函数入口处
    
    if (NULL != p);			// 非参数处
    ```

    **_在使用这些检验时都要求p在定义时被初始化为NULL_**

    >   _assert是一个宏，当括号里面值为假，程序终止并报错_
    >
    >   >   **_这个宏只在debug版本上起作用，在release版本被编译器优化掉_**



### 存储类别

-   **作用域**
    _作用域描述程序中可访问标识符的区域_

    1.  **_块作用域_**

        >   _变量x, y只在该块内有效_

        ```c
        func {
            x, y;
        }
        ```

        

    2.  **_文件作用域_**

        >   _从它的定义处到该定义所在文件的末尾均可见_
        >
        >   _这样的变量可用于多个函数， 所以文件作用域变量也称为全局变量（global variable）_

        

-   **链接**

    *C 变量有 3 种链接属性： 外部链接、 内部链接、或无链接*
    *具有块作用域、 函数作用域或函数原型作用域的变量都是无链接变量*
    *具有文件作用域的变量才可以是外部链接和内部链接*

    >   内部链接的文件作用域		文件作用域
    >
    >   外部链接的文件作用域  	  全局作用域（程序作用域）

    1.  **_static修饰符_**

        ````c
        int giants = 5;					// 外部链接
        static int dodgers = 3;			// 内部链接
        ````

        

-   **存储期**
    *C对象有4种存储期： 静态存储期、 线程存储期、 自动存储期、 动态分配存储期*

    >   1.所有的文件作用域变量都具有静态存储期
    >
    >   2.具有线程存储期的对象，从声明时到线程结束一直存在。_Thread_local声明一个对象时，每个线程都获得该变量的私有备份
    >
    >   3.块作用域的变量（局部变量）通常具有自动存储期。使用static在块中声明的局部变量具有静态存储期

    

    |   存储类别   | 存储期 | 作用域 | 链接 |      声明方式      |
    | :----------: | :----: | :----: | :--: | :----------------: |
    |     自动     |  自动  |   块   |  无  |        块内        |
    |    寄存器    |  自动  |   块   |  无  |   块内，register   |
    | 静态外部链接 |  静态  |  文件  | 外部 |     所有函数外     |
    | 静态内部链接 |  静态  |  文件  | 内部 | 所有函数外，static |
    |  静态无链接  |  静态  |   块   |  无  |    块内，static    |

    

-   **自动变量**

    >   _属于自动存储类别的变量具有自动存储期、 块作用域且无链接。 默认情况下， 声明在块或函数头中的任何变量都属于自动存储类别。为了显式表达可以使用auto关键字_

    ```c
    {	// block
        auto int x = 100;			// 自动存储类别的变量
    }
    ```

    

-   **寄存器变量**

    >   _寄存器变量和自动变量都一样。 也就是说， 它们都是块作用域、 无链接和自动存储期。 使用存储类别说明符register便可声明寄存器变量_

    ```c
    {	// block
        register int x = 100;		// 自动存储类别（更快，但是不能对该变量使用地址运算符）
    }
    ```

    

-   **块作用域的静态变量**

    >   _自动变量一样， 具有相同的作用域， 但是程序离开它们所在的函数后， 这些变量不会消失。 也就是说， 这种变量具有块作用域、 无链接， 但是具有静态存储期_

    ```c
    {	// block
        static int x = 100;
    }
    ```

    ***tips:	不能在函数的形参中使用static***

    

-   **外部链接的静态变量**

    _外部链接的静态变量具有文件作用域、 外部链接和静态存储期_

    ```c
    int errupt;					// 外部定义的变量
    double up[100];				// 外部定义的数组
    extern char coal;			// coal定义在另一个文件（必须要加extern）
    
    function {
        extern int errupt;
        extern double up[];			// 可选的声明（非必须）
    }
    ```

    _如果不得已要使用与外部变量名同名的局部变量，可以在局部变量的声明中使用auto存储类别说明符来表达这种意图_

    1.  **_初始化外部变量_**

        >   _外部变量和自动变量类似，也可以被显式初始化，未初始化的会被自动初始化为0，并且只能使用常量表达式来初始化_

        ```c
        ...
        int x = 10;
        int y = x * 2;					// not allowed
        int main(void) {return 0;}
        ```

        

    2.  **_使用外部变量_**

        ```c
        int x;
        main {
            extern int x;			// extern可选
            // op x
        }
        func {
            // op x
        }
        ```

        

    3.  **_定义和声明_**

        >   _外部变量只能初始化一次，且必须在定义该变量时进行_

        ```c
        // file_one.c
        char permis = 'N';
        ...
        // file_two.c
        extern char permis = 'Y';		// 错误（变量在file_one.c中已经创建并初始化
        ```

        

-   **内部链接的静态变量**
    _内部链接的静态变量具有静态存储期、文件作用域和内部链接_

    ```c
    static int svil = 1;		// 静态变量，内部链接
    func {
        extern int svil = 1;
    }
    ```

    

-   **多文件**
    _在一个文件中进行定义式声明，然后在其它文件中进行引用式声明来实现共享_

-   **存储类别说明符**
    ***auto register static extern _Thread_local typedef***

    >   _Thread_local例外，可以和static或extern一起使用

    1.  **_auto_**

        >   _auto说明符表明变量是自动存储期， 只能用于块作用域的变量声明中。_
        >
        >   _在块中声明的变量本身就具有自动存储期， 所以使用auto主要是为了明_
        >
        >   _确表达要使用与外部变量同名的局部变量的意图。_

    2.  **_register_**

        >   _register说明符也只用于块作用域的变量， 它把变量归为寄存器存储类_
        >
        >   _别， 请求最快速度访问该变量。 同时， 还保护了该变量的地址不被获取。_

    3.  **_static_**
        _static 说明符创建的对象具有静态存储期， 载入程序时创建对象， 当程序结束时对象消失。_

        >   _static 用于文件作用域声明， 作用域受限于该文件_

        >   _static 用于块作用域声明， 作用域则受限于该块_

    4.  **_extern_**

        _extern 说明符表明声明的变量定义在别处_

        >   _如果包含 extern 的声明具有文件作用域， 则引用的变量必须具有外部链接。_

        >   _如果包含 extern 的声明具有块作用域， 则引用的变量可能具有外部链接或内部链接_

        

-   **存储类别和函数**
    ***外部函数 静态函数 内联函数***

    1.  **_外部函数（默认）_**

        >   _外部函数可以被其它文件的函数访问_

        ```c
        // file 1
        double quick_pow(double x, int n);
        
        // file 2
        extern double quick_pow(double x, int n);
        ```

        

    2.  **_静态函数_**

        >   _使用static修饰，只能在本文件中调用_

        ```c
        static double quick_pow(double x, int n);
        ```

    ***tips:    用extern关键字声明定义在其他文件中的函数。 这样做是为了表明当前文件中使用的函数被定义在别处。 除非使用static关键字，
    否则一般函数声明都默认为extern。***

    

### 分配内存

-   **malloc free**
    ***malloc返回值强转为匹配的类型，提高可读性。如果malloc分配内存失败将返回空指针***

    1.  ***malloc***

        ```c
        double *ptd;
        ptd = (double *)malloc(size * sizeof(double));		// 比变长数组更灵活
        ```

        

    2.  ***free***

        >   _通常malloc()要和free()配套使用_

        ```c
        double *ptd = (double *)malloc(size * sizeof(double));
        free(ptd);
        ```

        **_tips:	free很重要，对于动态开辟的内存不使用时一定要free防止内存泄漏_**

    

-   **calloc**
    **_与malloc类似，要存储不同的类型，应使用强制类型转换_**

    ```c
    long *ptr;
    ptr = (long *)calloc(size, sizeof(long));
    free(ptr);
    ```

    

-   **VLA和动态内存分配**

    >   _变长数组是自动存储类别，在块结束时变长数组占用的内存会自动释放_
    >
    >   _被调函数创建一个数组并返回指针， 供主调函数访问， 然后主调函数在末尾调用free()释放之前被调函数分配的内存_
    >
    >   _free()所用的指针变量可以与 malloc()的指针变量不同， 但是两个指针必须储存相同的地址。 但是， 不能释放同一块内存两次_

    **_在多维数组方面，使用变长数组更方便_**

    ```c
    int m = 5, n = 6;
    int ar2[m][n];
    
    int (*p)[n];
    p = (int(*)[n])malloc(m*n*sizeof(int));				// m x n
    ```

    

-   **存储类别和动态内存分配**

    1.  **_静态数据（字符串字面量）占用一个区域_**
    2.  **_自动存储类别的变量所占用的内存通常作为栈来处理_**
    3.  **_动态开辟的内存要比栈慢，占用内存堆或自由内存_**



### ANSI C类型限定符

**_const volatie restrict _Atomic_**

-   **const**

    >   _const对于全局变量_

    ```c
    // file 1.c
    const double PI = 3.14;
    const int arr[] = {1, 2};
    
    // file 2.c
    extern const double PI;
    extern const int arr[];
    ```

    >   _使用头文件来解决，在需要使用到的C文件中添加该头文件即可_

    ```c
    // head.h
    static const double PI = 3.14;
    static const int arr[] = {1, 2};
    
    // file.c
    #include "head.h"		// and then you can use PI and arr
    ```

    **_tips:   如果数据过大不建议使用这种方式_**

    

-   **volatile**
    **_volatile涉及到编译器优化，主要用于声明一些易变的变量_**

    ```c
    volatile int cnt = 0;
    ...				// cnt++
    ```

    

-   **restrict**
    **_允许编译器优化某部分代码以更好地支持计算，只能用于指针，表明该指针是访问数据对象的唯一且初始化的方式_**

    ```c
    int * restrict restar = (int *)malloc(size * sizeof(int));
    // restar是访问这块内存区域唯一且初始化的方式
    
    // exp:
    restar[1] += 2;
    restar[1] += 3;
    // 被编译器替换为
    restar[1] += 5;
    ```

    

-   **_Atomic （C11）**

    ```c
    int hogs;
    hogs = 10;
    
    _Atomic int hogs;
    atomic_store(&hogs, 10);		// stdatomic.h中的宏
    ```

    >   _hogs存储10是一个原子过程，其它线程不能访问hogs_

    

-   **旧关键字的新位置**

    ```c
    void ofmouth(int * const a1, int * restrict a2, int n); // 以前的风格
    void ofmouth(int a1[const], int a2[restrict], int n); 	// C99允许
    double stick(double ar[static 20]);						// 还要指定数组大小，方便编译器优化代码
    ```



## 编码风格

### 合理规范头文件

-   **原则**

    1.  **_头文件适合放接口的声明,不适合放置实践_**

        >   头文件是模块（Module）或单元（Unit）的对外接口。头文件中应放置对外部的声明，如对外提供的函数声明、宏定义、类型定义等

        -   _内部使用的函数（相当于类的私有方法）声明不应放在头文件中_
        -   _内部使用的宏、枚举、结构定义不应放入头文件中_
        -   _变量定义不应放在头文件中，应放在.c文件中_
        -   _变量的声明尽量不要放在头文件中，亦即尽量不要使用全局变量作为接口。变量是模块或单元的内部实现细节，不应通过在头文件中声明的方式直接暴露给外部，应通过函数接口的方式进行对外暴露。即使必须使用全局变量，也只应当在.c中定义全局变量，在.h中仅声明变量为全局的_

    2.  **_头文件应当职责单一_**

        >   头文件过于复杂，依赖过于复杂是导致编译时间过长的主要原因。很多现有代码中头文件过大，职责过多，再加上循环依赖的问题，可能导致为了在.c中使用一个宏，而包含十几个头文件

    3.  **_头文件应向稳定的方向包含_**

        >   头文件的包含关系是一种依赖，一般来说，应当让不稳定的模块依赖稳定的模块，从而当不稳定的模块发生变化时，不会影响（编译）稳定的模块

        >   除了不稳定的模块依赖于稳定的模块外，更好的方式是两个模块共同依赖于接口，这样任何一个模块的内部实现更改都不需要重新编译另外一个模块。在这里，我们假设接口本身是最稳定的

        

-   **规则**

    1.  **_每一个.c文件应有一个同名.h文件，用于声明需要对外公开的接口_**

        >   如果一个.c文件不需要对外公布任何接口，则其就不应当存在，除非它是程序的入口，如main函数所在的文件

        现有某些产品中，习惯一个.c文件对应两个头文件，一个用于存放对外公开的接口，一个用于存放内部需要用到的定义、声明等，以控制.c文件的代码行    数。编者不提倡这种风格。这种风格的根源在于源文件过大，应首先考虑拆分.c文件，使之不至于太大。另外，一旦把私有定义、声明放到独立的头文件  中，就无法从技术上避免别人include之，难以保证这些定义最后真的只是私有的

        

        本规则反过来并不一定成立。有些特别简单的头文件，如命令ID定义头文件，不需要有对应的.c存在

        -   _源文件内部的函数调用关系_

            ```c
            static void bar();
            void foo() { bar(); }
            void bar() { Do something; }
            ```

            >   这一类的函数声明，应当在.c的头部声明，并声明为static的

            

    2.  **_ 禁止头文件循环依赖_**

        >   头文件循环依赖，指a.h包含b.h，b.h包含c.h，c.h包含a.h之类导致任何一个头文件修改，都导致所有包含了a.h/b.h/c.h的代码全部重新编译一遍。而如果是单向依赖，如a.h包含b.h，b.h包含c.h，而c.h不包含任何头文件，则修改a.h不会导致包含了b.h/c.h的源代码重新编译

        

    3.  **_.c/.h文件禁止包含用不到的头文件_**

        >   很多系统中头文件包含关系复杂，开发人员为了省事起见，可能不会去一一钻研，直接包含一切想到的头文件，甚至有些产品干脆发布了一个god.h，其中包含了所有头文件，然后发布给各个项目组使用，这种只图一时省事的做法，导致整个系统的编译时间进一步恶化，并对后来人的维护造成了巨大的麻烦

        

    4.  **_头文件应当自包含_**

        >   简单的说，自包含就是任意一个头文件均可独立编译。如果一个文件包含某个头文件，还要包含另外一个头文件才能工作的话，就会增加交流障碍，给这个头文件的用户增添不必要的负担

        

    5.  **_总是编写内部#include保护符（#define 保护）_**

        >   多次包含一个头文件可以通过认真的设计来避免。如果不能做到这一点，就需要采取阻止头文件内容被包含多于一次的机制

        -   _通常的手段是为每个文件配置一个宏，当头文件第一次被包含时就定义这个宏，并在头文件被再次包含时使用它以排除文件内容_
        -   _所有头文件都应当使用#define 防止头文件被多重包含，命名格式为FILENAME_H，为了保证唯一性，更好的命名是PROJECTNAME_PATH_FILENAME_H_

        

        **_定义包含保护符时，应该遵守如下规则_**

        -   _保护符使用唯一名称_

        -   _不要在受保护部分的前后放置代码或者注释_

            ```c
            #ifndef VOS_INCLUDE_TIMER_TIMER_H
            #define VOS_INCLUDE_TIMER_TIMER_H
            ...
            #endif
            ```

            

            例外情况：头文件的版权声明部分以及头文件的整体注释部分（如阐述此头文件的开发背景、使用注意事项等）可以放在保护符(#ifndef XX_H)前面

            

    6.  **_禁止在头文件中定义变量_**

        >   在头文件中定义变量，将会由于头文件被其他.c文件包含而导致变量重复定义

        

    7.  **_只能通过包含头文件的方式使用其他.c提供的接口，禁止在.c中通过extern的方式使用外部函数接口、变量_**

        >   若a.c使用了b.c定义的foo()函数，则应当在b.h中声明extern int foo(int input)；并在a.c中通过#include 来使用foo。禁止通过在a.c中直接写extern int foo(int input);来使用foo，后面这种写法容易在foo改变时可能导致声明和定义不一致

        

    8.  **_ 禁止在extern "C"中包含头文件_**

        >   在extern "C"中包含头文件，会导致extern "C"嵌套，Visual Studio对extern "C"嵌套层次有限制，嵌套层次太多会编译错误

        -   _导致被包含头文件的原有意图遭到破坏_

            ```c
            #ifndef A_H__
            #define A_H__
            
            #ifdef __cplusplus
            void foo(int);
            #define a(value) foo(value)
            #else
            void a(int)
            #endif
            
            #endif /* A_H__ */
            #ifndef B_H__
            #define B_H__
            
            #ifdef __cplusplus
            extern "C" {
            #endif
            
            #include "a.h"
                void b();
            
            #ifdef __cplusplus
            }
            #endif
            
            #endif /* B_H__ */
            ```

            使用C++预处理器展开b.h，将会得到

            ```c
            extern "C" {
                void foo(int);
                void b();
            }
            ```

            按照a.h作者的本意，函数foo是一个C++自由函数，其链接规范为"C++"。但在b.h中，由于#include "a.h"被放到了extern "C" { }的内部，函数foo的链接规范被不正确地更改了

            ```c
            #include "xxx.h"
            extern "C"
            {
                ...
            }
            ```

            

-   **建议**

    1.  **_一个模块通常包含多个.c文件，建议放在同一个目录下，目录名即为模块名。为方便外部使用者，建议每一个模块提供一个.h，文件名为目录名_**

        >   需要注意的是，这个.h并不是简单的包含所有内部的.h，它是为了模块使用者的方便，对外整体提供的模块接口

        

    2.  **_ 如果一个模块包含多个子模块，则建议每一个子模块提供一个对外的.h，文件名为子模块名_**

        >   降低接口使用者的编写难度

        

    3.  **_头文件不要使用非习惯用法的扩展名，如.inc_**

    4.  **_同一产品统一包含头文件排列方式_**

        >   常见的包含头文件排列方式：功能块排序、文件名升序、稳定度排序

        -   _exp:_

            ```c
            #include <a.h>
            #include <b.h>
            #include <c/d.h>
            #include <c/e.h>
            #include <f.h>
            ```

            >   升序方式排列头文件可以避免头文件被重复包含

            

            ```c
            #include <product.h>
            #include <platform.h>
            ```

            >   稳定度排序，建议将不稳定的头文件放在前面，如把产品的头文件放在平台的头文件前面

            

### 函数

-   **原则**

    1.  **_一个函数仅完成一个功能_**

        >   一个函数实现多个功能给开发、使用、维护都带来很大的困难

        

    2.  **_重复代码应该尽可能提炼成函数_**

        >   重复代码提炼成函数可以带来维护成本的降低

        

-   **规则**

    1.  **_避免函数过长,新增函数不超过50行(非空非注释行)_**

        >   本规则仅对新增函数做要求，对已有函数修改时，建议不增加代码行

    2.  **_避免函数的代码块嵌套过深，新增函数的代码块嵌套不超过4层_**

        >   本规则仅对新增函数做要求，对已有的代码建议不增加嵌套层次

    3.  **_可重入函数应避免使用共享变量；若需要使用，则应通过互斥手段（关中断、信号量）对其加以保护_**

        >   可重入函数是指可能被多个任务并发调用的函数。在多任务操作系统中，函数具有可重入性是多个任务可以共用此函数的必要条件。
        >
        >   共享变量指的全局变量和static变量

        ```c
        int g_exam;
        unsigned int example( int para )
        {
            unsigned int temp;
        
            [申请信号量操作]    // 若申请不到“信号量”，说明另外的进程正处于
            g_exam = para;     //给g_exam赋值并计算其平方过程中（即正在使用此
            temp = square_exam( );  // 信号），本进程必须等待其释放信号后，才可继
            [释放信号量操作]    // 续执行。其它线程必须等待本线程释放信号量后
            // 才能再使用本信号。
            return temp;
        }
        ```

        

    4.  **_对参数的合法性检查，由调用者负责还是由接口函数负责，应在项目组/模块内应统一规定。缺省由调用者负责_**

        >   对于模块间接口函数的参数的合法性检查这一问题，往往有两个极端现象，即：要么是调用者和被调用者对参数均不作合法性检查，结果就遗漏了合法性检查这一必要的处理过程，造成问题隐患；要么就是调用者和被调用者均对参数进行合法性检查，这种情况虽不会造成问题，但产生了冗余代码，降低了效率

        

    5.  **_对函数的错误返回码要全面处理_**

        >   一个函数（标准库中的函数/第三方库函数/用户定义的函数）能够提供一些指示错误发生的方法。这可以通过使用错误标记、特殊的返回数据或者其他手段，不管什么时候函数提供了这样的机制，调用程序应该在函数返回时立刻检查错误指示

        ```c
        FILE *fp = fopen( "./writeAlarmLastTime.log","r");
        if (fp == NULL)
        {
            return;
        }
        char buff[128] = "";
        fscanf(fp,“%s”, buff); /* 读取最新的告警时间；由于文件writeAlarmLastTime.log为空，导致buff为空 */
        fclose(fp);
        long fileTime = getAlarmTime(buff); /* 解析获取最新的告警时间；getAlarmTime函数未检查buff指针，导致宕机 */
        ```

        

    6.  **_设计高扇入，合理扇出（小于7）的函数_**

        >   扇出是指一个函数直接调用（控制）其它函数的数目，而扇入是指有多少上级函数调用它。
        >
        >   扇出过大，表明函数过分复杂，需要控制和协调过多的下级函数；而扇出过小，例如：总是1，表明函数的调用层次可能过多，这样不利于程序阅读
        >
        >   和函数结构的分析，并且程序运行时会对系统资源如堆栈空间等造成压力。通常函数比较合理的扇出（调度函数除外）通常是3~5

        -   _扇出太大，一般是由于缺乏中间层次，可适当增加中间层次的函数。扇出太小，可把下级函数进一步分解多个函数，或合并到上级函数中。当然分解或合并函数时，不能改变要实现的功能，也不能违背函数间的独立性_
        -   _扇入越大，表明使用此函数的上级函数越多，这样的函数使用效率高，但不能违背函数间的独立性而单纯地追求高扇入。公共模块中的函数及底层函数应该有较高的扇入_

        

    7.  **废弃代码（没有被调用的函数和变量)要及时清除**

        >   程序中的废弃代码不仅占用额外的空间，而且还常常影响程序的功能与性能，很可能给程序的测试、维护等造成不必要的麻烦

        

-   **建议**

    1.  **_函数不变参数使用const_**

        >   不变的值更易于理解/跟踪和分析，把const作为默认选项，在编译时会对其进行检查，使代码更牢固/更安全

        

    2.  **_函数应避免使用全局变量、静态局部变量和I/O操作，不可避免的地方应集中使用_**

        >   带有内部“存储器”的函数的功能可能是不可预测的，因为它的输出可能取决于内部存储器（如某标记）的状态。这样的函数既不易于理解又不利于测试和维护。在C语言中，函数的static局部变量是函数的内部存储器，有可能使函数的功能不可预测，然而，当某函数的返回值为指针类型时，则必须是static的局部变量的地址作为返回值，若为auto类，则返回为错针

        

    3.  **_检查函数所有非参数输入的有效性，如数据文件、公共变量等_**

        >   函数的输入主要有两种：一种是参数输入；另一种是全局变量、数据文件的输入，即非参数输入。函数在使用输入参数之前，应进行有效性检查

        ```c
        hr = root_node->get_first_child(&log_item); // list.xml 为空，导致读出log_item为空
        ...
        hr = log_item->get_next_sibling(&media_next_node); // log_item为空，导致宕机
        ```

        

    4.  **_ 函数的参数个数不超过5个_**

        >   函数的参数过多，会使得该函数易于受外部（其他部分的代码）变化的影响，从而影响维护工作。函数的参数过多同时也会增大测试的工作量

        

    5.  **_除打印类函数外，不要使用可变长参函数_**

        >   可变长参函数的处理过程比较复杂容易引入错误，而且性能也比较低，使用过多的可变长参函数将导致函数的维护难度大大增加

        

    6.  **_ 在源文件范围内声明和定义的所有函数，除非外部可见，否则应该增加static关键字_**

        >   如果一个函数只是在同一文件中的其他地方调用，那么就用static声明。使用static确保只是在声明它的文件中是可见的，并且避免了和其他文件或库中的相同标识符发生混淆的可能性

        建议定义一个STATIC宏，在调试阶段，将STATIC定义为static，版本发布时，改为空，以便于后续的打热补丁等操作

        ```c
        #ifdef _DEBUG
        #define STATIC static
        #else
        #define STATIC
        #endif
        ```

        

### 标识符命名与定义

#### 通用命名规则

-   **原则**

    1.  **_标识符的命名要清晰、明了，有明确含义，同时使用完整的单词或大家基本可以理解的缩写_**

        >   尽可能给出描述性名称，不要节约空间，让别人很快理解你的代码更重要

        ```c
        int error_number;
        int number_of_completed_connection;
        ```

        

    2.  **除了常见的通用缩写以外，不使用单词缩写，不得使用汉语拼音**

        >   较短的单词可通过去掉“元音”形成缩写，较长的单词可取单词的头几个字母形成缩写，一些单词有大家公认的缩写，常用单词的缩写必须统一。协议中的单词的缩写与协议保持一致。对于某个系统使用的专用缩写应该在注视或者某处做统一说明

        

-   **规则**

    1.  **_产品/项目组内部应保持统一的命名风格_**

        >   Unix like和windows like风格均有其拥趸，产品应根据自己的部署平台，选择其中一种，并在产品内部保持一致

        

-   **建议**

    1.  **_用正确的反义词组命名具有互斥意义的变量或相反动作的函数等_**

    2.  **_尽量避免名字中出现数字编号，除非逻辑上的确需要编号_**

    3.  **_标识符前不应添加模块、项目、产品、部门的名称作为前缀_**

        >   很多已有代码中已经习惯在文件名中增加模块名，这种写法类似匈牙利命名法，导致文件名不可读，并且带来带来如下问题

    4.  **_平台/驱动等适配代码的标识符命名风格保持和平台/驱动一致_**

    5.  **_ 重构/修改部分代码时，应保持和原有代码的命名风格一致_**

        >   根据源代码现有的风格继续编写代码，有利于保持总体一致



#### 文件命名规则

-   **建议**

    1.  **_文件命名统一采用小写字符_**

        >   因为不同系统对文件名大小写处理会不同（如MS的DOS、Windows系统不区分大小写，但是Linux系统则区分），所以代码文件命名建议统一采用全小写字母命名



#### 变量命名规则

-   **规则**
    1.  ***全局变量应增加“g_”前缀***
    2.  ***静态变量应增加“s_”前缀***
    3.  **_禁止使用单字节命名变量，但允许定义i、j、k作为局部循环变量_**
-   **建议**
    1.  **_不建议使用匈牙利命名法_**
    2.  **_使用名词或者形容词＋名词方式命名变量_**



#### 函数命名规则

-   **建议**

    1.  **_函数命名应以函数要执行的动作命名，一般采用动词或者动词＋名词的结构_**

        ```c
        DWORD GetCurrentDirectory( DWORD BufferLength, LPTSTR Buffer );
        ```

        

    2.  **_函数指针除了前缀，其他按照函数的命名规则命名_**



#### 宏的命名规则

-   **规则**

    1.  **_对于数值或者字符串等等常量的定义，建议采用全大写字母，单词之间加下划线‘_’的方式命名（枚举同样建议使用此方式定义）_**

        ```c
        #define PI_ROUNDED 3.14
        ```

        

    2.  ***除了头文件或编译开关等特殊标识定义，宏定义不能使用下划线‘_’开头和结尾***



### 变量

-   **原则**

    1.  **_一个变量只有一个功能，不能把一个变量用作多种用途_**

        >   一个变量只用来表示一个特定功能，不能把一个变量作多种用途，即同一变量取值不同时，其代表的意义也不同

        

    2.  **_结构功能单一；不要设计面面俱到的数据结构_**

        >   相关的一组信息才是构成一个结构体的基础，结构的定义应该可以明确的描述一个对象，而不是一组相关性不强的数据的集合

        

    3.  **_不用或者少用全局变量_**

        >   单个文件内部可以使用static的全局变量，可以将其理解为类的私有成员变量

        全局变量应该是模块的私有数据，不能作用对外的接口使用，使用static类型定义，可以有效防止外部文件的非正常访问，建议定义一个STATIC宏，在调试阶段，将STATIC定义为static，版本发布时，改为空，以便于后续的打补丁等操作

        ```c
        #ifdef _DEBUG
        #define STATIC static
        #else
        #define STATIC
        #endif
        ```

        

-   **规则**

    1.  **_防止局部变量与全局变量同名_**

        >   尽管局部变量和全局变量的作用域不同而不会发生语法错误，但容易使人误解

        

    2.  **_ 通讯过程中使用的结构，必须注意字节序_**

        >   对于这种跨平台的交互，数据成员发送前，都应该进行主机序到网络序的转换；接收时，也必须进行网络序到主机序的转换

        

    3.  **_严禁使用未经初始化的变量作为右值_**

        >   在首次使用前初始化变量，初始化的地方离使用的地方越近越好。可以有效避免未初始化错误

        

-   **建议**

    1.  **_构造仅有一个模块或函数可以修改、创建，而其余有关模块或函数只访问的全局变量，防止多个不同模块或函数都可以修改、创建同一全局变量的现象_**

        >   降低全局变量耦合度

        

    2.  **_使用面向接口编程思想，通过API访问数据：如果本模块的数据需要对外部模块开放，应提供接口函数来设置、获取，同时注意全局数据的访问互斥_**

        >   避免直接暴露内部数据给外部模型使用，是防止模块间耦合最简单有效的方法

        

    3.  **_在首次使用前初始化变量，初始化的地方离使用的地方越近越好_**

        >   未初始化变量是C和C++程序中错误的常见来源。在变量首次使用前确保正确初始化

        

    4.  **_明确全局变量的初始化顺序，避免跨模块的初始化依赖_**

        >   系统启动阶段，使用全局变量前，要考虑到该全局变量在什么时候初始化，使用全局变量和初始化全局变量，两者之间的时序关系，谁先谁后，一定要分析清楚，不然后果往往是低级而又灾难性的

        

    5.  **_尽量减少没有必要的数据类型默认转换与强制转换_**

        >   当进行数据类型强制转换时，其数据的意义、转换后的取值等都有可能发生变化，而这些细节若考虑不周，就很有可能留下隐患



### 宏 常量

-   **规则**

    1.  **_用宏定义表达式时，要使用完备的括号_**

        >   因为宏只是简单的代码替换，不会像函数一样先将参数计算后，再传递

        ```c
        #define RECTANGLE_AREA(a, b) a * b
        #define RECTANGLE_AREA(a, b) (a * b)
        #define RECTANGLE_AREA(a, b) (a) * (b)		// 有风险
        #define RECTANGLE_AREA(a, b) ((a) * (b))	// 安全
        ```

        

    2.  **_将宏所定义的多条表达式放在大括号中_**

        >   更好的方法是多条语句写成do while(0)的方式

        ```c
        #define FOO(x) do { \
            printf("arg is %s\n", x); \
            do_something_useful(x); \
        } while(0)
        ```

        

    3.  **_使用宏时，不允许参数发生变化_**

        ```c
        #define SQUARE(a) ((a) * (a))
        int a = 5;
        int b;
        b = SQUARE(a++); // 结果：a = 7，即执行了两次增。
        ```

        

    4.  **_不允许直接使用魔鬼数字_**

        >   使用魔鬼数字的弊端：代码难以理解；如果一个有含义的数字多处使用，一旦需要修改这个数值，代价惨重

        对于局部使用的唯一含义的魔鬼数字，可以在代码周围增加说明注释，也可以定义局部const变量，变量命名自注释。

        对于广泛使用的数字，必须定义const全局变量/宏；同样变量/宏命名应是自注释的。

        0作为一个特殊的数字，作为一般默认值使用没有歧义时，不用特别定义。

        

-   **建议**

    1.  **_除非必要，应尽可能使用函数代替宏_**

    2.  **_常量建议使用const定义代替宏_**

    3.  **_宏定义中尽量不使用return、goto、continue、break等改变程序流程的语句_**

        >   如果在宏定义中使用这些改变流程的语句，很容易引起资源泄漏问题，使用者很难自己察觉



### 代码质量

-   **原则**

    1.  **_代码质量保证优先原则_**

        -   _正确性，指程序要实现设计要求的功能_
        -   _简洁性，指程序易于理解并且易于实现_
        -   _可维护性，指程序被修改的能力，包括纠错、改进、新需求或功能规格变化的适应能力_
        -   _可靠性，指程序在给定时间间隔和环境条件下，按设计要求成功运行程序的概率_
        -   _代码可测试性，指软件发现故障并隔离、定位故障的能力，以及在一定的时间和成本前提下，进行测试设计、测试执行的能力_
        -   _代码性能高效，指是尽可能少地占用系统资源，包括内存和执行时间_
        -   _可移植性，指为了在原来设计的特定环境之外运行，对系统进行修改的能力_
        -   _个人表达方式/个人方便性，指个人编程习惯_

        

    2.  **_必须了解编译系统的内存分配方式，特别是编译系统对不同类型的变量的内存分配规则，如局部变量在何处分配、静态变量在何处分配等_**

        

    3.  **_不仅关注接口，同样要关注实现_**

    

-   **规则**

    1.  **_禁止内存操作越界_**

        >   内存操作主要是指对数组、指针、内存地址等的操作。内存操作越界是软件系统主要错误之一，后果往往非常严重，所以当我们进行这些操作时一定要仔细小心

        坚持下列措施可以避免内存越界：

        -   _数组的大小要考虑最大情况，避免数组分配空间不够_
        -   _避免使用危险函数sprintf/vsprintf/strcpy/strcat/gets操作字符串，使用相对安全的函数snprintf/strncpy/strncat/fgets代替_
        -   _使用memcpy/memset时一定要确保长度不要越界_
        -   _字符串考虑最后的'\0'，确保所有字符串是以'\0'结束_
        -   _指针加减操作时，考虑指针类型长度_
        -   _数组下标进行检查_
        -   _使用时sizeof或者strlen计算结构/字符串长度，避免手工计算_

        

    2.  **_禁止内存泄漏_**

        >   内存和资源（包括定时器/文件句柄/Socket/队列/信号量/GUI等各种资源）泄漏是常见的错误

        ```c
        MsgDBDEV = (PDBDevMsg)GetBuff( sizeof( DBDevMsg ), __LINE__);
        if (MsgDBDEV == NULL) 
        {
            return;
        } 
        MsgDBAppToLogic = (LPDBSelfMsg)GetBuff( sizeof(DBSelfMsg), __LINE__ );
        if ( MsgDBAppToLogic == NULL ) 
        {
            return; //MsgDB_DEV指向的内存丢失
        }
        ```

        坚持下列措施可以避免内存泄漏：

        -   异常出口处检查内存、定时器/文件句柄/Socket/队列/信号量/GUI等资源是否全部释放
        -   删除结构指针时，必须从底层向上层顺序删除
        -   使用指针数组时，确保在释放数组时，数组中的每个元素指针是否已经提前被释放了
        -   避免重复分配内存
        -   小心使用有return、break语句的宏，确保前面资源已经释放
        -   检查队列中每个成员是否释放

        

    3.  **_ 禁止引用已经释放的内存空间_**

        >   在实际编程过程中，稍不留心就会出现在一个模块中释放了某个内存块，而另一模块在随后的某个时刻又使用了它。要防止这种情况发生

        ```c
        int* foobar (void)
        {
            int local_auto = 100;
            return &local_auto;
        }
        ```

        坚持下列措施可以避免引用已经释放的内存空间：

        -   内存释放后，把指针置为NULL；使用内存指针前进行非空判断。
        -   耦合度较强的模块互相调用时，一定要仔细考虑其调用关系，防止已经删除的对象被再次使用。
        -   避免操作已发送消息的内存。
        -   自动存储对象的地址不应赋值给其他的在第一个对象已经停止存在后仍然保持的对象（具有更大作用域的对象或者静态对象或者从一个函数返回的对象）

        

    4.  **_ 编程时，要防止差1错误_**

        >   此类错误一般是由于把“<=”误写成“<”或“>=”误写成“>”等造成的，由此引起的后果，很多情况下是很严重的，所以编程时，一定要在这些地方小心。当编完程序后，应对这些操作符进行彻底检查。使用变量时要注意其边界值的情况

        

    5.  **_所有的if ... else if结构应该由else子句结束；switch语句必须有default分支_**

        

-   **建议**

    1.  **_函数中分配的内存，在函数退出之前要释放_**

        

    2.  **_if语句尽量加上else分支，对没有else分支的语句要小心对待_**

        

    3.  **_不要滥用goto语句_**

        

    4.  **_时刻注意表达式是否会上溢、下溢_**



### 程序效率

-   **原则**

    1.  **在保证软件系统的正确性、简洁、可维护性、可靠性及可测性的前提下，提高代码效率**

        >   不能一味地追求代码效率，而对软件的正确、简洁、可维护性、可靠性及可测性造成影响 

        ```c
        int foo() {
            if (异常条件) {
                异常处理;
                return ERR_CODE_1;
            }
            if (异常条件) {
                异常处理;
                return ERR_CODE_2;
            }
            正常处理;
            return SUCCESS;
        }
        ```

        ```c
        int foo() {
            if (满足条件) {
                正常处理;
                return SUCCESS;
            }
            else if (概率比较大的异常条件) {
                异常处理;
                return ERR_CODE_1;
            }
            else {
                异常处理;
                return ERR_CODE_2;
            }
        }
        ```

        除非证明foo函数是性能瓶颈，否则按照本规则，应优先选用前面一种写法

        

    2.  **_通过对数据结构、程序算法的优化来提高效率_**

        

-   **建议**

    1.  **_将不变条件的计算移到循环体外_**

        

    2.  **_对于多维大数组，避免来回跳跃式访问数组成员_**

        ```c
        for (int i = 0; i < SIZE_B; i++)
        {
            for (int j = 0; j < SIZE_A; j++)
            {
                sum += x[i][j];
            }
        }
        ```

        SIZE_B 数值较大时，这种写法效率更高

        

    3.  **_创建资源库，以减少分配对象的开销_**

        >   使用线程池机制，避免线程频繁创建、销毁的系统调用；使用内存池，对于频繁申请、释放的小块内存，一次性申请一个大块的内存，当系统申请内存时，从内存池获取小块内存，使用完毕再释放到内存池中，避免内存申请释放的频繁系统调用

        

    4.  **_将多次被调用的 “小函数”改为inline函数或者宏实现_**

        >   如果编译器支持inline，可以采用inline函数。否则可以采用宏



### 注释

-   **原则**

    1.  **_优秀的代码可以自我解释，不通过注释即可轻易读懂_**

        

    2.  **_注释的内容要清楚、明了，含义准确，防止注释二义性_**

        >   有歧义的注释反而会导致维护者更难看懂代码

        

    3.  **_在代码的功能、意图层次上进行注释，即注释解释代码难以直接表达的意图，而不是重复描述代码_**

        >   注释的目的是解释代码的目的、功能和采用的方法，提供代码以外的信息，帮助读者理解代码，防止没必要的重复注释信息
        >
        >   注释不是为了名词解释（what），而是说明用途（why）

        

-   **规则**

    1.  **_修改代码时，维护代码周边的所有注释，以保证注释与代码的一致性。不再有用的注释要删除_**

        >   不要将无用的代码留在注释中，随时可以从源代码配置库中找回代码；即使只是想暂时排除代码，也要留个标注，不然可能会忘记处理它

        

    2.  **_文件头部应进行注释，注释必须列出：版权说明、版本号、生成日期、作者姓名、工号、内容、功能说明、与其它文件的关系、修改日志等，头文件的注释中还应有函数功能简要说明_**

        >   通常头文件要对功能和用法作简单说明，源文件包含了更多的实现细节或算法讨论

        ```c
        /*************************************************
        Copyright © Huawei Technologies Co., Ltd. 1998-2011. All rights reserved.
        File name:      // 文件名
        Author:        ID：      Version:       Date: // 作者、工号、版本及完成日期
        Description:    // 用于详细说明此程序文件完成的主要功能，与其他模块
                        // 或函数的接口，输出值、取值范围、含义及参数间的控
                        // 制、顺序、独立或依赖等关系
        Others:         // 其它内容的说明
        History:        // 修改历史记录列表，每条修改记录应包括修改日期、修改
                        // 者及修改内容简述 
            1. Date:
            Author:               ID:
            Modification:
            2. ...
        *************************************************/
        ```

        

    3.  **_函数声明处注释描述函数功能、性能及用法，包括输入和输出参数、函数返回值、可重入的要求等；定义处详细描述函数功能和实现要点，如实现的简要步骤、实现的理由、设计约束_**

        >   重要的、复杂的函数，提供外部使用的接口函数应编写详细的注释

        

    4.  **_全局变量要有较详细的注释，包括对其功能、取值范围以及存取时注意事项等的说明_**

        ```c
        /* The ErrorCode when SCCP translate */
        /* Global Title failure, as follows */      /* 变量作用、含义*/
        /* 0 －SUCCESS   1 －GT Table error */
        /* 2 －GT error  Others －no use  */       /* 变量取值范围*/
        /* only  function  SCCPTranslate() in */
        /* this modual can modify it,  and  other */
        /* module can visit it through call */
        /* the  function GetGTTransErrorCode() */    /* 使用方法*/
        BYTE g_GTTranErrorCode;
        ```

        

    5.  **_注释应放在其代码上方相邻位置或右方，不可放在下面。如放于上方则需与其上面的代码用空行隔开，且与下方代码缩进相同_**

        exp:

        ```c
        /* active statistic task number */
        #define MAX_ACT_TASK_NUMBER 1000
        
        #define MAX_ACT_TASK_NUMBER 1000 /* active statistic task number */
        ```

        按如下形式说明枚举/数据/联合结构

        ```c
        /* sccp interface with sccp user primitive message name */
        enum SCCP_USER_PRIMITIVE
        {
            N_UNITDATA_IND, /* sccp notify sccp user unit data come */
            N_NOTICE_IND, /* sccp notify user the No.7 network can not transmission this message */
            N_UNITDATA_REQ, /* sccp user's unit data transmission request*/
        };
        ```

        

    6.  **_对于switch语句下的case语句，如果因为特殊情况需要处理完一个case后进入下一个case处理，必须在该case语句处理完、下一个case语句前加上明确的注释_**

        >   这样比较清楚程序编写者的意图，有效防止无故遗漏break语句

        ```c
        case CMD_FWD:
            ProcessFwd();
            /* now jump into case CMD_A */
        case CMD_A:
            ProcessA();
            break;
        // 对于中间无处理的连续case，已能较清晰说明意图，不强制注释
        ```

        

    7.  **_避免在注释中使用缩写，除非是业界通用或子系统内标准化的缩写_**

        

    8.  **_同一产品或项目组统一注释风格_**

        

-   **建议**

    1.  **_避免在一行代码或表达式的中间插入注释_**

        >   除非必要，不应在代码或表达中间插入注释，否则容易使代码可理解性变差

        

    2.  **_注释应考虑程序易读及外观排版的因素，使用的语言若是中、英兼有的，建议多使用中文，除非能用非常流利准确的英文表达_**

        >   注释语言不统一，影响程序易读性和外观排版，出于对维护人员的考虑，建议使用中文

        

    3.  **_文件头、函数头、全局常量变量、类型定义的注释格式采用工具可识别的格式_**

        >   采用工具可识别的注释格式，例如doxygen格式，方便工具导出注释形成帮助文档

        -   _文件头_

            ```c
            /** 
            *  @file           （本文件的文件名eg：mib.h）
            *  @brief          （本文件实现的功能的简述）
            *  @version 1.1    （版本声明）
            *  @author        （作者，eg：张三）
            *  @date          （文件创建日期，eg：2010年12月15日）
            */
            ```

            

        -   _函数头_

            ```c
            /**
            *@ Description:向接收方发送SET请求
            * @param req - 指向整个SNMP SET 请求报文.
            * @param ind - 需要处理的subrequest 索引.
            * @return 成功：SNMP_ERROR_SUCCESS，失败：SNMP_ERROR_COMITFAIL
            */
            
            Int commit_set_request(Request *req, int ind);
            ```

            

        -   _全局变量_

            ```c
            /**  模拟的Agent MIB */
            agentpp_simulation_mib * g_agtSimMib;
            ```

            

### 排版与格式

-   **文件内容的一般规则**

    1.   **_各个源文件必须有一个头文件说明，头文件各部分内容_**

         -   _Header File Header Section_
         -   _Multi-Include-Prevent Section_
         -   _Debug Switch Section_
         -   _Include File Section_
         -   _Macro Define Section_
         -   _Structure Define Section_
         -   _Prototype Declare Section_

         ```c
         /************************************************************************
         * 文件名 版权信息 模块名 创建日期
         * 作者/岗位
         * 文件描述
         *---------------------------Revision History-----------------------------
         * 文件版本及更改信息
         ************************************************************************/
         /* Multi-Include-Prevent Section */
         #ifndef __FN_FILENAME_H
         #define __FN_FILENAME_H
         /* Debug switch Section */
         #define D_DISP_BASE
         /* Include File Section */
         #include "IncFile.h"
         /* Macro Define Section */
         #define MAX_TIMER_OUT (4)
         /* Struct Define Section */
         typedef struct CM_RadiationDose
         {
             unsigned char ucCtgID;
             char cPatId_a[MAX_PATI_LEN];
         }CM_RadiationDose_st, *CM_RadiationDose_pst;
         /* Prototype Declare Section */
         unsigned int MD_guiGetScanTimes(void);
         #endif
         ```

         

    2.   **_源文件内容_**

         -   _Source File Header Section_
         -   _Debug Switch Section_
         -   _Include File Section_
         -   _Macro Define Section_
         -   _Structure Define Section_
         -   _Prototype Declare Section_
         -   _Global Variable Declare Section_
         -   _File Static Variable Define Section_
         -   _Function Define Section_

         ```c
         /************************************************************************
         * 文件名 版权信息 模块名 创建日期
         * 作者/岗位
         * 文件描述
         *---------------------------Revision History-----------------------------
         * 文件版本及更改信息
         ************************************************************************/
         
         /* Debug switch Section */
         #define D_DISP_BASE
         
         /* Include File Section */
         #include "IncFile.h"
         
         /* Macro Define Section */
         #define MAX_TIMER_OUT (4)
         
         /* Structure Define Section */
         typedef struct CM_RadiationDose
         {
             unsigned char ucCtgID;
             char cPatId_a[MAX_PATI_LEN];
         }CM_RadiationDose_st, *pCM_RadiationDose_st;
         
         /* Prototype Declare Section */
         unsigned int MD_guiGetScanTimes(void);
         
         /* Global Variable Declare Section */
         extern unsigned int MD_guiHoldBreathStatus;
         
         /* File Static Variable Define Section */
         static unsigned int nuiNaviSysStatus;
         
         /* Function Define Section */
         ```

         

-   **规则**

    1.  **_程序块采用缩进风格编写，每级缩进为4个空格_**

        

    2.  **_相对独立的程序块之间、变量说明之后必须加空行_**

        

    3.  **_一条语句不能过长，如不能拆分需要分行写。一行到底多少字符换行比较合适，产品可以自行确定_**

        换行时有如下建议：

        -   _换行时要增加一级缩进，使代码可读性更好_
        -   _低优先级操作符处划分新行；换行时操作符应该也放下来，放在新行首_
        -   _换行时建议一个完整的语句放在一行，不要根据字符数断行_

        

    4.  **_多个短语句（包括赋值语句）不允许写在同一行内，即一行只写一条语句_**

        

    5.  **_if、for、do、while、case、switch、default等语句独占一行_**

        

    6.  **_在两个以上的关键字、变量、常量进行对等操作时，它们之间的操作符之前、之后或者前后要加空格；进行非对等操作时，如果是关系密切的立即操作符（如－>），后不应加空格_**

        

-   **建议**

    1.  **_注释符（包括‘/*’‘//’‘*/’）与注释内容之间要用一个空格进行分隔_**

        

    2.  **_源程序中关系较为紧密的代码应尽可能相邻_**



### 表达式

-   **规则**

    1.  **_表达式的值在标准所允许的任何运算次序下都应该是相同的_**

        >   将复合表达式分开写成若干个简单表达式，明确表达式的运算次序，就可以有效消除非预期副作用

        

-   **建议**

    1.  **_函数调用不要作为另一个函数的参数使用，否则对于代码的调试、阅读都不利_**

        

    2.  **_赋值语句不要写在if等语句中，或者作为函数的参数使用_**

        

    3.  **_用括号明确表达式的操作顺序，避免过分依赖默认优先级_**

        >   使用括号强调所使用的操作符，防止因默认的优先级与设计思想不符而导致程序出错；同时使得代码更为清晰可读，然而过多的括号会分散代码使其降低了可读性

        

    4.  **_赋值操作符不能使用在产生布尔值的表达式上_**



### 代码编辑 编译

-   **规则**

    1.  **_使用编译器的最高告警级别，理解所有的告警，通过修改代码而不是降低告警级别来消除所有告警_**

        >   编译器是你的朋友，如果它发出某个告警，这经常说明你的代码中存在潜在的问题

        

    2.  **_在产品软件（项目组）中，要统一编译开关、静态检查选项以及相应告警清除策略_**

        >   如果必须禁用某个告警，应尽可能单独局部禁用，并且编写一个清晰的注释，说明为什么屏蔽
        >
        >   某些语句经编译/静态检查产生告警，但如果你认为它是正确的，那么应通过某种手段去掉告警信息

        

    3.  **_本地构建工具（如PC-Lint）的配置应该和持续集成的一致_**

        >   两者一致，避免经过本地构建的代码在持续集成上构建失败

        

    4.  **_使用版本控制（配置管理）系统，及时签入通过本地构建的代码，确保签入的代码不会影响构建成功_**

        >   及时签入代码降低集成难度

        

-   **建议**

    1.  **_要小心地使用编辑器提供的块拷贝功能编程_**



### 可测性

-   **原则**

    1.  **_模块划分清晰，接口明确，耦合性小，有明确输入和输出，否则单元测试实施困难_**

        单元测试实施依赖于：

        -   _模块间的接口定义清楚、完整、稳定_
        -   _模块功能的有明确的验收条件（包括：预置条件、输入和预期结果）_
        -   _模块内部的关键状态和关键数据可以查询，可以修改_
        -   _模块原子功能的入口唯一_
        -   _模块原子功能的出口唯一_
        -   _依赖集中处理：和模块相关的全局变量尽量的少，或者采用某种封装形式_

        

-   **规则**

    1.  **_在同一项目组或产品组内，要有一套统一的为集成测试与系统联调准备的调测开关及相应打印函数，并且要有详细的说明_**

        >   本规则是针对项目组或产品组的。代码至始至终只有一份代码，不存在开发版本和测试版本的说法。测试与最终发行的版本是通过编译开关的不同来实现的。并且编译开关要规范统一。统一使用编译开关来实现测试版本与发行版本的区别，一般不允许再定义其它新的编译开关

        

    2.  **_在同一项目组或产品组内，调测打印的日志要有统一的规定_**

        统一的调测日志记录便于集成测试，具体包括：

        -   _统一的日志分类以及日志级别_
        -   _通过命令行、网管等方式可以配置和改变日志输出的内容和格式_
        -   _在关键分支要记录日志，日志建议不要记录在原子函数中，否则难以定位_
        -   _调试日志记录的内容需要包括文件名/模块名、代码行号、函数名、被调用函数名、错误码、错误发生的环境等_

        

    3.  **_使用断言记录内部假设_**

        >   断言是对某种内部模块的假设条件进行检查，如果假设不成立，说明存在编程、设计错误。断言可以对在系统中隐藏很深，用其它手段极难发现的问题进行定位，从而缩短软件问题定位时间，提高系统的可测性

        

    4.  **_不能用断言来检查运行时错误_**

        >   断言是用来处理内部编程或设计是否符合假设；不能处理对于可能会发生的且必须处理的情况要写防错程序，而不是断言。如某模块收到其它模块或链路上的消息后，要对消息的合理性进行检查，此过程为正常的错误检查，不能用断言来实现

        

        

-   **建议**

    1.  **_为单元测试和系统故障注入测试准备好方法和通道_**



### 安全性

-   **原则**

    1.  **_对用户输入进行检查_**

        不能假定用户输入都是合法的，因为难以保证不存在恶意用户，即使是合法用户也可能由于误用误操作而产生非法输入。用户输入通常需要经过检验以保证安全，特别是以下场景：

        -   _用户输入作为循环条件_
        -   _用户输入作为数组下标_
        -   *用户输入作为内存分配的尺寸参数*
        -   *用户输入作为格式化字符串*
        -   *用户输入作为业务数据（如作为命令执行参数、拼装sql语句、以特定格式持久化）*

        

        这些情况下如果不对用户数据做合法性验证，很可能导致DOS、内存越界、格式化字符串漏洞、命令注入、SQL注入、缓冲区溢出、数据破坏等问题

        

        可采取以下措施对用户输入检查：

        -   *用户输入作为数值的，做数值范围检查*
        -   *用户输入是字符串的，检查字符串长度*
        -   *用户输入作为格式化字符串的，检查关键字“%”*
        -   *用户输入作为业务数据，对关键字进行检查、转义*



#### 字符串操作安全

-   **规则**

    1.  **_确保所有字符串是以NULL结束_**

        >   C语言中’\0’作为字符串的结束符，即NULL结束符。标准字符串处理函数（如strcpy()、strlen()）依赖NULL结束符来确定字符串的长度。
        >
        >   没有正确使用NULL结束字符串会导致缓冲区溢出和其它未定义的行为。
        >
        >   为了避免缓冲区溢出，常常会用相对安全的限制字符数量的字符串操作函数代替一些危险函数

        -   用strncpy()代替strcpy()
        -   用strncat()代替strcat()
        -   用snprintf()代替sprintf()
        -   用fgets()代替gets()

        

        这些函数会截断超出指定限制的字符串，但是要注意它们并不能保证目标字符串总是以NULL结尾。如果源字符串的前n个字符中不存在NULL字符，目标字符串就不是以NULL结尾

        

    2.  **_不要将边界不明确的字符串写到固定长度的数组中_**

        >   边界不明确的字符串（如来自gets()、getenv()、scanf()的字符串），长度可能大于目标数组长度，直接拷贝到固定长度的数组中容易导致缓冲区溢出

        exp:

        ```c
        char buff[256];
        char *editor = getenv("EDITOR");
        if (editor != NULL)
        {
            strcpy(buff, editor);
        }									// 不安全
        
        char *buff;
        char *editor = getenv("EDITOR");
        if (editor != NULL)
        {
            buff = malloc(strlen(editor) + 1);
            if (buff != NULL)
            {
                strcpy(buff, editor);
            }
        }									// 正确写法
        ```

        

#### 整数安全

-   **规则**

    1.  **_避免整数溢出_**

        >   当一个整数被增加超过其最大值时会发生整数上溢，被减小小于其最小值时会发生整数下溢。带符号和无符号的数都有可能发生溢出

        

    2.  **_避免符号错误_**

        >   有时从带符号整型转换到无符号整型会发生符号错误，符号错误并不丢失数据，但数据失去了原来的含义

        

    3.  **_避免截断错误_**

        >   将一个较大整型转换为较小整型，并且该数的原值超出较小类型的表示范围，就会发生截断错误，原值的低位被保留而高位被丢弃。截断错误会引起数据丢失

        

#### 格式化输出安全

-   **规则**

    1.  **_确保格式字符和参数匹配_**

        >   使用格式化字符串应该小心，确保格式字符和参数之间的匹配，保留数量和数据类型。格式字符和参数之间的不匹配会导致未定义的行为。大多数情况下，不正确的格式化字符串会导致程序异常终止

        exp:

        ```c
        char *error_msg = "Resource not available to user.";
        int error_type = 3;
        /* 格式字符和参数的类型不匹配*/
        printf("Error (type %s): %d\n", error_type, error_msg);
        
        /* 格式字符和参数的数量不匹配*/
        printf("Error: %s\n");
        ```

        

    2.  **_避免将用户输入作为格式化字符串的一部分或者全部_**

        >   调用格式化I/O函数时，不要直接或者间接将用户输入作为格式化字符串的一部分或者全部。攻击者对一个格式化字符串拥有部分或完全控制，存在以下风险：进程崩溃、查看栈的内容、改写内存、甚至执行任意代码

        

#### 文件IO安全

-   **规则**

    1.  **_避免使用strlen()计算二进制数据的长度_**

        >   strlen()函数用于计算字符串的长度，它返回字符串中第一个NULL结束符之前的字符的数量。因此用strlen()处理文件I/O函数读取的内容时要小心，因为这些内容可能是二进制也可能是文本

        在不能确定从文件读取到的数据的类型时，不要使用依赖NULL结束符的字符串操作函数

        ```c
        char buf[BUF_SIZE + 1];
        char *p;
        if (fgets(buf, sizeof(buf), fp)) 
        {
            p = strchr(buf, '\n');
            if (p) 
            {
                *p = '\0';
            }
        }
        else
        {
            /* handle error condition */
        }
        ```

        

    2.  **_使用int类型变量来接受字符I/O函数的返回值_**

        >   字符I/O函数fgetc()、getc()和getchar()都从一个流读取一个字符，并把它以int值的形式返回。如果这个流到达了文件尾或者发生读取错误，函数返回EOF。fputc()、putc()、putchar()和ungetc()也返回一个字符或EOF

        

-   **规则**

    1.  **_防止命令注入_**

        >   C99函数system()通过调用一个系统定义的命令解析器（如UNIX的shell，Windows的CMD.exe）来执行一个指定的程序/命令。类似的还有POSIX的函数popen()

        如果system()的参数由用户的输入组成，恶意用户可以通过构造恶意输入，改变system()调用的行为

        使用POSIX函数execve()代替system()

        Windows环境可能对execve()的支持不是很完善，建议使用Win32 API CreateProcess()代替system()

        ```c
        void secuExec (char *input)
        {
            pid_t pid;
            char *const args[] = {"", input, NULL};
            char *const envs[] = {NULL};
            pid = fork();
            if (pid == -1)
            {
                puts("fork error");
            }
            else if (pid == 0)
            {
                if (execve("/usr/bin/any_exe", args, envs) == -1)
                {
                    puts("Error executing any_exe");
                }
            }
            return;
        }
        ```



### 单元测试

-   **规则**

    1.  **_在编写代码的同时，或者编写代码前，编写单元测试用例验证软件设计/编码的正确_**

    

-   **建议**

    1.  **_单元测试关注单元的行为而不是实现，避免针对函数的测试_**

        >   应该将被测单元看做一个被测的整体，根据实际资源、进度和质量风险，权衡代码覆盖、打桩工作量、补充测试用例的难度、被测对象的稳定程度等，一般情况下建议关注模块/组件的测试，尽量避免针对函数的测试。尽管有时候单个用例只能专注于对某个具体函数的测试，但我们关注的应该是函数的行为而不是其具体实现细节

        

### 可移植性

-   **规则**

    1.  **_不能定义、重定义或取消定义标准库/平台中保留的标识符、宏和函数_**

    

-   **建议**

    1.  **_不使用与硬件或操作系统关系很大的语句，而使用建议的标准语句，以提高软件的可移植性和可重用性_**

        >   使用标准的数据类型，有利于程序的移植

        

    2.  **_除非为了满足特殊需求，避免使用嵌入式汇编_**

        >   程序中嵌入式汇编，一般都对可移植性有较大的影响





## 杂项

### void使用

**_void定义变量没有任何意义的，void真正的作用是对函数返回的限定以及对函数参数的限定_**

-   __void *__

    >   _任何类型的指针都可以直接赋值给他，无需进行强制类型转换_

-   **void修饰函数返回值**

    **_如果函数无返回值，应该声明为void类型_**

-   **void修饰函数参数**

    **_如果函数无参数，应该声明其参数为void_**

>   _不要对void *类型的指针进行非法操作_
>
>   ```c
>   void * pvoid;
>   pvoid++;
>   pvoid += 1;			// 都是非法的(ANSI),而在GNU标准下是合法的
>   ```



### 零值比较

-   **bool**

    ```c
    bool bTestFlag = false;
    if (bTestFlag);   if (!bTestFlag);
    ```

    **_推荐使用上面的写法_**

    

-   **float(double)**

    ```c
    float fTestVal = 0.0f;
    if ((fTestVal >= -EPSINON) && (fTestVal <= EPSINON)); // ESPINON为定义好的精度
    ```

    **_浮点数的存储是有精度限制的，不能直接比较，推荐使用预定义的精度来实现在某个精度区间内的比较_**

    

-   **pointer**

    ```c
    int *p = NULL;
    if (NULL == p);		if (NULL != p);
    ```

    **_NULL在前可以防止漏写一个=时可以被编译器捕获错误_**

>   _关于空语句推荐写法是：==NULL;==_



