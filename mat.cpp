//
// Created by shaul on 12/03/2022.
//
#include <iostream>
#include "mat.hpp"
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

const int maximum_digit = 1000;

namespace ariel {
    string mat(int columns, int rows, char symb1, char symb2) {
        vector<char> bad_symbols = {'\n','\r','\t','\0',' '};
        int const low = 33;
        int const high = 126;
        if (columns % 2 == 0 || rows % 2 == 0 || rows < 1 || columns < 1) {
            throw invalid_argument("Mat size is always odd ");
        }
        if(find(bad_symbols.begin(), bad_symbols.end(), symb1) != bad_symbols.end()||
           find(bad_symbols.begin(), bad_symbols.end(), symb2) != bad_symbols.end()){
            throw invalid_argument("Bad symbol. Choose a regular character ");
        }
        if (symb1 < low || symb1 > high || symb2 < low || symb2 > high ){
            throw invalid_argument("Bad symbol. Choose a regular character ");
        }
            vector<vector<char>> matrix( rows, vector<char>( columns ) );
        bool flag = true;
        //I will implement this function by working like an onion i.e. I will create each frame separately
        //starting from external frame until the final center frame.
        int start_rows = 0;
        int start_columns = 0;
        int end_rows = rows;
        int end_columns = columns;
        // 4 variables above are in charge of the bounds of the frame we color in each iteration
        int row_counter = rows;
        int col_counter = columns;
        //2 variables above will tell us when we are done creating the mat i.e. when one of them is below 0
        while (col_counter > 0 && row_counter > 0) {
            for (int i = start_rows; i < end_rows; ++i) {
                for (int j = start_columns; j < end_columns; ++j) {
                    if (i == start_rows || i == end_rows - 1 || j == start_columns || j == end_columns - 1) {
                        if (flag) {//simple flag to decide what symbol should be used in this iteration
                            matrix[i][j] = symb1;
                        } else {
                            matrix[i][j] = symb2;
                        }
                    }
                }
            }
            //basically my 2 inner loops are in charge of iterating a matrix and finding where we should color it
            // (only in the boundaries) when we finish the 2 inner loops we "move in a tier" and color the next frame
            flag = !flag;//want to make sure to switch between symbols
            start_columns++;
            start_rows++;
            end_columns--;
            end_rows--;
            row_counter -= 2;
            col_counter -= 2;
        }
        string result;
        //now all thats left is to make the matrix into a string which is printable easily
        for (int i = 0; i < rows; ++i) {
            if (i != 0) {
                result += '\n';
            }
            for (int j = 0; j < columns; ++j) {
                result += matrix[i][j];
            }
        }
        //vectors have been deleted
        return result;
    }
}
