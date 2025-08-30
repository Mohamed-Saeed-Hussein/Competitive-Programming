struct fenwick_tree {
private:
    vector<int64_t> tree;
    int N;
public:
    fenwick_tree(int n) : N(n) {
        tree.resize(N + 5, 0);
    }
 
    void add(int idx, int64_t val) {
        while (idx <= N) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
 
    int64_t query(int idx) {
        int64_t ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= idx & -idx;
        }
        return ret;
    }
 
    int64_t query(int l, int r) {
        return query(r) - query(l - 1);
    }
};