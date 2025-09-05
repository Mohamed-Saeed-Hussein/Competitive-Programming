#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}
 
template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << " ";
    return out;
}
 
template <class T>
bool ckmin(T &a, const T &b)
{
    return a > b ? a = b, 1 : 0;
}
 
template <class T>
bool ckmax(T &a, const T &b)
{
    return a < b ? a = b, 1 : 0;
}


constexpr int64_t N = (1e7 + 7);
constexpr int64_t inf = (0x3f3f3f3f3f3f3f3f);
constexpr int64_t mod = (1e9 + 7);
constexpr int64_t dx4[4] = {0, 0, 1, -1};
constexpr int64_t dy4[4] = {1, -1, 0, 0};
constexpr int64_t dx8[8] = {0, 0, 1, 1, 1, -1, -1, -1};
constexpr int64_t dy8[8] = {1, -1, 1, 0, -1, 1, 0, -1};
constexpr char dz[] = {'D', 'L', 'U', 'R'};