#include "Cell.h"

Cell::Cell(int x_cor, int y_cor){
	x=x_cor;
	y=y_cor;
	traced=false;
}

Cell::Cell(int x_cor, int y_cor, double prob_param){
	x=x_cor;
	y=y_cor;
	prob=prob_param;
	traced=false;
}

Cell::Cell(int x_cor, int y_cor, double prob_param, bool occ_param){
	x=x_cor;
	y=y_cor;
	prob=prob_param;
	occ=occ_param;
	traced=false;
}

void Cell::setOccupied(bool occ_param){
	occ=occ_param;
}

int Cell::getY(){
	return y;
}

int Cell::getX(){
	return x;
}

void Cell::setTraced(bool traced_param){
	traced=traced_param;
}

bool Cell::getTraced(){
	return traced;
}

void Cell::setProbability(double probability){
	prob=probability;
}

bool Cell::getOcc(){
	return occ;
}
















