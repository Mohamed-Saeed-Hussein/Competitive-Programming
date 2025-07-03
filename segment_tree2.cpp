class segment_tree {
private:
    int size_of_segment = 1;
    struct node {
        int64_t num = 0;
        int turn = 0;
        int64_t sum = 0;
        int64_t _min = 1e18;
        int64_t _max = -1e18;
    };
    vector<node> tree;

    node merge(node left, node right) {
        node ret;
        ret._min = min(left._min, right._min);
        return ret;
    }

    void build(int _node, int low, int high, vector<int64_t> &v) {
        if (low == high) {
            if (low >= 0 and high <= v.size() - 1) {
                tree[_node]._min = v[low];
            }
            return;
        }
        int mid = (low + high) / 2;
        int left_child = 2 * _node + 1;
        int right_child = 2 * _node + 2;
        build(left_child, low, mid, v);
        build(right_child, mid + 1, high, v);
        tree[_node] = merge(tree[left_child], tree[right_child]);
    }

    void update(int _node, int low, int high, int index, int64_t value) {
        if (low == high) {
            tree[_node]._min = value;
            return;
        }
        int mid = (low + high) / 2;
        int left_child = 2 * _node + 1;
        int right_child = 2 * _node + 2;
        if (index <= mid) {
            update(left_child, low, mid, index, value);
        } else {
            update(right_child, mid + 1, high, index, value);
        }
        tree[_node] = merge(tree[left_child], tree[right_child]);
    }

    node query(int _node, int low, int high, int l, int r) {
        if (l <= low and high <= r) {
            return tree[_node];
        }
        if (low > r or high < l) {
            return node();
        }
        int mid = (low + high) / 2;
        int left_child = 2 * _node + 1;
        int right_child = 2 * _node + 2;
        node left_result = query(left_child, low, mid, l, r);
        node right_result = query(right_child, mid + 1, high, l, r);
        return merge(left_result, right_result);
    }

    int find_first(int _node, int low, int high, int l, int r, int64_t value) {
        if (l > high or r < low or tree[_node]._min > value) {
            return -1;
        }
        if (low == high) {
            return low;
        }
        int mid = (low + high) / 2;
        int left_child = 2 * _node + 1;
        int right_child = 2 * _node + 2;
        int ret = find_first(left_child, low, mid, l, r, value);
        if (ret != -1) {
            return ret;
        }
        return find_first(right_child, mid + 1, high, l, r, value);
    }

public:
    segment_tree(vector<int64_t> &v) {
        while (size_of_segment < v.size()) {
            size_of_segment *= 2;
        }
        tree.assign(2 * size_of_segment, node());
        build(0, 0, size_of_segment - 1, v);
    }

    node query(int l, int r) {
        return query(0, 0, size_of_segment - 1, l, r);
    }

    void update(int index, int64_t value) {
        update(0, 0, size_of_segment - 1, index, value);
    }

    int find_first(int l, int r, int64_t value) {
        return find_first(0, 0, size_of_segment - 1, l, r, value);
    }

};
