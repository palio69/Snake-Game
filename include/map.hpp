#pragma once



#include <string>



class map {
private:
	std::string lvl;
	int w, h;

public:
	map() :
		lvl(""), w(12), h(7) {
		this->lvl += "............";
		this->lvl += "............";
		this->lvl += "............";
		this->lvl += "............";
		this->lvl += "............";
		this->lvl += "............";
		this->lvl += "............";
	}
	~map() { }

	std::string get_lvl() const { return this->lvl; }
	int get_w() const { return this->w; }
	int get_h() const { return this->h; }

};