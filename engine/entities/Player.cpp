#include "Player.h"
#include <SDL/SDL_opengl.h>

Player::Player ( int _x, int _y, int _width, int _height )
{
    this->x = _x;
    this->y = _y;
    this->width = _width;
    this->height = _height;
}

int Player::get_X ( )
{
    return this->x;
}

int Player::get_Y ( )
{
    return this->y;
}

void Player::set_Y ( int new_Y )
{
    this->y = new_Y;
}

int Player::get_Height ( void )
{
    return this->height;
}

int Player::get_Width ( void )
{
    return this->width;
}

void Player::drawn ( void )
{
    glColor3f ( 1.0f, .0f, .0f );
    glBegin ( GL_QUADS );
    glVertex2i ( this->get_X ( ), this->get_Y ( ) );
    glVertex2i ( this->get_X ( ) + this->width, this->get_Y ( ) );
    glVertex2i ( this->get_X ( ) + this->width, this->get_Y ( ) + this->height );
    glVertex2i ( this->get_X ( ), this->get_Y ( ) + this->height );
    glEnd ( );
}