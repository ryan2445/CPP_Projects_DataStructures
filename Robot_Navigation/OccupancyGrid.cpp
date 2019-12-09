#include "OccupancyGrid.h"

OccupancyGrid::OccupancyGrid(){
	width=1000;
	height=1000;
}

OccupancyGrid::OccupancyGrid(const int H, const int W){
	height=H;
	width=W;
	for(int i=0;i<height;i++){
		grid.push_back(std::vector<Cell>());
		for(int j=0;j<width;j++){
			Cell cell1(i, j);
			cell1.setTraced(false);
			cell1.setOccupied(false);
			if((i>=250 && i<=500) && (j>=250 && j<=500)){
				cell1.setOccupied(true);
			}
			grid[i].push_back(cell1);
		}
	}
}

void OccupancyGrid::printGrid(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout << "(" << grid[i][j].getX() << ", " << grid[i][j].getY() << ") ";
		}
	}
}

void OccupancyGrid::printCell(int x, int y){
	cout << "(" << grid[x][y].getX() << ", " << grid[x][y].getY() << ") ";
}

void OccupancyGrid::setCellTraced(int x, int y){
	grid[x][y].setTraced(true);
}

bool OccupancyGrid::isCellTraced(int x, int y){
	bool temp=grid[x][y].getTraced();
	return temp;
}


void OccupancyGrid::setProb(int x, int y, double probability){
	grid[x][y].setProbability(probability);
}

bool OccupancyGrid::isOccupied(int x, int y){
	return grid[x][y].getOcc();
}














