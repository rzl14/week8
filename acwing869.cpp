#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> get_divisors(int n)
{
    vector<int> res;

    for (int i = 1; i <= n / i; i ++)
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }

    sort(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        vector<int> res = get_divisors(x);
        for(auto t : res) cout << t << ' ';
        cout << endl;
    }
}