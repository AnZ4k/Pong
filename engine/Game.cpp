#include "Game.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

Game::Game ( int r_Size, int g_Size, int b_Size, int a_Size, int buffer_Size, int depth_Size, int double_Buffer )
{
    SDL_Init ( SDL_INIT_EVERYTHING );

    SDL_GL_SetAttribute ( SDL_GL_RED_SIZE, r_Size );
    SDL_GL_SetAttribute ( SDL_GL_GREEN_SIZE, g_Size );
    SDL_GL_SetAttribute ( SDL_GL_BLUE_SIZE, b_Size );
    SDL_GL_SetAttribute ( SDL_GL_ALPHA_SIZE, a_Size );
    SDL_GL_SetAttribute ( SDL_GL_BUFFER_SIZE, buffer_Size );
    SDL_GL_SetAttribute ( SDL_GL_DEPTH_SIZE, depth_Size );
    SDL_GL_SetAttribute ( SDL_GL_DOUBLEBUFFER, double_Buffer );
}

void Game::init ( const char *title, char *icon, int _width, int _height )
{
    this->width = _width;
    this->height = _height;

    SDL_WM_SetCaption ( title, icon );
    SDL_SetVideoMode ( this->width, this->height, 32, SDL_OPENGL );
    glClearColor ( 0, 0, 0, 1 );
    glViewport ( 0, 0, this->width, this->height );
    glShadeModel ( GL_SMOOTH );
    glMatrixMode ( GL_PROJECTION );
    glLoadIdentity ( );
    glDisable ( GL_DEPTH_TEST );
}

void Game::set_Loop ( bool new_State )
{
    this->loop = new_State;
}

bool Game::get_Loop ( void )
{
    return this->loop;
}

int Game::get_Width ( void )
{
    return this->width;
}

int Game::get_Height ( void )
{
    return this->width;
}

void Game::quit ( )
{
    SDL_Quit ( );
}