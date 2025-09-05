#include <iostream>
#include <future>
#include <vector>
#include <chrono>
#include "threadpool.h"

using namespace std;

// 基础任务
int sum(int a, int b) {
    return a + b;
}

// 无返回值任务
void printTask(int id) {
    cout << "Task " << id << " start" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Task " << id << " end" << endl;
}

// 高并发任务
int multiply(int a, int b) {
    this_thread::sleep_for(chrono::milliseconds(50)); // 模拟耗时
    return a * b;
}

int main() {
    ThreadPool pool;
    pool.start(4); // 启动 4 个线程

    // 1. 测试基础任务
    future<int> res1 = pool.submitTask(sum, 10, 20);
    cout << "sum = " << res1.get() << endl;

    // 2. 测试无返回值任务
    vector<future<void>> futures_void;
    for (int i = 0; i < 5; ++i) {
        futures_void.push_back(pool.submitTask(printTask, i));
    }
    for (auto& f : futures_void) f.get(); // 等待完成

    // 3. 测试高并发任务
    vector<future<int>> futures_int;
    for (int i = 1; i <= 10; ++i) {
        futures_int.push_back(pool.submitTask(multiply, i, i + 1));
    }
    for (auto& f : futures_int) {
        cout << "multiply result = " << f.get() << endl;
    }

    return 0;
}
