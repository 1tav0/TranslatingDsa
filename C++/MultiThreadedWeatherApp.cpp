#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>
using namespace std::chrono_literals; //to use the ms in 2000
//to simulate the behavior of an api
void refreshForecast(std::map<std::string,int> forecastMap){
  while(true){
    for(auto &item: forecastMap){
      item.second++;
      std::cout << item.first << " - " << item.second << std::endl;
    }
    std::this_thread::sleep_for(2000ms); //sleep this thread for 2 seconds
  }
}

int main(){
  //dummy data
  std::map<std::string,int> forecastMap = {
    {"New York", 15},
    {"Mumbai", 20},
    {"Berlin", 18}
  };
  //background worker
  std::thread bgWorker(refreshForecast, forecastMap);
  //To keep your program running and allow the background thread to execute, you should call bgWorker.join() in your main function. This ensures that the main thread will wait for the background thread to finish before it exits.
  //Wait for the background thread to finish
  bgWorker.join();
  return 0;
}