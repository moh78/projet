/****************************************************************************
** Meta object code from reading C++ file 'qgraphe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Téléchargements/projetAvecGestionnaire/build-projet-Desktop_Qt_5_9_2_GCC_64bit-Debug/qgraphe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgraphe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGraphe_t {
    QByteArrayData data[17];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGraphe_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGraphe_t qt_meta_stringdata_QGraphe = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QGraphe"
QT_MOC_LITERAL(1, 8, 11), // "arc_ajouter"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "deplacer"
QT_MOC_LITERAL(4, 30, 14), // "sommet_ajouter"
QT_MOC_LITERAL(5, 45, 9), // "supprimer"
QT_MOC_LITERAL(6, 55, 10), // "deleteItem"
QT_MOC_LITERAL(7, 66, 8), // "getGraph"
QT_MOC_LITERAL(8, 75, 7), // "Graphe*"
QT_MOC_LITERAL(9, 83, 9), // "setGraphe"
QT_MOC_LITERAL(10, 93, 1), // "g"
QT_MOC_LITERAL(11, 95, 10), // "getQSommet"
QT_MOC_LITERAL(12, 106, 8), // "QSommet*"
QT_MOC_LITERAL(13, 115, 2), // "id"
QT_MOC_LITERAL(14, 118, 16), // "supprimerQSommet"
QT_MOC_LITERAL(15, 135, 12), // "setNomSommet"
QT_MOC_LITERAL(16, 148, 1) // "s"

    },
    "QGraphe\0arc_ajouter\0\0deplacer\0"
    "sommet_ajouter\0supprimer\0deleteItem\0"
    "getGraph\0Graphe*\0setGraphe\0g\0getQSommet\0"
    "QSommet*\0id\0supprimerQSommet\0setNomSommet\0"
    "s"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGraphe[] = {

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
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       9,    1,   70,    2, 0x0a /* Public */,
      11,    1,   73,    2, 0x0a /* Public */,
      14,    0,   76,    2, 0x0a /* Public */,
      15,    1,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 8,
    QMetaType::Void, 0x80000000 | 8,   10,
    0x80000000 | 12, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void QGraphe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGraphe *_t = static_cast<QGraphe *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->arc_ajouter(); break;
        case 1: _t->deplacer(); break;
        case 2: _t->sommet_ajouter(); break;
        case 3: _t->supprimer(); break;
        case 4: _t->deleteItem(); break;
        case 5: { Graphe* _r = _t->getGraph();
            if (_a[0]) *reinterpret_cast< Graphe**>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setGraphe((*reinterpret_cast< Graphe*(*)>(_a[1]))); break;
        case 7: { QSommet* _r = _t->getQSommet((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QSommet**>(_a[0]) = std::move(_r); }  break;
        case 8: _t->supprimerQSommet(); break;
        case 9: _t->setNomSommet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QGraphe::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_QGraphe.data,
      qt_meta_data_QGraphe,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QGraphe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGraphe.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int QGraphe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
