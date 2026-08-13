class Solution {
public:

    struct Node {
        int l, r;
        int lmx, rmx, mx;

        Node() {}

        Node(int l, int r) {
            this->l = l;
            this->r = r;
            lmx = rmx = mx = 1;
        }
    };

    vector<Node> tree;
    string s;

    void build(int idx, int l, int r) {

        tree[idx] = Node(l, r);

        if (l == r)
            return;

        int mid = (l + r) / 2;

        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);

        merge(idx);
    }

    void merge(int idx) {

        Node &root = tree[idx];
        Node &left = tree[idx * 2];
        Node &right = tree[idx * 2 + 1];

        root.lmx = left.lmx;
        root.rmx = right.rmx;

        root.mx = max(left.mx, right.mx);

        int leftLen = left.r - left.l + 1;
        int rightLen = right.r - right.l + 1;

        // The two segments can be joined
        if (s[left.r - 1] == s[right.l - 1]) {

            // Entire left segment has the same character
            if (left.lmx == leftLen) {
                root.lmx += right.lmx;
            }

            // Entire right segment has the same character
            if (right.rmx == rightLen) {
                root.rmx += left.rmx;
            }

            // A repeating sequence crosses the middle
            root.mx = max(
                root.mx,
                left.rmx + right.lmx
            );
        }
    }

    void update(int idx, int pos, char ch) {

        if (tree[idx].l == tree[idx].r) {
            s[pos - 1] = ch;
            return;
        }

        int mid = (tree[idx].l + tree[idx].r) / 2;

        if (pos <= mid) {
            update(idx * 2, pos, ch);
        }
        else {
            update(idx * 2 + 1, pos, ch);
        }

        merge(idx);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n + 5);

        // Build segment tree
        build(1, 1, n);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            // queryIndices is 0-indexed,
            // segment tree is 1-indexed
            int pos = queryIndices[i] + 1;

            char ch = queryCharacters[i];

            // Update character
            update(1, pos, ch);

            // Root contains answer for entire string
            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};