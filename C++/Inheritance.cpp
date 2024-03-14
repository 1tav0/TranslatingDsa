#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;
//creating a class from another class 
class YoutubeChannel{
private:
    string Name;
    int Subscount;
    list<string> VideoTitles;
protected:
  string OwnerName;
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
//the public means whatever is public will be public in this inheritance to our derived class
class SoccerChannel:public YoutubeChannel{
  public:
    SoccerChannel(string name, string ownerName):YoutubeChannel(name, ownerName){}
    void print(){
      cout << OwnerName << " Testing protected varible from derived class" << endl;
    }
};

int main(){
  SoccerChannel soccerChannel("tavo","tttav0");
  soccerChannel.addVideo("saw1");
  soccerChannel.addVideo("saw2");
  soccerChannel.addVideo("saw3");
  soccerChannel.Subscribe();
  soccerChannel.Subscribe();
  soccerChannel.Subscribe();
  soccerChannel.getInfo();
  YoutubeChannel ytChannel("joe", "joe1");
  ytChannel.addVideo("xmen1");
  ytChannel.addVideo("xmen2");
  ytChannel.addVideo("xmen3");
  ytChannel.Subscribe();
  ytChannel.Subscribe();
  ytChannel.getInfo();
  // ytChannel.print();
  soccerChannel.print();//only available in the class it was declared for
}