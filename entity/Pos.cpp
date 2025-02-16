//
// Created by julian on 3/25/24.
//

#include "Pos.h"
#include <math.h>

Pos::Pos(int x, int y) : x(x), y(y) {}

int Pos::getX() const {
    return x;
}
int Pos::getY() const {
    return y;
}
void Pos::setX(int x) {
    Pos::x = x;
}
void Pos::setY(int y) {
    Pos::y = y;
}
void Pos::setPos(int x, int y) {
    Pos::x = x;
    Pos::y = y;
}
bool Pos::operator==(const Pos &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

Pos::Pos() : x(0), y(0){}

bool Pos::isNeighbor(const Pos &pos) const {
    int dx = std::abs(pos.x - x);
    int dy = std::abs(pos.y - y);
    return (dx == 1 && dy == 0) ||( dx == 0 && dy == 1);
}

std::vector<Pos> Pos::getNeighbors(int w, int h) const {
    return {
        Pos(x+1, y).normalize(w,h),
        Pos(x-1, y).normalize(w,h),
        Pos(x, y+1).normalize(w,h),
        Pos(x, y-1).normalize(w,h)
    };
}

void Pos::getNeighbors(std::vector<Pos> &positions,int w, int h) const {
    positions.push_back(Pos(x+1, y).normalize(w,h));
    positions.push_back(Pos(x-1, y).normalize(w,h));
    positions.push_back(Pos(x, y+1).normalize(w,h));
    positions.push_back(Pos(x, y-1).normalize(w,h));
}

Pos &Pos::normalize(int w, int h) {
    x = std::abs(x) % w;
    y = std::abs(y) % h;
    return *this;
}

