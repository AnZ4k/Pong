#include "engine/Game.h"
#include "engine/entities/Ball.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <chrono>
#include <thread>

using namespace std::chrono;

void tick(Game *game, Player *p1, Player *p2);
void render(Game *game, Player *p1, Player *p2, Ball *ball);
void run(Game *game, Player *p1, Player *p2, Ball *ball);

int main()
{
    const char *name = "Pong";
    Game game(8, 8, 8, 8, 32, 16, 1);
    game.init(name, NULL, 600, 400);

    Player p1(20, (int)(game.get_Height() / 2) - 40, 10, 80);
    Player p2((int)game.get_Width() - 40, (int)(game.get_Height() / 2) - 40, 10, 80);

    Ball ball((game.get_Width() / 2) - 4, (game.get_Height() / 2) - 5, 8, 10);
    ball.set_Spd(4, 2);

    run(&game, &p1, &p2, &ball);

    game.quit();

    return 0;
}

void tick(Game *game, Player *p1, Player *p2)
{
    SDL_Event events;

    if (SDL_PollEvent(&events))
    {
        if (events.type == SDL_QUIT)
            game->set_Loop(false);

        if (events.type == SDL_KEYDOWN)
        {
            if (events.key.keysym.sym == SDLK_ESCAPE)
                game->set_Loop(false);

            if (events.key.keysym.sym == SDLK_UP && p2->get_Y() >= 0)
                p2->set_Y(p2->get_Y() - 20);

            else if (events.key.keysym.sym == SDLK_DOWN && p2->get_Y() + p2->get_Height() < game->get_Height())
                p2->set_Y(p2->get_Y() + 20);

            if (events.key.keysym.sym == SDLK_w && p1->get_Y() >= 0)
                p1->set_Y(p1->get_Y() - 20);

            else if (events.key.keysym.sym == SDLK_s && p1->get_Y() + p1->get_Height() < game->get_Height())
                p1->set_Y(p1->get_Y() + 20);
        }
    }
}

void render(Game *game, Player *p1, Player *p2, Ball *ball)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glOrtho(0, game->get_Width(), game->get_Height(), 0, -1, 1);
    p1->drawn();
    p2->drawn();
    ball->drawn();
    glPopMatrix();
    SDL_GL_SwapBuffers();
}

void run(Game *game, Player *p1, Player *p2, Ball *ball)
{
    time_point<system_clock> time = system_clock::now();

    while (game->get_Loop())
    {
        tick(game, p1, p2);
        render(game, p1, p2, ball);
        ball->move(game->get_Height(), p1, p2);

        time += milliseconds(22);
        std::this_thread::sleep_until(time);
    }
}
