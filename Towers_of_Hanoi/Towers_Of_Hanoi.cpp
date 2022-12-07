#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> t[3];
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;
   
   // close is the number of spots to move to the right to find the "closest" tower.
   // If n is odd, close = 1 and far = 2.  If n is even, the reverse.
   int close, far;
   
   if (n%2==0){ //if n is even 
      close = 2, far = 1;
   }
   else{ //if n is odd
      close = 1, far = 2;
   }
   
   int from = 0, to = close, candidate = 1, move = 0; //"move" counts the move#
   
   // Initialize the towers
   for(int i = n + 1; i >= 1; --i){ //if n=3 this stacks 4,3,2,1 so 1 is closest to the "top" of the tower and 4 means empty  
      t[0].push_back(i);
   }
   t[1].push_back(n+1); //if n=3, initialize empty tower to 4
   t[2].push_back(n+1); //if n=3, initialize empty tower to 4
   
            // //DEBUGGING TESTS
            // cout << "Value of close is: " << close << " \nValue of far is: " << far << endl;
            // cout << "size of t[0] is: " << t[0].size() << endl;
            // cout << "size of t[1] is: " << t[1].size() << endl;
            // cout << "size of t[2] is: " << t[2].size() << endl;
            // cout << "the values in t[0] are: ";
            // for (int i = 0; i < t[0].size(); i++){
            //    cout << t[0][i] << ",  ";
            // }
            // cout << endl;
            // cout << "the values in t[1] are: ";
            // for (int i = 0; i < t[1].size(); i++){
            //    cout << t[1][i] << ",  ";
            // }
            // cout << endl;
            
            // cout << "the values in t[2] are: ";
            // for (int i = 0; i < t[2].size(); i++){
            //    cout << t[2][i] << ",  ";
            // }
            // cout << endl;
            // cout << endl;
            // //END DEBUGGING TESTS
      
   
   while (t[1].size() < n+1) { // while t[1] (ie tower B) does not contain all of the rings
      cout << "Move #" << ++move << ": Transfer ring " << candidate << 
            " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
            
      cout << endl;
      
      /* Move the ring from "from" to "to" (first copy it, then delete it from "from")
      1. push the top of the "from" tower to the "to" tower*/
      t[to].push_back(t[from].back()); // push_back takes in the value at the top of the "from" stack 
                                       // and puts it at the top of the "to" stack 
         
      //2. remove (pop) the ring from the "from" tower 
      t[from].pop_back(); //removes the ring from the tower
      
      // from = the tower with the smallest ring that has NOT just been moved: (to+1)%3 or (to+2)%3
      // we want to get the next "from" tower. It's not the most recent "to" tower
      if (t[(to+1)%3].back() < t[(to+2)%3].back())// is saying "if the value in tower C is less than the value in tower A"
         //if to is 1 then (to+1)%3 is (1+1)%3 which = 2 or Tower C
         //if to is 2 then (to+2)%3 is (2+1)%3 which = 0 or Tower A
         from = (to+1)%3;
      else
         from = (to+2)%3;

      // candidate = the ring on top of the from tower
      candidate = t[from].back();
      
               // //DEBUGGING
               // cout << "The next from tower is: " << from << endl;
               // cout << "The next candidate is: " << candidate << endl;
               // //END OF DEBUGGING
         
      // to = the closest tower on which the candidate can be placed: (from+close)%3 or (from+far)%3
      if (t[from].back() < t[(from+close)%3].back())
         to = (from+close)%3;
      else
         to = (from+far)%3;

               // //DEBUGGING
               // // The next tower is now being selescted correctly: 
               // cout << "The next to tower is: " << to << endl;
               // cout << "Value of close is: " << close << " \nValue of far is: " << far << endl;
               // cout << "size of t[0] is: " << t[0].size() << endl;
               // cout << "size of t[1] is: " << t[1].size() << endl;
               // cout << "size of t[2] is: " << t[2].size() << endl;
               
               // cout << "the values in t[0] are: ";
               // for (int i = 0; i < t[0].size(); i++){
               //    cout << t[0][i] << ",  ";
               // }
               // cout << endl;
               
               // cout << "the values in t[1] are: ";
               // for (int i = 0; i < t[1].size(); i++){
               //    cout << t[1][i] << ",  ";
               // }
               // cout << endl;
               
               // cout << "the values in t[2] are: ";
               // for (int i = 0; i < t[2].size(); i++){
               //    cout << t[2][i] << ",  ";
               // }
               
               // cout << endl;
               // cout << endl;
               // //END DEBUGGING TESTS
      
      //get next candidate
      // candidate = the ring on top of the from tower
      candidate = t[from].back();

   }//end of While loop
   
   return 0;

}//end of Main
