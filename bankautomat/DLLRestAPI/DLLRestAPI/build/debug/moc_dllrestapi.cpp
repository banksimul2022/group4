/****************************************************************************
** Meta object code from reading C++ file 'dllrestapi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../dllrestapi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dllrestapi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DLLRestAPI_t {
    QByteArrayData data[21];
    char stringdata0[323];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DLLRestAPI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DLLRestAPI_t qt_meta_stringdata_DLLRestAPI = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DLLRestAPI"
QT_MOC_LITERAL(1, 11, 13), // "balanceSignal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 21), // "balanceSignalInternal"
QT_MOC_LITERAL(4, 48, 13), // "startTransact"
QT_MOC_LITERAL(5, 62, 14), // "withdrawSignal"
QT_MOC_LITERAL(6, 77, 16), // "tilinumeroSignal"
QT_MOC_LITERAL(7, 94, 15), // "CardStateSignal"
QT_MOC_LITERAL(8, 110, 20), // "tilitapahtumatSignal"
QT_MOC_LITERAL(9, 131, 17), // "getTilinumeroSlot"
QT_MOC_LITERAL(10, 149, 14), // "QNetworkReply*"
QT_MOC_LITERAL(11, 164, 5), // "reply"
QT_MOC_LITERAL(12, 170, 16), // "getCardStateSlot"
QT_MOC_LITERAL(13, 187, 19), // "updateCardStateSlot"
QT_MOC_LITERAL(14, 207, 12), // "getSaldoSlot"
QT_MOC_LITERAL(15, 220, 20), // "getSaldoSlotInternal"
QT_MOC_LITERAL(16, 241, 21), // "getTilitapahtumatSlot"
QT_MOC_LITERAL(17, 263, 13), // "AllocateSaldo"
QT_MOC_LITERAL(18, 277, 11), // "Transaction"
QT_MOC_LITERAL(19, 289, 12), // "TransactSlot"
QT_MOC_LITERAL(20, 302, 20) // "addTilitapahtumaSlot"

    },
    "DLLRestAPI\0balanceSignal\0\0"
    "balanceSignalInternal\0startTransact\0"
    "withdrawSignal\0tilinumeroSignal\0"
    "CardStateSignal\0tilitapahtumatSignal\0"
    "getTilinumeroSlot\0QNetworkReply*\0reply\0"
    "getCardStateSlot\0updateCardStateSlot\0"
    "getSaldoSlot\0getSaldoSlotInternal\0"
    "getTilitapahtumatSlot\0AllocateSaldo\0"
    "Transaction\0TransactSlot\0addTilitapahtumaSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DLLRestAPI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       3,    1,  102,    2, 0x06 /* Public */,
       4,    0,  105,    2, 0x06 /* Public */,
       5,    0,  106,    2, 0x06 /* Public */,
       6,    1,  107,    2, 0x06 /* Public */,
       7,    1,  110,    2, 0x06 /* Public */,
       8,    1,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  116,    2, 0x08 /* Private */,
      12,    1,  119,    2, 0x08 /* Private */,
      13,    1,  122,    2, 0x08 /* Private */,
      14,    1,  125,    2, 0x08 /* Private */,
      15,    1,  128,    2, 0x08 /* Private */,
      16,    1,  131,    2, 0x08 /* Private */,
      17,    1,  134,    2, 0x08 /* Private */,
      18,    0,  137,    2, 0x08 /* Private */,
      19,    1,  138,    2, 0x08 /* Private */,
      20,    1,  141,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void DLLRestAPI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DLLRestAPI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->balanceSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->balanceSignalInternal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->startTransact(); break;
        case 3: _t->withdrawSignal(); break;
        case 4: _t->tilinumeroSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->CardStateSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->tilitapahtumatSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->getTilinumeroSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 8: _t->getCardStateSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 9: _t->updateCardStateSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->getSaldoSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 11: _t->getSaldoSlotInternal((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 12: _t->getTilitapahtumatSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 13: _t->AllocateSaldo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->Transaction(); break;
        case 15: _t->TransactSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 16: _t->addTilitapahtumaSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DLLRestAPI::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DLLRestAPI::balanceSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DLLRestAPI::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DLLRestAPI::balanceSignalInternal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DLLRestAPI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DLLRestAPI::startTransact)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DLLRestAPI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DLLRestAPI::withdrawSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DLLRestAPI::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DLLRestAPI::tilinumeroSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DLLRestAPI::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DLLRestAPI::CardStateSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DLLRestAPI::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DLLRestAPI::tilitapahtumatSignal)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DLLRestAPI::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DLLRestAPI.data,
    qt_meta_data_DLLRestAPI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DLLRestAPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DLLRestAPI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DLLRestAPI.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DLLRestAPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void DLLRestAPI::balanceSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DLLRestAPI::balanceSignalInternal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DLLRestAPI::startTransact()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DLLRestAPI::withdrawSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DLLRestAPI::tilinumeroSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DLLRestAPI::CardStateSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DLLRestAPI::tilitapahtumatSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
