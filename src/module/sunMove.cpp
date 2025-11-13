#include <cmath>
#include <stdio.h>

#include "module/sunMove.h"
#include "module/consts.h"

void sunMove(float rad, float T, data *myData, float x, float y)
{
    float seconds = myData->currentTime / 1000;
    float c = std::fmod(seconds, T);
    myData->sun.xf = sin(2 * PI * (c / T)) * rad + x;
    myData->sun.yf = cos(2 * PI * (c / T)) * rad + y;
    ////printf("xy rad c: %llf %llf %f %f\n", myData->sun.xf, myData->sun.yf, rad, c);
}