#ifndef _Image_Management_h
#define _Image_Management_h

#include "aia/aiaConfig.h"
#include "ucas/ucasConfig.h"
#include <opencv2\legacy\legacy.hpp>
#include <math.h>
#include <assert.h>
#include "tinyxml\tinyxml.h"
#include "wall_marker.h"

using namespace std;

class ImageManagement
{
public:
	ImageManagement(void);
	~ImageManagement(void); 
	static vector<cv::Mat> LoadAllInDir(string folder, string ext, bool force_gray);
	static vector<cv::Mat> ApplyMasks(vector<cv::Mat> images, vector<cv::Mat> masks);
	static vector<cv::Mat> ExtractChanell(vector<cv::Mat> images, int channel);
	static cv::Mat BlendImages(vector<cv::Mat> images);
	
};

#endif