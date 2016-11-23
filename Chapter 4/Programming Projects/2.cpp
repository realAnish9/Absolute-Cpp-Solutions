//The triangle inequality states that the sum of the length of any two sides of triangle must be greater than or equal to the length
//of third side
#include <iostream>
#include <cmath>
using namespace std;
void getvalues(double &len1, double &len2, double &len3);
bool check_valid(double len1, double len2, double len3);
void calculation(double len1, double len2, double len3, double &area, double &perimeter);
double perimet(double len1, double len2, double len3);
void output(double area, double perimeter);
int main(){
    double length1, length2, length3;
    double area, perimeter;
    getvalues(length1, length2, length3);
    if(check_valid(length1, length2, length3) == true){
        calculation(length1, length2, length3, area, perimeter);
        output(area, perimeter);
    }
    else{
        cout << "The sides you inputted cannot form a valid triangle.";
    }
    return 0;
}
void getvalues(double &len1, double &len2, double &len3){
    cout << "Enter the sides of the triangle: ";
    cin >> len1 >> len2 >> len3;
}
bool check_valid(double len1, double len2, double len3){
    bool result = false;
    if(len1 + len2 >= len3 || len1 + len3 >= len2 || len2 + len3 >= len1){
        result = true;
    }
    return result;
}
void calculation(double len1, double len2, double len3, double &area, double &perimeter){
    perimeter = perimet(len1, len2, len3);
    double s = perimeter/2;
    double exp = s*(s-len1) * (s-len2) * (s-len3);
    area = sqrt(exp);
}
double perimet(double len1, double len2, double len3){
    return (len1+len2+len3);
}
void output(double area, double perimeter){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "\nThe area of the triangle is: " << area << " square cm.";
    cout << endl;
    cout << "The perimeter of the triangle is: " << perimeter << " cm.";
    cout << endl;
}

