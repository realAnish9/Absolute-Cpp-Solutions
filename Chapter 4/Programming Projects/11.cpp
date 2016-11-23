#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
char stick();
int user_choice();
int main(){
    srand(time(0));
    char ans;
    int switch_won = 0;
    int sticking_won = 0;
    int opening_door;
    for(int i=1; i<= 10000; i++){
        int prize_door = rand() % 3 + 1;
        int user_door = user_choice();
        cout << "\nChoose a door number: " << user_door << endl;
        for(int i = 0; i<=3; i++){
            if(i == user_door || i == prize_door){
                continue;
            }
            else{
                opening_door = i;
            }
        }
        cout << "Door " << opening_door << " contains a consolation prize.";
        cout << endl << "Would you like to stick with your original choice or switch? ";
        ans = stick();
        cout << ans << endl;
        if(ans == 'y' || ans == 'Y'){
            if(user_door == prize_door){
                switch_won++;
                cout << "You won $1,000,000.";
            }
            else{
                cout << "You won consolation prize.";
            }
            cout << endl;
        }
        else{
            for(int i = 1; i<=3; i++){
                if(user_door == i || opening_door == i){
                    continue;
                }
                else{
                    user_door = i;
                }
            }
            if(user_door == prize_door){
                sticking_won++;
                cout << "You won $1,000,000.";
            }
            else{
                cout << "You won consolation prize.";
            }
            cout << endl;
        }
    }
    cout << endl;
    cout << "Switching won : " << switch_won << " times.";
    cout << endl << "Sticking won: " << sticking_won << " times.";
    cout << endl;
    return 0;
}
char stick(){
    char ans;
    int number = rand() % 2 + 1;
    if(number == 1){
        ans = 'y';
    }
    else{
        ans = 'n';
    }
    return ans;
}
int user_choice(){
    return (rand()% 3 + 1);
}
