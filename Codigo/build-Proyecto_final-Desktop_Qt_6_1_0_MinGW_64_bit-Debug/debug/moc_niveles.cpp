/****************************************************************************
** Meta object code from reading C++ file 'niveles.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Proyecto_final/niveles.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'niveles.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_niveles_t {
    const uint offsetsAndSize[16];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_niveles_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_niveles_t qt_meta_stringdata_niveles = {
    {
QT_MOC_LITERAL(0, 7), // "niveles"
QT_MOC_LITERAL(8, 10), // "Movim_per2"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 10), // "Movim_per3"
QT_MOC_LITERAL(31, 12), // "temporizador"
QT_MOC_LITERAL(44, 6), // "tempor"
QT_MOC_LITERAL(51, 19), // "on_anterior_clicked"
QT_MOC_LITERAL(71, 20) // "on_siguiente_clicked"

    },
    "niveles\0Movim_per2\0\0Movim_per3\0"
    "temporizador\0tempor\0on_anterior_clicked\0"
    "on_siguiente_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_niveles[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    0 /* Private */,
       3,    0,   51,    2, 0x08,    1 /* Private */,
       4,    0,   52,    2, 0x08,    2 /* Private */,
       5,    0,   53,    2, 0x08,    3 /* Private */,
       6,    0,   54,    2, 0x08,    4 /* Private */,
       7,    0,   55,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void niveles::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<niveles *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Movim_per2(); break;
        case 1: _t->Movim_per3(); break;
        case 2: _t->temporizador(); break;
        case 3: _t->tempor(); break;
        case 4: _t->on_anterior_clicked(); break;
        case 5: _t->on_siguiente_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject niveles::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_niveles.offsetsAndSize,
    qt_meta_data_niveles,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_niveles_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *niveles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *niveles::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_niveles.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int niveles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
