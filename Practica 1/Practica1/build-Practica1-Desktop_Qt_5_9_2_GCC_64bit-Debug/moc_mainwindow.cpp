/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Practica1/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[367];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 58, 12), // "GraficarTodo"
QT_MOC_LITERAL(5, 71, 12), // "MostrarGrafo"
QT_MOC_LITERAL(6, 84, 11), // "Avionllenar"
QT_MOC_LITERAL(7, 96, 54), // "AvionQuitarTurnos_llenarColaE..."
QT_MOC_LITERAL(8, 151, 15), // "GrafoDobleAvion"
QT_MOC_LITERAL(9, 167, 6), // "string"
QT_MOC_LITERAL(10, 174, 15), // "Pasajerosllenar"
QT_MOC_LITERAL(11, 190, 18), // "GrafoColaPasajeros"
QT_MOC_LITERAL(12, 209, 24), // "AvionMantenimientollenar"
QT_MOC_LITERAL(13, 234, 14), // "GrafoColaAvion"
QT_MOC_LITERAL(14, 249, 21), // "AvionMantenimientodel"
QT_MOC_LITERAL(15, 271, 13), // "Maletasllenar"
QT_MOC_LITERAL(16, 285, 9), // "noMaletas"
QT_MOC_LITERAL(17, 295, 17), // "GrafolistaMaletas"
QT_MOC_LITERAL(18, 313, 19), // "AvionEstacionllenar"
QT_MOC_LITERAL(19, 333, 11), // "Escritorios"
QT_MOC_LITERAL(20, 345, 21) // "GrafoEstacionServicio"

    },
    "MainWindow\0on_pushButton_clicked\0\0"
    "on_pushButton_2_clicked\0GraficarTodo\0"
    "MostrarGrafo\0Avionllenar\0"
    "AvionQuitarTurnos_llenarColaEspera_llenarColaPasajeros\0"
    "GrafoDobleAvion\0string\0Pasajerosllenar\0"
    "GrafoColaPasajeros\0AvionMantenimientollenar\0"
    "GrafoColaAvion\0AvionMantenimientodel\0"
    "Maletasllenar\0noMaletas\0GrafolistaMaletas\0"
    "AvionEstacionllenar\0Escritorios\0"
    "GrafoEstacionServicio"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
      10,    0,  101,    2, 0x08 /* Private */,
      11,    0,  102,    2, 0x08 /* Private */,
      12,    0,  103,    2, 0x08 /* Private */,
      13,    0,  104,    2, 0x08 /* Private */,
      14,    0,  105,    2, 0x08 /* Private */,
      15,    1,  106,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,
      18,    1,  110,    2, 0x08 /* Private */,
      20,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 9,
    QMetaType::Void,
    0x80000000 | 9,
    QMetaType::Void,
    0x80000000 | 9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    0x80000000 | 9,
    QMetaType::Void, QMetaType::Int,   19,
    0x80000000 | 9,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->GraficarTodo(); break;
        case 3: _t->MostrarGrafo(); break;
        case 4: _t->Avionllenar(); break;
        case 5: _t->AvionQuitarTurnos_llenarColaEspera_llenarColaPasajeros(); break;
        case 6: { string _r = _t->GrafoDobleAvion();
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->Pasajerosllenar(); break;
        case 8: { string _r = _t->GrafoColaPasajeros();
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->AvionMantenimientollenar(); break;
        case 10: { string _r = _t->GrafoColaAvion();
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->AvionMantenimientodel(); break;
        case 12: _t->Maletasllenar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: { string _r = _t->GrafolistaMaletas();
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->AvionEstacionllenar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: { string _r = _t->GrafoEstacionServicio();
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
