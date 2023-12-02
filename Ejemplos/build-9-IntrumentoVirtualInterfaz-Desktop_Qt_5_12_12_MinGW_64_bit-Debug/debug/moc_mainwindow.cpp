/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../9-IntrumentoVirtualInterfaz/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[459];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "readData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "handleError"
QT_MOC_LITERAL(4, 33, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(5, 62, 5), // "error"
QT_MOC_LITERAL(6, 68, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(7, 93, 25), // "on_digitalOutput7_toggled"
QT_MOC_LITERAL(8, 119, 7), // "checked"
QT_MOC_LITERAL(9, 127, 25), // "on_digitalOutput1_toggled"
QT_MOC_LITERAL(10, 153, 25), // "on_digitalOutput2_toggled"
QT_MOC_LITERAL(11, 179, 25), // "on_digitalOutput4_toggled"
QT_MOC_LITERAL(12, 205, 25), // "on_digitalOutput5_toggled"
QT_MOC_LITERAL(13, 231, 25), // "on_digitalOutput6_toggled"
QT_MOC_LITERAL(14, 257, 25), // "on_digitalOutput8_toggled"
QT_MOC_LITERAL(15, 283, 25), // "on_digitalOutput3_toggled"
QT_MOC_LITERAL(16, 309, 36), // "on_analogOutput1_dial_sliderR..."
QT_MOC_LITERAL(17, 346, 36), // "on_analogOutput2_dial_sliderR..."
QT_MOC_LITERAL(18, 383, 34), // "on_analogOutput2_dial_valueCh..."
QT_MOC_LITERAL(19, 418, 5), // "value"
QT_MOC_LITERAL(20, 424, 34) // "on_analogOutput1_dial_valueCh..."

    },
    "MainWindow\0readData\0\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "on_connectButton_clicked\0"
    "on_digitalOutput7_toggled\0checked\0"
    "on_digitalOutput1_toggled\0"
    "on_digitalOutput2_toggled\0"
    "on_digitalOutput4_toggled\0"
    "on_digitalOutput5_toggled\0"
    "on_digitalOutput6_toggled\0"
    "on_digitalOutput8_toggled\0"
    "on_digitalOutput3_toggled\0"
    "on_analogOutput1_dial_sliderReleased\0"
    "on_analogOutput2_dial_sliderReleased\0"
    "on_analogOutput2_dial_valueChanged\0"
    "value\0on_analogOutput1_dial_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    1,   90,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    1,   94,    2, 0x08 /* Private */,
       9,    1,   97,    2, 0x08 /* Private */,
      10,    1,  100,    2, 0x08 /* Private */,
      11,    1,  103,    2, 0x08 /* Private */,
      12,    1,  106,    2, 0x08 /* Private */,
      13,    1,  109,    2, 0x08 /* Private */,
      14,    1,  112,    2, 0x08 /* Private */,
      15,    1,  115,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    1,  120,    2, 0x08 /* Private */,
      20,    1,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readData(); break;
        case 1: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 2: _t->on_connectButton_clicked(); break;
        case 3: _t->on_digitalOutput7_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_digitalOutput1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_digitalOutput2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_digitalOutput4_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_digitalOutput5_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_digitalOutput6_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_digitalOutput8_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_digitalOutput3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_analogOutput1_dial_sliderReleased(); break;
        case 12: _t->on_analogOutput2_dial_sliderReleased(); break;
        case 13: _t->on_analogOutput2_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_analogOutput1_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
