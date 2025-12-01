struct two_sat
{
    int n;
    int nodes;
    vector<vector<int>> adj, adj_reverse;
    vector<bool> visited;
    vector<int> component;
    vector<int> nodes_stack;
    vector<bool> answer;

    two_sat(int num = 0)
    {
        n = num;
        nodes = num * 2;
        adj.resize(nodes);
        adj_reverse.resize(nodes);
    }

    int get_node_index(int i, bool value)
    {
        return 2 * i + (value ? 0 : 1);
    }

    void add_implication(int i, bool value_i, int j, bool value_j)
    {
        int u = get_node_index(i, value_i);
        int v = get_node_index(j, value_j);
        adj[u].push_back(v);
        adj_reverse[v].push_back(u);
    }

    void add_xnor(int i, int j)
    {
        add_or(i, 0, j, 1);
        add_or(i, 1, j, 0);
    }

    void add_or(int i, bool value_i, int j, bool value_j)
    {
        add_implication(i, !value_i, j, value_j);
        add_implication(j, !value_j, i, value_i);
    }

    void add_nand(int i, bool value_i, int j, bool value_j)
    {
        add_or(i, !value_i, j, !value_j);
    }

    void add_different(int i, int j)
    {
        add_or(i, 1, j, 1);
        add_or(i, 0, j, 0);
    }

    void add_same(int i, int j)
    {
        add_or(i, 0, j, 1);
        add_or(i, 1, j, 0);
    }

    void force_value(int i, bool val)
    {
        add_or(i, val, i, val);
    }

    void add_xor(int i, bool value_i, int j, bool value_j)
    {
        add_or(i, value_i, j, value_j);
        add_or(i, !value_i, j, !value_j);
    }

    void set_value(int i, bool value)
    {
        add_or(i, value, i, value);
    }

    void dfs_topo(int u)
    {
        visited[u] = true;
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                dfs_topo(v);
            }
        }
        nodes_stack.push_back(u);
    }

    void dfs_scc(int u, int c)
    {
        component[u] = c;
        for (int v : adj_reverse[u])
        {
            if (component[v] == -1)
            {
                dfs_scc(v, c);
            }
        }
    }

    bool is_satisfiable()
    {
        visited.assign(nodes, false);
        nodes_stack.clear();

        for (int i = 0; i < nodes; ++i)
        {
            if (!visited[i])
            {
                dfs_topo(i);
            }
        }

        component.assign(nodes, -1);
        int scc_count = 0;
        reverse(nodes_stack.begin(), nodes_stack.end());

        for (auto u : nodes_stack)
        {
            if (component[u] == -1)
            {
                dfs_scc(u, scc_count++);
            }
        }

        answer.resize(n);
        for (int i = 0; i < nodes; i += 2)
        {
            if (component[i] == component[i + 1])
            {
                return false;
            }

            answer[i / 2] = (component[i] > component[i + 1]);
        }
        return true;
    }
};
