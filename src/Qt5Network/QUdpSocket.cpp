#include "QUdpSocket.hpp"
#include "../thread.hpp"
#include "QHostAddress.hpp"
#include "QNetworkInterface.hpp"
#include "QAbstractSocket.hpp"

int QUdpSocket_joinMulticastGroup(lua_State* const state)
{
    return 0;
}
int QUdpSocket_leaveMulticastGroup(lua_State* const state)
{
    return 0;
}
int QUdpSocket_readDatagram(lua_State* const state)
{
    return 0;
}
int QUdpSocket_writeDatagram(lua_State* const state)
{
    return 0;
}

void lua::QUdpSocket_metatable(lua_State* const state, const int pos)
{
    lua::QAbstractSocket_metatable(state, pos);

    lua::index mt(state, pos);
    mt["hasPendingDatagrams"] = &QUdpSocket::hasPendingDatagrams;
    mt["joinMulticastGroup"] = QUdpSocket_joinMulticastGroup;
    mt["leaveMulticastGroup"] = QUdpSocket_leaveMulticastGroup;
    mt["multicastInterface"] = &QUdpSocket::multicastInterface;
    mt["pendingDatagramSize"] = &QUdpSocket::pendingDatagramSize;
    mt["readDatagram"] = QUdpSocket_readDatagram;
    mt["setMulticastInterface"] = &QUdpSocket::setMulticastInterface;
    mt["writeDatagram"] = QUdpSocket_writeDatagram;
}

int QUdpSocket_new(lua_State* const state)
{
    lua::make<QUdpSocket>(state);
    // TODO Set up object-specific methods

    return 1;
}

int luaopen_luacxx_QUdpSocket(lua_State* const state)
{
    lua::thread env(state);

    env["QUdpSocket"] = lua::value::table;
    env["QUdpSocket"]["new"] = QUdpSocket_new;
    auto t = env["QUdpSocket"];

    return 0;
}
