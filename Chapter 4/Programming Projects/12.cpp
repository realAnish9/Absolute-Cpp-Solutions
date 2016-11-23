//Hint from: http://stackoverflow.com/questions/14994767/randomly-generated-probability-game-with-loops-and-elimination
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int shot();
void hit(bool &aaron, bool &bob, bool &charlie);
char findWinner(bool aaron, bool bob, bool charlie);
void printWinner(char winner);
void add_score(int &a_score, int &b_score, int &c_score, char winner);
void printScore(int a_score, int b_score, int c_score);
int main(){
    srand(time(0));
    int a_score = 0, b_score = 0, c_score = 0;
    for(int i=1; i<=10000; i++){
        bool aaron = true;
        bool bob = true;
        bool charlie = true;
        cout << endl;
        hit(aaron, bob, charlie);
        char winner = findWinner(aaron, bob, charlie);
        printWinner(winner);
        cout << endl;
        add_score(a_score, b_score, c_score, winner);
    }
    printScore(a_score, b_score, c_score);
    return 0;
}
int shot(){
    return rand() % 100;
}
void hit(bool &aaron, bool &bob, bool &charlie){
    int a, b, c;
    a = shot();
    if(a <= 33){
        charlie = false;
        cout << "Charlie killed." << endl;
        b = shot();
        if(b <=50 ){
            aaron = false;
            cout << "Aaron killed." << endl;
        }
        else if(b > 50){
            while(true){
                a = shot();
                if(a <= 33){
                    bob = false;
                    cout << "Bob killed." << endl;
                    break;
                }
                else if(a > 33){
                    b = shot();
                    if(b <= 50){
                        aaron = false;
                        cout << "Arron killed." << endl;
                        break;
                    }
                }
            }
        }
    }
    else if(a > 33){
        b = shot();
        if(b <= 50 ){
            charlie = false;
            cout << "Charlie killed." << endl;
            a = shot();
            if(a <= 33){
                bob = false;
                cout << "Bob killed." << endl;
            }
            else if(a > 33){
                while(true){
                    b = shot();
                    if(b <= 50){
                        aaron = false;
                        cout << "Aaron killed." << endl;
                        break;
                    }
                    else if(b > 50){
                        a = shot();
                        if(a <= 33){
                            bob = false;
                            cout << "Bob killed." << endl;
                            break;
                        }
                    }
                }
            }
        }
        else if(b > 50){
            bob = false;
            cout << "Bob killed." << endl;
            a = shot();
            if(a <= 33){
                charlie = false;
                cout << "Charlie killed." << endl;
            }
            else if(a > 33){
                aaron = false;
                cout << "Aaron killed." << endl;
            }
        }
    }
}
char findWinner(bool aaron, bool bob, bool charlie){
    char result;
    if(aaron == false && bob == false && charlie == true){
        result = 'c';
    }
    else if(aaron == true && bob == false && charlie == false){
        result = 'a';
    }
    else if(aaron == false && bob == true && charlie == false){
        result = 'b';
    }
    return result;
}
void printWinner(char winner){
    if(winner == 'a'){
        cout << "The winner is Aaron."<< endl;
    }
    else if(winner == 'b'){
        cout << "The winner is Bob." << endl;
    }
    else if(winner == 'c'){
        cout << "The winner is Charlie." << endl;
    }
    return;
}
void add_score(int &a_score, int &b_score, int &c_score, char winner){
    if(winner == 'a'){
        a_score++;
    }
    else if(winner == 'b'){
        b_score++;
    }
    else if(winner == 'c'){
        c_score++;
    }
    return;
}
void printScore(int a_score, int b_score, int c_score){
    cout << "Score of Aaron is: " << a_score << endl;
    cout << "Score of Bob is: " << b_score << endl;
    cout << "Score of Charlie is: " << c_score << endl;
    return;
}
