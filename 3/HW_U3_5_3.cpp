#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "Quadrangle.h"


//++++++++++++++++++++++++++++++++++++++++++Triangle+++++++++++++++++++++++++++++++++++++++++//

class right_triangle : public triangle
{
public:
	right_triangle(double a_, double b_, double c_, double an_a, double an_b, double an_c = 90) : triangle{ a_, b_, c_, an_a, an_b, an_c, "Right triangle:" } {};
	void Check()
	{
		bool buf_check = (angle_a == 90 || angle_b == 90 || angle_c == 90);
		if ((angle_a + angle_b + angle_c) == 180 && sides == 3 && buf_check) str_Check = "Right";
		else str_Check = "Wrong";
	}
};

class isosceles_triangle : public triangle
{
public:
	isosceles_triangle(double a_, double b_, double c_, double an_a, double an_b, double an_c) :triangle{ a_, b_, c_, an_a, an_b, an_c, "Isosceles triangle:" } {};
	void Check()
	{
		bool buf_check = (a == b || a == c || b == c) && (angle_a == angle_b || angle_a == angle_c || angle_b == angle_c);
		if ((angle_a + angle_b + angle_c) == 180 && sides == 3 && buf_check) str_Check = "Right";
		else str_Check = "Wrong";
	}
};

class equilateral_triangle : public triangle
{
public:

	equilateral_triangle(double a_, double b_, double c_, double an_a, double an_b, double an_c) :triangle{ a_, b_, c_, an_a, an_b, an_c, "Equilateral triangle: " } {};

	void Check()
	{
		bool buf_check = (a == b && a == c) && (angle_a == angle_b && angle_a == angle_c && angle_a==60);
		if ((angle_a + angle_b + angle_c) == 180 && sides == 3 && buf_check) str_Check = "Right";
		else str_Check = "Wrong";
	}
};


//++++++++++++++++++++++++++++++++++++++++++Quadrangle+++++++++++++++++++++++++++++++++++++++++//


class rectangle :public quadrangle
{

public:

	rectangle (double a_, double b_, double c_, double d_, double an_a, double an_b, double an_c, double an_d) : quadrangle { a_, b_, c_, d_, an_a, an_b, an_c, an_d, "Rectangle: " } {};

	void Check()
	{
		bool buf_check = (a == c && b==d) && (angle_a == angle_c && angle_b == angle_d);
		if ((angle_a + angle_b + angle_c + angle_d) == 360 && sides == 4 && buf_check) str_Check = "Right";
		else str_Check = "Wrong";
	}
};

class square :public quadrangle
{
public:

	square(double a_, double b_, double c_, double d_, double an_a, double an_b, double an_c, double an_d) : quadrangle{ a_, b_, c_, d_, an_a, an_b, an_c, an_d, "Square: " } {};

	void Check()
	{
		bool buf_check = (a == b && a == c && c == d) && (angle_a == 90 && angle_b == 90 && angle_c == 90 && angle_d==90);
		if ((angle_a + angle_b + angle_c + angle_d) == 360 && sides == 4 && buf_check) str_Check = "Right";
		else str_Check = "Wrong";
	}
};

class parallelogramme :public quadrangle
{
public:
	parallelogramme(double a_, double b_, double c_, double d_, double an_a, double an_b, double an_c, double an_d) : quadrangle{ a_, b_, c_, d_, an_a, an_b, an_c, an_d, "Parallelogramme: " } {};

	void Check()
	{
		bool buf_check = (a == c && b == d) && (angle_a == angle_c && angle_b == angle_d);
		if ((angle_a + angle_b + angle_c + angle_d) == 360 && sides == 4 && buf_check) str_Check = "Right";
		else str_Check = "Wrong";
	}
};

class rhombus :public quadrangle
{
public:
	rhombus(double a_, double b_, double c_, double d_, double an_a, double an_b, double an_c, double an_d) : quadrangle{ a_, b_, c_, d_, an_a, an_b, an_c, an_d, "Rhombus: " } {};

	void Check()
	{
		bool buf_check = (a == c && b == d && c==d) && (angle_a == angle_c && angle_b == angle_d);
		if ((angle_a + angle_b + angle_c+angle_d) == 360 && sides == 4 && buf_check) str_Check = "Right";
		else str_Check = "Wrong";
	}

};


class any :public Figure
{
private:
	std::string type = "Any: ";
public:
	any() : Figure{ 0 } {};
};


int main()
{
	Figure* obj[10] = {nullptr};
	
	triangle t1{ 10, 20, 30, 60, 70, 50, "triangle"};
	right_triangle t_r1{ 10, 20, 30, 45, 45 };
	isosceles_triangle t_i1{ 10, 20, 20, 50, 80, 50 };
	equilateral_triangle t_e1{ 10, 10, 10, 60, 60, 60 };

	quadrangle q1{ 10, 20, 30, 40, 50, 60, 70, 80, "quadrangle" };
	rectangle q_r{ 10, 20, 30, 40, 90, 90, 90, 90 };
	square q_s{ 20, 20, 20, 20, 90, 90, 90, 90 };
	parallelogramme q_p{ 10, 20, 10, 20, 45, 95, 45, 95 };
	rhombus q_rh{ 10, 10, 10, 10, 80, 100, 80, 100 };
	
	obj[0] = &t1;
	obj[1] = &t_r1;
	obj[2] = &t_i1;
	obj[3] = &t_e1;
	obj[4] = &q1;
	obj[5] = &q_r;
	obj[6] = &q_s;
	obj[7] = &q_p;
	obj[8] = &q_rh;

	for (int i = 0; i < 9; ++i)
	{
		obj[i]->getDataFigure();
	}

	return EXIT_SUCCESS;
}