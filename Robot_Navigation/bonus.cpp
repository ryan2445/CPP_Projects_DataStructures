//RYAN HOFFMAN - AUTONOMOUS ROBOT NAVIGATION - OCCUPANCY GRIDS, RAY TRACING, VECTORS
#include <fstream>
#include <iostream>
using namespace std;
#include "Cell.cpp"
#include "OccupancyGrid.cpp"
#include "RayTrace.cpp"
int main(){
OccupancyGrid o1(1000, 1000);
RayTrace r1;
//ofstream outfile;
//outfile.open("output.pgm");
for(int i=0;i<180;i+=15){
	std::vector<Cell> v1=r1.trace(i,1,1,"N"); //Direction: N for North, S for South, E for East, W for West
		for(int j=0;j<50;j++){
			cout << "(" << v1[j].getX() << ", " << v1[j].getY() << ") ";
			if(v1[j].getX() >= 0 && v1[j].getY() >=0){
				if(o1.isOccupied(v1[j].getX(), v1[j].getY())){
					o1.setProb(v1[j].getX(), v1[j].getY(), 0.9); //measured cells are 0.7, occupied cell are 0.9
				}
				else{
					o1.setProb(v1[j].getX(), v1[j].getY(), 0.7);
				}
			}
		}
	cout << endl << endl;
}
// outfile << 255 << endl;
// for(int i=0;i<50;i++){
// 	for(int j=0;j<50;j++){
// 		if((i>=10 && i<=20) && (j>=10 && j<=20)){
// 			outfile << 0 << " ";
// 		}
// 		else{
// 			outfile << 255 << " ";
// 		}
// 	}
// 	outfile << endl;
// }
return 0;
}
