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

int mod = 1000000007;
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

// gcd of 2 numbers in logn
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// extended euclid algorithm for finding (x,y) such that a.x + b.y = gcd(a,b)
int extended_euclid_algo(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclid_algo(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// function to find the x and y of linear diophantine solution equation(ax+by=c)
bool LDE(int a, int b, int c, int &x, int &y)
{
    int x0, y0;
    int g = extended_euclid_algo(abs(a), abs(b), x0, y0);
    if (c % g)
    {
        return false;
    }

    x = x0 * (c / g);
    y = y0 * (c / g);

    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;
    return true;
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

// prime numbers in 0(rootn)
bool isprime(int n)
{
    int cnt = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if ((n / i) != i)
            {
                cnt++;
            }
        }
    }

    if (cnt == 1)
    {
        return true;
    }
    return false;
}
// finding x^n in logn time
double myPow(double x, int n)
{
    long long int nn = n;
    double ans = 1.0;
    if (nn < 0)
        nn = -1 * nn;
    while (nn)
    {
        if (nn % 2)
        {
            ans = ans * x;
            nn--;
        }
        else
        {
            x = x * x;
            nn /= 2;
        }
    }
    if (n < 0)
        ans = (double)1.0 / (double)ans;
    return ans;
}

ll Power(ll x, ll n)
{
    ll nn = n;
    ll ans = 1;
    if (nn < 0)
        nn = -1 * nn;
    while (nn)
    {
        if (nn % 2)
        {
            ans = (ans % mod * x % mod) % mod;
            nn--;
        }
        else
        {
            x = (x % mod * x % mod) % mod;
            nn /= 2;
        }
    }
    if (n < 0)
        ans = 1 / ans;
    return ans % mod;
}

// finding out the number is prime or not
void Sieve()
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

vector<int> generate_primes(int n)
{
    vector<int> p;
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == true)
        {
            p.push_back(i);
        }
    }
    return p;
}

// to find out the prime numbers within the given range
void Segmented_Sieve(int l, int r)
{
    // step 1
    // generate all primes till sqrt(r)

    vector<int> primes = generate_primes(sqrt(r));

    // step2
    // create a dummy array of size r-l+1 and mark all the elements as true

    int dummy[r - l + 1];
    for (int i = 0; i < r - l + 1; i++)
    {
        dummy[i] = 1;
    }

    // step 3
    // mark all the elements of dummy array as 0 which is the factor of primes numbers generated

    for (auto pr : primes)
    {
        int first_factor = (l / pr) * pr;

        if (first_factor < l)
        {
            first_factor += pr;
        }

        for (int i = max(first_factor, pr * pr); i <= r; i += pr)
        {
            dummy[i - l] = 0;
        }
    }

    for (int i = l; i <= r; i++)
    {
        if (dummy[i - l] == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

// to find Euler Totient Function or count of pair of co-primes(numbers are said to be co-primes if their gcd=1)
// time complexity =O(rootn)
int Euler_Totient_Function(int n)
{
    int res = n;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res /= i;
            res *= (i - 1);

            while (n % i == 0)
            {
                n /= i;
            }
        }

        if (n > 1)
        {
            res /= n;
            res *= (n - 1);
        }
    }
    return res;
}

// to find Euler Totient Function or count of pair of co-primes(numbers are said to be co-primes if their gcd=1)
// time complexity =O(nlogn)
int ETF(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (gcd(i, n) == 1)
        {
            cnt++;
        }
    }
    return cnt;
}

/*
    MODULAR ARITHMETIC-
    - a is modular congruent to b under modular N if a%N = b%N
    - if  a congruent(triple equal sign) b(mod N) then (a-b) is divisible by N i.e. (a-b)%N = 0
    - (a+b+c)%N = (a%N + b%N + c%N)%N
    - (a*b*c)%N = (a%N * b%N * c%N)%N
    - if a*b = c
      then (a%N) * (b%N) = (c%N)
*/

/*
    MODULAR INVERSE-
    - a*XmodP= 1 , where X = 1/a, and X is the modular inverse of the given number a
    - for modular inverse of a number to exist GCD(a,P) = 1
    - Eg-
      (6/2)%5 = ((6%5)*(3%5))%5 [3 being the modular multiplicative inverse of 2 since 2*3%5 = 1]
              = (1*3)%5 = 3
*/

// finding modular inverse given that m is prime using fermant theorem in logn
// acc to fermant's theorem
// a^m-1 mod m=1(dividing both side by a)
// a^m-2 mod m=a^-1
// we have to pass mod_inverse(a,m-2,m) from int main
int mod_inverse(int a, int n, int m)
{
    int ans = 1;
    while (n)
    {
        if (n % 2)
        {
            ans = ((ans % m) * (a % m)) % m;
            n--;
        }
        else
        {
            a = (a * a) % m;
            n /= 2;
        }
    }
    return ans;
}

// if m is not prime then general way of finding modular inverse in logn time
int modular_inverse(int a, int m)
{
    int x, y;
    int gcd = extended_euclid_algo(a, m, x, y);
    if (gcd != 1)
    {
        return 0;
    }
    // m is added to handle negative x
    int res = (x % m + m) % m;
    return res;
}

// CHINESE REMAINDER THEOREM-->
//     We are given 2 arrays -->nums,rem(where both the arrays have co-prime pairs of numbers) and we are asked to find a number a such that->
//     a%num[i] = rem[i]
//     p is the product of all the elements of nums array.

int CRT(int num[], int rem[], int size)
{
    int prod = 1;
    for (int i = 0; i < size; i++)
    {
        prod *= num[i];
    }
    int result = 0;

    for (int i = 0; i < size; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * modular_inverse(pp, num[i]) * pp;
    }

    return result % prod;
}

// Finding Binomial Coefficient nCk
ll F[10000001];
void Binomial_Coefficient()
{
    F[0] = F[1] = 1;

    // finding factorial of the number upto 1000000
    for (ll i = 2; i < 1000001; i++)
    {
        F[i] = (F[i - 1] * i) % mod;
    }
}

int NCK(int n, int k)
{
    if (k > n)
        return 0;
    ll res = F[n];
    res = (res * (Power(F[k], mod - 2))) % mod;
    res = (res * (Power(F[n - k], mod - 2))) % mod;
    return res % mod;
}

int bin_to_dec(string s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] - '0') & 1)
        {
            sum += (1 << (s.length() - i - 1));
        }
    }
    return sum;
}

/* -------------------------  ------------------------------------
1.(num & (1<<i) != 0)----> To check for set bit
2.(num | (1<<i)) -----> To set ith bit
3.(num & (~(1<<i))) -----> To unset ith bit
4.(num ^ (1<<i)) -----> To toggle the bit
__builtin_popcountll(s)-->returns total number of set bits in integer s
5. To check whether the ith bit is set:- (number &(1<<(ith bit))) & 1!=0
*/
string dec_to_bin(int n)
{
    string s = "";
    for (int i = 10; i >= 0; i--)
    {
        s += to_string((n >> i) & 1);
    }
    return s;
}
/*
if we want to convert lowercase to uppercase
character & '_'
if we want to convert uppercase to lowercase
character | ' '
**** these can be used if we want to change a number into another ****
to unset upto ith bit from LSB
number & (~((1<<i+1)-1))
to unset upto ith bit from MSB
number & ((1<<i+1)-1)
****** to check power of 2 ******
(n&(n-1)) non zero
*/
/*
Property of XOR is to find the unique element
if we perform the XOR operation with each element of the array then the final result
will be the unique element present in the array
***swap:-***
a=a^b
b=a^b
a=a^b
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
