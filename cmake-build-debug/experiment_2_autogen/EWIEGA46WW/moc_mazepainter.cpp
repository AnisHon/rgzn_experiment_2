/****************************************************************************
** Meta object code from reading C++ file 'mazepainter.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mazepainter.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mazepainter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMazePainterENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMazePainterENDCLASS = QtMocHelpers::stringData(
    "MazePainter",
    "finished",
    "",
    "initMaze",
    "initMazeWithoutDestroyWall",
    "bfsFind",
    "dfsFind",
    "abstract",
    "aStarFind"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMazePainterENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[12];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[27];
    char stringdata5[8];
    char stringdata6[8];
    char stringdata7[9];
    char stringdata8[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMazePainterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMazePainterENDCLASS_t qt_meta_stringdata_CLASSMazePainterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "MazePainter"
        QT_MOC_LITERAL(12, 8),  // "finished"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 8),  // "initMaze"
        QT_MOC_LITERAL(31, 26),  // "initMazeWithoutDestroyWall"
        QT_MOC_LITERAL(58, 7),  // "bfsFind"
        QT_MOC_LITERAL(66, 7),  // "dfsFind"
        QT_MOC_LITERAL(74, 8),  // "abstract"
        QT_MOC_LITERAL(83, 9)   // "aStarFind"
    },
    "MazePainter",
    "finished",
    "",
    "initMaze",
    "initMazeWithoutDestroyWall",
    "bfsFind",
    "dfsFind",
    "abstract",
    "aStarFind"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMazePainterENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   51,    2, 0x0a,    2 /* Public */,
       4,    0,   52,    2, 0x0a,    3 /* Public */,
       5,    0,   53,    2, 0x0a,    4 /* Public */,
       6,    1,   54,    2, 0x0a,    5 /* Public */,
       8,    0,   57,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MazePainter::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSMazePainterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMazePainterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMazePainterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MazePainter, std::true_type>,
        // method 'finished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initMaze'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initMazeWithoutDestroyWall'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bfsFind'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dfsFind'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'aStarFind'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MazePainter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MazePainter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->initMaze(); break;
        case 2: _t->initMazeWithoutDestroyWall(); break;
        case 3: _t->bfsFind(); break;
        case 4: _t->dfsFind((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->aStarFind(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MazePainter::*)();
            if (_t _q_method = &MazePainter::finished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MazePainter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MazePainter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMazePainterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MazePainter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void MazePainter::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
