# week8
## vector, 变长数组，倍增的思想
 *	v.size()	返回元素个数 
 *	v.empty()	返回是否为空 
 *	v.clear()	清空 
 *	v.front()	返回第一个数
 *	v.back()	返回最后一个数
 *	v.push_back()	向最后插入一个数
 *	v.pop_back()	删掉最后一个数
 *	v.begin()	第一个数的指针
 *	v.end()		最后一个数后面的位置的指针
 *	[]
 
## pair<int/..., int/...> 二元组
 *	p.first	第一个元素 
 *	p.second	第二个元素 
 *	 
 * string，字符串，substr()返回某一个子串, c_str()返回起始地址 
 *	size()
 *	empty()
 *	clear()
 
## quene, 队列
 *	q.push()	向队尾插入
 *	q.front()	返回队头元素
 *	q.pop()  	弹出队头元素 

## priority_quene，优先队列（默认是大根堆） 
 *	pq.push()	插入一个元素 
 *	pq.top()	返回堆顶元素 
 *	pq.pop()	弹出堆顶元素
 *	priority_quene<int, vecor<int>, greater<int>> q;	定义成小根堆 

## stack，栈，
 *	size()
 *	empty()
 *	push()
 *	top()
 *	pop()

## deque，双端队列，队头队尾都可插入删除
 *	size()
 *	empty()
 *	clear()
 *	front()
 *	back()
 *	push_back()
 *	pop_back()

## set, map, multiset, multimap，基于平衡二叉树（红黑树），动态维护有序序列
 *	size()
 *	empty()
 *	clear()
 *	begin()/end()	支持++，--，返回前驱和后缀 
###	set/multiset
 *		insert()	插入一个数 
 *		find()		查找一个数 
 *		count()		返回某一个数的个数 
 *		earse()
  			输入是一个数x：删除所有x 	O(k + logn),k是x的个数 
  			输入是一个迭代器：删除这个迭代器 
 *		lower_bound()	返回大于等于x的最小的数的迭代器 
 *		upper_bound()	返回大于x的最小的数的迭代器
###	map/multimap
 *		insert()	插入的是一个pair 
 *		earse()		输入的参数是pair或者迭代器
 *		find()
 *		[]			可以像用数组一样使用map，时间复杂度是O(logn) 
 *		lower_bound()	返回大于等于x的最小的数的迭代器 
 *		upper_bound()	返回大于x的最小的数的迭代器

## unordered_set, unordered_map, unordered_multiset, unordered_multimap，基于哈希表
 *	和上面类似，增删改查时间复杂度是O(1)，缺点是不支持 lower_bound()以及upper_bound()

## bitset，压位
 *  bitset<10000>	定义10000个位
 *  ~ , &,  |,  ^ 		取反，与，或，异或
 *  >>, <<			移位
 *  ==， !=
 *  []
 *  count()		返回有多少个1 
 *  any()		判断是否至少有一个1 
 *  none() 		判断是否全为0 
 *  set()		把所有位置成1 
 *  set(k, v)	把第k位变成v
 *  reset()		把所有位置成0 
 *  flip()		把所有位取反
 *  flip(k)		把第k位取反 
 
## 数学知识相关

### 质数
相关题型：分解质因数，质数筛算法
#### 试除法分解质因数
```
void divide(int x)
{
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;
            cout << i << ' ' << s << endl;
        }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}
```
#### 埃氏筛法
```
void get_primes(int n)
{
    for (int i = 2; i <= n / i; i ++) {
        if (!st[i]) {
            primes[cnt ++] = i;
            for (int j = i + i; j <= n; j += i) st[j] = true;
        }
    }
}
```
#### 欧氏筛法
```
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
```
### 约数
如果 N = p1^c1 * p2^c2 * ... *pk^ck
约数个数： (c1 + 1) * (c2 + 1) * ... * (ck + 1)
约数之和： (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
#### 试除法求所有约数
```
vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    sort(res.begin(), res.end());
    return res;
}
```
#### 欧几里得算法
` return b ? gcd(b, a % b) : a;
