#include <iostream>

class Figure
{
protected:
	size_t sides{};
public:
	Figure() = default;
	Figure(size_t s) :sides{ s } {};
	const void getDataFigure( const Figure* obj) { std::cout << obj->sides << std::endl; }
};

class triangle :public Figure
{
private:
	std::string type = "Triangle";
public:
	triangle() : Figure{ 3 } {};
	void getData() { std::cout << type << ": "; getDataFigure(this); }
};

class quadrangle :public Figure
{
private:
	std::string type = "Quadrangle";
public:
	quadrangle() : Figure{ 4 } {};
	void getData() { std::cout << type << ": "; getDataFigure(this); }
};

class any :public Figure
{
private:
	std::string type = "Any";
public:
	any() : Figure{ 0 } {};
	void getData() { std::cout << type << ": "; getDataFigure(this); }
};

int main()
{
	triangle t1;
	quadrangle q1;
	any a1;
	std::cout << "Num sides: " << std::endl;
	t1.getData();
	q1.getData();
	a1.getData();

	return EXIT_SUCCESS;
}