/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[48];
    char stringdata0[551];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 11), // "choose_file"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 6), // "redraw"
QT_MOC_LITERAL(31, 6), // "rebuff"
QT_MOC_LITERAL(38, 15), // "take_screenshot"
QT_MOC_LITERAL(54, 10), // "record_gif"
QT_MOC_LITERAL(65, 21), // "valueChanged_to_Rot_X"
QT_MOC_LITERAL(87, 5), // "value"
QT_MOC_LITERAL(93, 21), // "valueChanged_to_Rot_Y"
QT_MOC_LITERAL(115, 21), // "valueChanged_to_Rot_Z"
QT_MOC_LITERAL(137, 22), // "valueChanged_to_Move_X"
QT_MOC_LITERAL(160, 22), // "valueChanged_to_Move_Y"
QT_MOC_LITERAL(183, 22), // "valueChanged_to_Move_Z"
QT_MOC_LITERAL(206, 58), // "on_comboBox_settings_view_pol..."
QT_MOC_LITERAL(265, 5), // "index"
QT_MOC_LITERAL(271, 57), // "on_doubleSpinBox_settings_vie..."
QT_MOC_LITERAL(329, 4), // "arg1"
QT_MOC_LITERAL(334, 57), // "on_comboBox_settings_view_ver..."
QT_MOC_LITERAL(392, 55), // "on_doubleSpinBox_settings_vie..."
QT_MOC_LITERAL(448, 34), // "on_pushButton_screen_start_cl..."
QT_MOC_LITERAL(483, 38), // "on_pushButton_screen_gif_star..."
QT_MOC_LITERAL(522, 13), // "recording_gif"
QT_MOC_LITERAL(536, 14) // "recording_stop"

    },
    "MainWindow\0choose_file\0\0redraw\0rebuff\0"
    "take_screenshot\0record_gif\0"
    "valueChanged_to_Rot_X\0value\0"
    "valueChanged_to_Rot_Y\0valueChanged_to_Rot_Z\0"
    "valueChanged_to_Move_X\0valueChanged_to_Move_Y\0"
    "valueChanged_to_Move_Z\0"
    "on_comboBox_settings_view_polygon_type_currentIndexChanged\0"
    "index\0on_doubleSpinBox_settings_view_polygon_width_valueChanged\0"
    "arg1\0on_comboBox_settings_view_vertex_type_currentIndexChanged\0"
    "on_doubleSpinBox_settings_view_vertex_size_valueChanged\0"
    "on_pushButton_screen_start_clicked\0"
    "on_pushButton_screen_gif_start_clicked\0"
    "recording_gif\0recording_stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x0a,    1 /* Public */,
       3,    0,  129,    2, 0x0a,    2 /* Public */,
       4,    0,  130,    2, 0x0a,    3 /* Public */,
       5,    0,  131,    2, 0x0a,    4 /* Public */,
       6,    0,  132,    2, 0x0a,    5 /* Public */,
       7,    1,  133,    2, 0x08,    6 /* Private */,
       9,    1,  136,    2, 0x08,    8 /* Private */,
      10,    1,  139,    2, 0x08,   10 /* Private */,
      11,    1,  142,    2, 0x08,   12 /* Private */,
      12,    1,  145,    2, 0x08,   14 /* Private */,
      13,    1,  148,    2, 0x08,   16 /* Private */,
      14,    1,  151,    2, 0x08,   18 /* Private */,
      16,    1,  154,    2, 0x08,   20 /* Private */,
      18,    1,  157,    2, 0x08,   22 /* Private */,
      19,    1,  160,    2, 0x08,   24 /* Private */,
      20,    0,  163,    2, 0x08,   26 /* Private */,
      21,    0,  164,    2, 0x08,   27 /* Private */,
      22,    0,  165,    2, 0x08,   28 /* Private */,
      23,    0,  166,    2, 0x08,   29 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Double,   17,
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
        (void)_t;
        switch (_id) {
        case 0: _t->choose_file(); break;
        case 1: _t->redraw(); break;
        case 2: _t->rebuff(); break;
        case 3: _t->take_screenshot(); break;
        case 4: _t->record_gif(); break;
        case 5: _t->valueChanged_to_Rot_X((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->valueChanged_to_Rot_Y((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->valueChanged_to_Rot_Z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->valueChanged_to_Move_X((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->valueChanged_to_Move_Y((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->valueChanged_to_Move_Z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_comboBox_settings_view_polygon_type_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_doubleSpinBox_settings_view_polygon_width_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->on_comboBox_settings_view_vertex_type_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_doubleSpinBox_settings_view_vertex_size_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->on_pushButton_screen_start_clicked(); break;
        case 16: _t->on_pushButton_screen_gif_start_clicked(); break;
        case 17: _t->recording_gif(); break;
        case 18: _t->recording_stop(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
