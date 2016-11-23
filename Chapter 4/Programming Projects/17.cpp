#include <iostream>
using namespace std;
void getNumbers(int &a, int &b, int &c);
void sortNumbers(int &a, int &b, int &c);
void printNumbers(int a , int b, int c);
int main(){
    int a, b, c;
    getNumbers(a, b, c);
    sortNumbers(a, b, c);
    printNumbers(a, b, c);
    return 0;
}
void getNumbers(int &a, int &b, int &c){
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    return;
}
void sortNumbers(int &a, int &b, int &c){
    int lowest = a;
    if(b < a && b < c){
        lowest = b;
    }
    else if(c < a && c < b){
        lowest = c;
    }
    int greatest = c;
    if(a > b && a > c){
        greatest = a;
    }
    else if(b > a && b > c){
        greatest = b;
    }
    int middle;
    if(lowest == a && greatest == b){
        middle = c;
    }
    if(lowest == b && greatest == c){
        middle = a;
    }
    if(lowest == c && greatest == a){
        middle = b;
    }
    a = lowest;
    b = middle;
    c = greatest;
    return;
}
void printNumbers(int a, int b, int c){
    cout << "The sorted numbers are: " << a << ", " << b << ", " << c << endl;
    return;
}

