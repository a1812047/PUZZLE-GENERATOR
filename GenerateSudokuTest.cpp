#include "GenerateSudoku.h"

int main(){
    vector<vector<char>> puzzle = generatePuzzle((difficulty) 2 );

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<puzzle[i][j]<<" ";
        }
        cout<<endl;
    }

}