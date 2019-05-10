#include <map>
#include <string>
#include "WordMap.h"

using namespace std;

int WordMap::get_count(const string text) const
{
    map<string, Word>::const_iterator it = find(text);
    return it != end() ? (it->second).get_count() : -1;
}

void WordMap::insert(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Look for the word in the map.
    map<string, Word>::iterator it = find(text);

    // Not already in the map: Insert the new word
    //                         by constructing it in place.
    if (it == end()) emplace(text, text);

    // Already in the map: Increment the word's count.
    else (it->second).increment_count();

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time, end_time);
}

map<string, Word>::iterator WordMap::search(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Look for the word in the map.
    map<string, Word>::iterator it = find(text);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time, end_time);

    // Return the iterator.
    return it;
}
