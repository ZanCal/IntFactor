#include <iostream>
#include <array>
#include <cmath>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;
/*
  so the idea is to find all factor pairs of an int
  with as few flops as possible. The "twist" is that
  any flop must result in an int, so no decimals.
  the decimal that would be there can be rounded up
  or down, but that's it. 
  ceil() for ceiling 
  floor() for floor
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
    ignore (j,i) when (i,j) already discovered 
      this is sometimes done automatically with certian algorithms

    (i,2j) -> (2i,j)

  overlapping algorithms
    identifiy which algorithms can be used together, and which ones conflict with each other
      spreadsheet?

*/

using namespace std;


//overlapping algorithms
int hsqrtiter(int n){
  int flops = 0;
  //cout << "(1," << n << ") is a factor pair of " << n << "(hardandsqrtiter)" << endl;
   for(int i = 2; i <= sqrt(n); i ++){
     for(int j = sqrt(n)+1; j <= n; j ++){
      if( i * j == n){
         //cout << "(" <<  i << "," << j << ") is a factor pair of " << n << " (hardandsqrtiters)" << endl;
        }
       flops += 1; 
     }
   }
  return flops;
}

int iRhard1n(int n){
  int flops = 0;
  //cout << "(1," << n << ") is a factor pair of " << n << "(iRhard1n)" << endl;
  for(int i = 2; i <= n; i ++){
    for(int j = 2; j <= n; j ++){
      flops += 1;
      if( i * j == n){
        //cout << "(" <<  i << "," << j << ") is a factor pair of " << n << " (iRhard1n)" << endl;
        break;
      }
      
    }
  }
  return flops; 
}

//individual algorithms
int sqrtiters(int n){
  int flops = 0;
  for(int i = 0; i <= sqrt(n) + 1; i ++){
    for(int j = sqrt(n); j <= n; j ++){
     if( i * j == n){
        cout << "(" <<  i << "," << j << ") is a factor pair of " << n << " (sqrtiters)" << endl;
      }
      flops += 1; 
    }
  }
  return flops;
}

int sqrtiters2(int n){
  int flops = 0;
  for(int i = 0; i <= sqrt(n)+1; i ++){
    for(int j = n; j >= sqrt(n); j --){
     if( i * j == n){
        cout << "(" <<  i << "," << j << ") is a factor pair of " << n << " (sqrtiters2)" << endl;
      }
      flops += 1; 
    }
  }
  return flops;
}

int sqrtiters3(int n){
  int flops = 0;
  int i = 1;
  int j = n;
  while(j >= floor(sqrt(n))  && i <= ceil(sqrt(n))){
    flops+=1;
    if(i*j==n){
        //can't find all factor pairs
        //has potential, needs bugfixing
        cout << "(" <<  i << "," << j << ") is a factor pair of " << n << " (sqrtiters3)" << endl;
        i +=1;
    } else if (i*j <n){
      //i think this else if fixed my bug
      //still should test more tho.
      i +=1;
      j +=1;
    }
    j-=1;
  }

  return flops;
}

int hardcode1n(int n){
  int flops = 0;
  //cout << "(1," << n << ") is a factor pair of " << n << " (hardcoded 1n)" << endl;
  for(int i = 2; i < n; i ++){
    for(int j = 2; j < n; j ++){
      if( i * j == n){
        //cout << "(" <<  i << "," << j << ") is a factor pair of " << n << " (hardcoded 1n)" << endl;
      }
      flops += 1;
    }
  }
  return flops; 
}

int jLessI(int n){
  int flops = 0;
  for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= i; j ++){
      if( i * j == n){
        //cout << "(" <<  i << "," << j << ") is a factor pair of " << n << " (jLessI)" << endl;
      }
      flops += 1;
    }
  }
  return flops;
}

int iterReset(int n){
  /*
  when a factor pair of (i,j) is found, there are no other values of j where i results in a factor pair, so there is no point in checking. Therefore when we find a factor pair, we start looking for the next one.
  */
  int flops = 0;
  for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j ++){
      flops += 1;
      if( i * j == n){ 
        //cout << "(" <<  i << "," << j << ") is a factor pair of " << n << " (iterReset)" << endl;
        break;
      }
    }
  }
  return flops; 
}

int oddOnlyOdd(int n){
  /*
    if n is odd, it will only be made up 
    of odd factor pairs. if n is even, it will have at least 1 even factor 
    in all factor pairs 

    have to check if n is even or odd with the limitiation of no decimals 
  */

  bool isOdd;

  //determine if isOdd 

  int flops = 0;
  
  if(isOdd){
    for(int i = 1; i <= n; i ++){
      for(int j = 1; j <= n; j ++){
        if( i * j == n){ 
          cout << "(" <<  i << "," << j << ") is a factor pair of " << n << " (baseline)" << endl;
          }
       flops += 1;
      }
    }
  return flops; 
  } else {


  }
}

//baseline algorithm
int baseline(int n) {
  /*
  go from 1 to n in i 
  go from 1 to n in j 
  if i * j is n, print the factor pair 
  should have n^2 flops.
  This is the bare bones, simplist, most basic way to get factor pairs. It is also the least efficient way to do so without trying to be inefficient, and is the baseline to which all other algorithms are compaired to
  */
  int flops = 0;
  for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j ++){
      if( i * j == n){ 
        cout << "(" <<  i << "," << j << ") is a factor pair of " << n << " (baseline)" << endl;
      }
      flops += 1;
    }
  }
  return flops; 
}



int main() {

 int defInts[6] = {128, 64, 32, 16, 8, 4};
 for(int i = 0; i < 6; i++ ){
  int temp1 = baseline(defInts[i]);
  //int temp2 = sqrtiters(defInts[i]);
  //int temp3 = sqrtiters3(defInts[i]);
  int temp4 = hardcode1n(defInts[i]);
  //int temp5 = hsqrtiter(defInts[i]);
  //int temp6 = iterReset(defInts[i]);
  //int temp7 = iRhard1n(defInts[i]);
  //int temp8 = jLessI(defInts[i]);
  cout << "int: " << defInts[i];
  cout<< " Baseline: " << temp1;
  //cout << " Sqrt Iter 1: " << temp2;
  //cout << " Sqrt Iter 3: " << temp3;
  cout << " Hardcoded (1,n): "<< temp4;
  //cout << " sri and hard: " << temp5;
  //cout << " iterReset: " << temp6;
  //cout << " iRhard1n: " << temp7;
  //cout << " jLessI: " << temp8;
  cout << endl;
 }
 
}

