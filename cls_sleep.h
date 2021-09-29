#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <chrono>
#include <thread>

#include <iostream>


#define cls() std::cout <<"\033[2J\033[1;1H";
int main(){
  cls();
  for (int i=0; i<5; i++) {
    std::cout << "---\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}
