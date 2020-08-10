// silly experiment to try out generic programming
#include <iostream>
#include <string>
using namespace std;

template <typename T> 
T const& Max (T const& a, T const& b) {
    return a < b ? b:a;
}
template <typename T>
T generic_sum(T a, T b) {
    return (b + a);
}

template <typename T>   
std::pair<T,T> ask(T a, T b) {
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    // cout << "Max number is: " << Max(a,b) << endl;
    return std::pair<T,T> (a,b);
}

int main() {
    float num1, num2; // 0.76876 465468.89686
    auto couple = ask(num1,num2);
    cout << "Max number" << max(couple.first, couple.second) << endl;

    int num3, num4;
    auto ints = ask(num3,num4);
    cout << "Max number:" << max(ints.first, ints.second) << endl;

    char c1,c2;
    cin >> c1 >> c2;
    cout << (int) generic_sum(c1,c2);
}