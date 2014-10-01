#pragma once
class Fenetre
{
private:
	int windowsWidth_;
	int windowsHeight_;

public:
	Fenetre(int windowsWidth, int windowsHeight) :
		windowsWidth_(windowsWidth),
		windowsHeight_(windowsHeight)
	{}

	inline int getWindowsWidth(){
		return windowsWidth_;
	}

	inline int getWindowsHeight(){
		return windowsHeight_;
	}
};

