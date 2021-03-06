#include "QImageWriter.hpp"
#include "../thread.hpp"

#include "../Qt5Core/QIODevice.hpp"
#include "../Qt5Core/QString.hpp"
#include "QImageIOHandler.hpp"
#include "../Qt5Core/QByteArray.hpp"
#include "../Qt5Core/QList.hpp"
#include "QImage.hpp"

void lua::QImageWriter_metatable(lua_State* const state, const int pos)
{
    lua::index mt(state, pos);
    mt["canWrite"] = &QImageWriter::canWrite;
    mt["compression"] = &QImageWriter::compression;
    mt["device"] = &QImageWriter::device;
    mt["error"] = &QImageWriter::error;
    mt["errorString"] = &QImageWriter::errorString;
    mt["fileName"] = &QImageWriter::fileName;
    mt["format"] = &QImageWriter::format;
    mt["gamma"] = &QImageWriter::gamma;
    mt["quality"] = &QImageWriter::quality;
    mt["setCompression"] = &QImageWriter::setCompression;
    mt["setDevice"] = &QImageWriter::setDevice;
    mt["setFileName"] = &QImageWriter::setFileName;
    mt["setFormat"] = &QImageWriter::setFormat;
    mt["setGamma"] = &QImageWriter::setGamma;
    mt["setQuality"] = &QImageWriter::setQuality;
    mt["setText"] = &QImageWriter::setText;
    mt["supportsOption"] = &QImageWriter::supportsOption;
    mt["write"] = &QImageWriter::write;
}

int QImageWriter_new(lua_State* const state)
{
    // QImageWriter()
    // QImageWriter(QIODevice * device, const QByteArray & format)
    // QImageWriter(const QString & fileName, const QByteArray & format = QByteArray())
    lua::make<QImageWriter>(state);
    // TODO Set up object-specific methods

    return 1;
}

int luaopen_Qt5Gui_QImageWriter(lua_State* const state)
{
    lua::thread env(state);

    env["QImageWriter"] = lua::value::table;
    env["QImageWriter"]["new"] = QImageWriter_new;
    auto t = env["QImageWriter"];

    // enum QImageWriter::ImageWriterError
    t["DeviceError"] = QImageWriter::DeviceError;
    t["UnsupportedFormatError"] = QImageWriter::UnsupportedFormatError;
    t["UnknownError"] = QImageWriter::UnknownError;

    t["supportedImageFormats"] = QImageWriter::supportedImageFormats;
    t["supportedMimeTypes"] = QImageWriter::supportedMimeTypes;

    return 0;
}
