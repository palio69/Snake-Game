#pragma once



#include <ctime>
#include <string>
#include <utility>
#include <vec2f.hpp>



class map {
private:
	std::string lvl;
	int w, h, tw, th;
	std::pair<int, int> f;

public:
	map(const int w, const int h, const int tw, const int th) :
		lvl(""), w(w), h(h), tw(tw), th(th), f(std::make_pair(0, 0)) {

		for (int i = this->w * this->h; i > 0; --i)
			lvl += '.';

		this->f.first = std::rand() % this->w;
		this->f.second = std::rand() % this->h;

		this->lvl[this->f.second * this->w + this->f.first] = 'O';

	}
	~map() { }

	std::string get_lvl() const { return this->lvl; }
	int get_w() const { return this->w; }
	int get_h() const { return this->h; }
	int get_tw() const { return this->tw; }
	int get_th() const { return this->th; }

	void set_lvl(const std::string lvl) { this->lvl = lvl; }

	void new_fruit(const vec2f xy);

};