# timeduration-cpp

A lightweight C++17 library for parsing time duration strings into chrono durations.

## Features

* Parse human-readable time strings like "5h 30m" or "2d 4h 15m 30s"
* Convert durations between different units (days, hours, minutes, seconds)
* Format durations as human-readable strings
* Generate SQL interval expressions
* Header-only implementation with minimal dependencies

## Requirements

* C++17 compatible compiler
* CMake 3.14 or higher

## Installation

### Using CMake

```bash
git clone https://github.com/yourusername/timeduration-cpp.git
cd timeduration-cpp
mkdir build && cd build
cmake ..
cmake --install .
```

### Header-only Usage

Simply copy the `include/timeduration/timeduration.hpp` file to your project and include it.

## Usage

```cpp
#include <timeduration/timeduration.hpp>
#include <iostream>

int main() {
    // Parse a time duration string
    auto duration = timeduration::CTimePeriod("2h 30m 15s");
    
    // Access components
    std::cout << "Hours: " << duration.hours() << std::endl;
    std::cout << "Minutes: " << duration.minutes() << std::endl;
    std::cout << "Seconds: " << duration.seconds() << std::endl;
    
    // Get total duration in seconds
    auto total_seconds = duration.duration().count();
    std::cout << "Total seconds: " << total_seconds << std::endl;
    
    // Format as string
    std::cout << "Formatted: " << duration.toString() << std::endl;
    
    // Generate SQL interval
    std::cout << "SQL interval: " << duration.asSqlInterval() << std::endl;
    
    // Create from components
    auto custom = timeduration::CTimePeriod(15, 30, 2); // 2h 30m 15s
    
    // Compare durations
    if (duration == custom) {
        std::cout << "Durations are equal!" << std::endl;
    }
    
    return 0;
}
```

## Supported Time Units

The library supports the following time units:

| Unit | Abbreviation | Full Name |
|------|--------------|-----------|
| Seconds | s | seconds |
| Minutes | m | minutes |
| Hours | h | hours |
| Days | d | days |
| Months | mo | months |
| Years | y | years |

## Running Tests

The library comes with a comprehensive test suite built with Google Test. To run the tests:

```bash
git clone https://github.com/yourusername/timeduration-cpp.git
cd timeduration-cpp
mkdir build && cd build
cmake .. -DTIMEDURATION_BUILD_TESTS=ON
cmake --build .
ctest -V
```

By default, if Google Test is not found on your system, CMake will automatically download and build it. You can disable this behavior with `-DTIMEDURATION_DOWNLOAD_GTEST=OFF` if you prefer to use your system's Google Test installation.

## Running Examples

To build and run the examples:

```bash
git clone https://github.com/yourusername/timeduration-cpp.git
cd timeduration-cpp
mkdir build && cd build
cmake .. -DTIMEDURATION_BUILD_EXAMPLES=ON
cmake --build .
./examples/basic_usage
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
