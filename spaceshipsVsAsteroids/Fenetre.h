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

	inline int getWindowsWidth() const{
		return windowsWidth_;
	}

	inline int getWindowsHeight() const{
		return windowsHeight_;
	}
};

