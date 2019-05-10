#include <vector>
#include <string>
#include "WordVector.h"

using namespace std;

int WordVector::get_count(const string text) const
{
    int index = find(text, 0, size()-1);
    return index >= 0 ? at(index).get_count() : -1;
}

void WordVector::insert(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // First insertion?
    if (size() == 0) push_back(Word(text));

    // Insert a new word or increment the count of an existing word.
    else
    {
        // Use a binary search to look for the word in the vector.
        // If the word is not found, function find() returns the
        // negative of the index where to insert +1.
        int index = find(text, 0, size());

        // Not already in the vector: Insert the word at the appropriate
        // position in order to keep the vector sorted.
        if (index < 0)
        {
            vector<Word>::iterator it = begin() - index - 1;
            it = emplace(it, text);
        }

        // Already in the vector: Increment the word's count.
        else (*this)[index].increment_count();
    }

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time, end_time);
}

vector<Word>::iterator WordVector::search(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Look for the word in the vector.
    int index = find(text, 0, size());

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time, end_time);

    // Return the iterator.
    return index >= 0 ? begin() + index : end();
}

int WordVector::find(const string text, int low, int high) const
{
    int mid = 0;

    while (low < high)
    {
        mid = (low + high)/2;
        if (text == (*this)[mid].get_text()) return mid;

        else if (text < (*this)[mid].get_text()) high = mid;
        else                                     low  = mid + 1;
    }

    return -low - 1;
}
