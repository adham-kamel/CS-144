#include <list>
#include <string>
#include "WordList.h"

using namespace std;

int WordList::get_count(const string text)
{
    auto position = find(text);
    return position != end() ? position->get_count() : -1;
}

void WordList::insert(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    auto it = begin();
    while ((it != end()) && (text > it->get_text())) it++;

    if ((it == end()) || (text < it->get_text())) it = emplace(it, text);
    else                                          it->increment_count();

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time, end_time);
}

list<Word>::iterator WordList::search(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Look for the word in the list.
    auto position = find(text);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time, end_time);

    // Return the iterator.
    return position;
}

list<Word>::iterator WordList::find(const string text)
{
    list<Word>::iterator it = begin();
    while ((it != end()) && (text != it->get_text())) it++;
    return it;
}
