#include <cstdlib>
#include <iostream> 
#define PI 3.14
using namespace std;

class Shape {
protected:
	float area;
public:
	Shape() { area = 0; }
	virtual void computeArea() = 0;
	void printArea()
	{
		cout << area << endl;
	}
};
class Rectangle : public Shape{
	protected:
		float width,height;
	public:
		Rectangle(float a,float b){
			width=a;
			height=b;
		}
	//	Rectangle(Rectangle &rec){
	//		height=rec.height;
	//		width=rec.width;
	//	}
		void computeArea(){
			area=height*width;
		}
	// Add code here
};
class Triangle : public Shape{
	protected:
		float bottom,height;
	public:
		Triangle(float a,float b){
			bottom=a;
			height=b;
		}
	//	Triangle(Triangle &tri){
	//		bottom=tri.bottom;
	//		height=tri.height;
	//	}
		void computeArea(){
			area=0.5*bottom*height;
		}
	// Add code here
};
class Circle : public Shape{
	protected:
		float radius;
	public:
		Circle(float a){
			radius=a;
		}
	//	Circle(Circle &cir){
	//		radius=cir.radius;
	//	}
		void computeArea(){
			area=PI*radius*radius;
		}
	// Add code here
};
class Trapezium : public Shape{
	protected:
		float top,bottom,height;
	public:
		Trapezium(float a,float b,float c){
			top=a;
			bottom=b;
			height=c;
		}
	//	Trapezium(Trapezium &tre){
	//		top=tre.top;
	//		bottom=tre.bottom;
	//		height=tre.height;
	//	}
		void computeArea(){
			area=(top+bottom)*height*0.5;
		}
	// Add code here
};
class Rhombus : public Shape{
	protected:
		float longedge,shirtedge;
	public:
		Rhombus(float a,float b){
			longedge=a;
			shirtedge=b;
		}
	//	Rhombus(Rhombus &rho){
	//		longedge=rho.longedge;
	//		shirtedge=rho.shirtedge;
	//	}
		void computeArea(){
			area=0.5*longedge*shirtedge;
		}
};

int main()
{
	float a, b, c;
	Shape *shape;
	
	cin >> a >> b; // Enter the height and width of Rectangle
	Rectangle rec(a, b);
	
	cin >> a >> b; // Enter the bottom and height of Triangle
	Triangle  tri(a, b);

	cin >> a ; // Enter the radius of Circle
	Circle cir(a);
    
    cin >> a >> b >> c; // Enter the top, bottom and height of Trapezium
    Trapezium tre(a, b, c);

    cin >> a >> b; // Enter the long edge and short edge of Rhombus
    Rhombus rho(a, b);

	shape = &rec;
	shape->computeArea();
	shape->printArea();

    shape = &tri;
    shape->computeArea();
    shape->printArea();

    shape = &cir;
    shape->computeArea();
    shape->printArea();
  
  	shape = &tre;
	shape->computeArea();
    shape->printArea();

	shape = &rho;
    shape->computeArea();
    shape->printArea();

	return 0;
}
