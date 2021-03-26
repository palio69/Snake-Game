#pragma once



#include <string>



class map {
private:
	std::string lvl;
	int w, h, tw, th;

public:
	map() :
		lvl(""), w(12), h(7), tw(64), th(64) {
		this->lvl += "............";
		this->lvl += "..........O.";
		this->lvl += "............";
		this->lvl += "..........A.";
		this->lvl += "..........|.";
		this->lvl += "..........Q.";
		this->lvl += "............";
	}
	~map() { }

	std::string get_lvl() const { return this->lvl; }
	int get_w() const { return this->w; }
	int get_h() const { return this->h; }
	int get_tw() const { return this->tw; }
	int get_th() const { return this->th; }

};