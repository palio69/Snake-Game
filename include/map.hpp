#pragma once



#include <ctime>
#include <string>



class map {
private:
	std::string lvl;
	int w, h, tw, th;

public:
	map(const int w, const int h, const int tw, const int th) :
		lvl(""), w(w), h(h), tw(tw), th(th) {

		for (int i = this->w * this->h; i > 0; --i)
			lvl += '.';

		this->lvl[std::rand() % this->lvl.size()] = 'O';

	}
	~map() { }

	std::string get_lvl() const { return this->lvl; }
	int get_w() const { return this->w; }
	int get_h() const { return this->h; }
	int get_tw() const { return this->tw; }
	int get_th() const { return this->th; }

	void set_lvl(const std::string lvl) { this->lvl = lvl; }

};