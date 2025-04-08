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

    // Parse different formats
    std::cout << "\nParsing different formats:" << std::endl;
    std::cout << "1h = " << timeduration::CTimePeriod("1h").duration().count() << " seconds" << std::endl;
    std::cout << "90m = " << timeduration::CTimePeriod("90m").duration().count() << " seconds" << std::endl;
    std::cout << "1d 2h 3m 4s = " << timeduration::CTimePeriod("1d 2h 3m 4s").toString() << std::endl;
    std::cout << "1mo 2d = " << timeduration::CTimePeriod("1mo 2d").toString() << std::endl;

    return 0;
}
