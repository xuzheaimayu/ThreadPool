#Thread pool
一个线程池的简单实现(C++11/14)
1、使用future类定制subMitTask提交任务的返回值  
2、使用map和queue容器管理线程对象和任务  
3、基于条件变量condition_variable和互斥锁mutex实现任务提交线程和任务执行线程间的通信机制  
4、支持fixed和cached两种线程池模式的定制  

##文件
threadpool.cpp  
threadpool.h  

##编译方式
$ g++ -std=c++11 main.cpp threadpool.cpp -pthread -o main  
$ ./main  
