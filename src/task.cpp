#include "task.h"
#include <thread>
#include <future>
#include <iostream>

/**
 * This function executes a given task on a separate thread.
 * @param t a function that takes an integer as an argument and returns void.
 * @param load an integer that is passed to the function t which is used to simulate a workload.
 * @return void
 * @throws std::exception if the task t throws an exception.
 */
void execute(std::function<void(int)> t, int load) {
    std::packaged_task<void(int)> task(t);
    std::future<void> future = task.get_future();
    std::thread worker(std::move(task), load);
    worker.join();
    try {
        future.get();
    } catch (const std::exception& e) {
        std::cerr << "Task threw an exception: " << e.what() << '\n';
        throw;
    }
    std::cout << "Task completed." << '\n';
}
