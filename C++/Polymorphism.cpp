#include <iostream>
#include <list>
#include <string>
#include <vector>
//the ability for an object to have multiple forms 
//different implementations of print for different derived class with same name
using namespace std;

class YoutubeChannel{
private:
    string Name;
    int Subscount;
    list<string> VideoTitles;
protected:
  string OwnerName;
  int ContentQuality;
public:
    YoutubeChannel(string name, string ownerName){
      Name = name;
      OwnerName = ownerName;
      Subscount = 0;
      ContentQuality = 0;
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
    void checkAnalitics(){
      if(ContentQuality < 5){
        cout << Name << " has bad quality content." << endl;
      }else{
        cout << Name << " has good quality content." << endl;
      }
    }
};
//the public means whatever is public will be public in this inheritance to our derived class
class SoccerChannel:public YoutubeChannel{
  public:
    SoccerChannel(string name, string ownerName):YoutubeChannel(name, ownerName){}
    void print(){
      cout << OwnerName << " Testing protected varible in derived SoccerChannel class" << endl;
      ContentQuality++;
    }
};

class FoodChannel:public YoutubeChannel{
  public:
    FoodChannel(string name, string ownerName):YoutubeChannel(name, ownerName){};
    void print(){
      cout << OwnerName << " Testing protected varible in derived class FoodChannel class" << endl;
      ContentQuality++;
    }
};

int main(){
  SoccerChannel soccerChannel("tavo","tttav0");
  FoodChannel foodChannel("bob's kitchen", "bob");
  soccerChannel.print();
  soccerChannel.print();
  soccerChannel.print();
  soccerChannel.print();
  soccerChannel.print();
  soccerChannel.print();
  // soccerChannel.checkAnalitics();
  foodChannel.print();
  foodChannel.print();
  foodChannel.print();
  foodChannel.print();
  // foodChannel.checkAnalitics();

  YoutubeChannel *yt1 = &soccerChannel;
  YoutubeChannel *yt2 = &foodChannel;

  yt1->checkAnalitics();
  yt2->checkAnalitics();
}