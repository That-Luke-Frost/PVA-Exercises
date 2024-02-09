#include <iostream>
#include <climits>

using namespace std;

char space64[64];
char space_rotated[64];
int rounds;

int convert_base(int bi, int bbase) {
    int i;
//    cout << "function: " << bi << ' ' << bbase << endl;
//    cout << bi % bbase << endl;
    for (i = 0; bi != 0; i++) {
        space64[i] = bi % bbase;
//        cout << (int) space50[i] << endl;
        bi /= bbase;
//        cout << i << endl;
    }
    return i;
}

int rotate_and_compare(int spaces) { //1 error, 0 fine, the number is palindrome
    int j = spaces - 1;
    for (int i = 0; i < spaces; i++, j--) {
//        cout << "i: " << i;
//        cout << " j: " << j << endl;
        space_rotated[j] = space64[i];
    }

    for (int i = 0; i < spaces; i++) {
        if (space64[i] != space_rotated[i])
            return 1;
    }
    return 0;
}

int nextPalindrome(unsigned long long from, int radix, unsigned long long * next) {
//    int rounds;
    if (radix >= 2 && radix <= 36) {
        for (;true;) {
            if (from < ULLONG_MAX) {
                from++;

                rounds = convert_base(from, radix);
                if (rotate_and_compare(rounds) == 0) {
                    *next = from;
                    return 1; //success, found palindrome
                }
            }
            else {
                return 0;
            }
        }
        //ULLONG_MAX
    }
    else
        return 0; //error, not success
}


int main () {
    int i;
    int base;
    unsigned long long returnval = 0;
//    int rounds;
    scanf("%d %d", &i, &base);
    nextPalindrome(i, base, &returnval);
    cout << returnval << endl;

//    rounds = convert_base(i, base);
//    if (rotate_and_compare(rounds) == 1) {
//        cout << "not palindrome" << endl;
//    }
//    else
//        cout << "palindrome" << endl;
//    cout << "rounds: " << rounds << endl;


    //internal use
    for (int i = 0; i < rounds; i++) { //rounds is one than the last used index
        cout << '[' << (int) space64[i] << "] [" << (int) space_rotated[i] << ']' << endl;
    }



}
