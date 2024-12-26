#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <functional>
#include <iostream>
#include <thread>
#include <future>

// Include the header where the execute function is declared
#include "../src/task.h"

// Mock function to be used with execute
void mock_function(int load) {
    std::cout << "Processing load: " << load << '\n';
}

TEST_CASE("Testing execute function") {
    CHECK_NOTHROW(execute(mock_function, 10));
    CHECK(true); // Add a simple assertion to ensure the test case runs
}