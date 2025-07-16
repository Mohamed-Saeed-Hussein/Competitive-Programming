struct sparse_table
{
    vector<vector<int>> table;
    vector<int> log_table, a;
    int n;

    void build()
    {
        int current_log = 0;
        for (int i = 0; i < n; i++)
        {
            table[i][0] = a[i];
            if ((1 << (current_log + 1)) <= i + 1)
                current_log++;
            log_table[i + 1] = current_log;
        }
        for (int j = 1; j < 20; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int L, int R)
    {
        int k = log_table[R - L + 1];
        return min(table[L][k], table[R - (1 << k) + 1][k]);
    }

    sparse_table(int n, vector<int> &a)
    {
        table = vector<vector<int>>(n, vector<int>(20));
        log_table.resize(n + 5);
        this->a = a;
        this->n = n;
        build();
    }
};
