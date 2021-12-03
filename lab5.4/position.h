#pragma once
#ifndef Position
#define Position
class position
{
private:
	int x;
	int y;
public:
	position();
	position(int corx, int cory);
	~position();

	void change(int corx, int cory);
	int getx();
	int gety();
};
#endif

