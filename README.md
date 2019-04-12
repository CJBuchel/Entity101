Entity101
===

# Quick Commands
## Build
`./gradlew build`, `./gradlew :vision:build`, `./gradlew :voicerecognition:build`, or `./gradlew :machinelearning:build`,
Build will compile and get the code ready without deploying it. It will also run all automated tests, which is great for testing your code before it ever gets run on a robot (which also means you can build whenever)

## Deploy
`./gradlew :vision:deploy`, `./gradlew :voicerecognition:build`, or `./gradlew :machinlearning:deploy`  
Deploying will build your code (as above), and deploy it to the robot. You have to be connected to the robot for this to work. Just keep in mind that deploying _does not run any automated tests_.

## Running Vision
`./gradlew runVision`  
You can run vision on your local computer without needing a Raspberry Pi or Tinker Board to test on. As long as you have a webcam, you should be A OK.

## [Common](common)
Common is code that is shared between both teams. It includes the bulk of our code. 
It also includes the simulation framework, as well as simulation 'wrappers' for vendor parts that don't have builds for desktop (like CTRE and NavX).
Almost all of the code should be inside of `common`, so if we move parts between the robots, or need to do quick repairs, we don't have to reinvent code that the other team has already written :)

## [Vision](vision)
Vision is the code that gets put on our vision system for the competition. Vision doesn't get deployed to the RoboRIO, but instead to a Raspberry Pi or Asus Tinkerboard.
