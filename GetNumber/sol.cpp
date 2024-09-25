#include <iostream>
using namespace std;

bool is_different(int num) {
    int last_dig = num % 10;
    num /= 10;

    int prev = last_dig;

    while (num > 0) {
        int dig = num % 10;
        num /= 10;

        if (prev == dig)
            return false;
        prev = dig;
    }
    return last_dig != prev;
}

int get_number(int range) {
    int count = 0;
    for (int i = 10; i < range; ++i) {
        if (is_different(i)) {
            cout << i << endl;
            ++count;
        }
    }
    return count;
}

int main() {
    cout << "Count: " << get_number(1000);

    cout << endl;

    cout << static_cast<bool>(is_different(525)) << endl;;

    return 0;
}