#include "geom.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <stack>

using namespace std; 

/* **************************************** */
/* returns the signed area of triangle abc. The area is positive if c
   is to the left of ab, and negative if c is to the right of ab
 */
int signed_area2D(point2d a, point2d b, point2d c) {
  return 1; 
}



/* **************************************** */
/* return 1 if p,q,r collinear, and 0 otherwise */
int collinear(point2d p, point2d q, point2d r) {
  double a_x = p.x - q.x;
  double a_y = p.y - q.y;
  double b_x = p.x - r.x;
  double b_y = p.y - r.y;
  return (a_x*b_y - a_y*b_x) == 0; 
}



/* **************************************** */
/* return 1 if c is  strictly left of ab; 0 otherwise */
int left_strictly(point2d a, point2d b, point2d c) {
  double a_x = a.x - b.x;
  double a_y = a.y - b.y;
  double b_x = a.x - c.x;
  double b_y = a.y - c.y;
  return (a_x*b_y - a_y*b_x) > 0; 
}


/* return 1 if c is left of ab or on ab; 0 otherwise */
int left_on(point2d a, point2d b, point2d c) {
  double a_x = a.x - b.x;
  double a_y = a.y - b.y;
  double b_x = a.x - c.x;
  double b_y = a.y - c.y;
  return (a_x*b_y - a_y*b_x) >= 0; 
}



// compute the convex hull of pts, and store the points on the hull in hull
void graham_scan(vector<point2d>& pts, vector<point2d>& hull ) {

  printf("hull2d (graham scan): start\n"); 
  hull.clear(); //should be empty, but clear it to be safe


  // find p
  point2d p = pts[0];
  for (int i = 1; i < pts.size(); i++)
  {
    if (pts[i].y < p.y) p = pts[i];
  }
  printf("Lowest Point: (%d, %d)\n", p.x, p.y);

  // Calculating angle while sorting, because I think the time it takes to 
  // initialize a data structure that both a) points to my original point and 
  // b) sortable probably would be more time consuming.
  sort(pts.begin(), pts.end(),[p](const point2d& a_pt, const point2d& other_pt){
    return atan2(a_pt.y - p.y, a_pt.x-p.x) < atan2(other_pt.y - p.y, other_pt.x-p.x);
  });

  // Super gross hack: in C++, atan2(0,0) returns 0, so my p would be at first. 

  hull.push_back(p);
  hull.push_back(pts[1]);
  hull.push_back(pts[2]);

  for (int i = 3; i < pts.size(); i++)
  {
    while (!left_strictly(hull[hull.size() - 2], hull.back(), pts[i]))
    {
      hull.pop_back();
    }
    hull.push_back(pts[i]);
  }
  for (size_t i = 0; i < hull.size(); i++)
  {
    printf("Point: (%d, %d)\n", hull[i].x, hull[i].y);
  }
  
  printf("hull2d (graham scan): end\n"); 
  return; 
}

