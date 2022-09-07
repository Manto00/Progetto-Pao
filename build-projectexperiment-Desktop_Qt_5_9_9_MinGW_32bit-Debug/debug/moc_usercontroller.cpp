/****************************************************************************
** Meta object code from reading C++ file 'usercontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projectexperiment/controller/usercontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usercontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_userController_t {
    QByteArrayData data[20];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_userController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_userController_t qt_meta_stringdata_userController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "userController"
QT_MOC_LITERAL(1, 15, 11), // "onShowChart"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 1), // "i"
QT_MOC_LITERAL(4, 30, 13), // "onInsertEsame"
QT_MOC_LITERAL(5, 44, 9), // "matricola"
QT_MOC_LITERAL(6, 54, 4), // "voto"
QT_MOC_LITERAL(7, 59, 7), // "appello"
QT_MOC_LITERAL(8, 67, 4), // "date"
QT_MOC_LITERAL(9, 72, 6), // "chiuse"
QT_MOC_LITERAL(10, 79, 6), // "aperte"
QT_MOC_LITERAL(11, 86, 8), // "esercizi"
QT_MOC_LITERAL(12, 95, 6), // "durata"
QT_MOC_LITERAL(13, 102, 13), // "onInsertCorso"
QT_MOC_LITERAL(14, 116, 13), // "onDeleteCorso"
QT_MOC_LITERAL(15, 130, 9), // "posizione"
QT_MOC_LITERAL(16, 140, 8), // "onSaveAs"
QT_MOC_LITERAL(17, 149, 6), // "onSave"
QT_MOC_LITERAL(18, 156, 16), // "onOrganizzaEsami"
QT_MOC_LITERAL(19, 173, 12) // "onViewClosed"

    },
    "userController\0onShowChart\0\0i\0"
    "onInsertEsame\0matricola\0voto\0appello\0"
    "date\0chiuse\0aperte\0esercizi\0durata\0"
    "onInsertCorso\0onDeleteCorso\0posizione\0"
    "onSaveAs\0onSave\0onOrganizzaEsami\0"
    "onViewClosed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_userController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       1,    0,   67,    2, 0x2a /* Public | MethodCloned */,
       4,    8,   68,    2, 0x0a /* Public */,
       4,    7,   85,    2, 0x2a /* Public | MethodCloned */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    1,  101,    2, 0x0a /* Public */,
      16,    0,  104,    2, 0x0a /* Public */,
      17,    0,  105,    2, 0x0a /* Public */,
      18,    0,  106,    2, 0x0a /* Public */,
      19,    0,  107,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QDate, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,    8,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QDate, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,    8,    9,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void userController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        userController *_t = static_cast<userController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onShowChart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onShowChart(); break;
        case 2: _t->onInsertEsame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QDate(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 3: _t->onInsertEsame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QDate(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 4: _t->onInsertCorso(); break;
        case 5: _t->onDeleteCorso((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onSaveAs(); break;
        case 7: _t->onSave(); break;
        case 8: _t->onOrganizzaEsami(); break;
        case 9: _t->onViewClosed(); break;
        default: ;
        }
    }
}

const QMetaObject userController::staticMetaObject = {
    { &Controller::staticMetaObject, qt_meta_stringdata_userController.data,
      qt_meta_data_userController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *userController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *userController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_userController.stringdata0))
        return static_cast<void*>(this);
    return Controller::qt_metacast(_clname);
}

int userController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Controller::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
