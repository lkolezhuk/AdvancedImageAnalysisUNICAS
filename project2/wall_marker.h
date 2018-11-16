#pragma once
#include <string>
#include "aia/aiaConfig.h"
#include "ucas/ucasConfig.h"
#include "tinyxml\tinyxml.h"

class WallMarker
{
public:
	WallMarker(void);
	~WallMarker(void);

	std::vector < cv::Point2f > control_points;
	static std::vector<cv::Point2f> GetInitialWallMarkers(std::string filePath);
};

