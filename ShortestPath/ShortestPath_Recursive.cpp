#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int rows = 5, cols = 6;
string path[rows][cols];

// Returns the cost of the shortest path from the left to the square in row i, column j.
int calculateCost(int i, int j) {
   static int weight[rows][cols] = {{3,4,1,2,8,6},
                                    {6,1,8,2,7,4},
                                    {5,9,3,9,9,5},
                                    {8,4,1,3,2,6},
                                    {3,7,2,8,6,4}};
   // Declare the cost matrix.
   static int cost[rows][cols];
   
   // If the cost has already been calculated, return it.
   if(cost[i][j]>0) return cost[i][j];
   
   // Check for the base case.
   if (j == 0) {
      path[i][j] = to_string(i);
      return weight[i][j];
   }
   
   // Calculate the costs of the 3 adjacent squares by calling the function recursively.
   int up = calculateCost((i-1)%5, j-1);
   int left = calculateCost(i, j-1);
   int down = calculateCost((i+1)%5, j-1);
   
   // Find the minimum of the 3 costs.
   int minimum = min(up, left);
   minimum = min(minimum, down);
   int minCost = minimum;

   
  // Update the path matrix (store the path to the current square in path[i][j]):
  // If up is the minimum, get the shortest path to the up-left square from the path matrix and concatenate it with the current row.
      if(minimum == up) path[i][j] = path[((i-1)%5)][j-1] + to_string(i);
  // If left is the minimum...
      if(minimum == left) path[i][j] = path[i][j-1] + to_string(i);
  // If down is the minimum...
      if(minimum == down) path[i][j] = path[((i+1)%5)][j-1] + to_string(i);
      
  // Calculate the cost of the current square, store the correct number in the cost matrix, and return the cost.
  
  return cost[i][j] = calculateCost(i,j);
  
return 1;
}

int main() {
   int minRow = 0;
    // Call the calculateCost function once for each square in the rightmost column of the grid.
    // Check which one has the lowest cost and store the row number in minRow.
    for (int r=1; r<rows; r++){
        if (calculateCost(r, cols-1) < calculateCost(r-1, cols-1)){
            minRow = r;
        }
        else minRow = r-1;
    }

   cout << "The length of the shortest path is " << calculateCost(minRow, cols-1);
   cout << ".\nThe rows of the path from left to right are " << path[minRow][cols-1] << ".";

   return 0;
}
