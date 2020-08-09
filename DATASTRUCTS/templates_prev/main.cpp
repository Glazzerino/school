// silly experiment to try out generic programming
#include <iostream>
#include <string>
using namespace std;

template <typename T> 
T const& Max (T const& a, T const& b) {
    return a < b ? b:a;
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
    float num1, num2;
    auto couple = ask(num1,num2);
    cout << "Max number" << max(couple.first, couple.second) << endl;

    int num3, num4;
    auto ints = ask(num3,num4);
    cout << "Max number:" << max(ints.first, ints.second) << endl;
}