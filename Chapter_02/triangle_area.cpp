// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4 
// The area of the triangle is 33.6

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Enter three points for a triangle: ";
    string line;
    if(!std::getline(cin, line))
    return 0;

    for(char &c : line)
    if(c == ',')
   { c = '';
    return 0;
   }
    stringstream ss(line);
    double x_1, y_1, x_2, y_2, x_3, y_3;
    if(!(ss >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3))
    {
        if(!(cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3))
        return 0;
    }
    auto dist = [](double ax, double ay, double bx, double by)
    {
        return hypot(ax - bx, ay - by);
    };
    double side_1 = dist(x_1, y_1, x_2, y_2);
    double side_2 = dist(x_2, y_2, x_3, y_3);
    double side_3 = dist(x_3, y_3, x_1, y_1);

    double s = (side_1 + side_2 + side_3) / 2.0;
    double val = s * (s - side_1) *  (s - side_2) * (s - side_3);
    double area = 0.0;
    if(val > 0)
    area = sqrt(val);

    cout.setf(ios::fixed);
    cout << setprecision(1);
    cout << "The area of the triangle is " << area << endl;
    return 0;

}