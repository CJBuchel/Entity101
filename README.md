Entity101
===

## Project Setup
- First you will need to download all dependencies the project needs. Luckily being the best thing that ever happened to programming,     gradle does this all for you. Just enter the command in the project directory `.\gradlew downloadAll` and it should download all the      nesessary dependecies and requirements.

# Getting started

### 1. Grab the image:
  - [Tinkerboard Image](https://dlcdnets.asus.com/pub/ASUS/mb/Linux/Tinker_Board_S/20181023-tinker-board-linaro-stretch-alip-v2.0.8.img.zip)
    - Make sure you use version 2.0.8! v1.8 doesn't work with some USB cameras (nor the Kinect) due to a kernel problem.
  - [Raspberry Pi](https://downloads.raspberrypi.org/raspbian_lite_latest)
### 2. Flash the image onto a microsd card using etcher: https://etcher.io/
  - You will need to grab the .img file from the zip. The .img file is what you give to etcher.
  - After complete, insert the microSD card and startup the coprocessor. It may take a minute or two.
### 3. SSH into the Coprocessor
  - On Mac/Linux, use `ssh username@hostname`
  - On Windows, download [puTTY](https://the.earth.li/~sgtatham/putty/latest/w64/putty-64bit-0.70-installer.msi) and use that.
  - Tinkerboard:
    - Hostname: `tinkerboard`, Username: `linaro`, Password: `linaro`
  - Raspberry Pi:
    - Hostname: `raspberrypi`, Username: `pi`, Password: `raspberry`
### 4. Run the following command:
  - `wget --no-check-certificate -qO - https://github.com/A-Loose-Screw/Entity101/blob/master/common/bootstrap.sh?raw=1 | bash`
### 5. Your Coprocessor will now restart

# Quick Commands

## Build
`./gradlew build`, `./gradlew :vision:build`, `./gradlew :voicerecognition:build`, or `./gradlew :machinelearning:build`,
Build will compile and get the code ready without deploying it. It will also run all automated tests, which is great for testing your code before it ever gets run on a robot (which also means you can build whenever)

## Deploy
`./gradlew :vision:deploy`, `./gradlew :voicerecognition:deploy`, or `./gradlew :machinlearning:deploy`  
Deploying will build your code (as above), and deploy it to the robot. You have to be connected to the robot for this to work. Just keep in mind that deploying _does not run any automated tests_.

## Running Code Locally
`./gradlew runVision`,`.\gradlew runVoice`,`.\gradlew runMachineLearning`
You can run the code on your local computer without needing a Raspberry Pi or Tinker Board to test on. As long as you have a webcam (for vision), you should be A OK.



![alt text](http://url/to/Git_General_Pull.png)




## [Common](common)
Common is code that is shared between all folders. It includes the bulk of our code and the bootstrap for the tinkerboard. 
It also includes the simulation framework, as well as simulation 'wrappers' for vendor parts that don't have builds for desktop (like CTRE and NavX).
Almost all of the code should be inside of `common`, so if we move parts between the robot, or need to do quick repairs, we don't have to reinvent code.

## [Vision](vision)
Vision is the code that detects via the camera, to see and visulize the environment. Vision gets deployed to a Raspberry Pi or Asus Tinkerboard.

## [VoiceRecognition](voiceRecognition)
Voice Recognition is the code that gets put onto the tinkerboard for detection and synthesis of voice communication. And much the same like vision gets deployed to a Raspberry Pi or Asus Tinkerboard. But it doesn't require to be on the same board, as all values are passed via network tables. -> As Long As you have ethernet :)

## [MachineLearning](MachineLearning)
Machine Learning is the same story, it holds the code where all values from Vision and Voice Recognition are passed to, processed and then executed using neural networks to determin what it should do next... hopefully not skynet. Again, it can be on a seperate board to Vision and/ or voice recognition as all values are passed via network tables.
