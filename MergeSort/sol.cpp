#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& vec, int left, int m, int right) {
    int n1 = m - left + 1;
    int n2 = right - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = vec[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = vec[m + i + 1];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k++] = L[i];
            ++i;
        } else {
            vec[k++] = R[j];
            ++j;
        }
    }

    while (i < n1) {
        vec[k++] = L[i++];
    }

    while (j < n2) {
        vec[k++] = R[j++];
    }
}

void merge_sort(vector<int>& vec, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);

    merge(vec, left, mid, right);
}

int binary_search(int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (target == mid)
            return mid;
        else if (target < mid)
            return binary_search(target, left, mid - 1);
        else 
            return binary_search(target, mid + 1, right);
    }
    return -1;
}

int main() {
    vector<int> vec { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    merge_sort(vec, 0, vec.size() - 1);

    for (auto item : vec)
        cout << item << " ";
    
    cout << endl;

    cout << binary_search(5, 0, vec.size() - 1);
    cout << endl;
}


/* Another way!!!
template<typename T>
class YrMergeSort {
private:
    vector<int> vec;
    void MergeSortRec(vector<T> vec);
public:
    explicit YrMergeSort(const vector<T>& vec);
    void MergeSort();
};

template <typename T>
YrMergeSort<T>::YrMergeSort(const vector<T>& vec) {
    this->vec = vec;
}

template<typename T>
void YrMergeSort<T>::MergeSort() {
    MergeSortRec(vec);
}

template<typename T>
void YrMergeSort<T>::MergeSortRec(vector<T> vec) {
    if (vec.size() <= 0) {
        for(auto item : vec)
            cout << item; 
        cout << endl;
        return;
    }

    for(auto item : vec)
        cout << item; 
    cout << endl;

    if (vec.size() > 1) {
        vector<T> left(vec.begin(), vec.begin() + vec.size() / 2);
        vector<T> right(vec.begin() + vec.size() / 2, vec.end());

        if (left.size() > 1)
            MergeSortRec(left);
        if (right.size() > 1)
            MergeSortRec(right);
    }
}

int main() {
    vector<int> vec { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    YrMergeSort<int>* yrMergeSort = new YrMergeSort<int>(vec);

    yrMergeSort->MergeSort();

    delete yrMergeSort;
}
*/