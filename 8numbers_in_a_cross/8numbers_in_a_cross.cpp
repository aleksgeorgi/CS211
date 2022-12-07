#include <iostream>
using namespace std;

void printCross(int cross[]){
    static int sol = 0;

    sol++; 
    cout << "Solution #" << sol << ": \n";
    for(int i=0; i<8; i++){
        if(i==2 || i==6){
            cout << endl;
        }
    
        if(i==0 || i==6){
            cout << "  ";
        }
        
        cout << " " << cross[i];
    }
    cout << endl;
    
    return;
} // end printCross - TESTED & WORKS

bool alreadyPlaced(int q[], int c){
    /* row test */
    //Fill-in
    for(int i=0; i <c; i++){
        if(q[c]==q[i]){
           return true;   
        }
    }
    return false;
} // end alreadyPlaced - TESTED & WORKS

bool okAdjacent(int q[], int c){
    static int checkArray[8][5] = {
        {-1},       // position 0; -1 is a sentinel value (to stop checking)
        {0,-1},     //position 1 
        {0,-1},     //position 2
        {0,1,2,-1}, //position 3
        {0,1,3,-1}, //position 4
        {1,4,-1},    //position 5
        {2,3,4,-1},  //position 6
        {3,4,5,6,-1}//position 7
    };

    for (int i = 0; checkArray[c][i] != -1; i++)
        if(abs(q[c]-q[checkArray[c][i]]) == 1){
            return false;
        }
        return true;
} // end okAdjacent - TESTED & WORKS

bool ok(int q[], int col){
    if (!alreadyPlaced(q, col) and okAdjacent(q, col))
        return true;
    return false;
}

int main() {

    int q[8] = {1,1,1,1,1,1,1,1}, col = 0;

    // Start at the first position in the cross
    // while we have not backtracked beyond the first index
    while (col>=0){

        // If we have exceed our last index
        if (col>7){
            printCross(q);// printCross
            // backtrack
            col--;
            q[col]++;
        }

        // If we have run out of numbers to try
        if(q[col]>8){
            q[col] = 1;// reset 
            // backtrack
            col--;
            if (col != -1) q[col]++;
        }

        // if the number we place is okay
        else if (ok(q, col)){
            // Move to the next index
            col++;  
        }

        else{
            // increment the current index
            q[col]++;
        }
    }
    return 0;
}
