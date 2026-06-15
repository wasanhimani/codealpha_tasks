#include<iostream>
using namespace std;

#define N 9

int grid[N][N]={
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}

};

void printing_grid(){
    cout<<"*****************************"<<endl;
    for(int i=0;i<N;i++){
        cout<<"|";
        for(int j=0;j<N;j++){
            if(grid[i][j]==0)
            cout<<". ";
        else{
            cout<<grid[i][j]<<" ";

        }
        if((j+1)%3==0){
            cout<<"|";
        }
        }

        cout<<endl;
        if((i+1)%3==0)
        cout<<"**************************"<<endl;
    }
}


bool rowcheck(int row,int num){
    for(int col=0;col<N;col++){
        if(grid[row][col]==num)
        return true;
    }
    return false;
}


bool colcheck(int col,int num){
    for(int row=0;row<N;row++){
        if(grid[row][col]==num){
            return true;
        }
    }
    return false;
}


bool checkbox(int rowstart,int colstart, int num){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[rowstart+i][colstart+j]==num){
                return true;
            }
        }
    }

    return false;

}

bool issafe(int row,int col,int num){
    return !rowcheck(row,num) &&
           !colcheck(col,num)&& !checkbox(row-(row %3),col-(col%3),num);
}

bool solvesudoku(){
    int row=-1;
    int col=-1;

    bool emptycell=false;

    for(int i=0;i<N && !emptycell;i++){
        for(int j=0;j<N && !emptycell;j++){
            if(grid[i][j]==0){
                row=i;
                col=j;
                emptycell=true;
            }
        }
    }


    if(!emptycell){
        return true;
    }

    for(int num=1;num<=9;num++){
        if(issafe(row,col,num)){
            grid[row][col]=num;

            if(solvesudoku())
                return true;
            

            grid[row][col]=0;
        }
    }
    return false;


}

int main(){
    cout<<"***********SUDOKU SOLVING*********"<<endl;

    cout<<"PUZZLE"<<endl;
    printing_grid();

    if(solvesudoku()){
        cout<<"GREAT JOB! YOU SOLVED THE PUZZLE"<<endl;
        printing_grid();
    }
    else{
        cout<<"NO SOLUTION FOR THIS PUZZLE"<<endl;
    }

    return 0;

}