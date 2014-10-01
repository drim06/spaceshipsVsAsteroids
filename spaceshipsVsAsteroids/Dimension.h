#pragma once
class Dimension
{
private:
	int windowsWidth_;
	int windowsHeight_;
	int spaceTop_;
	int spaceBottom_;

public:
	Dimension(int windowsWidth, int windowsHeight) :
		windowsWidth_(windowsWidth),
		windowsHeight_(windowsHeight),
		spaceTop_(windowsWidth/5.f),
		spaceBottom_(windowsWidth/10.f)
	{}

	inline int getWindowsWidth() const{
		return windowsWidth_;
	}

	inline int getWindowsHeight() const{
		return windowsHeight_;
	}

	inline int getSpaceTop() const{
		return spaceTop_;
	}

	inline int getSpaceBottom() const{
		return spaceBottom_;
	}
};

