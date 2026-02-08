# TimeDuration - A C++17 Library for Time Parsing and Formatting ⏳

![GitHub release](https://img.shields.io/github/release/Saddamansa/timeduration-cpp.svg)
![License](https://img.shields.io/badge/license-MIT-blue.svg)

Welcome to the **TimeDuration** repository! This lightweight C++17 header-only library allows you to parse and format human-readable time durations with ease. Whether you're working with durations like "2d 5h 30m" or need to integrate with `chrono` or SQL intervals, this library has you covered.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Integration with Chrono](#integration-with-chrono)
- [SQL Interval Output](#sql-interval-output)
- [Flexible Duration Construction](#flexible-duration-construction)
- [Contributing](#contributing)
- [License](#license)
- [Release Information](#release-information)

## Features

- **Human-Readable Parsing**: Convert strings like "2d 5h 30m" into usable duration objects.
- **Formatting**: Easily format duration objects back into human-readable strings.
- **Chrono Integration**: Seamlessly work with the C++ standard library's `chrono`.
- **SQL Interval Output**: Output durations in SQL interval format for database use.
- **Flexible Construction**: Create duration objects using various time units.

## Installation

To use TimeDuration, simply include the header file in your project. Since this is a header-only library, no additional setup is required.

```cpp
#include "timeduration.h"
```

## Usage

Here’s a simple example of how to use TimeDuration:

```cpp
#include "timeduration.h"
#include <iostream>

int main() {
    TimeDuration duration("2d 5h 30m");
    std::cout << "Duration in seconds: " << duration.to_seconds() << std::endl;
    std::cout << "Formatted: " << duration.format() << std::endl;
    return 0;
}
```

## Examples

### Parsing a Duration

You can parse a duration string like this:

```cpp
TimeDuration duration("1d 2h 15m");
std::cout << duration.to_seconds(); // Outputs total seconds
```

### Formatting a Duration

You can format a duration object back into a string:

```cpp
std::string formatted = duration.format();
std::cout << formatted; // Outputs "1d 2h 15m"
```

## Integration with Chrono

TimeDuration works well with C++'s `chrono` library. You can convert your duration to `chrono::duration` easily:

```cpp
#include <chrono>

std::chrono::seconds chrono_duration = duration.to_chrono_seconds();
```

## SQL Interval Output

If you need to output your duration in SQL interval format, TimeDuration makes this easy:

```cpp
std::string sql_interval = duration.to_sql_interval();
std::cout << sql_interval; // Outputs "INTERVAL '2 days 5 hours 30 minutes'"
```

## Flexible Duration Construction

You can create durations in various ways:

```cpp
TimeDuration duration1(3600); // 1 hour in seconds
TimeDuration duration2(1, TimeUnit::DAYS); // 1 day
```

## Contributing

We welcome contributions! Please fork the repository and submit a pull request with your changes. 

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourFeature`).
3. Make your changes.
4. Commit your changes (`git commit -m 'Add some feature'`).
5. Push to the branch (`git push origin feature/YourFeature`).
6. Create a new Pull Request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Release Information

For the latest releases, visit [here](https://github.com/Saddamansa/timeduration-cpp/releases). You can download the latest version and execute it in your project.

Feel free to check the "Releases" section for more details.

## Conclusion

TimeDuration is designed to simplify working with time durations in C++. Whether you are developing applications that require time calculations or need to format durations for display, this library provides the necessary tools in a lightweight package. 

We hope you find this library useful for your projects. For any issues or suggestions, please feel free to reach out or open an issue in the repository.

Happy coding!