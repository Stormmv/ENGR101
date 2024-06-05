/*
 * The code below is meant to detect whether the Red Ruby
 * is present. The starategy implemented by the code is not very effective. 
 * Study the code so that you understand what the strategy is and how 
 * it is implemented. Then design and implement a better startegy.
 * 
 * */



#include <iostream>
#include <vector>
#include <algorithm>
#include "E101.h"

using namespace std;

int main() {
  int err = init(0);
  cout<<"Error: "<<err<<endl;
  open_screen_stream(); // allows camera
  int setup = 0;
  // make 1000 runs  
  vector<int> rowVector;
  vector<int> colVector;
  int centerRow = 0;
  int centerCol = 0;
  if (setup == 0){
	  take_picture();
	  update_screen();
	  for (int row = 0 ; row < 240 ; row++){
		  for (int col = 0; col < 320; col++){
			  int red = (int)get_pixel(row, col, 0);
			  int green = (int)get_pixel(row, col, 1);
			  int blue = (int)get_pixel(row, col, 2);
			  if ((green * 2) <= red && (blue * 2) <= red){
				  rowVector.push_back(row);
				  colVector.push_back(col);
			  }
		  }
      }
	  int maxRow = 0;
	  int minRow = 99999999;
	  int maxCol = 0;
	  int minCol = 99999999;
	  for(int rowmax: rowVector){
		  if(rowmax > maxRow){
			  maxRow = rowmax;
		  }
	  }
	  for(int rowmin: rowVector){
		  if(rowmin < minRow){
			  minRow = rowmin;
		  }
	  }
	  for(int colmax: colVector){
		  if(colmax > maxCol){
			  maxCol = colmax;
		  }
	  }
	  for(int colmin: colVector){
		  if(colmin < minCol){
			  minCol = colmin;
		  }
	  }
	  cout<<"max row: "<<maxRow<<endl;
	  cout<<"min row: "<<minRow<<endl;
	  cout<<"max col: "<<maxCol<<endl;
	  cout<<"min col: "<<minCol<<endl;
	  centerRow = ((maxRow + minRow)/2);
	  centerCol = ((maxCol + minCol)/2);
	  setup = 1;
  }
  //get top left (lowest row, lowest col)
  for (int countrun = 0; countrun < 1000; countrun++) {
	take_picture();
	update_screen();
	int centerR = 0;
	int centerG = 0;
	int centerB = 0;
	
	centerR = (int)get_pixel(centerRow, centerCol, 0);
	centerG = (int)get_pixel(centerRow, centerCol, 1);
	centerB = (int)get_pixel(centerRow, centerCol, 2);
	
	if((centerG * 2) <= centerR && (centerB * 2) <= centerR){
		cout<<"RUBY NOT STOLEN"<<endl;
	}
	else{
		cout<<"RUBY STOLEN"<<endl;
	}
	sleep1(10);
  }  
  close_screen_stream();
  return 0;
}

