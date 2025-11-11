#include "module/getCoord.h"

int getCoord(float recSize, int n, float x1)
{
    int start = 0, finish = n - 1;
    int result = finish / 2;
    if(x1 < 0 or x1 >= recSize * n)
    {
        return 0;
    }
    while(x1 < result * recSize or x1 >= (result + 1) * recSize)
    {
        if(finish * recSize <= x1 and (finish + 1) * recSize > x1)
        {
            result = finish;
            break;
        }
        if(start * recSize <= x1 and (start + 1) * recSize > x1)
        {
            result = start;
            break;
        }

        if(x1 < result * recSize)
        {
            finish = result;           
        }
        else
        {
            start = result;            
        }
        result = (start + finish) / 2;
    }
    return result;
}