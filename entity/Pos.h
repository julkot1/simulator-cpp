//
// Created by julian on 3/25/24.
//

#ifndef SIM_CPP_POS_H
#define SIM_CPP_POS_H
#include <vector>

class Pos {
private:
    int x, y;
public:
    Pos(int x, int y);
    Pos();
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void setPos(int x, int y);
    bool isNeighbor(const Pos& pos) const;
    std::vector<Pos> getNeighbors(int w, int h) const;
    void getNeighbors(std::vector<Pos> &positions,int w, int h) const;
    Pos& normalize(int w, int h);
    bool operator==(const Pos &rhs) const;
};


#endif //SIM_CPP_POS_H
