
#include "image_management.h"
#include "aia/aiaConfig.h"
#include "ucas/ucasConfig.h"
#include <iostream>

using namespace std;

ImageManagement::ImageManagement(void)
{
}
ImageManagement::~ImageManagement(void)
{
}

std::vector<cv::Mat> ImageManagement :: LoadAllInDir(std::string folder, std::string ext, bool force_gray)
{
	 //check folders exist
		if(!ucas::isDirectory(folder))
			throw aia::error(aia::strprintf("in getImagesInFolder(): cannot open folder at \"%s\"", folder.c_str()));

		// get all files within folder
		std::vector < cv::String > files;
		try{
			cv::glob(folder, files);
		}
		catch(const std::exception& e){
			std::cout << e.what() <<std::endl;
		}

		//// open files that contains 'ext'
		std::vector < cv::Mat > images;
		for(auto & f : files)
		{
			if(f.find(ext) == std::string::npos)
				continue;

			images.push_back(cv::imread(f, force_gray ? CV_LOAD_IMAGE_GRAYSCALE : CV_LOAD_IMAGE_UNCHANGED));
		}
		std :: cout << "Loaded " << images.size() << " from dataset" << std :: endl;
		return images;

}
std::vector<cv::Mat> ImageManagement :: ApplyMasks(vector<cv::Mat> images, vector<cv::Mat> masks){
	
	if(images.size() != masks.size()) throw std::runtime_error("ApplyMasks: The number of images and masks is not the same");
	try
	{
		std::vector<cv::Mat> result;
		for(unsigned int i = 0; i < images.size(); i++){
			cv::Mat img;
			result.push_back(img);
			images[i].copyTo(result[i], masks[i]);
		
			std :: cout << "Applied Masks to " << images.size() << " images" << std :: endl;
			return result;
		}
	}
	catch(exception e){
		std::cout << "Apply Masks of ImageManagement ERROR : "<< e.what() << std :: endl;
		throw e;
	}
}
std::vector<cv::Mat> ImageManagement :: ExtractChanell(vector<cv::Mat> images, int channelNo){
	
	cv::vector<cv::Mat> result;
	for (int i = 0; i < images.size(); i++)
	{
		cv :: Mat channel[3];
		// The actual splitting.
		split(images[i], channel);
		result.push_back(channel[channelNo]);
	}
	return result;
}
cv::Mat ImageManagement :: BlendImages(vector<cv::Mat> images){
	cv::Mat mergedImage(images[0].size(), images[0].type());
	cout<< "B" <<endl;
	//Add each image from a vector<Mat> inputImages with weight 1.0/n where n is number of images to merge
	for (cv::Mat mat : images) {
		cout<< "B" <<endl;
		cv::addWeighted(mergedImage, 5./6, mat, 1.0/6, 0, mergedImage);
		cout<< "B" <<endl;
	}
	cout<< "b" <<endl;
	return mergedImage;
}

