#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class YoutubeChannel{
  public:
    string Name;
    string OwnerName;
    int Subscount;
    list<string> VideoTitles;

    YoutubeChannel(string name, string ownerName){
      Name = name;
      OwnerName = ownerName;
      Subscount = 0;
    }

    void getInfo(){
      cout << Name << endl;
      cout << OwnerName << endl;
      cout << Subscount << endl;
      for(auto it: VideoTitles){
          cout << it << endl;
      }
    }
};

int main(){
  YoutubeChannel ytChannel("tavo","1tav0");
  ytChannel.VideoTitles.push_back("1");
  ytChannel.VideoTitles.push_back("1");
  ytChannel.VideoTitles.push_back("1");

  ytChannel.getInfo();
}