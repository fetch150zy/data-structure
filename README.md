# Data Structure



## 1.Introduction

**_程序设计 = 数据结构 + 算法_**

### 基本概念和术语

-   **数据**

    >   是描述客观事物的符号，是计算机中可以操作的对象，是能被计算机识别，并输入给计算机处理的符号集合

-   **数据元素**

    >   是组成数据的、有一定意义的基本单位，在计算机中通常作为整体处理。 也被称为记录

-   **数据项**

    >   一个数据元素可以自若干个数据项组成（数据项是数据不可分割的最小单位）

-   **数据对象**

    >   是性质相同的数据元素的集合，是数据的子集

-   **数据结构**

    >   是相互之间存在-种或多种特定关系的数据元蠢的集舍

    

### 逻辑结构和物理结构

-   **逻辑结构**

    1.  **_集合结构_**

        >   集合结构中的数据元素除了 同属于一个集合外，宫们之间没有其他关系

    2.  **_线性结构_**

        >   统性结构中的数据元素之间是一对一的关系

    3.  **_树形结构_**

        >   树形结构中的数据元素之间存在一种一对多的层次关系

    4.  **_图形结构_**

        >   图形结构的数据元素是多对多的关系

        

-   **物理结构**

    >是指数据的逻辑结构在计算机中的存储形式

    1.  **_顺序存储结构_**

        >   是把数据元素存放在地址连续的存储单元里，其数据间的逻辑关系和物理关系是一致的

    2.  **_链式存储结构_**

        >   是把数据元素存放在任意的存储单元里，这组存储单元可以是连续的，也可以是不连续的

        

-   **抽象数据类型**

    1.  **_数据类型_**

        >   是指一组性质相同的值的集合及定义在此集合上的一些操作的总称

        -   *原子类型:是不可以再分解的基本类型，包括整型、实型、字符型等*
        -   *结构类型:自若干个类型组合而戚，是可以再分解的。例如，整型数组是由若干整型数据组成的*

        

    2.  **_抽象数据类型_**

        >   抽象数据类型 (Abstract Dataη肘 ， ADT) : 是指一个数学模型及定义在该模型上的一组操作





## 2.Algorithm

### 算法的定义

**_算法是解决特定问噩求解步'的描述，在计算机中表现为指令的有限序列，并且4事务指令亵示一个或多个操作_**



### 算法的特性

-   **输入输出**

    >    算法具有零个或多个输入，算法至少有一个或多个输出

-   **有穷性**

    >   指算法在执行有限的步骤之后，自动结束而不会出现无限循环，并且每一个步骤在可接受的时间内完成

-   **确定性**

    >   算法的每一步骤都具有确定的含义 ， 不会出现二义性 

-   **可行性**

    >   算法的每一步都必须是可行的 ， 也就是说，每一步都能够通过执行有限次数完成



### 算法设计的要求

-   **正确性**

    >   算法的正确性是指算法至少应该具有输入、输出和加工处理无歧义性、能正确反映问题的需求、能够得到问题的正确答案

-   **可读性**

    >   算法设计的另一目的是为了便于阅读、 理解和交流

-   **健壮性**

    >   当输入数据不合法时，算法也能做出相关处理， 而不是产生异常或莫名其妙的结果

-   **时间效率高和存储量低**

    >   设计算法应该尽量满足时间效率高和存储量低的需求



