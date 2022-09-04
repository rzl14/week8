#include <iostream>

using namespace std;

void divide(int x) {
    for (int i = 2; i <= x / i; i ++) {
        if (x % i) continue;
        int s = 0;
        while (x % i == 0) {
            x /= i;
            s ++;
        }
        printf("%d %d\n", i, s);
    }
    if (x > 1) printf("%d %d\n", x, 1);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        divide(x);
        cout << endl;
    }
    cin >> n;
}