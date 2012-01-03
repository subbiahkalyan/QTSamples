/****************************************************************************
** Meta object code from reading C++ file 'downloader.h'
**
** Created: Mon Jan 2 11:37:39 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WebFTPClient/downloader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Downloader[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   20,   12,   11, 0x0a,
      53,   45,   11,   11, 0x0a,
      90,   84,   11,   11, 0x0a,
     115,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Downloader[] = {
    "Downloader\0\0QString\0url\0chooseSaveFile(QUrl)\0"
    "request\0startDownload(QNetworkRequest)\0"
    "reply\0saveFile(QNetworkReply*)\0"
    "finishDownload()\0"
};

const QMetaObject Downloader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Downloader,
      qt_meta_data_Downloader, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Downloader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Downloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Downloader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Downloader))
        return static_cast<void*>(const_cast< Downloader*>(this));
    return QObject::qt_metacast(_clname);
}

int Downloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = chooseSaveFile((*reinterpret_cast< const QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: startDownload((*reinterpret_cast< const QNetworkRequest(*)>(_a[1]))); break;
        case 2: saveFile((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: finishDownload(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
