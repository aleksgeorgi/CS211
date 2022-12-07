#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//GLOBALS
const int rows = 5, cols = 6;
int minRow, minLength;

string path[rows][cols];

// Calculates the cost of every square and fills in the cost matrix.
void calculateCosts() {
    
    int leftUp, left, leftDown;
    
    static int weight[rows][cols] = {{3,4,1,2,8,6},
                                    {6,1,8,2,7,4},
                                    {5,9,3,9,9,5},
                                    {8,4,1,3,2,6},
                                    {3,7,2,8,6,4}};
                                    
    // Declare the cost matrix.
    static int cost[rows][cols];
     
   // Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if (c==0){
                    //Copying the leftmost column of the weight matrix to the cost matrix
                    cost[r][c]=weight[r][c]; 
                    //initializing the leftmost column of the path matrix to the first row of the weight matrix
                    path[r][c] = to_string(r);
                }
                else 
                    cost[r][c]=999999; //assinging 999999 as a test value to check my code
                    path[r][c]="";
            }
        }

                                
  // For each remaining column,
      // Calculate the cost of each square in the column (non-recursively),
        for(int r=0; r<rows; r++){ 
            for(int c=1; c<cols; c++){ //starting from col 1 since col 0 is just the value of itself
            
                //calculate the minimum cost to get into the current square
                leftUp = cost[((r-1)%5)][c-1]; // mod5 to compensate for top/bottom wrapping
                left = cost[r][c-1];
                leftDown = cost[((r+1)%5)][c-1]; // mod5 to compensate for top/bottom wrapping
                
                //assign minimum value from previous calculations to minLength variable
                
                minLength = leftUp;
                //quit fix:
                if((r-1)==-1){
                    minRow=4;
                }

               if(left < minLength){
                    minLength = left;  
                    minRow = r;
               } 
               
               if(leftDown < minLength){
                    minLength = leftDown;  
                    //quit fix:
                    if((r+1)==5){
                        minRow=0;
                    }
                    else minRow = (r+1);
               }
                
                /*  *BUG* problem is that the first minLength is returning 0 when it should return 3
                    Issue seems to be with the first occurance of leftUp = cost[((r-1)%5)][c-1]
                    The value being returned from cost[((r-1)%5)][c-1] is 0
                    
                    I tested cout << (-1%5); and cout << ((0-1)%5) and both are returning -1 instead of 4
                    I'm not sure why the compiler is not returning 4 when using the mod operator 
                    
                */
                
                //update the cost matrix by adding the previous min col to the current box
                cost[r][c] = weight[r][c] + cost[minRow][c-1]; //I used weight instead of cost because cost had junk values

                //record the minimum row to the path mathrix / assign the minRow to the path matrix
                path[r][c] = path[minRow][c-1] + to_string(r);

            }
        }//end of Outer For Loop

//   // Check which square in the rightmost column has the lowest cost.  Store that cost in minLength and the row number in minRow.
    for (int r=1; r<rows; r++){
        if (cost[r][cols-1] < cost[r-1][cols-1]){
            minRow = r;
        }
        else minRow = r-1;
    }

}// END OF calculateCosts

int main() {
   calculateCosts();
   cout << "The length of the shortest path is " << minLength;
   cout << ".\nThe rows of the path from left to right are " << path[minRow][cols-1] << ".";

   return 0;
}
