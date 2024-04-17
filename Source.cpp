#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class ArrayFunctions {
private:
    vector<T> arr;

public:
    ArrayFunctions(const vector<T>& input_arr) : arr(input_arr) {}

    T find_max() const {

        T max_val = arr[0];
        for (const T& elem : arr) {
            if (elem > max_val)
                max_val = elem;
        }
        return max_val;
    }

    T find_min() const {

        T min_val = arr[0];
        for (const T& elem : arr) {
            if (elem < min_val)
                min_val = elem;
        }
        return min_val;
    }

    void selection_sort() {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            }
            swap(arr[i], arr[min_idx]);
        }
    }

    int binary_search(const T& key) const {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key)
                return mid;
            else if (arr[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1; 
    }

    void replace_element(const T& old_val, const T& new_val) {
        replace(arr.begin(), arr.end(), old_val, new_val);
    }

    void display() const {
        for (const T& elem : arr)
            cout << elem << " ";
        cout << endl;
    }
};

int main() {
    vector<int> nums = { 5, 2, 8, 1, 9, 3 };

    ArrayFunctions<int> arr_func(nums);

    cout << "Original array: ";
    arr_func.display();

    cout << "Max element: " << arr_func.find_max() << endl;
    cout << "Min element: " << arr_func.find_min() << endl;

    arr_func.selection_sort();
    cout << "Sorted array: ";
    arr_func.display();

    int key = 8;
    int index = arr_func.binary_search(key);
    if (index != -1)
        cout << "Element " << key << " found at index " << index << endl;
    else
        cout << "Element " << key << " not found" << endl;

    int old_val = 9;
    int new_val = 100;
    arr_func.replace_element(old_val, new_val);
    cout << "Array after replacing " << old_val << " with " << new_val << ": ";
    arr_func.display();

    return 0;
}
