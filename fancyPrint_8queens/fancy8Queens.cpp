#include <iostream>
#include <cmath>
using namespace std;

bool OKFunction(int q[8], int c);
void fancyPrint(int q[]);

int main() {
    int board[8]={0}, c = 0, counter = 0; 
    
    //put the queen in the upper left square
    board[0] = 0; 

    while(c>=0){// if we backtrack beyond the first col, we are done
        
        // if we have moved beyond the last column
        if(c==8){
            // print the board
            fancyPrint(board);
            
            // BACKTRACK to find more solutions
            c--;
            board[c]++;
        }
        
        // If we have moved beyond the last row 
        else if(board[c]==8){
            // reset queen
            board[c] = 0;
            
            // BACKTRACK
            c--;
            if (c == -1){
                return 0;
            }
            board[c]++; 
        }

        // Check if the placed queen is ok.
        else if(OKFunction(board, c)){
            // move to next column if ok
            c++;
        } 
        
        else{
            // move to next row if not ok
            board[c]++;
        }
    }
    return 0;
}//end of Main()



bool OKFunction(int q[8], int c){
    //row and diagonal tests
    for(int i=0; i<c; i++){
        if((q[i]==q[c]) || ((c-i) == abs(q[c]-q[i]))){
            return false; //false it does not pass test
        }
    }
    return true; //true it passes test
}//end of OKFunction()



void fancyPrint(int q[]){
    static int config = 0;
    config++;
    // printing the configuration iteration
    cout << "Configuration " << config << ":\n";
    
    // printing the values in q
    cout << "q: ";
    for (int i = 0; i < 8; i++) cout << q[i] << " ";
    cout << endl;
    cout << endl;
    
    //Starting fancy print code:
    
    // box is now a datatype which refers to a 2D array, with 5 rows and 7 columns, of characters
    typedef char box[5][7];
    
        /*bb and wb are both of type box; 
            that is, they are both 2D character arrays with 5 rows and 7 columns. 
        board is a 2D array, with 8 rows and 8 columns, of pointers to box types; 
            that is, each cell of board stores the address of some variable of type box*/
    box bb, wb, wq, bq, *board[8][8]; //bb=black box, wb=white box, wq=white queen, bq=black queen
    
    //filling the 5x7 wb and bb boxes with their respective characters needed
        /*Remember that wb and bb are both of type box –
            that is, a 2D character array with 5 rows and 7 columns. 
        We can treat wb and bb as arrays, because they are arrays*/
    for (int i = 0; i < 5; ++i){ //for each row
        for (int j = 0; j < 7; ++j) { //for each column
            wb[i][j] = ' ';
            //bb[i][j] = char(219); //char219 does not work for my ide
            bb[i][j] = '%'; //fills the black boxes with chars 
        }
    }
    
    //filling the 5x7 wq and bq
    for(int row=0; row<5; row++){ //rows
        for(int col=0; col<7; col++){ //cols
            //filling in queeens background 
            if(row==0 || row==4 || col==0 || col==6){
                wq[row][col]='%';  //if white queen, then % (black) background
                bq[row][col]=' ';  //if black queen, then ' ' (white) background
            }
        }
    }
    //hardcoding the rest of the background cells
    wq[1][2] = '%';
    wq[2][2] = '%';
    wq[1][3] = '%';
    wq[1][4] = '%';
    wq[2][4] = '%';
    
    bq[1][2] = ' ';
    bq[2][2] = ' ';
    bq[1][3] = ' ';
    bq[1][4] = ' ';
    bq[2][4] = ' ';
    
    //hardcoding the queen cells
    wq[1][1] = ' ';
    wq[2][1] = ' ';
    wq[3][1] = ' ';
    wq[3][2] = ' ';
    wq[3][3] = ' ';
    wq[3][4] = ' ';
    wq[1][5] = ' ';
    wq[2][5] = ' ';
    wq[3][5] = ' ';
    wq[2][3] = ' ';
    
    bq[1][1] = '%';
    bq[2][1] = '%';
    bq[3][1] = '%';
    bq[3][2] = '%';
    bq[3][3] = '%';
    bq[3][4] = '%';
    bq[1][5] = '%';
    bq[2][5] = '%';
    bq[3][5] = '%';
    bq[2][3] = '%';
    
    //filling the 8x8 board 
        /*Remember that pointers store memory addresses. Each element of board is a
        pointer to a box, and therefore stores the memory address of a box. In the
        loops below, we alternate between white boxes and black boxes.*/
    for (int i = 0; i < 8; ++i){ //for each row
        for (int j = 0; j < 8; ++j){ //for each column
            if ((i+j) % 2 == 0 && q[j]==i){         //if white box & black queen placed
                board[i][j] = &bq;
            }
            else if ((i+j) % 2 == 0){               //if white box & no queen 
                board[i][j] = &wb;
            }
            else if ((i+j) % 2 != 0 && q[j]==i){    //if black box & white queen placed
                board[i][j] = &wq;
            }
            else{                                   //if black box & no queen 
                board[i][j] = &bb; 
            }
        }
    }
 
    //Printing the board
    for (int i = 0; i < 8; ++i){ //for each board row
        for (int k = 0; k < 5; ++k) { //for each box row
            //cout << " " << char(179); //char179 does not work for my ide
            cout << " " << '#'; //makes the left hand side wall of the board 

                for (int j = 0; j < 8; ++j){ //for each board column
                    for (int l = 0; l < 7; ++l){ //for each box column
                        /*Retrieve box pointer from board, then
                        dereference. Dereferencing a box pointer
                        gives us the box being pointed to.*/ 
                        cout << (*board[i][j])[k][l]; // k= box row, l= box col 
                    }
                }
            //cout << char(179) << endl; //char179 does not work for my ide 
            cout << '#' << endl; //makes the righ hand side wall of the board
        }
    }
    
    cout << endl;
    cout << endl;
            
}//end of fancyPrint()
   
