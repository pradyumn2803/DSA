#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
#define tc      \
    ll t;       \
    cin >> t;   \
    while (t--) \
int arr[100005];

void insert(vector<int> &v, int val)
{
    if (v.size() == 0 || v[v.size() - 1] <= val)
    {
        v.push_back(val);
        return;
    }
    int temp = v[v.size() - 1];
    v.pop_back();
    insert(v, val);
    v.push_back(temp);
}

void sort(vector<int> &v)
{
    if (v.size() == 1)
    {
        return;
    }
    int val = v[v.size() - 1];
    v.pop_back();
    sort(v);
    insert(v, val);
}

int main()
{
    vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v);

    for (auto iter : v)
    {
        cout << iter << " ";
    }
    return 0;
}