#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "square.hpp"

using namespace std;

int main(){
	Rectangle rec(5,4,"box","red");
	cout << "Rectangle:...\n";
	cout << "Name: " << rec.getName() << "\n";
	cout << "Color: " << rec.getColor() << "\n";
	cout << "Height: " << rec.getHeight() << "\n";
	cout << "Width: " << rec.getWidth() << "\n";
	cout << "Area: " << rec.getArea(rec.getHeight(),rec.getWidth()) << "\n\n";

	rec.setName("BOX");
	rec.setColor("RED");
	rec.setHeight(6);
	rec.setWidth(7);
	
	cout << "Rectangle:...\n";
        cout << "Name: " << rec.getName() << "\n";
        cout << "Color: " << rec.getColor() << "\n";
        cout << "Height: " << rec.getHeight() << "\n";
        cout << "Width: " << rec.getWidth() << "\n";
        cout << "Area: " << rec.getArea(rec.getHeight(),rec.getWidth()) << "\n\n";


	Circle circle(5,"ball","blue");
	cout << "Circle:...\n";
	cout << "Name: " << circle.getName() << "\n";
	cout << "Color: " << circle.getColor() << "\n";
	cout << "Radius: " << circle.getRadius() << "\n";
	cout << "Area: " << circle.getArea(circle.getRadius()) << "\n\n";
	
	circle.setName("BALL");
	circle.setColor("BLUE");
	circle.setRadius(7);

	cout << "Circle:...\n";
        cout << "Name: " << circle.getName() << "\n";
        cout << "Color: " << circle.getColor() << "\n";
        cout << "Radius: " << circle.getRadius() << "\n";
        cout << "Area: " << circle.getArea(circle.getRadius()) << "\n\n";

	Square square(5,"cube","yellow");
	cout << "Square:...\n";
	cout << "Name: " << square.getName() << "\n";
	cout << "Color: " << square.getColor() << "\n";
	cout << "Height: " << square.getHeight() << "\n";
	cout << "Width: " << square.getWidth() << "\n";
	cout << "Area: " << square.getArea(square.getHeight(),square.getWidth()) << "\n\n";

	square.setName("CUBE");
	square.setColor("YELLOW");
	square.setDimentions(6);

	cout << "Square:...\n";
        cout << "Name: " << square.getName() << "\n";
        cout << "Color: " << square.getColor() << "\n";
        cout << "Height: " << square.getHeight() << "\n";
        cout << "Width: " << square.getWidth() << "\n";
        cout << "Area: " << square.getArea(square.getHeight(),square.getWidth()) << "\n\n";


	return 0;
}
