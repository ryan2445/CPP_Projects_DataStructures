#ifndef CELL_H_
#define CELL_H_

class Cell{
public:
Cell();
Cell(int x_cor, int y_cor);
Cell(int x_cor, int y_cor, double prob_param);
Cell(int x_cor, int y_cor, double prob, bool occ_param);
void setOccupied(bool occ_param);
void setTraced(bool traced_param);
int getX();
int getY();
bool getTraced();
void setProbability(double probability);
bool getOcc();
private:
int x;
int y;
double prob;
bool occ;
bool traced;
};

#endif
