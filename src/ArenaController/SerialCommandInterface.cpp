//.$file${./ArenaControlle~::SerialCommandInterface.cpp} vvvvvvvvvvvvvvvvvvvvv
//
// Model: ArenaController.qm
// File:  ${./ArenaControlle~::SerialCommandInterface.cpp}
//
// This code has been generated by QM 5.1.3 <www.state-machine.com/qm/>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.
//
//.$endhead${./ArenaControlle~::SerialCommandInterface.cpp} ^^^^^^^^^^^^^^^^^^
#include "ArenaController.hpp"  // ArenaController application interface


using namespace QP;

//============================================================================
// generate declaration of the active object
//.$declare${AOs::SerialCommandInterface} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
namespace AC {

//.${AOs::SerialCommandInterface} ............................................
class SerialCommandInterface : public QP::QActive {
public:
    QP::QTimeEvt command_time_evt_;
    static SerialCommandInterface instance;

public:
    SerialCommandInterface();

protected:
    Q_STATE_DECL(initial);
    Q_STATE_DECL(Active);
    Q_STATE_DECL(Inactive);
};

} // namespace AC
//.$enddecl${AOs::SerialCommandInterface} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//============================================================================
// generate definition of to opaque pointer to the AO
//.$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//. Check for the minimum required QP version
#if (QP_VERSION < 690U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpcpp version 6.9.0 or higher required
#endif
//.$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//.$define${Shared::AO_SerialCommandInterface} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
namespace AC {

//.${Shared::AO_SerialCommandInterface} ......................................
QP::QActive * const AO_SerialCommandInterface = &SerialCommandInterface::instance;

} // namespace AC
//.$enddef${Shared::AO_SerialCommandInterface} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//============================================================================
// generate definition of the AO
//.$define${AOs::SerialCommandInterface} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
namespace AC {

//.${AOs::SerialCommandInterface} ............................................
SerialCommandInterface SerialCommandInterface::instance;
//.${AOs::SerialCommandInt~::SerialCommandInterface} .........................
SerialCommandInterface::SerialCommandInterface()
: QActive(Q_STATE_CAST(&SerialCommandInterface::initial)),
    command_time_evt_(this, COMMAND_TIMEOUT_SIG, 0U)
{}

//.${AOs::SerialCommandInt~::SM} .............................................
Q_STATE_DEF(SerialCommandInterface, initial) {
    //.${AOs::SerialCommandInt~::SM::initial}
    subscribe(ACTIVATE_SERIAL_COMMAND_INTERFACE_SIG);
    subscribe(DEACTIVATE_SERIAL_COMMAND_INTERFACE_SIG);
    return tran(&Inactive);
}
//.${AOs::SerialCommandInt~::SM::Active} .....................................
Q_STATE_DEF(SerialCommandInterface, Active) {
    QP::QState status_;
    switch (e->sig) {
        //.${AOs::SerialCommandInt~::SM::Active}
        case Q_ENTRY_SIG: {
            command_time_evt_.armX(BSP::TICKS_PER_SEC/50, BSP::TICKS_PER_SEC/50);
            status_ = Q_RET_HANDLED;
            break;
        }
        //.${AOs::SerialCommandInt~::SM::Active}
        case Q_EXIT_SIG: {
            command_time_evt_.disarm();
            status_ = Q_RET_HANDLED;
            break;
        }
        //.${AOs::SerialCommandInt~::SM::Active::COMMAND_TIMEOUT}
        case COMMAND_TIMEOUT_SIG: {
            BSP::pollSerialCommand();
            status_ = Q_RET_HANDLED;
            break;
        }
        //.${AOs::SerialCommandInt~::SM::Active::DEACTIVATE_SERIAL_COMMAND_INTERF~}
        case DEACTIVATE_SERIAL_COMMAND_INTERFACE_SIG: {
            status_ = tran(&Inactive);
            break;
        }
        default: {
            status_ = super(&top);
            break;
        }
    }
    return status_;
}
//.${AOs::SerialCommandInt~::SM::Inactive} ...................................
Q_STATE_DEF(SerialCommandInterface, Inactive) {
    QP::QState status_;
    switch (e->sig) {
        //.${AOs::SerialCommandInt~::SM::Inactive::ACTIVATE_SERIAL_COMMAND_INTERFAC~}
        case ACTIVATE_SERIAL_COMMAND_INTERFACE_SIG: {
            status_ = tran(&Active);
            break;
        }
        default: {
            status_ = super(&top);
            break;
        }
    }
    return status_;
}

} // namespace AC
//.$enddef${AOs::SerialCommandInterface} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
