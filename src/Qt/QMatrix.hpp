#ifndef LUA_CXX_QMATRIX_INCLUDED
#define LUA_CXX_QMATRIX_INCLUDED

#include "../lua-cxx/stack.hpp"

class QMatrix;

namespace lua {

void QMatrix_metatable(const lua::index& mt);

template <>
struct Metatable<QMatrix>
{
    static constexpr const char* name = "QMatrix";

    static bool metatable(const lua::index& mt, QMatrix* const)
    {
        lua::QMatrix_metatable(mt);
        return true;
    }
};

}; // namespace lua

extern "C" int luaopen_luacxx_QMatrix(lua_State* const);

#endif // LUA_CXX_QMATRIX_INCLUDED
