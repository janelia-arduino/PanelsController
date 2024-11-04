//.$file${./ArenaControlle~::Display.cpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: ArenaController.qm
// File:  ${./ArenaControlle~::Display.cpp}
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
//.$endhead${./ArenaControlle~::Display.cpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include "ArenaController.hpp"  // ArenaController application interface

using namespace QP;

//============================================================================
// generate declaration of the active object
//.$declare${AOs::Display} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
namespace AC {

//.${AOs::Display} ...........................................................
class Display : public QP::QActive {
public:
    static Display instance;

public:
    Display();

protected:
    Q_STATE_DECL(initial);
    Q_STATE_DECL(Off);
    Q_STATE_DECL(On);
    Q_STATE_DECL(AllOn);
    Q_STATE_DECL(AllOnWaiting);
    Q_STATE_DECL(AllOnDisplaying);
};

} // namespace AC
//.$enddecl${AOs::Display} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//============================================================================
// generate definition of to opaque pointer to the AO
//.$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//. Check for the minimum required QP version
#if (QP_VERSION < 690U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpcpp version 6.9.0 or higher required
#endif
//.$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//.$define${AOs::AO_Display} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
namespace AC {

//.${AOs::AO_Display} ........................................................
QP::QActive * const AO_Display = &Display::instance;

} // namespace AC
//.$enddef${AOs::AO_Display} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//============================================================================
// generate definition of the AO
//.$define${AOs::Display} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
namespace AC {

//.${AOs::Display} ...........................................................
Display Display::instance;
//.${AOs::Display::Display} ..................................................
Display::Display()
: QActive(Q_STATE_CAST(&Display::initial))
{}

//.${AOs::Display::SM} .......................................................
Q_STATE_DEF(Display, initial) {
    //.${AOs::Display::SM::initial}
    subscribe(ALL_ON_SIG);
    subscribe(ALL_OFF_SIG);
    subscribe(DISPLAY_FRAME_TIMEOUT_SIG);
    return tran(&Off);
}
//.${AOs::Display::SM::Off} ..................................................
Q_STATE_DEF(Display, Off) {
    QP::QState status_;
    switch (e->sig) {
        //.${AOs::Display::SM::Off}
        case Q_ENTRY_SIG: {
            BSP::ledOff();
            status_ = Q_RET_HANDLED;
            break;
        }
        //.${AOs::Display::SM::Off::ALL_ON}
        case ALL_ON_SIG: {
            status_ = tran(&AllOn);
            break;
        }
        default: {
            status_ = super(&top);
            break;
        }
    }
    return status_;
}
//.${AOs::Display::SM::On} ...................................................
Q_STATE_DEF(Display, On) {
    QP::QState status_;
    switch (e->sig) {
        //.${AOs::Display::SM::On}
        case Q_ENTRY_SIG: {
            BSP::armDisplayFrameTimer(400);
            status_ = Q_RET_HANDLED;
            break;
        }
        //.${AOs::Display::SM::On}
        case Q_EXIT_SIG: {
            BSP::disarmDisplayFrameTimer();
            status_ = Q_RET_HANDLED;
            break;
        }
        //.${AOs::Display::SM::On::ALL_OFF}
        case ALL_OFF_SIG: {
            status_ = tran(&Off);
            break;
        }
        default: {
            status_ = super(&top);
            break;
        }
    }
    return status_;
}
//.${AOs::Display::SM::On::AllOn} ............................................
Q_STATE_DEF(Display, AllOn) {
    QP::QState status_;
    switch (e->sig) {
        //.${AOs::Display::SM::On::AllOn::initial}
        case Q_INIT_SIG: {
            status_ = tran(&AllOnWaiting);
            break;
        }
        default: {
            status_ = super(&On);
            break;
        }
    }
    return status_;
}
//.${AOs::Display::SM::On::AllOn::AllOnWaiting} ..............................
Q_STATE_DEF(Display, AllOnWaiting) {
    QP::QState status_;
    switch (e->sig) {
        //.${AOs::Display::SM::On::AllOn::AllOnWaiting}
        case Q_ENTRY_SIG: {
            BSP::ledOff();
            status_ = Q_RET_HANDLED;
            break;
        }
        //.${AOs::Display::SM::On::AllOn::AllOnWaiting::DISPLAY_FRAME_TIMEOUT}
        case DISPLAY_FRAME_TIMEOUT_SIG: {
            status_ = tran(&AllOnDisplaying);
            break;
        }
        default: {
            status_ = super(&AllOn);
            break;
        }
    }
    return status_;
}
//.${AOs::Display::SM::On::AllOn::AllOnDisplaying} ...........................
Q_STATE_DEF(Display, AllOnDisplaying) {
    QP::QState status_;
    switch (e->sig) {
        //.${AOs::Display::SM::On::AllOn::AllOnDisplaying}
        case Q_ENTRY_SIG: {
            BSP::ledOn();
            status_ = Q_RET_HANDLED;
            break;
        }
        //.${AOs::Display::SM::On::AllOn::AllOnDisplaying::DISPLAY_FRAME_TIMEOUT}
        case DISPLAY_FRAME_TIMEOUT_SIG: {
            status_ = tran(&AllOnWaiting);
            break;
        }
        default: {
            status_ = super(&AllOn);
            break;
        }
    }
    return status_;
}

} // namespace AC
//.$enddef${AOs::Display} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
