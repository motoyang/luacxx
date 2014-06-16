#include "QVector4D.hpp"
#include "../type/function.hpp"
#include "../thread.hpp"

#include <QVector4D>

void lua::QVector4D_metatable(const lua::index& mt)
{
    // TODO Set up metatable methods for this class
}

int QVector4D_new(lua::state* const state)
{
    lua::make<QVector4D>(state);
    // TODO Set up object-specific methods

    return 1;
}

int luaopen_luacxx_QVector4D(lua::state* const state)
{
    lua::thread env(state);

    env["QVector4D"] = lua::value::table;
    env["QVector4D"]["new"] = QVector4D_new;

    return 0;
}