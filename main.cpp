#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "PlayGround.h"
#include "Utilities\SerializationUtility.h"
#include "Utilities\Calibrator.h"

#include <iostream>

#include <thread>
#include <process.h>

using namespace cv;
using namespace std;

void playgroundStartPlay()
{
	
}

int main( int argc, char** argv )
{

	PlayGround pg = PlayGround();
	pg.startToPlay();

	//cv::Mat image = SerializationUtility::getGrayScaleImage("boxes1");
	//std::vector<short> depth = SerializationUtility::getDepthData("boxes1");
	//std::vector<cv::Vec3b> color = SerializationUtility::getColorData("boxes1");

	//std::thread showImage(imshow, "bla bla", image);
	////showImage.join();

	char endofTheLine;
	cout << "Terminated!",
	cin >> endofTheLine;

    return 0;
}
