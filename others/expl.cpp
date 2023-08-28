#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

int main(){
    vector<int> list{1,2,3};
    for(int i=0;i<list.size();++i){
        cout<<list[i]<<endl;
    }
    cout<<endl;

    auto i=1;
    auto i_copy = i; // copy

    auto* i_ptr = &i; // int* i_ptr = &i;
    int& i_ref = i; // ref means alias
    auto& i_ref2 = i_ref; // auto ref ,no ref to ref

    const int& i_const_ref = i;
    const auto& j_const_ref = i;
    // i = 2;
    // cout<<i_const_ref<<endl;

    const auto j=1; // const int j=1; // j=2;
    // int& j_ref = j; // const! 

    for(auto it = list.begin();it!=list.end();++it){
        cout<<*it<<endl;
    }

    for(const auto& num:list){
        cout<<num<<' ';
    }
    // equals to
    for(int i=0;i<list.size();++i){
        const auto& num = list[i];
        // your code
    }
    // python
    // list = [1,2,3]
    // for num in list:
    //     print(num)
    return 0;
}