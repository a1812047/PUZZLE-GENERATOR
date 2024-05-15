
#include "SudokuSolver.cpp"
#include <iostream>
#include <vector>
const int maxLoopsAllowed = 5*1e6;

//create a sudoku. 
//then chose a random element and remove that number and try to solve it.
//try to solve the sudoku as many times required. if we can solve the sudoku in some other fashion
enum difficulty{
    easy,medium,hard
};
vector<vector<char>> generatePuzzle(difficulty d){
    int randomNumber;
    if(d == easy){
        /*pick a number between 40-45*/
        randomNumber = (rand()%5)+40;
    }else if(d == medium){
        /* pick a number between 45 and 50*/
        randomNumber = (rand()%5)+45;
    }else if (d == hard){
        /*pick a number between 50 and 55*/
        randomNumber = (rand()%5)+55;
    }

    vector<vector<char>> solvedSudoku = createSudoku();
    int loopsmade = 0;
    while(randomNumber > 0 && loopsmade < maxLoopsAllowed){
        int row_To_remove = rand()%9;
        int col_to_remove = rand()%9;

        if(solvedSudoku[row_To_remove][col_to_remove] == '.'){
           
        }else{
            int numberRemoved = solvedSudoku[row_To_remove][col_to_remove];
            solvedSudoku[row_To_remove][col_to_remove] = '.';
            int count = 0;
            vector<vector<char>> thisSudoku = solvedSudoku;
            numberOfways_to_solve(0,0,thisSudoku, count);
            if(count > 1){
                solvedSudoku[row_To_remove][col_to_remove] = numberRemoved;
            }else{
                randomNumber--;
            }
        }
        loopsmade++;
    }

    std::cout<<"loopsmade: "<<loopsmade<<endl;
    return solvedSudoku;
}

