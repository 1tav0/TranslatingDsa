#include <iostream>
using namespace std;

//BASE clasS
class Square{
  private:
    int x;
  public:
    Square(int _x = 0) : x(_x){}

    void setX(int _x) {
      x = _x;
    }
    int getX() const{
      return x;
    }
    int getArea()const {
      return x * x;
    }
};
//DERIVED class FROM SQUARE
//BASE CLASS FOR SOLID
class Rectangle: public Square{
  private:
    int y;
  public:
    Rectangle(int _x = 0, int _y = 0) : Square(_x) { y = _y; }
    void setY(int _y) { y = _y; }
    int getY() const { return y; }
    int getArea() const{
      return getX() * y;
    }
};
//DERIVED CLASS FROM RECTANGLE
class Solid: public Rectangle{
  private:
    int z;
  public:
    Solid(int _x = 0, int _y = 0, int _z = 0) : Rectangle(_x, _y) { z = _z; }
    void setZ(int _z) { z = _z; }
    int getZ() const { return z; }
    int getArea() const{
      return getX() * getY() * z;
    }
};

class Triangle: public Rectangle{
  public:
    using Rectangle::Rectangle;
    int getArea() const {
      return 0.5 * getX() * getY();
    }
};

int main(){
    Solid s(2, 1, 4);

    cout << s.getArea() << "\n";

    Triangle t(3, 4);

    cout << t.getArea() << "\n";

    return 0;
}