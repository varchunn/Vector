#include <iostream>
#include <vector>

using namespace std;

struct FindMin 
{
    int operator()(const vector<int>& vec) const 
    {
        return *min_element(vec.begin(), vec.end());
    }
};

struct FindMax 
{
    int operator()(const vector<int>& vec) const
    {
        return *max_element(vec.begin(), vec.end());
    }
};

struct SortDescending
{
    void operator()(vector<int>& vec) const 
    {
        sort(vec.begin(), vec.end(), greater<int>());
    }
};

struct SortAscending 
{
    void operator()(vector<int>& vec) const
    {
        sort(vec.begin(), vec.end());
    }
};

struct IncreaseBy 
{
    int constant;
    IncreaseBy(int c) : constant(c) {}
    void operator()(vector<int>& vec) const 
    {
        for_each(vec.begin(), vec.end(), [this](int& x) { x += constant; });
    }
};

struct DecreaseBy 
{
    int constant;
    DecreaseBy(int c) : constant(c) {}
    void operator()(vector<int>& vec) const 
    {
        for_each(vec.begin(), vec.end(), [this](int& x) { x -= constant; });
    }
};

struct RemoveValue 
{
    int value;
    RemoveValue(int v) : value(v) {}
    void operator()(vector<int>& vec) const 
    {
        vec.erase(remove(vec.begin(), vec.end(), value), vec.end());
    }
};

int main() {
    vector<int> vec = {3, 7, 2, 8, 3, 5, 2, 9};
    FindMin findMin;
    cout << "Minimum value: " << findMin(vec) << endl;
    FindMax findMax;
    cout << "Maximum value: " << findMax(vec) << endl;

    SortDescending sortDesc;
    sortDesc(vec);
    cout << "Sorted descending: ";
    for (int val : vec) cout << val << " ";
    cout << endl;
    SortAscending sortAsc;
    sortAsc(vec);
    cout << "Sorted ascending: ";
    for (int val : vec) cout << val << " ";
    cout << endl;
    IncreaseBy increaseBy(5);
    increaseBy(vec);
    cout << "Increased by 5: ";
    for (int val : vec) cout << val << " ";
    cout << endl;
    DecreaseBy decreaseBy(3);
    decreaseBy(vec);
    cout << "Decreased by 3: ";
    for (int val : vec) cout << val << " ";
    cout << endl;
    RemoveValue removeValue(7);
    removeValue(vec);
    cout << "After removing 7: ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    return 0;
}
