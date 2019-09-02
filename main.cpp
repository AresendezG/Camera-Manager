#include <stdio.h>
#include <string.h>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char* argv[])

//Requires Mode, Camera, Image Location
//Usage example: CamManager.exe snapshot 0 c:\test\testimage.jpg

{

	if (strcmp(argv[1],"help") == 0) { // Display help
	
		return 0;
	}

	else if (strcmp(argv[1],"snapshot")==0) {
		
		if (argc > 3) {

			
			cout << "Snapshot mode" << endl;
			int cam = 0;
			cam = std::stoi(argv[2], nullptr);

			VideoCapture cap(cam); // Initialize camera
			// Get the frame
			Mat save_img; cap >> save_img;
			this_thread::sleep_for(chrono::seconds(3));
			cap >> save_img; //Take snapshot after 3 seconds


			if (save_img.empty())
			{
				std::cerr << "Something wrong with Webcam, confirm it works" << std::endl;
			}
			// Save the frame into a file
			imwrite(argv[3], save_img); // Save picture
			cout << "Image Save Successfull" << endl;
		}
		return 0;

	}

	else if (strcmp(argv[1], "video")==0)
	{
		int cam = 0;
		cam = std::stoi(argv[2], nullptr);
		VideoCapture cap(cam);
		// Get the frame
		Mat save_img; cap >> save_img;

		while (true) {
			cap >> save_img;

			// Display the frame
			cv::imshow("Video feed Press Esc to Exit", save_img);

			// For breaking the loop
			if (cv::waitKey(25) >= 0) break;

		} // end while (video.read(frame))
	}

	else {
		cout << "Wrong Cmd: Mode Camera Img Location, type help to display the Help Message" << endl;
	}


}