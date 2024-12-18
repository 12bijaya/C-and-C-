//checking the number if it is power of 2 or not
#include<iostream>
using namespace std;

bool check_2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    if(check_2(n)) {
        cout << "\n\nThe number is a power of 2" << endl;
    } else {
        cout << "\n\nThe number is not a power of 2" << endl;
    }
    return 0;
}
