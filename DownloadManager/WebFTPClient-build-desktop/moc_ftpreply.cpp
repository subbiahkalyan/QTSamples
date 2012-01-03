/****************************************************************************
** Meta object code from reading C++ file 'ftpreply.h'
**
** Created: Mon Jan 2 11:37:39 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WebFTPClient/ftpreply.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftpreply.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FtpReply[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   10,    9,    9, 0x08,
      57,   49,    9,    9, 0x08,
      83,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FtpReply[] = {
    "FtpReply\0\0command,error\0"
    "processCommand(int,bool)\0urlInfo\0"
    "processListInfo(QUrlInfo)\0processData()\0"
};

const QMetaObject FtpReply::staticMetaObject = {
    { &QNetworkReply::staticMetaObject, qt_meta_stringdata_FtpReply,
      qt_meta_data_FtpReply, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FtpReply::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FtpReply::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FtpReply::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FtpReply))
        return static_cast<void*>(const_cast< FtpReply*>(this));
    return QNetworkReply::qt_metacast(_clname);
}

int FtpReply::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkReply::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: processCommand((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: processListInfo((*reinterpret_cast< const QUrlInfo(*)>(_a[1]))); break;
        case 2: processData(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
