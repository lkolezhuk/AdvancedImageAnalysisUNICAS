#include "wall_marker.h"


WallMarker::WallMarker(void)
{
}

WallMarker::~WallMarker(void)
{
}

std::vector<cv::Point2f> WallMarker::GetInitialWallMarkers(std::string filePath){
	 // where we want to store the series of control points
    std::vector < cv::Point2f > control_points;
     
    // open the xml
	TiXmlDocument xml(filePath.c_str());
    if(!xml.LoadFile())
        std::cout<<"Error reading wall markers"<< std::endl; // should throw an exception
 
    // parse the xml
    TiXmlElement *pElem = xml.FirstChildElement("CellCounter_Marker_File");
    pElem = xml.FirstChildElement("CellCounter_Marker_File");
    pElem = pElem->FirstChildElement("Marker_Data");
    pElem = pElem->FirstChildElement("Marker_Type");
    pElem = pElem->FirstChildElement("Marker");
    while(pElem)
    {
        // read the x-y-t coordinates
        int x = std::stoi(pElem->FirstChildElement("MarkerX")->GetText());
        int y = std::stoi(pElem->FirstChildElement("MarkerY")->GetText());
        int t = std::stoi(pElem->FirstChildElement("MarkerZ")->GetText());
         
        // we should check if the series belongs to the time frame we are interested at
        //if(t == ...) // <-- you have to decide
        control_points.push_back(cv::Point2f(x, y));
         
        // go to next point
        pElem = pElem->NextSiblingElement("Marker");
    }

	std::cout<<"Loaded "<< control_points.size() << " wall marker points from "<< filePath <<std::endl;
	return control_points;
}