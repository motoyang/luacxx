#ifndef LUA_CXX_QOBJECT_HEADER
#define LUA_CXX_QOBJECT_HEADER

#include <QObject>

#include "../lua-cxx/stack.hpp"
#include "../lua-cxx/algorithm.hpp"
#include "../lua-cxx/type/standard.hpp"

namespace lua {

void QObject_metatable(const lua::index& mt);

template <>
struct Metatable<QObject>
{
    static constexpr const char* name = "QObject";

    static bool metatable(const lua::index& mt, const QObject* const)
    {
        lua::QObject_metatable(mt);
        return true;
    }
};

void qmetamethod_metatable(const lua::index& mt);

template <>
struct Metatable<QMetaMethod>
{
    static constexpr const char* name = "QMetaMethod";

    static bool metatable(const lua::index& mt, const QMetaMethod* const)
    {
        lua::qmetamethod_metatable(mt);
        return true;
    }
};

} // namespace lua

#endif // LUA_CXX_QOBJECT_HEADER
