![alt text](https://github.com/A-Loose-Screw/Entity101/blob/master/png/Entity101_1.png)




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









## For The Members Invloved with programming on the project, the following is the general steps for how the project is pull requested
- (1) First Make Sure you have forked the project to your account, then create a branch that is not master, (Master should be used as a fallback rather than a editing branch. It's also good practice to keep your master synced with the Origin Master [A-Loose-Screw/Entity101]) Then while on your editing branch sync it with your forked master.

- (2) After Editing Your branch to the desired effect, and you think it's ready to be sent to the origin. Pull Request it with the origin page at (https://github.com/A-Loose-Screw/Entity101/pulls). It's also a general rule that you never send code that does not build or work to the origin. EVER. The origin has one branch and is suppose to be the working branch people get the code from, and should always be working. (finish the code on your own branch and if it doesn't work... don't send it, that simple) The only exception to this rule, is if the code your working with was already broken. And you are adding to fix the issue.

- (3) After Pull requesting your code, pull request it again at the previous link, But Point it from A-Loose-Screw/Entity101 Master -> username/Entity101 Master, this will sync your master with (hopefully) working code. And code that was also sent and made by others.

- (4) after this you can merge your Master branch to your editing branch, And then after this has been done, you can continue editing your branch and repeat the process for your next pull request. However it's also to note, that if the pull request is pending. It is synced with your editing branch. so until it has been merged don't make any sudden changes that stop it from working again. But pull requests should only last for a few minutes, so no changes should occure during the operation.

![alt text](https://github.com/A-Loose-Screw/Entity101/blob/master/png/Git_General_Pull.png)





## [Log](LogReadMe.md)



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
