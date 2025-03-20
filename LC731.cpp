#include "MyLib.h"

// 线段树节点
template<typename V,typename R=int>
class SegmentTreeNode {
public:
    SegmentTreeNode(const R& l, const R& r) :range_l(l), range_r(r) {  }
    SegmentTreeNode(const R& l, const R& r, const V& v) :val(v), SegmentTreeNode(l, r) {  }

    // 在区间[l, r)进行改变v
    // 不接受输入的[l, r)超过此节点负责的范围
    void change(const R& l, const R& r, const V& v) {
        if (l < range_l) {
            std::cerr << "SegmentTreeNode change l < range_l\n";
            return;
        }
        if (range_r < r) {
            std::cerr << "SegmentTreeNode change range_r < r\n";
            return;
        }
        if (l == range_l && r == range_r) {
            change_val_func(l, r, v);
            if (range_r > range_l + 1) { change_lazy_func(v); }
            return;
        }
        // 在本次计算之前，完成此前拖延的计算
        push_down();
        // 对子节点进行本次计算
        R mid = (range_l + range_r) / 2;
        if (l < mid) {
            child_l->change(l, std::min(mid, r), v);
        }
        if (mid < r) {
            child_r->change(std::max(mid, l), r, v);
        }
        // 利用子节点的值更新当前节点的值，完成本次计算
        merge_val_func();
    }

    // 在区间[l, r)进行查询
    // 不接受输入的[l, r)超过此节点负责的范围
    V query(const R& l, const R& r) {
        if (l < range_l) {
            std::cerr << "SegmentTreeNode query l < range_l\n";
            return V{};
        }
        if (range_r < r) {
            std::cerr << "SegmentTreeNode query range_r < r\n";
            return V{};
        }
        if (l == r) {
            std::cerr << "SegmentTreeNode query l == r\n";
            return V{};
        }
        if (l == range_l && r == range_r) {
            return val;
        }
        // 此前在本节点拖延着的计算
        // 会在"不完全覆盖本节点所负责区间的查询"执行前
        // 下推至子节点，以完成此次查询
        push_down();
        R mid = (range_l + range_r) / 2;
        if (r <= mid) {
            return child_l->query(l, r);
        }
        if (mid <= l) {
            return child_r->query(l, r);
        }
        return query_merge_func(
            child_l->query(l, mid),
            child_r->query(mid, r)
        );
        // 但是下推改变子节点后
        // 子节点的改变不会影响到此节点的值
        // 因为之前能在此节点拖延着的计算
        // 都是全量覆盖此节点的区间的
        // 当时就用change_val_func函数
        // 把本节点的值改正确了
        // 因此无需进行下行的合并操作
        // merge_val_func();
    }

    void get_range(R& l, R& r) {
        l = range_l;
        r = range_r;
    }
private:
    V val{};
    R range_l, range_r; // 节点负责的区间为[range_l, range_r)
    SegmentTreeNode* child_l = nullptr, * child_r = nullptr;
    V lazy{}; // 当更新覆盖此节点负责的整个区间时，暂存用于lazy更新子节点的信息，如每个叶节点在原值基础上加了几

    // 创建左右子节点（若无）
    // 将lazy推至子节点
    void push_down() {
        if (range_r <= range_l + 1) {
            std::cerr << "push_down range_r <= range_l + 1\n";
            return;
        }
        R mid = (range_l + range_r) / 2;
        if (nullptr == child_l) {
            child_l = new SegmentTreeNode(range_l, mid);
        }
        if (nullptr == child_r) {
            child_r = new SegmentTreeNode(mid, range_r);
        }
        push_lazy_func();
    }

    // 以下为自定义函数，根据具体问题进行修改

    // 当本节点完全能独立处理传入的请求参数，无需下推时
    // 使用此函数
    void change_val_func(const R &l, const R &r, const V& v) {
        val += v;
    }
    // 当本节点完全能独立处理传入的请求参数，无需下推时
    // 使用此函数
    void change_lazy_func(const V& v) {
        lazy += v;
    }
    // 下推时的具体操作
    void push_lazy_func() {
        if (0 == lazy) {
            return;
        }
        child_l->val += lazy; // todo: may use change_val_func; may need l, r
        child_l->lazy += lazy;
        child_r->val += lazy;
        child_r->lazy += lazy;
        lazy = 0;
    }
    // 左右孩子的值更新完成后
    // 用此函数更新本节点的值
    void merge_val_func() {
        val = std::max(child_l->val, child_r->val);
    }
    // 左右递归查询的值返回后
    // 用此函数返回本次查询的值
    V query_merge_func(const V &val_l, const V &val_r) {
        return std::max(val_l, val_r);
    }
};

// 线段树包装类
// 包装一个SegmentTreeNode root
// 以防对内部节点的误操作
template<typename V, typename R = int>
class SegmentTree {
public:
    SegmentTree(const R& l, const R& r) :root(l, r) {}

    void change(R l, R r, const V& v) {
        if (l > r) {
            R temp = l;
            l = r;
            r = temp;
        }
        else if (l == r) {
            return;
        }
        R range_l{}, range_r{};
        root.get_range(range_l, range_r);
        if (l < range_l) { l = range_l; }
        if (range_r < r) { r = range_r; }
        root.change(l, r, v);
    }

    V query(R l, R r) {
        if (l > r) {
            R temp = l;
            l = r;
            r = temp;
        }
        else if (l == r) {
            return V{};
        }
        R range_l{}, range_r{};
        root.get_range(range_l, range_r);
        if (l < range_l) { l = range_l; }
        if (range_r < r) { r = range_r; }
        return root.query(l, r);
    }
private:
    SegmentTreeNode<V, R> root;
};

class MyCalendarTwo {
public:
    MyCalendarTwo() {
    }

    bool book(int startTime, int endTime) {
        if (seg_tree.query(startTime, endTime) >= 2) {
            return false;
        }
        seg_tree.change(startTime, endTime, 1);
        return true;
    }
private:
    SegmentTree<int> seg_tree{ 0, 1000000001 }; // 1000000001
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */

//int main() {
//    MyCalendarTwo s{};
//    bool test{};
//    test = true == s.book(10, 20);
//    test = true == s.book(50, 60);
//    test = true == s.book(10, 40);
//    test = false == s.book(5, 15);
//    test = true == s.book(5, 10);
//    test = true == s.book(25, 55);
//    return 0;
//}