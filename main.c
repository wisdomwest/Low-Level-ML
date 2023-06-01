#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define train_count (sizeof(train)/sizeof(train[0]))
float train[][2]  = {
    //{input, expected}
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};

//training model y = x*w;
float rand_float(void)
{
    return (float) rand() / (float) RAND_MAX;
}

float cost(float w)
{
    size_t i;
    float result = 0.0f;
    for (i = 0; i < train_count; i++)
    {
        float x = train[i][0];
        float y = x*w;
        float d = y - train[i][1];
        result += d*d;
    }

    result /= train_count;
    return result;
}

int main()
{
    size_t i;

    srand(69);
    //y = x*w
    float w = rand_float()*10.0f;

    float eps = 1e-3;
    //learning rate 
    float rate = 1e-3;

    //printf("%f\n", cost(w));
    //printf("%f\n", cost(w - eps));
    //printf("%f\n", cost(w -eps*2));
    //using derivatives to automate this

    printf("%f\n", cost(w));
    for (i = 0; i < 500; i++)
    {
        float dcost = (cost(w + eps) - cost(w)) / eps;
        //finite difference(use when learning) good when nature of function is unkown
        w -= rate*dcost;
        printf("%f\n", cost(w));
    }

    printf("%f\n", w);
    return 0;    
}  