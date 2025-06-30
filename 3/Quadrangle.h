#ifndef QUADRANGLE_H
#define QUADRANGLE_H

//#include <iostream>;

class quadrangle :public Figure
{
protected:
	double a{}, b{}, c{}, d{};
	double angle_a{}, angle_b{}, angle_c{}, angle_d{};
	std::string type = "Quadrangle: ";
	std::string str_Check{};
public:
	quadrangle(double a_, double b_, double c_, double d_, double an_a, double an_b, double an_c, double an_d, std::string type_= "Quadrangle: ");

	virtual void Check();
	void getDataFigure();

	/*void getDataTypeQuadrangle() { std::cout << '\n' << type << std::endl; getDataQuadrangle(*this); }
	void getDataQuadrangle(quadrangle& obj)
	{
		std::cout << "Sides: " << "a= " << a << " b=" << b << " c=" << c << " d=" << d << \
			"\nAngle: " << "A= " << angle_a << " B=" << angle_b << " C=" << angle_c << " D=" << angle_d << std::endl;
	}*/
};


#endif
