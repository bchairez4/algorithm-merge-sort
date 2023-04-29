/*****************************************************************************
*    Brian Chairez
*
*    Merge Sort Algorithm
*        Time Complexity:
*            Worst Case: O(nlogn)
*            Average Case: O(nlogn)
*        Space Complexity:
*            O(n)
*****************************************************************************/

#include <vector>

// Merging function that takes care of ordering
template <class T>
std::vector<T> merge_(std::vector<T>& left, std::vector<T>& right) {
    std::vector<T> result;

    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.erase(left.begin());
        } else {
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    while (!left.empty()) {
        result.push_back(left.front());
        left.erase(left.begin());
    }

    while (!right.empty()) {
        result.push_back(right.front());
        right.erase(right.begin());
    }

    return result;
}

// Top-Down approach recursively breaking down the array to then build it back up
template <class T>
std::vector<T> MergeSort_(std::vector<T>& array) {
    if (array.size() <= 1) {
        return array;
    }

    std::vector<T> left;
    std::vector<T> right;

    for (int i = 0; i < array.size(); ++i) {
        if (i < (array.size()/2)) {
            left.push_back(array[i]);
        } else {
            right.push_back(array[i]);
        }
    }

    left = MergeSort_(left);
    right = MergeSort_(right);

    return merge_(left, right);
}

// Wrapper function to call the recursive function
template <class T>
void MergeSort(std::vector<T>& array) {
    array = MergeSort_(array);
}