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

// consts for number of iterations
int st1r = 0;
int st2r = 0;
int st3r = 0;
int st0r = 0;

int st1i = 0;
int st2i = 0;
int st3i = 0;
int st4i = 0;
int st0i = 0;

/*
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
*/

extern float _f1(float x);
extern float _f2(float x);
extern float _f3(float x);

// function f1
r_type f1(r_type x)
{
    return _f1(x);
}
//function f2
r_type f2(r_type x)
{
    return _f2(x);
}

//function f3
r_type f3(r_type x)
{
    return _f3(x);
}

r_type root (r_type (*f)(r_type), r_type (*g)(r_type), r_type a, r_type b, r_type eps)
{
    if ((b - a) < eps) 
    {
        return (a+b)/2;
    }
    r_type c = (a + b) / 2;
    r_type q = f(a) - g(a);
    r_type w = f(b) - g(b);
    r_type r = f(c) - g(c);
    st0r+=1;
    if (q * r  < 0) 
    {
        return root (f, g, a, c, eps);
        
    }
    return root(f, g, c, b, eps);
}   
 

r_type integral(r_type (*f)(r_type), r_type a, r_type b, r_type eps)
{
    r_type int_left = 0;
    r_type int_right = 2 * eps;
    unsigned steps = 100;
    r_type length = b-a;
    st0i+=1;
    while (fabs(int_right - int_left) > eps){
        int_left = 0;
        int_right = 0;
        r_type dx = length/steps;
        for(r_type cursor = a; cursor < b; cursor=cursor+dx){
            int_left = int_left + (f(cursor)*dx);
            int_right = int_right + (f(cursor+dx)*dx);
        }
        steps*=2;
    }
    return (int_left+int_right)/2;
}

r_type square(r_type (*f)(r_type), r_type (*g)(r_type), r_type (*w)(r_type), r_type a, r_type b)
{
    st0r = 0;
    r_type root_1 = root(f, g, a, b, eps1);
    st1r = st0r;
    st0r = 0;
    r_type root_2 = root(f, w, a, b, eps1);
    st2r = st0r;
    st0r = 0;
    r_type root_3 = root(w, g, a, b, eps1);
    st3r = st0r;
    st0i = 0;
    r_type s_f_1 = integral(f, root_2, root_3, eps2);
    st1i = 0;
    st0i = 0;
    r_type s_w_1 = integral(w, root_2, root_3, eps2);
    st2i = 0;
    st0i = 0;
    r_type s_1 = s_f_1-s_w_1;
    r_type s_f_2 = integral(f, root_3, root_1, eps2);
    st3i = 0;
    st0i = 0;
    r_type s_g_1 = integral(g, root_3, root_1, eps2);
    st4i = 0;
    st0i = 0;
    r_type s_2 = s_f_2-s_g_1;
    return (s_1 + s_2);

}

int test(r_type a, r_type b, r_type eps)
{

    return fabs (a-b) < eps;
}

int main (void)
{
    //printf("choose scenario and type number:\n1 - count integral\n2 - test root\n3 - test integral\n");
    int h = 1;
    //scanf("%d",&h);
    if (h == 1)
    {
        
        printf("\nSize of square: %f\n\n", square(f1, f2, f3, -2, 2));
        printf("number of  iterations f1 and f2 in root: %d\n", st1r);
        printf("number of  iterations f2 and f3 in root: %d\n", st2r);
        printf("number of  iterations f3 and f1 in root: %d\n\n", st3r);
        printf("abscissas of intersection f1 and f2: %f\n", root(f1, f2, -2, 2, eps1));
        printf("abscissas of intersection f1 and f3: %f\n", root(f1, f3, -2, 2, eps1));
        printf("abscissas of intersection f2 and f3: %f\n", root(f2, f3, -2, 2, eps1)); 
        
        //printf("number of  iterations integral s1: %f\n", st1i);
        //printf("number of  iterations integral s2: %f\n", st2i);
        //printf("number of  iterations integral s3: %f\n", st3i);
        //printf("number of  iterations integral s4: %f\n", st4i);
    }
    /*if (h == 2)
    {   
        
        1 - f1{1 + 4/(x^2 + 1)}
        2 - f{x^3}
        3 - f3{2^-x}
        4 - f4{const}
        5 - f5{sinx}
        
        //choose functions, chooose interval, choose eps
        r_type sd = root(f5, f4, 2, 4, 0.001);
        printf("Testing function root\n");
        //write right answer, choose eps
        if (test(sd, 3.1415, 0.001 ) == 1 )
        {printf(" - True (Answer %f)\n", sd );}
        else
        {printf(" - False (Answer %f)\n", sd);};
        
    }
    if (h == 3)
    {
         //choose function, chooose interval, choose eps
        r_type sd = integral(f5, 0, 3.14159265, 0.001);
        printf("Testing function integral\n");
        
        if (test(sd, 2, 0.001 ) == 1 )
        {printf(" - True (Answer %f)\n", sd );}
        else
        {printf(" - False (Answer %f)\n", sd);};

    }
    //printf("%f", integral(f6, 0, 3, 0.001));
    */
    return 0;
}
