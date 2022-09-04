#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = 2 * N;

int n;
int h[N], e[M], ne[M], idx;
bool st[N];
int ans = N;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u)
{
    st[u] = true;
    int a = 0, size = 1;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int k = dfs(j);
            size += k;
            a = max(a, k);
        }
    }
    a = max(a, n - size);
    ans = min(a, ans);
    return size;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;
    return 0;
}