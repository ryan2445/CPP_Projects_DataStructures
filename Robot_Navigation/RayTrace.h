#ifndef RAY_TRACE_H_
#define RAY_TRACE_H_
#include <vector>
#include <utility>
#include <cmath>
#include <math.h>
#include "Cell.h"
#include "OccupancyGrid.h"
class RayTrace{
private:
public:
void riseRun(int theta, double &rise, double &run);
double toRadians(double degrees);
std::vector<Cell> trace(double theta, int fromX, int fromY, std::string dir);
};

#endif
