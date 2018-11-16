#include "bezier_curve.h"


BezierCurve::BezierCurve(void)
{
}


BezierCurve::~BezierCurve(void)
{
}

		// linear interpolation
		float BezierCurve::interpolate(float n1, float n2, float prec)
        {
            return n1 + ((n2-n1) * prec);
        }
 
         
        // factorial
        double BezierCurve:: factorial(double num)
        {
            if(num <= 1)
                return 1;
            double fac = 1;
            for(double i = 1; i <= num; i++)
                fac *= i;
            return fac;
        }
 
        // utility function
        double BezierCurve:: choose(double a, double b )
        {
            return BezierCurve::factorial(a) / (BezierCurve::factorial(b ) * BezierCurve::factorial(a - b ));
        }
 
        // Bezier
        // returns the point at t from the Bezier curve that approximates the given control points
        // t is a curve parameter between 0 (curve starting point) and 1 (curve end point)
        // the more samples in t=[0,1] are taken, the more smoothed the curve resulting from putting
        // together all the calculated samples
        cv::Point2f BezierCurve::bezier(std::vector<cv::Point2f>& pts, double t)
        {
            cv::Point2f p;
            int p0 = 0;
            int p1 = int(pts.size());
            std::size_t len = p1 - p0;
            for(std::size_t i = 0; i < len; i++)
                p += pts[i+p0] * choose(len - 1, static_cast<double>(i)) * pow(1 - t, len - 1 - i) * pow(t, i);
            return p;
        }
		
		std::vector<cv::Point2f> BezierCurve::getBezierCurve(std::vector<cv::Point2f>& pts, int samples){
			std::vector<cv::Point2f> curve;

			for(double i = 0; i < samples; i++){
				cv::Point2f point = bezier(pts, i/samples);
				curve.push_back(point);
				
			}
			return curve;
		
		}
