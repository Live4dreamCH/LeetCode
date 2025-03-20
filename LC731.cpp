#include "MyLib.h"

// �߶����ڵ�
template<typename V,typename R=int>
class SegmentTreeNode {
public:
    SegmentTreeNode(const R& l, const R& r) :range_l(l), range_r(r) {  }
    SegmentTreeNode(const R& l, const R& r, const V& v) :val(v), SegmentTreeNode(l, r) {  }

    // ������[l, r)���иı�v
    // �����������[l, r)�����˽ڵ㸺��ķ�Χ
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
        // �ڱ��μ���֮ǰ����ɴ�ǰ���ӵļ���
        push_down();
        // ���ӽڵ���б��μ���
        R mid = (range_l + range_r) / 2;
        if (l < mid) {
            child_l->change(l, std::min(mid, r), v);
        }
        if (mid < r) {
            child_r->change(std::max(mid, l), r, v);
        }
        // �����ӽڵ��ֵ���µ�ǰ�ڵ��ֵ����ɱ��μ���
        merge_val_func();
    }

    // ������[l, r)���в�ѯ
    // �����������[l, r)�����˽ڵ㸺��ķ�Χ
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
        // ��ǰ�ڱ��ڵ������ŵļ���
        // ����"����ȫ���Ǳ��ڵ�����������Ĳ�ѯ"ִ��ǰ
        // �������ӽڵ㣬����ɴ˴β�ѯ
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
        // �������Ƹı��ӽڵ��
        // �ӽڵ�ĸı䲻��Ӱ�쵽�˽ڵ��ֵ
        // ��Ϊ֮ǰ���ڴ˽ڵ������ŵļ���
        // ����ȫ�����Ǵ˽ڵ�������
        // ��ʱ����change_val_func����
        // �ѱ��ڵ��ֵ����ȷ��
        // �������������еĺϲ�����
        // merge_val_func();
    }

    void get_range(R& l, R& r) {
        l = range_l;
        r = range_r;
    }
private:
    V val{};
    R range_l, range_r; // �ڵ㸺�������Ϊ[range_l, range_r)
    SegmentTreeNode* child_l = nullptr, * child_r = nullptr;
    V lazy{}; // �����¸��Ǵ˽ڵ㸺�����������ʱ���ݴ�����lazy�����ӽڵ����Ϣ����ÿ��Ҷ�ڵ���ԭֵ�����ϼ��˼�

    // ���������ӽڵ㣨���ޣ�
    // ��lazy�����ӽڵ�
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

    // ����Ϊ�Զ��庯�������ݾ�����������޸�

    // �����ڵ���ȫ�ܶ���������������������������ʱ
    // ʹ�ô˺���
    void change_val_func(const R &l, const R &r, const V& v) {
        val += v;
    }
    // �����ڵ���ȫ�ܶ���������������������������ʱ
    // ʹ�ô˺���
    void change_lazy_func(const V& v) {
        lazy += v;
    }
    // ����ʱ�ľ������
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
    // ���Һ��ӵ�ֵ������ɺ�
    // �ô˺������±��ڵ��ֵ
    void merge_val_func() {
        val = std::max(child_l->val, child_r->val);
    }
    // ���ҵݹ��ѯ��ֵ���غ�
    // �ô˺������ر��β�ѯ��ֵ
    V query_merge_func(const V &val_l, const V &val_r) {
        return std::max(val_l, val_r);
    }
};

// �߶�����װ��
// ��װһ��SegmentTreeNode root
// �Է����ڲ��ڵ�������
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