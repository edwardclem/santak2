/****************************************************************************
** Meta object code from reading C++ file 'SantakWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SantakWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SantakWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SantakWindow_t {
    QByteArrayData data[5];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SantakWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SantakWindow_t qt_meta_stringdata_SantakWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SantakWindow"
QT_MOC_LITERAL(1, 13, 9), // "slotClear"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "slotSearch"
QT_MOC_LITERAL(4, 35, 16) // "slotSwitchSymbol"

    },
    "SantakWindow\0slotClear\0\0slotSearch\0"
    "slotSwitchSymbol"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SantakWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SantakWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SantakWindow *_t = static_cast<SantakWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotClear(); break;
        case 1: _t->slotSearch(); break;
        case 2: _t->slotSwitchSymbol(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SantakWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SantakWindow.data,
      qt_meta_data_SantakWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SantakWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SantakWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SantakWindow.stringdata0))
        return static_cast<void*>(const_cast< SantakWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SantakWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
