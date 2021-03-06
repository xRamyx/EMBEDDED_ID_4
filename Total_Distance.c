#include "STD_TYPES.h"
#include "Math.h"
#define PI 3.14159265359

f32 calc_dist(f32 yo,f32 xo,f32 y1,f32 x1){
	
	f32 dy = (y1-yo)* PI/180.0; //Distance between latitudes and longitudes
	f32 dx = (x1-xo)* PI/180.0;
	
	//Convert to radians
	yo = (yo)* PI/180.0;
	y1 = (y1)* PI/180.0;
	
	//Calculate using haversine method (A method for calculating the distance between two points on Earth's surface)
	f32 a = pow(sin(dy / 2), 2) + pow(sin(dx / 2), 2) * cos(yo) * cos(y1);
	f32 rad = 6371;
	f32 c = 2 * asin(sqrt(a));
	return rad * c * 1000; // Converting KM to M by multiplying by 1000
}

f32 Total_Distance (f32* yo, f32* xo, f32 y1, f32 x1) // previous and current latitude and longitude that will be obtained from the gps module
{
	f32 Total=0;
	if(*xo!=0 && *yo !=0){ // check if this is my first point we set it as the starting point only and don't calculate distance
		Total = calc_dist(*yo,*xo,y1,x1);
	}
	*yo=y1; //dereferencing
	*xo=x1;
	return Total;
}
