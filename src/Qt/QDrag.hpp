#ifndef LUA_CXX_QDRAG_INCLUDED
#define LUA_CXX_QDRAG_INCLUDED

#include "../lua-cxx/stack.hpp"

class QDrag;

namespace lua {

void QDrag_metatable(const lua::index& mt);

template <>
struct Metatable<QDrag>
{
    static constexpr const char* name = "QDrag";

    static bool metatable(const lua::index& mt, QDrag* const)
    {
        lua::QDrag_metatable(mt);
        return true;
    }
};

}; // namespace lua

extern "C" int luaopen_luacxx_QDrag(lua_State* const);

#endif // LUA_CXX_QDRAG_INCLUDED
