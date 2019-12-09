#ifndef OCCUPANCY_GRID_H_
#define OCCUPANCY_GRID_H_
#include <iostream>
#include <vector>
#include "Cell.h"

class OccupancyGrid{
public:
OccupancyGrid();
OccupancyGrid(const int H, const int W);
void printGrid();
void printCell(int x, int y);
void setCellTraced(int x, int y);
bool isCellTraced(int x, int y);
void setProb(int x, int y, double probability);
bool isOccupied(int x, int y);
private:
int height;
int width;
std::vector<std::vector<Cell> > grid;
};

#endif
