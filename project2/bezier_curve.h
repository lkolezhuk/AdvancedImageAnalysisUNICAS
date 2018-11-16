#include "aia\aiaConfig.h"
#include "ucas\ucasConfig.h"

class BezierCurve{
		  BezierCurve(void);
	~BezierCurve(void);
	public:
	static float interpolate(float n1, float n2, float prec);
  
        // factorial
    static double factorial(double num);
    
        // utility function
    static double choose(double a, double b );
       
        // Bezier
        // returns the point at t from the Bezier curve that approximates the given control points
        // t is a curve parameter between 0 (curve starting point) and 1 (curve end point)
        // the more samples in t=[0,1] are taken, the more smoothed the curve resulting from putting
        // together all the calculated samples
    static cv::Point2f bezier(std::vector<cv::Point2f>& pts, double t);

	static std::vector<cv::Point2f> getBezierCurve(std::vector<cv::Point2f>& pts, int samples);
	
};