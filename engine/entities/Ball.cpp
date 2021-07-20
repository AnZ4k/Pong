#include "Ball.h"
#include <SDL/SDL_opengl.h>


Ball::Ball ( int _x, int _y, int _width, int _height )
{
    this->x = _x;
    this->y = _y;
    this->width = _width;
    this->height = _height;
}

void Ball::set_Spd ( int new_Spd_X, int new_Spd_Y )
{
    this->spd_X = new_Spd_X;
    this->spd_Y = new_Spd_Y;
}

void Ball::drawn ( void )
{
    glColor3f ( .0f, 1.0f, .0f );

    glBegin ( GL_QUADS );
    glVertex2i ( this->x, this->y );
    glVertex2i ( this->x + this->width, this->y );
    glVertex2i ( this->x + this->width, this->y + this->height );
    glVertex2i ( this->x, this->y + this->height );
    glEnd ( );
}

void Ball::move ( int window_Height, Player *p1, Player *p2 )
{
    if ( this->y + this->height > window_Height || this->y < 0 )
    {
        this->set_Spd ( this->spd_X, -this->spd_Y );
    }

    if ( this->x <= p1->get_X ( ) + p1->get_Width ( ) && this->y < p1->get_Y ( ) + p1->get_Height ( ) && this->y > p1->get_Y ( ) )
    {
        this->set_Spd ( -this->spd_X, this->spd_Y );
    }

    if ( this->x + this->width >= p2->get_X ( ) && this->y > p2->get_Y ( ) && this->y < p2->get_Y ( ) + p2->get_Height ( ) )
    {
        this->set_Spd( -this->spd_X, this->spd_Y );
    }

    this->x += this->spd_X;
    this->y += this->spd_Y;
}