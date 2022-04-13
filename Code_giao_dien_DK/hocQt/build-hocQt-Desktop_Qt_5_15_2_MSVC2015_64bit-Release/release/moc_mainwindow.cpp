/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../hocQt/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[333];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 7), // "showMat"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 13), // "videoOriginal"
QT_MOC_LITERAL(4, 34, 21), // "on_Disconnect_clicked"
QT_MOC_LITERAL(5, 56, 18), // "on_Connect_clicked"
QT_MOC_LITERAL(6, 75, 7), // "dst_Mat"
QT_MOC_LITERAL(7, 83, 9), // "WriteData"
QT_MOC_LITERAL(8, 93, 4), // "data"
QT_MOC_LITERAL(9, 98, 8), // "ReadData"
QT_MOC_LITERAL(10, 107, 26), // "convertOpenCVMatToQtQImage"
QT_MOC_LITERAL(11, 134, 3), // "Mat"
QT_MOC_LITERAL(12, 138, 3), // "mat"
QT_MOC_LITERAL(13, 142, 27), // "on_btnPauseOrResume_clicked"
QT_MOC_LITERAL(14, 170, 14), // "on_Len_clicked"
QT_MOC_LITERAL(15, 185, 14), // "on_Len_pressed"
QT_MOC_LITERAL(16, 200, 15), // "on_Len_released"
QT_MOC_LITERAL(17, 216, 21), // "on_Sang_Phai_released"
QT_MOC_LITERAL(18, 238, 20), // "on_Sang_Phai_pressed"
QT_MOC_LITERAL(19, 259, 21), // "on_Sang_Trai_released"
QT_MOC_LITERAL(20, 281, 20), // "on_Sang_Trai_pressed"
QT_MOC_LITERAL(21, 302, 15), // "on_Lui_released"
QT_MOC_LITERAL(22, 318, 14) // "on_Lui_pressed"

    },
    "MainWindow\0showMat\0\0videoOriginal\0"
    "on_Disconnect_clicked\0on_Connect_clicked\0"
    "dst_Mat\0WriteData\0data\0ReadData\0"
    "convertOpenCVMatToQtQImage\0Mat\0mat\0"
    "on_btnPauseOrResume_clicked\0on_Len_clicked\0"
    "on_Len_pressed\0on_Len_released\0"
    "on_Sang_Phai_released\0on_Sang_Phai_pressed\0"
    "on_Sang_Trai_released\0on_Sang_Trai_pressed\0"
    "on_Lui_released\0on_Lui_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    1,  109,    2, 0x08 /* Private */,
       9,    0,  112,    2, 0x08 /* Private */,
      10,    1,  113,    2, 0x08 /* Private */,
      13,    0,  116,    2, 0x08 /* Private */,
      14,    0,  117,    2, 0x08 /* Private */,
      15,    0,  118,    2, 0x08 /* Private */,
      16,    0,  119,    2, 0x08 /* Private */,
      17,    0,  120,    2, 0x08 /* Private */,
      18,    0,  121,    2, 0x08 /* Private */,
      19,    0,  122,    2, 0x08 /* Private */,
      20,    0,  123,    2, 0x08 /* Private */,
      21,    0,  124,    2, 0x08 /* Private */,
      22,    0,  125,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void,
    QMetaType::QImage, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showMat(); break;
        case 1: _t->videoOriginal(); break;
        case 2: _t->on_Disconnect_clicked(); break;
        case 3: _t->on_Connect_clicked(); break;
        case 4: _t->dst_Mat(); break;
        case 5: _t->WriteData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 6: _t->ReadData(); break;
        case 7: { QImage _r = _t->convertOpenCVMatToQtQImage((*reinterpret_cast< Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->on_btnPauseOrResume_clicked(); break;
        case 9: _t->on_Len_clicked(); break;
        case 10: _t->on_Len_pressed(); break;
        case 11: _t->on_Len_released(); break;
        case 12: _t->on_Sang_Phai_released(); break;
        case 13: _t->on_Sang_Phai_pressed(); break;
        case 14: _t->on_Sang_Trai_released(); break;
        case 15: _t->on_Sang_Trai_pressed(); break;
        case 16: _t->on_Lui_released(); break;
        case 17: _t->on_Lui_pressed(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
