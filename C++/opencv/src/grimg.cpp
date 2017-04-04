#include <stdio.h>
#include <string.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
	if(argc < 2){
		printf("usage: pimage <image_path> [<grayscale_path>]\n");
		return -1;
	}

	Mat image, grayImage;
	string source(argv[1]);
	image = imread(source, IMREAD_COLOR);
	if(!image.data){
		printf("No image data\n");
		return -1;
	}

	// grayscale image conversion
	cvtColor(image, grayImage, COLOR_BGR2GRAY);

	// save image
	string destination("grayscale");
	if(argv[2]){
		destination = string(argv[2]);
		imwrite(destination, grayImage);
	}
	
	namedWindow(source, WINDOW_NORMAL);
	namedWindow(destination, WINDOW_NORMAL);
	imshow(source, image);
	imshow(destination, grayImage);
	waitKey(0);
}
