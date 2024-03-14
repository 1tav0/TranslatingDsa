#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;
//Encapsulates the private stuff that cannot be accessed by public instead create methods to modify them 
class YoutubeChannel{
private:
    string Name;
    string OwnerName;
    int Subscount;
    list<string> VideoTitles;
public:
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
    void Subscribe() {
      Subscount++;
    }
    void Unsubscribe(){
      if(Subscount>0){
        Subscount--;
      }
    }
    void addVideo(string video){
      VideoTitles.push_back(video);
    }
    void setName(string name){
      Name = name;
    }
    string getName(){
      return Name;
    }
};

int main(){
  YoutubeChannel ytChannel("tavo","1tav0");
  ytChannel.Subscribe();
  ytChannel.Subscribe();
  ytChannel.Subscribe();
  ytChannel.addVideo("one");
  ytChannel.addVideo("two");
  ytChannel.addVideo("three");
  ytChannel.getInfo();
}