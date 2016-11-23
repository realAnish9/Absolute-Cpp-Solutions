#include <iostream>
using namespace std;
void getTime(int& hours, int& minutes);
char conversion(int& hours);
void output(int hours, int minutes, char cp);
int main(){
    int hours, minutes;
    char ans;
    do{
        getTime(hours, minutes);
        char cp = conversion(hours);
        output(hours, minutes, cp);
        cout << "\nCalculate again? ";
        cin>> ans;
    }while(ans == 'Y' || ans == 'y');
    return 0;
}
void getTime(int& hours, int& minutes){
    //input the hours and minutes as call-by-reference parameters
    cout << "Enter hours: ";
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> minutes;
}
char conversion(int& hours){
    char cp;
    int division;
    if(hours <= 12){
        cp = 'A';
    }
    else{
        division = hours % 12;
        if(division == 0){
            hours = 00;
        }
        else{
            hours = division;
        }
        cp = 'P';
    }
    return cp;
}
void output(int hours, int minutes, char cp){
    cout << "The time is: " << hours<< ":" << minutes << " " << cp << "M";
    cout << endl;
}


