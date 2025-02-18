/****************************************************************************
** Meta object code from reading C++ file 'changestu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../StudentManager/changestu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changestu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_changestu_t {
    QByteArrayData data[7];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_changestu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_changestu_t qt_meta_stringdata_changestu = {
    {
QT_MOC_LITERAL(0, 0, 9), // "changestu"
QT_MOC_LITERAL(1, 10, 20), // "on_btncancel_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "on_btnok_clicked"
QT_MOC_LITERAL(4, 49, 15), // "on_stus_clicked"
QT_MOC_LITERAL(5, 65, 15), // "on_stum_clicked"
QT_MOC_LITERAL(6, 81, 15) // "on_stul_clicked"

    },
    "changestu\0on_btncancel_clicked\0\0"
    "on_btnok_clicked\0on_stus_clicked\0"
    "on_stum_clicked\0on_stul_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_changestu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void changestu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        changestu *_t = static_cast<changestu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btncancel_clicked(); break;
        case 1: _t->on_btnok_clicked(); break;
        case 2: _t->on_stus_clicked(); break;
        case 3: _t->on_stum_clicked(); break;
        case 4: _t->on_stul_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject changestu::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_changestu.data,
      qt_meta_data_changestu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *changestu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *changestu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_changestu.stringdata0))
        return static_cast<void*>(const_cast< changestu*>(this));
    return QDialog::qt_metacast(_clname);
}

int changestu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
