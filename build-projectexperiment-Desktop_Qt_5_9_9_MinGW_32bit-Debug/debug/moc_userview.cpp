/****************************************************************************
** Meta object code from reading C++ file 'userview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projectexperiment/view/userview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_userView_t {
    QByteArrayData data[7];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_userView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_userView_t qt_meta_stringdata_userView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "userView"
QT_MOC_LITERAL(1, 9, 11), // "insertEsame"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "showChart"
QT_MOC_LITERAL(4, 32, 11), // "insertCorso"
QT_MOC_LITERAL(5, 44, 11), // "selectCorso"
QT_MOC_LITERAL(6, 56, 11) // "deleteCorso"

    },
    "userView\0insertEsame\0\0showChart\0"
    "insertCorso\0selectCorso\0deleteCorso"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_userView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    8,   39,    2, 0x06 /* Public */,
       3,    0,   56,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    1,   60,    2, 0x06 /* Public */,
       6,    1,   63,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QDate, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void userView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        userView *_t = static_cast<userView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->insertEsame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QDate(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 1: _t->showChart(); break;
        case 2: _t->insertCorso((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->selectCorso((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->deleteCorso((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (userView::*_t)(int , int , int , QDate , int , int , int , int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&userView::insertEsame)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (userView::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&userView::showChart)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (userView::*_t)(int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&userView::insertCorso)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (userView::*_t)(int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&userView::selectCorso)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (userView::*_t)(int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&userView::deleteCorso)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject userView::staticMetaObject = {
    { &View::staticMetaObject, qt_meta_stringdata_userView.data,
      qt_meta_data_userView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *userView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *userView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_userView.stringdata0))
        return static_cast<void*>(this);
    return View::qt_metacast(_clname);
}

int userView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = View::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void userView::insertEsame(int _t1, int _t2, int _t3, QDate _t4, int _t5, int _t6, int _t7, int _t8)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(const_cast< userView *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void userView::showChart()const
{
    QMetaObject::activate(const_cast< userView *>(this), &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void userView::insertCorso(int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< userView *>(this), &staticMetaObject, 2, _a);
}

// SIGNAL 3
void userView::selectCorso(int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< userView *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void userView::deleteCorso(int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< userView *>(this), &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
