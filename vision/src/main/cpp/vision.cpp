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

RNG rng(12345);
Rect bounding_rect;
int thresh = 100;
int width_goal;
int height_goal;

//--HumanAquisition
bool TargetFaceAquired;
bool TargetHumanAquired;
int HumXoffset, HumYoffset;

//--ObjectAquisition
bool TargetObjectAquired;
int objXoffset, objYoffset;


int ResWidth = 640, ResHeight = 480;

void entity101_vision::run() {
  

  // This creates a webcam on USB, and dumps it into a sink. The sink allows us to access the image with sink.GrabFrame
  cs::UsbCamera cam{"USBCam", 0};
  cs::CvSink sink{"USB"};
  sink.SetSource(cam);

  // The camera defaults to a lower resolution, but you can choose any compatible resolution here.
  cam.SetResolution(ResWidth, ResHeight);

  width_goal = ResWidth/2;
  height_goal = ResHeight/2;


  auto video_mode = cam.GetVideoMode();
  std::cout << "Width: " << video_mode.width << " Height: " << video_mode.height << std::endl;
  std::cout << "Goals: " << width_goal << "," << height_goal << endl; 

  // This lets us see the camera output on the robot dashboard. We give it a name, and a width and height.
  cs::CvSource output = frc::CameraServer::GetInstance()->PutVideo("USB Camera", video_mode.width, video_mode.height);

  cv::Mat imgColoured{video_mode.height, video_mode.width, CV_8UC3};
  cv::Mat VisionTracking;

  //-- 1. Load the cascades
  // Load Face cascade (.xml file)
  CascadeClassifier face_cascade;

  face_cascade.load( "C:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml" );
  if(!face_cascade.load("C:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml"))
  {
    cerr<<"Error Loading Face XML file"<<endl;
  }


  /// Set up the pedestrian detector --> let us take the default one
  HOGDescriptor hog;
  hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

  while (true) {
    // Grab a frame. If it's not an error (!= 0), convert it to grayscale and send it to the dashboard.
    if (sink.GrabFrame(imgColoured) != 0) {
      std::vector<Rect> faces;

      cvtColor( imgColoured, VisionTracking, COLOR_BGR2GRAY );

      //-- Detect faces
      face_cascade.detectMultiScale( VisionTracking, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(1, 1) );

      for( size_t i = 0; i < faces.size(); i++ )
      {
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( imgColoured, center, Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 255, 0, 0 ), 2, 2, 0 );
        putText(imgColoured, "Target Aquired", Point(center) + cv::Point(-10,10), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,0,255));
        HumXoffset = /*width_goal - */faces[i].x;
        HumYoffset = /*height_goal - */faces[i].y;
      }

      //-- Detect Person
      
      vector<Rect> human;
      vector<double> weights;

      hog.detectMultiScale(imgColoured, human, weights);

      /// draw detections and store location
      for( size_t i = 0; i < human.size(); i++ )
      {
        Rect r = human[i];
        rectangle(imgColoured, human[i], cv::Scalar(0,0,255), 3);
        stringstream temp;
        temp << weights[i];
        putText(imgColoured, temp.str(),Point(human[i].x,human[i].y+50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,0,255));
        HumXoffset = /*width_goal - */human[i].x;
        HumYoffset = /*height_goal - */human[i].y;
      }
      
      //-- Show what you got
      cout << "X[" << HumXoffset << "]," << "Y[" << HumYoffset << "]" << endl;
      imshow("VisionTracking", imgColoured);

      output.PutFrame(imgColoured);
		  waitKey(10);

    }
  }
}