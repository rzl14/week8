#include <iostream>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

// 埃氏筛法
void get_primes(int n)
{
    for (int i = 2; i <= n / i; i ++) {
        if (!st[i]) {
            primes[cnt ++] = i;
            for (int j = i + i; j <= n; j += i) st[j] = true;
        }
    }
}

// 线性筛法，欧氏筛法
void get_primes02(int n)
{
    for (int i = 2; i <= n / i; i ++) {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    get_primes02(n);
    cout << cnt << endl;
}