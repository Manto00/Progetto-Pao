/****************************************************************************
** Meta object code from reading C++ file 'esamimodcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projectexperiment/controller/esamimodcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'esamimodcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_esamiModController_t {
    QByteArrayData data[8];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_esamiModController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_esamiModController_t qt_meta_stringdata_esamiModController = {
    {
QT_MOC_LITERAL(0, 0, 18), // "esamiModController"
QT_MOC_LITERAL(1, 19, 12), // "onViewClosed"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "onSaveEsame"
QT_MOC_LITERAL(4, 45, 5), // "esame"
QT_MOC_LITERAL(5, 51, 13), // "onDeleteEsame"
QT_MOC_LITERAL(6, 65, 1), // "i"
QT_MOC_LITERAL(7, 67, 6) // "onHome"

    },
    "esamiModController\0onViewClosed\0\0"
    "onSaveEsame\0esame\0onDeleteEsame\0i\0"
    "onHome"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_esamiModController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       5,    1,   38,    2, 0x0a /* Public */,
       7,    0,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void esamiModController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        esamiModController *_t = static_cast<esamiModController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onViewClosed(); break;
        case 1: _t->onSaveEsame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onDeleteEsame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onHome(); break;
        default: ;
        }
    }
}

const QMetaObject esamiModController::staticMetaObject = {
    { &Controller::staticMetaObject, qt_meta_stringdata_esamiModController.data,
      qt_meta_data_esamiModController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *esamiModController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *esamiModController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_esamiModController.stringdata0))
        return static_cast<void*>(this);
    return Controller::qt_metacast(_clname);
}

int esamiModController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Controller::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
