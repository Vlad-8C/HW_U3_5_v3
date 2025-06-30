#include <iostream>

#include "Figure.h"
#include "Quadrangle.h"

quadrangle::quadrangle(double a_, double b_, double c_, double d_, double an_a, double an_b, double an_c, double an_d, std::string type_) :Figure{ 4 }, a{ a_ }, b{ b_ }, c{ c_ }, d{ d_ }, \
angle_a{ an_a }, angle_b{ an_b }, angle_c{ an_c }, angle_d{ an_d }, type{type_}{};

void quadrangle::Check()
{
	if ((angle_a + angle_b + angle_c + angle_d) == 360 && sides == 4) str_Check = "Right";
	else str_Check = "Wrong";
}

void quadrangle::getDataFigure()
{
	Check();
	std::cout << "Name figure: " << type << "\nQuantity sides: " << sides << "\nSides: a= " << a << " b= " << b << " c= " << c << " d= " << d << \
		"\nAngls: A= " << angle_a << " B= " << angle_b << " C= " << angle_c << " D= " << angle_d << "\nCheck parametrs: " << str_Check << std::endl << "--------------------------------" << std::endl;
}