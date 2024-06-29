// уравнения кривых - 10
// f1 = 1 + 4/(x^2 + 1)
// f2 = x^3
// f3 = 2^-x
// метод деленения отрезка пополам
// формула прямоугольников


#include <stdio.h>
#include <time.h>   // работа с измерением времени
#include <stdlib.h> // работа с динамической память, rand()
#include <math.h>
#include <stdbool.h>

//
typedef float r_type;

// epsilons
const r_type eps = 0.001;
const r_type eps1 = 0.0001;
const r_type eps2 = 0.0001;

// function f1
r_type f1(r_type x)
{
    return (1 + 4/(pow(x, 2) + 1));
}

//function f2
r_type f2(r_type x)
{
    return (pow(x, 3));
}

//fnction f3
r_type f3(r_type x)
{
    return (pow(2, -1*x));
}
//function f4 - const
r_type f4 (r_type x)
{
    return 0;
}

//function f5 - sinx
r_type f5(r_type x)
{
    return sinf(x);
}
//function f6
r_type f6(r_type x)
{
    return (pow(x, 2));
}