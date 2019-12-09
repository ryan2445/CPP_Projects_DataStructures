#include "RayTrace.h"

void RayTrace::riseRun(int theta, double &rise, double &run){
	switch(theta){
		case 0:
			rise=0;
			run=1;
			return;
		case 45:
			rise=1;
			run=1;
			return;
		case 90:
			rise=1;
			run=0;
			return;
		case 135:
			rise=1;
			run=-1;
			return;
		case 180:
			rise=0;
			run=-1;
			return;
		case 225:
			rise=-1;
			run=-1;
			return;
		case 270:
			rise=-1;
			run=0;
			return;
		case 315:
			rise=-1;
			run=1;
			return;
	}
	rise=std::tan(toRadians(theta));
	run=1;
	if(theta>90 && theta<270){
		rise=-rise;
		run=-run;
    if ((std::abs(rise) > std::abs(run))){
       double oldRise = rise;
       if (rise >= 0){
          rise = 1;
          run = (run * rise) / oldRise;
       }else{
        	rise = -1;
          run = (run * rise) / oldRise;
        }
     }
   }
}

double RayTrace::toRadians(double degrees){
	return degrees*(M_PI/180.0);
}

std::vector<Cell> RayTrace::trace(double theta, int fromX, int fromY, std::string dir){
	std::vector<Cell> v1;
	int currCell=1;
	int x=0;
	int y=0;
	double rise=0.0;
	double run=0.0;
	if(dir=="W"){
		theta+=90;
	}
	else if(dir=="S"){
		theta+=180;
	}
	else if(dir=="E"){
		theta+=270;
	}
	riseRun(theta, rise, run);
	for(int i=0;i<50;i++){
		x=run*currCell+fromX;
		y=rise*currCell+fromY;
		Cell c1(x, y);
		v1.push_back(c1);
		currCell++;
	}
	return v1;
}
















