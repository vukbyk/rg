#ifndef FLOORGRID_H
#define FLOORGRID_H

class floorGrid
{
private:
    int span;
    float r, g, b;
public:
    floorGrid();
    floorGrid(int s, float rr, float gg, float bb);
    floorGrid(float rr, float gg, float bb);

    void put();
};
#endif // FLOORGRID_H
