准备：一些常用c语言基础：指针、数组、字符串数组、int、size_t、char、signed/unsigned、const

第一层，基本常用结构：**std::string、std::map、std::vector、0401-？**ios  

第二层，自定义对象：**struct、class、0331**       继承、重载、多态

第三层，进一步抽象对象：虚继承

第四层，：static变量、static函数、static class成员、static class函数

第五层，程序设计：有限状态机、单例、命令模式、function、lambda

第六层，网络基础：socket、std::shared_ptr、std::unique_ptr、std::array

第七层，高级网络开发：asio

第八层，并发：packaged_task + future + thread、promise、lambda

第九层，静态优化：constexpr、templete

第十层，渐入佳境：随意发挥



+ Difference between pointer and reference?
+ i++, ++i, which one is better?
+ Why use virtual destructor?
+ What is the signature of a copy constructor/ assignment operator?
+ How to specialize a class template?
+ What are the four types of casts in C++? Usage?

What are the four types of casts in C++? Usage?

etc



#### 书籍推荐

c++入门:c++ primer(没有plus) 
c++进阶:effective c++ more effective c++ 
深度探索c++对象模型 STL源码剖析 effective STL c++的设计与演化 c++沉思录 c++编程思想 
算法与数据结构:算法(第四版) 编程珠玑 算法导论 算法与数据结构(wesis) 
网络编程:APUE UNP 
操作系统:深入理解计算机系统(CSAPP，简直神书，值得不断看反复看) 现代操作系统 操作系统概念
计算机网络: 自顶向下的方法 TCP/IP V1 计算机网络 HTTP权威指南
数据库:入门推荐学习MySQL
MySQL必知必会 高性能MySQL
设计模式:Head First设计模式
Redis:Redis设计与实现
还有最好学习一门脚本语言，比如shell/python/perl 
源码推荐:leveldb nginx muduo libevent redis

### 学习C++ Primer 的方法

以C++ Primer第五版为例，第一遍读的时候：
Part1也就是前七章，除了6.6，6.7节，都要通读。尤其是第三章初步介绍了vector和string，简直就是新手福音，搞定这两个容器就能写一些简单的程序。
Part2基本就是数据结构和算法，如果有基础读起来很轻松。
9，11两章介绍的容器，以及12.1节的智能指针要通读。多用智能指针和容器，远离segment fault. 第10章里的泛型算法可以慢慢读，读完以后可以写出高逼格的函数式风格C++。12.2节讲了怎么用new和delete分配空间，题主作为新手，知道这种写法就行，写程序时尽量用容器代替原始数组，尤其是代码里最好不要有delete。
Part3是块硬骨头，标题就是Tools for Class Authors. 作为一个"class user"，有些部分第一次是可以略过的。
13章很重要，要细读。初始化，复制，赋值，右值引用是C++里很微妙很重要的部分，别的语言对于这些概念很少有区分得这么细的。这一章不但要精读，还要完全掌握。
14章的操作符重载第一次可以观其大略；14.9节第一次可以跳过。
15章讲OOP，重要性不言而喻。如果之前一点概念都没有，学起来会觉得比较抽象。网上关于OOP有很多通俗有趣的文章，可以一起看看。
16章讲泛型编程，第一次读16.1节，掌握最基本的函数模板和类模板就行了。
Part4就更高档了，很多内容第一次就算啃下来，长久不用又忘了。第一次读推荐把18.2节读懂，命名空间简单易用效果好。别的内容可以观其大略，用时再看。17.1节的tuple是个有趣的东东，可以读一读。17.3节的正则表达式和17.4节的随机数也许有用，也可以读一读。如果需要读写文件，要读一下17.5.2节的raw I/O和17.5.3节的random I/O。

最后给题主的建议是，写C++，要尽量避免C的写法。用static_cast而不是括号转换符；用vector而不是C里面的数组；用string而不是char *；用智能指针而不是原始指针。当然I/O是个例外，printf()还是比cout好用的；转换数字和字符串时sprintf()也比stringstream快



### 学习C++的过程

由于我大一也陷入过迷茫，也走过一些弯路，那时候学不会直接记忆代码之类的事情我都干过，
我也希望我的这些经验可以对你有所帮助。首先是一本好的C++书籍（Accelerated C++， C++ Primer），
然后以及尽量多的完成书籍的习题，可以帮助完成C++语法的学习。虽然前面的书籍涵盖了标准库，但是不够完善
，这个时候你可以选择在线查阅C++标准库这种泛型的学习方式，也可以选择阅读《C++标准库》的方式进行学习。
通过这样的步骤，你应该可以完成C++的初步学习了。

然后，由于C++是一门系统级语言，我想你需要到大三学习操作系统的时候，
才会明白栈与堆、内存管理等更深层次的含义。但是，在明白这些概念之前不会妨碍你利用C++做一些事情，
比如写一个简单的XML Parser。
这个时候，你应该会发现很多问题，如效率，代码规范等，
这个时候，你可以研究Effective C++，Google C++ Code Standard等，
只有自己犯了错，回过头反省才会更加深刻。随后，你可以更加深刻的去思考C++，
你需要阅读《The Design and Evolution of C++》。这本书的阅读，会教会你很多，是对你影响最大的C++书籍。

如果你对C++编译器的一些细节有兴趣，深入C++对象模型可以推荐。
如果你对STL的一些实现有兴趣，可以去翻翻STL源代码（很多人推荐STL源码剖析，但是我没有阅读过，
我没有办法发表是否应该推荐的观点，列出来供你自行判断是否应该阅读）。

到这一步骤，我想你应该可以称为C++ Programmer了，剩下的就是实践中发现问题，然后补足自己。


此外，由于C++博大精深，应用的范围多如牛毛，特定方向所需要的知识未列举。
比如你要研究Android的NDK什么的，那就是属于你后面的事情了。
计算机的世界不仅计算机编程语言，与之相关的还有操作系统、数据结构、编译原理、计算机网络等知识