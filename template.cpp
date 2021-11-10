#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)

#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define pb emplace_back

int arr[10000000];
int N = 10000000;
bool sieve[10000001];
int a[10000001];
// taking input of array
void array_input(ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
// input for vector array
vector<int> vec_array_input(vector<int> arr, ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}
// print all array elements
void print_array(ll n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

// factorial
ll factorial(ll n)
{
    ll f = 1;
    for (int i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

// gcd of 2 numbers
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// extended euclid algorithm for finding (x,y) such that a.x+b.y=gcd(a,b)
int extended_euclid_algo(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclid_algo(a, b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// prime factors in a range
vector<int> prime_factors(int n)
{
    vector<int> prime;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            prime.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
    {
        prime.push_back(n);
    }
    return prime;
}

// finding out the number is prime or not
void isprime()
{
    for (int i = 2; i <= N; i++)
    {
        sieve[i] = true;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
