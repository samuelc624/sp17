#include "shape.hpp"
#define PI  3.14159265


//Base class
//Please implement Shape's member functions
//constructor, getName()
//
//Base class' constructor should be called in derived classes'
//constructor to initizlize Shape's private variable

Shape::Shape(string name) {
  name_ = name;
}
string Shape::getName(){
  return name_;
}

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

Rectangle Rectangle::operator+(const Rectangle& rec){
  double dest_length = rec.length_ + length_;
  double dest_width = rec.width_ + width_;
  return Rectangle(dest_length, dest_width);
}

Rectangle Rectangle::operator-(const Rectangle& rec){
  double dest_length = max(0.0, length_ - rec.length_);
  double dest_width = max(0.0, width_ - rec.width_);
  return Rectangle(dest_width, dest_length);
}

double Rectangle::getWidth(){return width_;}
double Rectangle::getLength(){return length_;}


//Circle
//Please implement the member functions of Circle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here
Circle::Circle(double radius) : Shape("Circle"){
  radius_ = radius;
}
double Circle::getArea(){
  return (radius_ * radius_ * PI);
}

double Circle::getVolume(){
  return 0;
}

Circle Circle::operator+(const Circle& cir){
  double dest_radius = cir.radius_ + radius_;
  return Circle(dest_radius);
}

Circle Circle::operator-(const Circle& cir){
  double dest_radius = max( 0.0, radius_ - cir.radius_);
  return Circle(dest_radius);
}

double Circle::getRadius(){return radius_;}

//Sphere
//Please implement the member functions of Sphere:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Sphere::Sphere(double radius) : Shape("Sphere"){
  radius_ = radius;
}
double Sphere::getArea(){
  return (4 * PI * radius_ * radius_);
}

double Sphere::getVolume(){
  return((4.0 / 3.0) * radius_ * radius_ * radius_ * PI);
}

Sphere Sphere::operator+(const Sphere& sph){
  double dest_radius = sph.radius_ + radius_;
  return Sphere(dest_radius);
}

Sphere Sphere::operator-(const Sphere& sph){
  double dest_radius = max(0.0, radius_ - sph.radius_);
  return Sphere(dest_radius);
}

double Sphere::getRadius(){return radius_;}

//Rectprism
//Please implement the member functions of RectPrism:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

RectPrism::RectPrism(double length, double width, double height) : Shape("RectPrism"){
  length_ = length;
  width_ = width;
  height_ = height;
}

double RectPrism::getArea(){
  return (2 * (length_ *  width_  + length_ * height_ + width_ * height_));
}

double RectPrism::getVolume(){
  return (length_ * width_ * height_);
}

RectPrism RectPrism::operator+(const RectPrism& rectp){
  double dest_length = rectp.length_ + length_;
  double dest_width = rectp.width_ + width_;
  double dest_height = rectp.height_ + height_;
  return RectPrism(dest_length, dest_width, dest_height);
}

RectPrism RectPrism::operator-(const RectPrism& rectp){
  double dest_length = max(0.0, length_ - rectp.length_);
  double dest_width = max(0.0, width_ - rectp.width_);
  double dest_height = max(0.0, height_ - rectp.height_);
  return RectPrism(dest_width, dest_length, dest_height);
}

double RectPrism::getWidth(){return width_;}
double RectPrism::getHeight(){return height_;}
double RectPrism::getLength(){return length_;}



// Read shapes from test.txt and initialize the objects
// Return a vector of pointers that points to the objects
vector<Shape*> CreateShapes(char* file_name){
  double temp1, temp2, temp3;
  string name;
  ifstream poop(file_name, std::ifstream::in);
  poop >> name;
  vector<Shape*> shapes;
  while(poop >> name){
    if(name == "Rectangle"){
      poop >> temp1 >> temp2;
      Shape* shape_ptr = new Rectangle(temp1, temp2);
      shapes.push_back(shape_ptr);
    }
    if(name == "Circle"){
      poop >> temp1;
      Shape* shape_ptr = new Circle(temp1);
      shapes.push_back(shape_ptr);
    }
    if(name == "RectPrism") {
      poop >> temp1 >> temp2 >> temp3;
      Shape* shape_ptr = new RectPrism(temp1, temp2, temp3);
      shapes.push_back(shape_ptr);
    }
    if(name == "Sphere"){
      poop >> temp1;
      Shape* shape_ptr = new Sphere(temp1);
      shapes.push_back(shape_ptr);
    }
  }
  poop.close();
	return shapes;
}

// call getArea() of each object
// return the max area
double MaxArea(vector<Shape*> shapes){
	double max_area = 0;
  double temp = 0;
  for(vector<Shape*>::iterator shape_ptr = shapes.begin();shape_ptr != shapes.end(); shape_ptr++) {
    temp = (*shape_ptr)->getArea();
    if(temp > max_area){
      max_area = temp;
    }
}
	return max_area;
}


// call getVolume() of each object
// return the max volume
double MaxVolume(vector<Shape*> shapes){
	double max_volume = 0;
  double temp = 0;
    for(vector<Shape*>::iterator shape_ptr = shapes.begin();shape_ptr != shapes.end(); ++shape_ptr) {
      temp = (*shape_ptr) -> getVolume();
      if(temp > max_volume){
        max_volume = temp;
      }
  }
  	return max_volume;
  }
