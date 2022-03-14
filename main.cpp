//
// Created by shaul on 14/03/2022.
//
#include <iostream>
#include "mat.hpp"
#include <string>
using namespace std;

int main(){

    int num1,num2;
    char symb1 , symb2;
    cout<< "Please enter a positive odd integer to define the length of your mat"<<endl;
    cin>>num1;
    cout<< "Please enter a positive odd integer to define the width of your mat"<<endl;
    cin>>num2;
    cout<< "Please enter your first regular symbol which will determine the design of the mat"<<endl;
    cin>>symb1;
    cout<< "Please enter your second regular symbol which will determine the design of the mat"<<endl;
    cin>>symb1;
    cout<<"you entered  : "<<num1<<num2<<"as numbers\n";
    cout<<"you entered  : "<<symb1<<symb2<<"as characters\n";
    try {
        cout << ariel::mat(num2, num1, symb1, symb2) << endl;
    }
    catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;
    }
    return 1;

}
