#include "../ncurses.hpp"
#include "../lua-cxx/thread.hpp"

// http://invisible-island.net/ncurses/man/keyok.3x.html

void lua::ncurses_keyok(lua_State* const state)
{
    lua::thread env(state);

    env["keyok"] = keyok;
}
