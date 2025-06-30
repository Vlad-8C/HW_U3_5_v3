#ifndef TRIANGLE_H
#define TRIANGLE_H

class triangle :public Figure
{
protected:
	double a{}, b{}, c{};
	double angle_a{}, angle_b{}, angle_c{};
	std::string type = "Triangle:";
	std::string str_Check{};
public:
	triangle(double a_, double b_, double c_, double an_a, double an_b, double an_c, std::string type_);
	
	virtual void Check();
	void getDataFigure () override;
};





#endif // !TRIANGLE_H

