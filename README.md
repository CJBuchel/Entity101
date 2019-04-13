Entity101
===

# Quick Commands
## Build
`./gradlew build`, `./gradlew :vision:build`, `./gradlew :voicerecognition:build`, or `./gradlew :machinelearning:build`,
Build will compile and get the code ready without deploying it. It will also run all automated tests, which is great for testing your code before it ever gets run on a robot (which also means you can build whenever)

## Deploy
`./gradlew :vision:deploy`, `./gradlew :voicerecognition:build`, or `./gradlew :machinlearning:deploy`  
Deploying will build your code (as above), and deploy it to the robot. You have to be connected to the robot for this to work. Just keep in mind that deploying _does not run any automated tests_.

## Running Code Locally
`./gradlew runVision`,`.\gradlew runVoice`,`.\gradlew runMachineLearning`
You can run the code on your local computer without needing a Raspberry Pi or Tinker Board to test on. As long as you have a webcam (for vision), you should be A OK.

## [Common](common)
Common is code that is shared between both teams. It includes the bulk of our code and the bootstrap for the tinkerboard. 
It also includes the simulation framework, as well as simulation 'wrappers' for vendor parts that don't have builds for desktop (like CTRE and NavX).
Almost all of the code should be inside of `common`, so if we move parts between the robot, or need to do quick repairs, we don't have to reinvent code.

## [Vision](vision)
Vision is the code that detects via the camera, to see and visulize the environment. Vision gets deployed to a Raspberry Pi or Asus Tinkerboard.

## [VoiceRecognition](voiceRecognition)
Voice Recognition is the code that gets put onto the tinkerboard for detection and synthesis of voice communication. And much the same like vision gets deployed to a Raspberry Pi or Asus Tinkerboard. But it doesn't require to be on the same board, as all values are passed via network tables. -> As Long As you have ethernet :)

## [MachineLearning](MachineLearning)
Machine Learning is the same story, it holds the code where all values from Vision and Voice Recognition are passed to, processed and then executed using neural networks to determin what it should do next... hopefully not skynet. Again, it can be on a seperate board to Vision and/ or voice recognition as all values are passed via network tables.
