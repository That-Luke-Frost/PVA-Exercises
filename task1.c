#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

#include <stdbool.h>
#include <stdio.h>
#include <math.h> //use "-l m" in the command line
#include <float.h>

using namespace std;

class easyFloat {
    //initialisation to zero at the beginning to prevent random values
    int number = 0;
    //Beware! This number must be the exponent of the number ten
    //Beware! If it's zero then you must not divide by it!
    int base10 = 0; //this number tells us by how many decimal places we have to move the number
    //to the left to get the original number

public:
    easyFloat() {
//        cout << number << ' ' << base10 << endl;
        char c;
        int numbers_behind = 0; //Numbers behind the decimal place. Attention! The dot counts too,
        //So if someone enters 5., the value will be 1, for 5.5, the value will be 2
        while (true) {
            scanf("%c", &c);
//            cout << "Loaded: " << c << endl;
            if (c >= '0' && c <= '9') {
                number *= 10; //on the first run won't do anything
                number += c - '0'; //converting to number
                if (numbers_behind > 0) //If we are to the right of the dot
                    numbers_behind++; //add one
            }
            else if (c == '.') { //Starting to count places right of the decimal dot
                if (numbers_behind > 0)
                    printf("Error: too many dot separators\n");
                numbers_behind++;
            }
            else if (c == ' ' || c == '\n') //exiting when detecting end of a number sequence
                break;
        }
        if (numbers_behind == 1) {
            printf("Error: numbers like 5. not allowed\n");
        }
        else if (numbers_behind > 1) {
            base10 = numbers_behind - 1;
        }
//        printf("End\n");
    }
    void print() {
//        cout << number << ' ' << base10 * 10 << endl;
        if (base10 == 0) {
            cout << number << endl;
        }
        else {
            cout << number / (int) pow(10, base10) << '.' << number % (int) pow(10, base10) << endl;
        }
    }
    int base() {
        return base10;
    }
    operator const char*() {
        return "hello";
    }
    void move_dec(int e) {
        if (base10 < e) { //moving involves multiplying int number
            number *= (int) pow(10, e - base10);
            base10 = 0;
            cout << "number now" << number << endl;
        }
        else {
            base10 -= e;
        }
    }
    operator int() {
        return number;
    }
private:

};

int main() {

//    easyFloat t;
//    t.print();
//    cout << "Answered" << endl;
//    string abc;
//    abc << 254;
//    cout << abc;

//    cout << setprecision(30) << fixed << FLT_EPSILON << endl;
    double a[2];
    double b[2];
    double v_ab[2];
    double buffer;
    double c[2];
/*
    cout << "Bod A: " << endl;
    easyFloat a1, a2;
    cout << "Bod B: " << endl;
    easyFloat b1, b2;
    cout << "Bod C: " << endl;
    easyFloat c1, c2;

    int most_offset = 0;
    if (a1.base() > most_offset) //rubbish code
      most_offset = a1.base();
    if (a2.base() > most_offset)
      most_offset = a2.base();
    if (b1.base() > most_offset)
      most_offset = b1.base();
    if (b2.base() > most_offset)
      most_offset = b2.base();
    if (c1.base() > most_offset)
      most_offset = c1.base();
    if (c2.base() > most_offset)
      most_offset = c2.base();

    cout << most_offset << endl;

    //most offset tells how many times we have to put ten to the power to to get integer digits
    //AKA: what's x in 10^x


    if (most_offset > 0) {
        a1.move_dec(most_offset);
        a1.print();
        cout << endl;
        a2.move_dec(most_offset);
        a2.print();
        cout << endl;

        b1.move_dec(most_offset);
        b1.print();
        cout << endl;
        b2.move_dec(most_offset);
        b2.print();
        cout << endl;

        c1.move_dec(most_offset);
        c1.print();
        cout << endl;
        c2.move_dec(most_offset);
        c2.print();
        cout << endl;
    }
*/
//    cout << (int) c2 << endl;

//    int a =
//    a1 =
//    b1 =
//    c1 =


//    cout << a1 << endl;
//    a1.print();

//    scanf("%lf %lf", &a[0], &a[1]);
//    cout << "Bod A: " << a1.print() << ", " << a2.print() << endl;

    cout << "Bod A: " << endl;
//    cout << scanf("%lf %lf", &a[0], &a[1]);
    if (scanf("%lf %lf", &a[0], &a[1]) != 2) {
        cout << "Nespravny vstup." << endl;
        return 1;
    }
    printf("Bod B:\n");
    if (scanf("%lf %lf", &b[0], &b[1]) != 2) {

        cout << "Nespravny vstup." << endl;
        return 1;
    }
//    printf("Bod B: %f, %f", b[0], b[1]);
    printf("Bod C:\n");
    if (scanf("%lf %lf", &c[0], &c[1]) != 2) {
        cout << "Nespravny vstup." << endl;
        return 1;
    }
    v_ab[0] = b[0] - a[0];
    v_ab[1] = b[1] - a[1];
//    printf("%f\n", v_ab[0]);
    buffer = (c[0] - a[0]) / v_ab[0]; //how many times to multiply the vector to get c
//    printf("vector: %f %f\n", v_ab[0], v_ab[1]);
//    printf("%f\n", buffer);
//    printf("%1.20f == %1.20f\n", buffer * v_ab[1], c[1] - a[1]);
//    cout << buffer * v_ab[1] << endl;
//    cout << c[1] - a[1] << endl;
//    if (c[1] == c[1]) {
//        printf("test1\n");
//    }
//    cout << ((buffer * v_ab[1]) - (c[1] - a[1])) << endl;

    //are some points in the same locations?
    if (a[0] == b[0] && a[1] == b[1]) { //A an B
        cout << "Nektere body splyvaji." << endl;
        return 1;
    }
    if (a[0] == c[0] && a[1] == c[1]) { //A an C
        cout << "Nektere body splyvaji." << endl;
        return 1;
    }
    if (c[0] == b[0] && c[1] == b[1]) { //B an C
        cout << "Nektere body splyvaji." << endl;
        return 1;
    }

    double result0 = buffer * v_ab[1];
    double result1 = c[1] - a[1];
//    printf("%1.20f == %1.20f\n", result0, result1);
//    printf("%1.20f, %1.20f\n", round(result0 * 100) / 100, round(result1 * 100) / 100);
    if (round(result0 * 100) / 100 == round(result1 * 100) / 100) {
//        cout << "in if" << endl;
//        printf("nothing\n");
        printf("Body lezi na jedne primce.\n");
/*
        if (buffer > 1)
            printf("Prostredni bod je B\n");
        else if (a[0] > c[0]) {
            cout << "Prostredni bod je A" << endl;
        }
        else {
            printf("Prostredni bod je C\n");
        }
*/
        if (a[0] > b[0]) {
            if (a[0] > c[0]) {
                if (b[0] > c[0])
                    cout << "Prostredni bod je B" << endl;
                else
                    cout << "Prostredni bod je C" << endl;
            }
            else
                cout << "Prostredni bod je A" << endl;
        }
        else { // b is bigger than a
            if (b[0] > c[0]) {
                if (a[0] > c[0]) {
                    cout << "Prostredni bod je A" << endl;
                }
                else {
                    cout << "Prostredni bod je C" << endl;
                }
            }
            else
                cout << "Prostredni bod je B" << endl;
        }

    }
    else if (a[0] == 0 && b[0] == 0 && c[0] == 0) { //math breaks when 0 gets involved in X coord
        cout << "Body lezi na jedne primce." << endl;

        //finding which point is in the middle.
        if (a[1] > b[1]) {
            if (a[1] > c[1]) {
                if (b[1] > c[1])
                    cout << "Prostredni bod je B" << endl;
                else
                    cout << "Prostredni bod je C" << endl;
            }
            else
                cout << "Prostredni bod je A" << endl;
        }
        else { // b is bigger than a
            if (b[1] > c[1]) {
                if (a[1] > c[1]) {
                    cout << "Prostredni bod je A" << endl;
                }
                else {
                    cout << "Prostredni bod je C" << endl;
                }
            }
            else
                cout << "Prostredni bod je B" << endl;
        }
    }
    else {
        cout << "Body nelezi na jedne primce." << endl;
    }
//    cout << "after if" << endl;

}
