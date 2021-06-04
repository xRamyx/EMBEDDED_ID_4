#include "STD_TYPES.h"
#include "Math.h"
#define PI 3.14159265359

f32 calc_dist(f32 xo,f32 yo,f32 x1,f32 y1){
	f32 dx;
	f32 dy;
	dx= x1-xo;
	dy= y1-yo;
	return sqrt(pow(dx,2)+pow(dy,2));
}

f32 Total_Distance (f32 xo ,f32 yo ,f32 x1, f32 y1) // previous and current latitude and longitude that will be obtained from the gps module
{
	f32 Total;
	if(xo!=0 && yo !=0) // check if this is my first starting point or not
		{
		Total+= calc_dist(xo,yo,x1,y1);
	}
	xo=x1;
	yo=y1;
	return Total;
}