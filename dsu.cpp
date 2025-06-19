struct dsu {
private:
    vector<int> par, size;
public:
    dsu(int n) {
        par.resize(n + 5);
        size.resize(n + 5, 1);
        iota(par.begin(), par.end(), 0);
    }

    int get_root(int u) {
        if (u == par[u]) return u;
        return par[u] = get_root(par[u]);
    }

    bool same_set(int u, int v) {
        return get_root(u) == get_root(v);
    }

    void merge(int u, int v) {
        u = get_root(u);
        v = get_root(v);
        if (u == v) {
            return;
        }
        par[u] = v;
        size[v] += size[u];
    }
};


struct dsu {
    int n, components;
    vector<int> parent, rank, count;
    vector<pair<int, int>> st;
    vector<array<int, 3>> edge;
 
    void init(int _n) {
        n = _n;
        components = n;
        rank.assign(n, 1);
        count.assign(n, 1);
        parent.assign(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
 
    int root(int u) {
        if (parent[u] == u) return u;
        return root(parent[u]);
    }
 
    int is_same_set(int u, int v) {
        return root(u) == root(v);
    }
 
    void merge(int u, int v, int id) {
        int uroot = root(u), vroot = root(v);
        if (uroot == vroot) return;
        if (rank[uroot] > rank[vroot]) swap(uroot, vroot);
 
        --components;
        edge.push_back({ u, v, id });
 
        parent[uroot] = vroot;
        rank[vroot] += rank[uroot];
        count[vroot] += count[uroot];
        st.push_back({ uroot, vroot });
    }
 
    void roll_back() {
        auto [uroot, vroot] = st.back();
        st.pop_back();
 
        ++components;
        edge.pop_back();
 
        parent[uroot] = uroot;
        parent[vroot] = vroot;
        rank[vroot] -= rank[uroot];
        count[vroot] -= count[uroot];
    }
}
