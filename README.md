# Entity101

## Current Tasks {
 
 
 ## Build Projects:
  `.\gradlew build` in directory to build and test platform.
  `.\gradlew TestProject_cpp:build` to build an executable for all programs in the cpp folder.
  `.\gradlew TestProject_java:build` to build and test all programs inside the java folder.
  
 ## Run Projects:
  `.\gradlew TestProject_java:run` to run the java program in the current terminal.
  
  `.\gradlew tasks` to view a list of tasks.
  `.\gradlew tasks --all` to view a detailed list of tasks.
  
  
  ## Tutorials & Information
  
  ### Setup
  - Requirement Install Instructions http://mlpack.org/docs/mlpack-3.0.4/doxygen/build_windows.html
  - mlpack (Machine Learning Pack) Video Breakdown https://www.youtube.com/watch?v=FX6Db6TxkS0
  - The mlpack needs to have cmake links installed to do this (After you have installed cmake) go to your directory where mlpack is         installed, and run this command. Remember to change the command to the current desired setting e.g ```':FILEPATH="C:/mlpack/mlpack-```

  ```cmake -G "Visual Studio 15 2017 Win64" -DBLAS_LIBRARY:FILEPATH="D:\Users\Conno\Desktop\Code\Entity101\common\mlpack\mlpack-3.0.4/packages/OpenBLAS.0.2.14.1/lib/native/lib/x64/libopenblas.dll.a" -DLAPACK_LIBRARY:FILEPATH="D:\Users\Conno\Desktop\Code\Entity101\common\mlpack\mlpack-3.0.4/packages/OpenBLAS.0.2.14.1/lib/native/lib/x64/libopenblas.dll.a" -DCMAKE_PREFIX:FILEPATH="D:\Users\Conno\Desktop\Code\Entity101\common\mlpack\armadillo" -DBUILD_SHARED_LIBS=OFF ..```
  
  - Once it has successfully finished, open "C:\mlpack\armadillo-8.500.1\build\armadillo.sln"
    Build > Build Solution
    Once it has successfully finished, close Visual Studio

  - Next We need to run a similar command into the build file of mlpack/mlpack<version>. again update the command to your correct           directories.
 
 ```cmake -G "Visual Studio 15 2017 Win64" -DBLAS_LIBRARY:FILEPATH="D:/Users/Conno/Desktop/Code/Entity101/common/mlpack/mlpack-3.0.4/packages/OpenBLAS.0.2.14.1/lib/native/lib/x64/libopenblas.dll.a" -DLAPACK_LIBRARY:FILEPATH="D:/Users/Conno/Desktop/Code/Entity101/common/mlpack/mlpack-3.0.4/packages/OpenBLAS.0.2.14.1/lib/native/lib/x64/libopenblas.dll.a" -DARMADILLO_INCLUDE_DIR="D:/Users/Conno/Desktop/Code/Entity101/common/mlpack/mlpack-3.0.4/armadillo-9.200.7/include" -DARMADILLO_LIBRARY:FILEPATH="D:/Users/Conno/Desktop/Code/Entity101/common/mlpack/mlpack-3.0.4/armadillo-9.200.7/build/Debug/armadillo.lib" -DBOOST_INCLUDEDIR:PATH="C:/boost/boost_1_69_0/" -DBOOST_LIBRARYDIR:PATH="C:/boost/boost_1_69_0/lib64-msvc-12.0" -DDEBUG=OFF -DPROFILE=OFF ..```
 
  ### Common
  
  - (common) readme
  Common Hosts all the libraries affilated with the program, including `mlpack`(Main), `EmbeddedTools`, `armadillo`, `boost`, `lapackpp` and `libxml2` 
## }
