struct dsu
{
private:
    vector<int> parent, size;
 
public:
    dsu(int n)
    {
        parent.resize(n + 5);
        size.resize(n + 5, 1);
        iota(parent.begin(), parent.end(), 0);
    }
 
    int get_root(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = get_root(parent[u]);
    }
 
    bool same_set(int u, int v)
    {
        return get_root(u) == get_root(v);
    }
 
    void merge(int u, int v)
    {
        u = get_root(u);
        v = get_root(v);
        if (u == v)
        {
            return;
        }
        parent[u] = v;
        size[v] += size[u];
    }
    int get_size(int u)
    {
        return size[get_root(u)];
    }
};
 