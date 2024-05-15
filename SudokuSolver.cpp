#include <iostream>
#include <vector>
#include "shuffleItems.h"

using namespace std;

const int n = 9;
//Generate a solved sudoku


vector<char> getPossibleNumbers(int row, int col, vector<vector<char>>& board){
    vector<bool> numbers(10,true);
    //check grid
    int grid_row_start = (row/3)*3;
    int grid_col_start = (col/3)*3;

    for(int i = grid_row_start; i < grid_row_start+3; i++){
        
        for(int j = grid_col_start; j < grid_col_start+3; j++){
        
            if(board[i][j] != '.') numbers[board[i][j]-'0'] = false;
        
        }

    }

    //check row //check col
    for(int i =  0; i < n; i++){
        
        //check row
        if(board[row][i] != '.') numbers[board[row][i]-'0'] = false;
        
        //check col
        if(board[i][col] != '.') numbers[board[i][col]-'0'] = false;
    }

    vector<char> answers;

    for(int i = 1; i <= n; i++){
        if(numbers[i]) answers.emplace_back(i+'0');
    }
    shuffleItems(answers);
    return answers;
    
}

void numberOfways_to_solve(int curr_row, int curr_col, vector<vector<char>>& board, int& count){

    if(count > 1) return;
    if(curr_col >= n && curr_row < n){
        curr_col = 0;
        curr_row += 1;
    }

    if(curr_row >= n){
        count += 1;
        return ;
    }
    
    //if we reach the last box we should be able to return true anyways. 
    

    if(board[curr_row][curr_col] != '.'){

        numberOfways_to_solve(curr_row,curr_col+1,board, count);
       
    }else{
        vector<char> answers = getPossibleNumbers(curr_row,curr_col,board);
        for(int i = 0; i < answers.size(); i++){
            
            board[curr_row][curr_col] = answers[i];
            numberOfways_to_solve(curr_row,curr_col+1,board, count);
            if(count > 1) break;

        }
        board[curr_row][curr_col] = '.';
    }
}

void solve(int curr_row, int curr_col, vector<vector<char>>& board,bool& solved){
    if(solved) return;

    if(curr_col >= n && curr_row < n){
        curr_col = 0;
        curr_row += 1;
    }

    if(curr_row >= n){
        solved = true;
        return;
    }
    
    //if we reach the last box we should be able to return true anyways. 
    

    if(board[curr_row][curr_col] != '.'){

        solve(curr_row,curr_col+1,board,solved);
       
    }else{
        vector<char> answers = getPossibleNumbers(curr_row,curr_col,board);
        for(int i = 0; i < answers.size(); i++){
            
            board[curr_row][curr_col] = answers[i];
            solve(curr_row,curr_col+1,board, solved);
            if(solved) break;

        }
        if(!solved) board[curr_row][curr_col] = '.';
    }
}


void solveSUDOKU(vector<vector<char>>& board){
    bool solved = false;
    solve(0,0,board,solved);
    auto print = [&](){
        for(auto& line: board){
            for(char& x: line){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    };
    print();
    
}
std::vector<vector<char>> createSudoku(){
    vector<vector<char>> v(n,vector<char>(n,'.'));//start with empty one
    solveSUDOKU(v);// solve that . 
    return v; // we have a new sudoku
}
