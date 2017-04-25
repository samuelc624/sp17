#include "shape.hpp"
#define PI  3.14159265


//Base class
//Please implement Shape's member functions
//constructor, getName()
//
//Base class' constructor should be called in derived classes'
//constructor to initizlize Shape's private variable
/*class Shape{
  Rectangle operator+(const Rectangle& other);
  Rectangle operator-(const Rectangle& other)
  double getVolume();
  double getArea();
}
return name_;
*/

//Rectangle
//Please implement the member functions of Rectangle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Rectangle::Rectangle(double width, double length) : Shape("Rectangle")
{
length_ = length;
width_ = width;
}


double Rectangle::getArea(){
  return (width_ * length_);
}

double Rectangle::getVolume(){
  return 0;
}

Rectangle Rectangle::operator+(const Rectangle& other){
  int dest_length = other.length_ + length_;
  int dest_width = other.width_ + width_;
  return Rectangle(dest_length, dest_width);
}

Rectangle Rectangle::operator-(const Rectangle& other){
  int dest_length = other.length_ - length_;
  int dest_width = other.width_ - width_;
  return Rectangle(dest_length, dest_width);
}


double Rectangle::getWidth(){
  return width_;
}
double Rectangle::getLength(){
  return length_;
}

//Circle
//Please implement the member functions of Circle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here
Circle::Circle(double radius) : Shape("Circle"){
  int radius_ = radius;
}
double Circle::getArea(){
  return (radius_ * radius_ * PI);
}

double Circle::getVolume(){
  return 0;
}

Circle Circle::operator+(const Circle& other){
  int dest_radius = other.radius_ + radius_;
  return Circle(dest_radius);
}

Circle Circle::operator-(const Circle& other){
  int dest_radius = other.radius_ - radius_;
  return Circle(dest_radius);
}

double Circle::getRadius(){return radius_;}

//Sphere
//Please implement the member functions of Sphere:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here



double Sphere::getRadius(){return radius_;}

//Rectprism
//Please implement the member functions of RectPrism:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here


double RectPrism::getWidth(){return width_;}
double RectPrism::getHeight(){return height_;}
double RectPrism::getLength(){return length_;}



// Read shapes from test.txt and initialize the objects
// Return a vector of pointers that points to the objects
vector<Shape*> CreateShapes(char* file_name){
  int count, r, i;
  double temp;
  string name;
  ifstream readfile ("test1.txt");
  while(getline(readfile, name)){

  }
	return vector<Shape*>(0, NULL);
}

// call getArea() of each object
// return the max area
double MaxArea(vector<Shape*> shapes){
	double max_area = 0;
	//@@Insert your code here

	return max_area;
}


// call getVolume() of each object
// return the max volume
double MaxVolume(vector<Shape*> shapes){
	double max_volume = 0;
	//@@Insert your code here


	return max_volume;
}
