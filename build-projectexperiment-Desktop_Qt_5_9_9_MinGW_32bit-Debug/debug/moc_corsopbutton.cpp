/****************************************************************************
** Meta object code from reading C++ file 'corsopbutton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projectexperiment/view/corsopbutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'corsopbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_corsoPButton_t {
    QByteArrayData data[4];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_corsoPButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_corsoPButton_t qt_meta_stringdata_corsoPButton = {
    {
QT_MOC_LITERAL(0, 0, 12), // "corsoPButton"
QT_MOC_LITERAL(1, 13, 11), // "selectCorso"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11) // "deleteCorso"

    },
    "corsoPButton\0selectCorso\0\0deleteCorso"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_corsoPButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       3,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void corsoPButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        corsoPButton *_t = static_cast<corsoPButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectCorso((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->deleteCorso((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (corsoPButton::*_t)(int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&corsoPButton::selectCorso)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (corsoPButton::*_t)(int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&corsoPButton::deleteCorso)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject corsoPButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_corsoPButton.data,
      qt_meta_data_corsoPButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *corsoPButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *corsoPButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_corsoPButton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int corsoPButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void corsoPButton::selectCorso(int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< corsoPButton *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void corsoPButton::deleteCorso(int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< corsoPButton *>(this), &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE