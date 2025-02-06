#include<iostream>
#include<cmath>

float ParallelogramSquare(float x[3], float y[3])
{
    return sqrt(pow(x[1]*y[2] - x[2]*y[1], 2) + \
                pow(x[2]*y[0] - x[0]*y[2], 2) + \
                pow(x[0]*y[1] - x[1]*y[0], 2));
}


class Parallelipiped
{
private:

    float start_point[3]; 
    float vector_1[3];
    float vector_2[3];
    float vector_3[3];


public:

    Parallelipiped(float sp[3], float v1[3], float v2[3], float v3[3])
    {
        for(int i =0; i < 3; i++)
        {
            start_point[i] = sp[i];
            vector_1[i] = v1[i];
            vector_2[i] = v2[i];
            vector_3[i] = v3[i];
        }
    }

    void SetStartPoint(float sp[3])
    {
        for(int i =0; i < 3; i++)
        {
            start_point[i] = sp[i];
        }
    }

    void SetBaseVectors(float sp[3], float v1[3], float v2[3], float v3[3])
    {
        for(int i =0; i < 3; i++)
        {
            vector_1[i] = v1[i];
            vector_2[i] = v2[i];
            vector_3[i] = v3[i];
        }
    }

    float GetSquare()
    {
        return (ParallelogramSquare(vector_1, vector_2) + \
                ParallelogramSquare(vector_1, vector_2) + \
                ParallelogramSquare(vector_2, vector_3)) * 2;
    }

    float GetVolume()
    {
        return abs(vector_1[0] * (vector_2[1]*vector_3[2] - vector_2[2]*vector_3[1]) -\
                   vector_1[1] * (vector_2[0]*vector_3[2] - vector_2[2]*vector_3[0]) +\
                   vector_1[2] * (vector_2[0]*vector_3[1] - vector_2[1]*vector_3[0]));
    }

    float GetDiagonalLength()
    {
        return sqrt(pow(vector_1[0] + vector_2[0] + vector_3[0], 2) + \
                    pow(vector_1[1] + vector_2[1] + vector_3[1], 2) + \
                    pow(vector_1[2] + vector_2[2] + vector_3[2], 2));
    }

};


int main()
{
    float sp[3] = {0, 0, 0}, v1[3] = {1, 2, 3}, v2[3] = {2, 3, 2}, v3[3] = {4, 5, 6};
    Parallelipiped p1(sp, v1, v2, v3);
    std::cout << "Square: " << p1.GetSquare() << std::endl;
    std::cout << "Volume: " << p1.GetVolume() << std::endl;
    std::cout << "Diagonal length: " << p1.GetDiagonalLength() << std::endl;

    return 0;
}