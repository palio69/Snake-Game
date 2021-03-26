#pragma once



#include <string>



class map {
private:
	std::string lvl;
	int w, h;

public:
	map() { }
	~map() { }

	std::string get_lvl() const { return this->lvl; }
	int get_w() const { return this->w; }
	int get_h() const { return this->h; }

};