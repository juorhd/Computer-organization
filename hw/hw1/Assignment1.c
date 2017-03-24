// Assignment 1, linear interpolation
// Given a set of points, construct the equation for a line given any
// two adjacent points.  Use the slope-intercept form y = mx + b
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct point
{
    double x;
    double y;
};

// Allocate the right amount of memory to store "count" number of "point"s
// We assume malloc() never fails :)
void allocate_points(struct point ** ptr, int count)
{
	*ptr = (struct point*) malloc(count * sizeof(struct point));
}

// Ask for the proper number of X and Y coordinates
// The X coordinates should strictly increase and will never be negative
// Y values can vary
// Return -1 (immediately) if the X coordinates do not strictly increase
// Return 0 if no problems were encountered in this function
int collect_points(struct point * points, int count)
{
	int i;
	for (i=0; i<count; ++i){
		printf("Please enter X[%d]:\n", i);
		scanf("%lf", &points[i].x);
		if (i!=0 && points[i].x <= points[i-1].x)
			return -1;
		printf("Please enter Y[%d]:\n", i);
		scanf("%lf", &points[i].y);
	}
    return 0;
}

// Simply print out the list of coordinates stored in "points"
// Use a width of 6 and a precision of 3 so things line up nice
// This should help with debugging
void print_points(struct point * points, int count)
{
	int i;
	for (i=0; i<count; ++i){
		printf("Point[%d] is ( %.3f,  %.3f)\n", i, points[i].x, points[i].y);
	}
}

// Find the slope between two points
// m = (y_2 - y_1) / (x_2 - x_1)
double find_slope(struct point p1, struct point p2)
{
    return (p2.y-p1.y)/(p2.x-p1.x);
}

// Find intercept given the slope and a point it passes through
double find_intercept(double slope, struct point p, double x)
{
    return p.y+slope*(x-p.x);
}

// This function should find the Y value of the curve given an X coordinate
// If it's not within our set of points, it cannot be interpolated
// Return DBL_MAX
// Otherwise, return the point we calculated
double y_val_at(struct point * points, int count, double x)
{
    int i;
    for (i=0; i<count-1; ++i){
        if ( x<points[i].x){
            return DBL_MAX;
        }
    	if( x==points[i].x ){
    		return points[i].y;
    	}
    	else if ( x<points[i+1].x ){
    		return find_intercept(find_slope(points[i], points[i+1]),points[i], x);
        }
    }
    if( x==points[count-1].x ) 
        return points[count-1].y;
    return DBL_MAX;
}

// DO NOT MODIFY THIS FUNCTION
// This assignment must be completed using the main() function AS-IS
int main()
{
    int ret;
    struct point *points;
    int num_points = 0;
    
    printf("How many data points would you like to enter? (2 or more):\n");
    scanf("%d", &num_points);
    if (num_points <= 1) {
        return 0;
    }
    
    allocate_points(&points, num_points);
    
    printf("Please enter non-negative X values.\n");
    ret = collect_points(points, num_points);
    if (ret == -1) {
        printf("Please enter points in order of ascending X values.\n");
        return -1;
    }
    
    print_points(points, num_points);
    
    while (1) {
        double x, y;
        printf("Please enter an X coordinate (-1 to exit): \n");
        scanf("%lf", &x);
        if (x == -1) {
            break;
        }
        
        y = y_val_at(points, num_points, x);
        if (y == DBL_MAX) {
            printf("%6.3lf cannot be interpolated\n", x);
        }
        else {
            printf("%6.3lf maps to (%6.3lf, %6.3lf)\n", x, x, y);
        }
    }
    
    return 0;
}
