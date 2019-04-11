//To build Program use .\gradlew vision:build
//To Run Program use .\gradlew vision:runvision
//To deploy to a tinkerboard or pi us .\gradlew vision:deploy  Note that when using tinkerboard deploy might not work to OS, you might need to use Raspbian ISO properly installed to the sd
#include "vision.h"
#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <stdio.h>
#include <iostream>

#include <cameraserver/CameraServer.h>
#include <cscore.h>

using namespace cv;
using namespace std;

/** Function Headers */
void detectAndDisplay( Mat VisionTracking );

String face_cascade_name = "haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
String window_name = "Capture - Face detection";



RNG rng(12345);
Rect bounding_rect;
int thresh = 100;
float height_offset;
float width_offset;
float width_goal;
float height_goal;

// This is the main entrypoint into the CurtinFRC Vision Program!

void entity101_vision::run() {

  // This is just a demonstration so you can see how this kind of code works. You'll be replacing this
  // with our actual vision tracking software!
  // You can view the vision output with Shuffleboard. Launch with `./gradlew :vision:ShuffleBoard`

  // This creates a webcam on USB, and dumps it into a sink. The sink allows us to access the image with sink.GrabFrame
  cs::UsbCamera cam{"USBCam", 0};
  cs::CvSink sink{"USB"};
  sink.SetSource(cam);

  // The camera defaults to a lower resolution, but you can choose any compatible resolution here.
  cam.SetResolution(640, 480);

  width_goal = 320;
  height_goal = 240;


  auto video_mode = cam.GetVideoMode();
  std::cout << "Width: " << video_mode.width << " Height: " << video_mode.height << std::endl;

  // This lets us see the camera output on the robot dashboard. We give it a name, and a width and height.
  cs::CvSource output = frc::CameraServer::GetInstance()->PutVideo("USB Camera", video_mode.width, video_mode.height);

  // The capMat is what comes from the camera, and the outMat is what goes to the dashboard. Note: 
  // the height - width order is reversed here (height first, width second), unlike other parts.
  cv::Mat VisionTracking{video_mode.height, video_mode.width, CV_8UC1};
  // cv::Mat img_HSV{video_mode.height, video_mode.width, CV_8UC3};

	//-- 1. Load the cascades
  if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading face cascade\n"); };
  if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading eyes cascade\n"); };


  while (true) {
    // Grab a frame. If it's not an error (!= 0), convert it to grayscale and send it to the dashboard.
    if (sink.GrabFrame(VisionTracking) != 0) {
      //cv::cvtColor(VisionTracking, img_HSV, COLOR_RGB2HSV);
      // cv::cvtColor(VisionTracking, img_HSV, cv::COLOR_RGB2HSV);
      // output.PutFrame(drawing);
    }

		//-- 3. Apply the classifier to the frame
    detectAndDisplay( VisionTracking );

		
    output.PutFrame(VisionTracking);
		imshow( "VisionTracking", VisionTracking );
		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			//break;
		}



  }


}

	/** @function detectAndDisplay */
void detectAndDisplay( Mat VisionTracking )
{
    std::vector<Rect> faces;
    Mat frame_gray;

    cvtColor( VisionTracking, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );

    for( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( VisionTracking, center, Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

        Mat faceROI = frame_gray( faces[i] );
        std::vector<Rect> eyes;

        //-- In each face, detect eyes
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(30, 30) );

        for( size_t j = 0; j < eyes.size(); j++ )
        {
            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( VisionTracking, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
        }
    }
    //-- Show what you got
    imshow( window_name, VisionTracking );
}