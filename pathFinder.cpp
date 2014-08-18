#include <iostream>


using namespace std;


int findNumberOfPaths(int rows, int cols, int currRow, int currCol, int a[][4]){

    if(rows == 2 && cols == 2){     // 2x2 matrix
        int number = 0;

        if(a[currRow][currCol +1] != 0)
            number += 1 ;
        if(a[currRow + 1][currCol] != 0)
            number += 1;


        return number;
    }


    if(rows == 1){      // 1 X N matrix
        for(int i=0; i<cols; i++){
            if(a[currRow][i + currCol] == 0)
                return 0;
        }
        return 1;
    }
    if(cols == 1){       // M X 1 matrix
        for(int i=0; i<rows; i++){
            if(a[i + currRow][currCol] == 0)
                return 0;
        }
        return 1;
    }


    if(a[currRow][currCol] != 0)    // M X N  matrix
        return findNumberOfPaths(rows-1, cols, currRow+1, currCol, a  ) + findNumberOfPaths(rows, cols-1, currRow, currCol+1, a);
    else        // if the current postion itself is 0, no path exists from that element
        return 0;


}



int main(int, char**){


    int a[3][4] = {{1,1,1,1} ,
                   {0,1,1,1} ,
                   {1,1,1,1} };

    /*int b[2][2] = {{1,1} ,
                   {0,1} };

    */

    int rows = 3, cols = 4;

    int currRow = 0; int currCol = 0;

    int noOfPaths = findNumberOfPaths(rows, cols, currRow, currCol, a);

    cout<<"No of Paths = " << noOfPaths<<endl;

}
