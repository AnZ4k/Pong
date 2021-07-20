class Game
{
public:
    Game ( int r_Size, int g_Size, int b_Size, int a_Size, int buffer_Size, int depth_Size, int double_Buffer );
    void init ( const char* title, char* icon, int width, int height );
    void set_Loop ( bool new_State );
    bool get_Loop ( void );
    int get_Width ( void );
    int get_Height ( void );
    void quit ( void );

private:
    int width, height;
    bool loop = true;
};