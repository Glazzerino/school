#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// template<class T>
// void swap(T& a, T& b) {
//     T aux = a;
//     a = b;
//     b = aux;
// }


int partition(vector<int> list, int start, int end) {
    int pivot = list[end];
    // elements less than pivot goes to the left of pIndex
	// elements more than pivot goes to the right of pIndex
	// equal elements can go either way

    int pindex = start;

    for (int i = start; i < end; i++) {
        if (list[pindex] <= list[i]) {
            swap(list[pindex],list[i]);
            pindex++;
        }
    }
    
    swap(list[pindex],list[end]);
    return pindex;
}




int main() {

}