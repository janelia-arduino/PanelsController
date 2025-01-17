//.$file${./ArenaControlle~::Region.cpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: ArenaController.qm
// File:  ${./ArenaControlle~::Region.cpp}
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
//.$endhead${./ArenaControlle~::Region.cpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include "ArenaController.hpp"  // ArenaController application interface


using namespace QP;

//============================================================================
// generate declaration of the active object
//.$declare${AOs::Region} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
namespace AC {

//.${AOs::Region} ............................................................
class Region : public QP::QHsm {
public:
    static Region instances[constants::region_count_per_frame_max];

public:
    Region()
      : QHsm(&initial)
    {}

protected:
    Q_STATE_DECL(initial);
    Q_STATE_DECL(state1);
};

} // namespace AC
//.$enddecl${AOs::Region} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//============================================================================
// generate definition of to opaque pointer to the AO
//$define${Shared::AO_Region}

//============================================================================
// generate definition of the AO
//.$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//. Check for the minimum required QP version
#if (QP_VERSION < 690U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpcpp version 6.9.0 or higher required
#endif
//.$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//.$define${AOs::Region} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
namespace AC {

//.${AOs::Region} ............................................................
Region Region::instances[constants::region_count_per_frame_max];
//.${AOs::Region::SM} ........................................................
Q_STATE_DEF(Region, initial) {
    //.${AOs::Region::SM::initial}
    return tran(&state1);
}
//.${AOs::Region::SM::state1} ................................................
Q_STATE_DEF(Region, state1) {
    QP::QState status_;
    switch (e->sig) {
        default: {
            status_ = super(&top);
            break;
        }
    }
    return status_;
}

} // namespace AC
//.$enddef${AOs::Region} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
