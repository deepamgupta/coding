#include <algorithm>
#include <chrono>
#include <iostream>
using namespace std;

class TimeDuration
{
public:
    static chrono::_V2::system_clock::time_point _start;

    static void start()
    {
        _start = chrono::high_resolution_clock::now();
    }

    static string duration_micro()
    {
        return to_string(
                   chrono::duration_cast<chrono::microseconds>(
                       chrono::high_resolution_clock::now() - _start)
                       .count()) +
               " microseconds\n";
    }

    static string duration_nano()
    {
        return to_string(
                   chrono::duration_cast<chrono::nanoseconds>(
                       chrono::high_resolution_clock::now() - _start)
                       .count()) +
               " nanoseconds\n";
    }

    static string duration_mili()
    {
        return to_string(
                   chrono::duration_cast<chrono::milliseconds>(
                       chrono::high_resolution_clock::now() - _start)
                       .count()) +
               " miliseconds\n";
    }

    static string duration()
    {
        return "\n" + duration_mili() + duration_micro() + duration_nano() + "\n";
    }
};

// Initialize the static varable
chrono::_V2::system_clock::time_point TimeDuration::_start = chrono::high_resolution_clock::now();
