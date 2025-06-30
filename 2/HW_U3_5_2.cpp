#include <iostream>
#include <vector>

class Figure
{
protected:
	size_t sides{};
public:
	Figure() = default;
	Figure(size_t s) :sides{ s } {};
	const void getDataFigure(std::string str ,const Figure* obj) { std::cout << str<<": "<< obj->sides << std::endl; }
};

class triangle :public Figure
{
private:
	double a{}, b{}, c{};
	double angle_a{}, angle_b{}, angle_c{};
	std::string type = "Triangle:";
public:
	//triangle() : Figure{ 3 } {};
	triangle(double a_, double b_, double c_, double an_a, double an_b, double an_c) :Figure{ 3 }, a{ a_ }, b{ b_ }, c{ c_ }, \
		angle_a{ an_a }, angle_b{ an_b }, angle_c{ an_c }{};
	void getDataTypeTriangle() { std::cout << '\n' << type << std::endl; getDataTriangle(*this); }
	void getDataTriangle(const triangle& obj)
	{
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << "\nAngle: " << "A= " << angle_a << " B=" << angle_b << " C=" << angle_c << std::endl;
	}
};

class right_triangle : public triangle
{
private:
	std::string type = "Right triangle:";
public:
	right_triangle(double a_, double b_, double c_, double an_a, double an_b) :triangle{ a_, b_, c_, an_a, an_b, 90 } {};
	void getDataTypeTriangle() { std::cout << '\n' << type << std::endl; getDataTriangle(*this); }
};

class isosceles_triangle : public triangle
{
private:
	std::string type = "Isosceles triangle:";
public:
	isosceles_triangle(double a_, double c_, double an_a, double an_b, double an_c) :triangle{ a_, a_, c_, an_a, an_b, an_c } {};
	void getDataTypeTriangle() { std::cout << '\n' << type << std::endl; getDataTriangle(*this); }
};

class equilateral_triangle : public triangle
{
private:
	std::string type = "Equilateral triangle: ";
public:
	equilateral_triangle(double a_) :triangle{ a_, a_, a_, 60, 60, 60 } {};
	void getDataTypeTriangle() { std::cout << '\n' << type << std::endl; getDataTriangle(*this); }
};


class quadrangle :public Figure
{
protected:
	double a{}, b{}, c{}, d{};
	double angle_a{}, angle_b{}, angle_c{}, angle_d{};
	std::string type = "Quadrangle: ";
public:
	quadrangle(double a_, double b_, double c_, double d_, double an_a, double an_b, double an_c, double an_d) :Figure{ 4 }, a{ a_ }, b{ b_ }, c{ c_ }, d{ d_ }, \
		angle_a{ an_a }, angle_b{ an_b }, angle_c{ an_c }, angle_d{ an_d }{};
	void getDataTypeQuadrangle() { std::cout << '\n' << type << std::endl; getDataQuadrangle(*this); }
	void getDataQuadrangle(quadrangle& obj)
	{
		std::cout << "Sides: " << "a= " << a << " b=" << b << " c=" << c << " d=" << d <<\
			"\nAngle: " << "A= " << angle_a << " B=" << angle_b << " C=" << angle_c << " D=" << angle_d << std::endl;
	}
};

class rectangle :public quadrangle
{
private:
	std::string type = "Rectangle: ";
public:
	rectangle(double a_, double b_) :quadrangle{ a_, b_, a_, b_, 90, 90, 90, 90 } {};
	void getDataTypeQuadrangle() { std::cout << '\n' << type << std::endl; getDataQuadrangle(*this); }
};

class square :public quadrangle
{
private:
	std::string type = "Square: ";
public:
	square(double a_) :quadrangle{ a_, a_, a_, a_, 90, 90, 90, 90 } {};
	void getDataTypeQuadrangle() { std::cout << '\n' << type << std::endl; getDataQuadrangle(*this); }
};

class parallelogramme :public quadrangle
{
private:
	std::string type = "Parallelogramme: ";
public:
	parallelogramme(double a_, double b_, double an_a, double an_b) :quadrangle{ a_, b_, a_, b_, an_a, an_b, an_a, an_b } {};
	void getDataTypeQuadrangle() { std::cout << '\n' << type << std::endl; getDataQuadrangle(*this); }
};

class rhombus :public quadrangle
{
private:
	std::string type = "Rhombus: ";
public:
	rhombus(double a_, double an_a, double an_b) :quadrangle{ a_, a_, a_, a_, an_a, an_b, an_a, an_b } {};
	void getDataTypeQuadrangle() { std::cout << '\n' << type << std::endl; getDataQuadrangle(*this); }
};


class any :public Figure
{
private:
	std::string type = "Any: ";
public:
	any() : Figure{ 0 } {};
	//void getData() { std::cout << type << ": "; getDataFigure(this); }
};

int main()
{
	triangle t1{10, 20, 30, 60, 70, 110};
	right_triangle t_r1{ 10, 20, 30, 45, 45 };
	isosceles_triangle t_i1{ 10, 20, 60, 50, 70 };
	equilateral_triangle t_e1{ 10 };

	quadrangle q1{10, 20, 30, 40, 50, 60, 70, 80};
	rectangle q_r{ 10, 20 };
	square q_s{ 20 };
	parallelogramme q_p{ 10, 20, 45, 95 };
	rhombus q_rh{ 10, 80, 100 };

	any a1;

	//+++++++++++++++++++++++/_\+++++++++++++++++++++//
	t1.getDataTypeTriangle();
	
	t_r1.getDataTypeTriangle();;
	t_i1.getDataTypeTriangle();
	t_e1.getDataTypeTriangle();

	//+++++++++++++++++++++++|_|+++++++++++++++++++++//
	q1.getDataTypeQuadrangle();
	
	q_r.getDataTypeQuadrangle();
	q_s.getDataTypeQuadrangle();
	q_p.getDataTypeQuadrangle();
	q_rh.getDataTypeQuadrangle();


	return EXIT_SUCCESS;
}