//
// Created by shaul on 14/03/2022.
//
#include <iostream>
#include "mat.hpp"
#include <string>
using namespace std;

int main(){
    int flag=1;
    while(flag) {
        int num1, num2;
        char symb1, symb2;
        cout << "Please enter a positive odd integer to define the length of your mat" << endl;
        cin >> num1;
        cout << "Please enter a positive odd integer to define the width of your mat" << endl;
        cin >> num2;
        cout << "Please enter your first regular symbol which will determine the design of the mat" << endl;
        cin >> symb1;
        cout << "Please enter your second regular symbol which will determine the design of the mat" << endl;
        cin >> symb2;
        try {
            cout<<"\nThis is your mat which you have designed!!\n"<<endl;
            cout << ariel::mat(num2, num1, symb1, symb2) << endl;
        }
        catch (exception &ex) {
            cout << "   caught exception: " << ex.what() << endl;
        }
        cout << "\nIf you wish to create an additional mat enter 1, if you wish to exit enter 0" << endl;
        cin>>flag;
        if (!flag){
            break;
        }
    }
    return 1;

}
