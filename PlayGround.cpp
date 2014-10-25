#include "PlayGround.h"

#include <opencv2/core/core.hpp>
//#include <opencv2/features2d/features2d.hpp>
#include "opencv2/nonfree/features2d.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/legacy/legacy.hpp>

#include "Models\BaseKinectModel.h"
#include "Utilities\SerializationUtility.h"
#include "Models\DepthScale.h"


using namespace cv;
using namespace std;

static short surfHessianThreshold = 300;
static float uniquenessThreshold = 0.8f;
static short k = 2;

PlayGround::PlayGround(void)
{}

void PlayGround::startToPlay()
{
	std::string filePrefix1 = "father1", filePrefix2 = "father2";

	BaseKinectModel f1 = SerializationUtility::getKinectDataWithFilePrefix(filePrefix1);
	BaseKinectModel f2 = SerializationUtility::getKinectDataWithFilePrefix(filePrefix2);

	//-- Step 1: Detect the keypoints using SURF Detector
	SurfFeatureDetector surfDetector (surfHessianThreshold);

	std::vector<cv::KeyPoint> keyPoints1, keyPoints2;

	surfDetector.detect(f1.grayImage, keyPoints1);
	surfDetector.detect(f2.grayImage, keyPoints2);

	//-- Step 2: Calculate descriptors (feature vectors)

	SurfDescriptorExtractor extractor;
	Mat descriptors1, descriptors2;
	
	extractor.compute(f1.grayImage, keyPoints1, descriptors1);
	extractor.compute(f2.grayImage, keyPoints2, descriptors2);

	//-- Step 3: Matching descriptor vectors with a brute force matcher
	BFMatcher matcher(NORM_L2, false);

	std::vector<vector<DMatch>> matches;
	Mat mask;
	//matcher.match(descriptors1, descriptors2, matches);
	matcher.knnMatch(descriptors1, descriptors2, matches, k, mask, false);



	//-- Draw matches
	//Mat imgMatches;
	//drawMatches(f1.grayImage, keyPoints1, f2.grayImage,keyPoints2, matches, imgMatches);
	//
	////-- Show detected matches
	//imshow("Matches", imgMatches );

	//waitKey(0);

}