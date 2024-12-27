#include "task.h"
#include <thread>
#include <future>

void execute(std::function<void(int)> t, int load) {
    std::packaged_task<void(int)> task(t);
    std::future<void> future = task.get_future();
    std::thread worker(std::move(task), load);
    worker.join();
    future.get();
    std::cout << "execute: Task completed." << '\n';
}
