#include <iostream>
using namespace std;
void get_numbers(int &numerator, int &denominator);
void convert_to_lowest(int &numerator, int &denominator);
void print_result(int numerator, int denominator);
int main(){
    int numerator, denominator;
    get_numbers(numerator, denominator);
    convert_to_lowest(numerator, denominator);
    print_result(numerator, denominator);
}
void get_numbers(int &numerator, int &denominator){
    cout << "Enter the numerator: " ;
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;
    return;
}
void convert_to_lowest(int &numerator, int &denominator){
    int greatest_number = (numerator > denominator) ? numerator : denominator;
        for(int i = greatest_number; i>1; i--){
            if(numerator % i == 0 && denominator % i == 0){
                numerator = numerator / i;
                denominator = denominator /i;
                if(numerator == 1 || denominator == 1){
                    break;
                }
            }
        }
    return;
}
void print_result(int numerator, int denominator){
    cout << "Numerator: " << numerator;
    cout << endl;
    cout << "Denominator: " << denominator;
    cout << endl;
    return;
}

