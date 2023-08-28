// λ
// y = f(x) = ax + b
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::stoi;

// int f(int x){
//     return a*x + b;
// }

// todo: callable object

void print();

int main(int argc, char* argv[]){
    if(3 != argc){
        cout << "wrong argument!";
        return 1;
    }
    int a = stoi(argv[1]), b = stoi(argv[2]);

    // what is a and b?
    auto lambda_fun = [&a, &b](int x){
        return a*x+b;
    };

    int i = 10;
    int j = lambda_fun(i);
    a++;
    b++;
    cout << j << endl;
    cout << lambda_fun(j) << endl;
    //cout<<f(i)<<endl;
    print();
    return 0;
}

void print(){
    cout<<"hello world!"<<endl;
}