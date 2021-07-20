#include "Player.h"

class Ball
{
public:
    Ball ( int _x, int _y, int _width, int _height );
    void set_Spd ( int new_Spd_X, int new_Spd_Y );
    void drawn ( void );
    void move ( int _height, Player *p1, Player *p2 );

private:
    int x, y, width, height, spd_X, spd_Y;
};