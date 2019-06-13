#include "vision.h"
#include <iostream>
#include <networktables/NetworkTableInstance.h>

#ifndef RUNNING_FRC_TESTS
int main(int argc, char **argv) {
  int team = 0;
  if (argc > 1) {
    team = std::stoi(argv[1]);
  }


  #ifdef __DESKTOP__
  std::cout << "Running on Desktop - imshow enabled" << std::endl;
  bool isDesktop = true;
#else
  std::cout << "Running embedded - imshow disabled" << std::endl;
  bool isDesktop = false;
#endif

  auto ntinst = nt::NetworkTableInstance::GetDefault();
  if (team != 0) {
    std::cout << "Starting Entity101 Vision Program (Client Mode - Team " << team << ")" << std::endl;
    ntinst.StartClientTeam(team);
  } else {
    std::cout << "Starting Entity101 Vision Program (Server Mode - For Testing Only)" << std::endl;
    ntinst.SetServer("Entity101");
    ntinst.StartServer();
  }

  entity101_vision vision;  
  vision.run();

  std::cout << "Vision Program Exited. Error Check Required" << std::endl;
  return -1;
}
#endif