#include <iostream>
#include <chrono>
class Timer {
public:
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    };

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        auto timestep = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "Execution time: " << timestep* 0.000000001 << " seconds" << std::endl;
    };
private:
    std::chrono::high_resolution_clock::time_point start,end;
};