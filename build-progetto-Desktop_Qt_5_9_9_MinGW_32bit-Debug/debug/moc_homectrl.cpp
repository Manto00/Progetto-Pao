/****************************************************************************
** Meta object code from reading C++ file 'homectrl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Filament3dPrint-master/ctrl/homectrl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'homectrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HomeCtrl_t {
    QByteArrayData data[5];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HomeCtrl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HomeCtrl_t qt_meta_stringdata_HomeCtrl = {
    {
QT_MOC_LITERAL(0, 0, 8), // "HomeCtrl"
QT_MOC_LITERAL(1, 9, 12), // "onNewProject"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "onOpenProject"
QT_MOC_LITERAL(4, 37, 12) // "onViewClosed"

    },
    "HomeCtrl\0onNewProject\0\0onOpenProject\0"
    "onViewClosed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HomeCtrl[] = {

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
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HomeCtrl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HomeCtrl *_t = static_cast<HomeCtrl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNewProject(); break;
        case 1: _t->onOpenProject(); break;
        case 2: _t->onViewClosed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject HomeCtrl::staticMetaObject = {
    { &Ctrl::staticMetaObject, qt_meta_stringdata_HomeCtrl.data,
      qt_meta_data_HomeCtrl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HomeCtrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HomeCtrl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HomeCtrl.stringdata0))
        return static_cast<void*>(this);
    return Ctrl::qt_metacast(_clname);
}

int HomeCtrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Ctrl::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
