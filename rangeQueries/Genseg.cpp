#include <bits/stdc++.h>
using namespace std;
#define int long long
#define aint(x) (x).begin(), (x).end()

// Define the Node structure for the segment tree
//initialization: SegTree<Node1, Update1> obj(size, arr);
struct Node1 {
    // a lot of values can be stores at a node
    int val; 
    Node1() { val = 0; } 
    Node1(int p1) { val = p1; } 
    void merge(Node1 &l, Node1 &r) {
        val = max(l.val, r.val);
    }
};

struct Update1 {
    int val;
    // this about the update operation
    Update1(int p1) { val = p1; }
    void apply(Node1 &a) {
        a.val = val;
    }
};

template<typename Node, typename Update>
class SegTree {

    vector<Node> tree;
    vector<int> arr;
    int n, s;

public:
    SegTree(int a_len, vector<int> &a) {
        arr = a;
        n = a_len;
        s = 1;
        while(s < 2 * n) s = s << 1;
        tree.resize(s);
        fill(tree.begin(), tree.end(), Node());
        build(0, n - 1, 1);
    }

    void build(int start, int end, int index) {
        if (start == end) {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }

    void update(int start, int end, int index, int query_index, Update &u) {
        if (start == end) {
            u.apply(tree[index]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index) update(start, mid, 2 * index, query_index, u);
        else update(mid + 1, end, 2 * index + 1, query_index, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }

    Node query(int start, int end, int index, int left, int right) {
        if (start > right || end < left) return Node();
        if (start >= left && end <= right) return tree[index];
        int mid = (start + end) / 2;
        Node l = query(start, mid, 2 * index, left, right);
        Node r = query(mid + 1, end, 2 * index + 1, left, right);
        Node ans;
        ans.merge(l, r);
        return ans;
    }

    void make_update(int index, int val) {
        Update new_update = Update(val);
        update(0, n - 1, 1, index, new_update);
    }

    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};
int32_t main() {
	// Example array
	vector<int> arr = {1, 2, 3, 4, 5};
	int n = arr.size();

	// Initialize the segment tree
	SegTree<Node1, Update1> segTree(n, arr);

	// Example query: XOR of range [1, 3]
	cout << "XOR of range [1, 3]: " << segTree.make_query(1, 3).val << endl;

	// Example update: Set index 2 to 10
	segTree.make_update(2, 10);
	cout << "After update, XOR of range [1, 3]: " << segTree.make_query(1, 3).val << endl;

	return 0;
}
