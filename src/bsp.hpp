//.$file${.::bsp.hpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: ArenaController.qm
// File:  ${.::bsp.hpp}
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
//.$endhead${.::bsp.hpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#ifndef BSP_HPP
#define BSP_HPP
#include "Constants.hpp"

class BSP {
public:
    enum { TICKS_PER_SEC = 100} ;

    static void init(void);
    static void pollSerialCommand(void);
    static void ledOff(void);
    static void ledOn(void);
    static void armDisplayFrameTimer(uint32_t frequency_hz);
    static void disarmDisplayFrameTimer();
};

#endif // BSP_HPP