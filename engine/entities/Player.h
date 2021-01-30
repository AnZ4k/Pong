class Player
{
public:
    Player(int _x, int _y, int _width, int _height);
    int get_X(void);
    int get_Y(void);
    void set_Y(int new_Y);
    int get_Height(void);
    int get_Width(void);
    void drawn(void);

private:
    int x, y, width, height, spd;
};