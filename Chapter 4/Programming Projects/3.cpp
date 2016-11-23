#include <iostream>
using namespace std;
void getCoinValue(int &coinValue);
void computeCoin(int coinValue, int &number, int &amountLeft);
//passing arrays in the function changes the value of array.
//passing values by reference
int main(){
    int coinValue;
    int quarter, dime, penny;
    getCoinValue(coinValue);
    int amountLeft = coinValue;
    int number;
    computeCoin(coinValue, number, amountLeft);
    quarter = number;
    computeCoin(coinValue, number, amountLeft);
    dime = number;
    computeCoin(coinValue, number, amountLeft);
    penny = number;
    cout << "Quarter: " << quarter;
    cout << endl << "Dime: " << dime;
    cout << endl << "Penny: " << penny;
    cout << endl;
    return 0;
}
void getCoinValue(int &coinValue){
    cout << "Enter the coin value: ";
    cin >> coinValue;
}
void computeCoin(int coinValue, int &number, int &amountLeft){
    if(amountLeft >= 25){
        number = amountLeft/25;
        amountLeft = amountLeft - (number*25);
    }
    else if(amountLeft >= 10){
        number = amountLeft/10;
        amountLeft = amountLeft - (number*10);
    }
    else if(amountLeft < 10){
        number = amountLeft;
    }
    return;
}
