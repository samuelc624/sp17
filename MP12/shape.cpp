rec#include "shape.hpp"
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
  int dest_length = rec.length_ + length_;
  int dest_width = rec.width_ + width_;
  return Rectangle(dest_length, dest_width);
}

Rectangle Rectangle::operator-(const Rectangle& rec){
  int dest_length = max(0.0, rec.length_ - length_);
  int dest_width = max(0.0, rec.width_ - width_);
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
  radius_ = radius;
}
double Circle::getArea(){
  return (radius_ * radius_ * PI);
}

double Circle::getVolume(){
  return 0;
}

Circle Circle::operator+(const Circle& cir){
  int dest_radius = cir.radius_ + radius_;
  return Circle(dest_radius);
}

Circle Circle::operator-(const Circle& cir){
  int dest_radius = std::max( 0.0, cir.radius_ - radius_);
  return Circle(dest_radius);
}

double Circle::getRadius(){return radius_;}

//Sphere
//Please implement the member functions of Sphere:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Sphere::Sphere(double radius) : Shape("Sphere"){
  radius_ = radius;

double Sphere::getArea (){
  return (4 * PI * radius_ * radius_);
}

double Sphere::getVolume(){
  return((4.0 / 3.0) * radius_ * radius_ * radius_ * PI);
}

Sphere Sphere::operator+(const Sphere& sph){
  int dest_radius = sph.radius_ + radius_;
  return Sphere(dest_radius);
}

Sphere Sphere::operator-(const Sphere& sph){
  int dest_radius = std::max(0.0, sph.radius_ - radius_);
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
  int dest_length = rectp.length_ + length_;
  int dest_width = rectp.width_ + width_;
  int dest_height = rectp.height_ + height_;
  return RectPrism(dest_length, dest_width, dest_height);
}

RectPrism RectPrism::operator-(const RectPrism& rectp){
  int dest_length = max(0.0, rectp.length_ - length_);
  int dest_width = max(0.0, rectp.width_ - width_);
  int dest_height = max(0.0, rectp.height_ - height_);
  return Rectangle(dest_length, dest_width, dest_height);
}

double RectPrism::getWidth(){return width_;}
double RectPrism::getHeight(){return height_;}
double RectPrism::getLength(){return length_;}



// Read shapes from test.txt and initialize the objects
// Return a vector of pointers that points to the objects
vector<Shape*> CreateShapes(char* file_name){
  double temp1, temp2, temp3;
  string name;
  ifstream readfile(file_name, std::ifstream::in);
  in_file >> name;
  vector<Shape*> shapes;
  while(in_file >> name){
    if(name == "Rectangle"){
      in_file >> temp1 >> temp2;
      Shape* shape_ptr = new Rectangle(temp1, temp2);
      shapes.push_back(shape_ptr);
    }
    if(name == "Circle"){
      in_file >> temp1;
      Shape* shape_ptr = new Circle(temp1);
      shapes.push_back(shape_ptr);
    }
    if(name == "RectPrism") {
      in_file >> temp1 >> temp2 >> temp3;
      Shape* shape_ptr = new RectPrism(temp1, temp2, temp3);
      shapes.push_back(shape_ptr);
    }
    if(name == "Sphere"){
      in_file >> temp1;
      Shape* shape_ptr = new Sphere(temp1);
      shapes.push_back(shape_ptr);
    }
  }
  in_file.close();
	return shapes;
}

// call getArea() of each object
// return the max area
double MaxArea(vector<Shape*> shapes){
	double max_area = 0;
  int count;
  ifstream readfile(file_name, std::ifstream::in);
  in_file >> count;
for(int i = 0; i < count; i++){
  vector<Shapes*> iterator::i = shapes.begin();
    if(*i)->getArea() > max_area){
      max_area = *i -> getArea();
    }
  }
  in_file.close;
	return max_area;
}


// call getVolume() of each object
// return the max volume
double MaxVolume(vector<Shape*> shapes){
	double max_volume = 0;
  int count;
  ifstream readfile(file_name, std::ifstream::in);
  in_file >> count;
for(int i = 0; i < count; i++){
  vector<Shapes*> iterator::i = shapes.begin();
    if(*i)->getVolume() > max_volume){
      max_volume = *i -> getVolume();
    }
  }
  in_file.close;
	return max_volume;
}
