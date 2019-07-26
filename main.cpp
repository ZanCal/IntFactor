#include <iostream>
#include <array>
/*
  so the idea is to find all factor pairs of an int
  with as few flops as possible. The "twist" is that
  any flop must result in an int, so no decimals.
  the decimal that would be there can be rounded up
  or down, but that's it. 
*/

/*
  Ideally, I'd like to have a set of graphs where
  on one axis it shows the int that the factor pairs
  of are trying to be found, and on the other axis 
  the total amount of flops. Then each induvidual graph 
  will be using a different techninque or techninques
*/

//TO-DO list
/*
  Graphing stuff
  more algorithms 
    iterative reset
    hard coded (1, n) factor pair
    j always <= i
    i below sqrt(n) and j above sqrt(n) 
  overlapping algorithms

*/


using namespace std;

int baseline(int n) {
  /*since we only care about the number of flops, and not
  the actual factor pairs, we only return the number of 
  flops. The factor pairs are printed out to make sure 
  that what the algorith thinks are the factor pairs are 
  actually the factor pairs
  */
  int flops = 0;
  for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j ++){
      if( i * j == n){
        cout << "(" <<  i << "," << j << ") is a factor pair" << endl;
      }
      flops += 1;
    }
  }
  return flops; 
}






int main() {
 int defInts[6] = {6, 8, 10, 16, 18, 20};
 for(int i = 0; i < 6; i++ ){
   int temp = baseline(defInts[i]);
   cout << temp << endl;
 }
    
}

