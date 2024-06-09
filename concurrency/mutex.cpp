#include <iostream>  // std::cout
#include <mutex>     // std::mutex
#include <thread>    // std::thread

std::mutex mtx;  // mutex for critical section
int count = 0;

void print_thread_id(int id)
{
    // critical section (exclusive access to std::cout signaled by locking mtx):
    mtx.lock();
    std::cout << "thread #" << id << "  count:" << count << '\n';
    count++;
    mtx.unlock();
}
int main()
{
    std::thread threads[10];
    // spawn 10 threads:
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(print_thread_id, i + 1);
    for (auto &th : threads)
        th.join();
    return 0;
}
