//���������������������������������������������������������������������������
//                  ooo        ooooo
//                  `88.       .888'
//                   888b     d'888   .oooo.   oooo    ooo
//                   8 Y88. .P  888  `P  )88b   `88b..8P'
//                   8  `888'   888   .oP"888     Y888'
//                   8    Y     888  d8(  888   .o8"'88b
//                  o8o        o888o `Y888""8o o88'   888o
//
//                          Across the event horizon...
//
//           Copyright (c) 1994 - 1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//���������������������������������������������������������������������������
//
//           *** Charybdis Enterprises, Inc. Company Confidential ***
//
//  This file and all associated files are the company proprietary property
//        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
//
// CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
// TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
// AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//���������������������������������������������������������������������������
//
// Events
//
//      This module defines the types used in the Event system.
// The following types are defined within:
//  Event -- The concept of an event that the user is interested in,
//          such as "balance shields", or "fire lasers".
//  EventList -- A collection of Events.  Events may be added to or removed
//          from the list, as well as checked for presence.  Technically,
//          this structure is a Set, but List is close enough. :-)
//  EventTrigger -- A user action, classified in terms of keypress
//          combinations and mouse moves/button presses.
//
//���������������������������������������������������������������������������

#ifndef __MAXEVT_HPP
#define __MAXEVT_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//
//                                Includes
//
//���������������������������������������������������������������������������

#include <string.h>
#include <portable.h>

#include "maxdevs.hpp"

//���������������������������������������������������������������������������
//
//                                Pragmas
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������


const int EVENT_MAX_EVENT = 512;

//���������������������������������������������������������������������������
// The notion of a unique event.
//���������������������������������������������������������������������������
class MaxEvent
{
private:
        word    packed;

public:
        // Constructor to create a specific Event.
        MaxEvent (int event_number);

        // Events can be compared for equality
        int operator == (const MaxEvent &evt) const;

        // These two members return the information packed into the event
        int offset () const;
        int mask () const;
};

//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// The notion of an "event mask", or collection of events.
//���������������������������������������������������������������������������
class MaxEventList
{
        byte    mask[EVENT_MAX_EVENT / 8];

public:
        MaxEventList (int init = 0);

        // Event presence members
void    add (const MaxEvent);
void    remove (const MaxEvent);

int     check (const MaxEvent) const;
int     empty () const;

        // This class is a friend for efficiency's sake;
        // Although it can be implemented with the boolean functions,
        // direct access is faster.  (It's good to be the implementer!)
        friend class MaxEventListOneshot;
        friend class MaxEventListToggle;

        // Now for some boolean operations on MaxEventLists
MaxEventList    operator ~() const;
MaxEventList    operator ^ (const MaxEventList &) const;
MaxEventList    operator | (const MaxEventList &) const;
MaxEventList    operator & (const MaxEventList &) const;

        // An a few assignment operators, to boot!
MaxEventList    &operator  = (const MaxEventList &);
MaxEventList    &operator ^= (const MaxEventList &);
MaxEventList    &operator |= (const MaxEventList &);
MaxEventList    &operator &= (const MaxEventList &);
};


//���������������������������������������������������������������������������


//���������������������������������������������������������������������������
//  The Oneshot class provides a rising-edge detector for event streams.
//  This class works like the Toggler below, except that it only returns
//  and event the first time it is present.
//���������������������������������������������������������������������������
class MaxEventListOneshot
{
        MaxEventList    triggers;

public:
        MaxEventListOneshot ():
            triggers (0)
        {
        }


        // Process the given event list, and return the toggle list,
        // which can be interpreted as the list of "on" events.
        MaxEventList process (const MaxEventList &elist)
        {
#ifdef USE_BOOLEAN_MEMBERS
            MaxEventList toggles = elist & ~triggers;
            triggers = elist;
#else
            MaxEventList toggles;
            for (int i = 0; i < EVENT_MAX_EVENT/32; i++)
            {
                ((dword *)toggles.mask)[i]  = ((dword *)elist.mask)[i] & ~((dword *)triggers.mask)[i];
                ((dword *)triggers.mask)[i] = ((dword *)elist.mask)[i];
            }
#endif
            return toggles;
        }

        // Wipe out the triggers and toggles.  (Return to initial state)
        void reset ()
        {
            memset (triggers.mask, 0, sizeof (triggers.mask));
        }
};


//���������������������������������������������������������������������������
//  This odd class is a utility to allow an application to easily keep
//  a list of which events are toggled on.  In this class, all events
//  passed in to the toggler will be toggled on/off depending on their
//  presence in the new event list.
//  Basically, and event is toggled every time its "leading edge" occurs,
//  much like a leading-edge-triggered electrical circuit.
//���������������������������������������������������������������������������
class MaxEventListToggle
{
        MaxEventList    toggles;
        MaxEventList    triggers;

public:
        MaxEventListToggle ():
            toggles (0),
            triggers (0)
        {
        }

        // Process the given event list, and return the toggle list,
        // which can be interpreted as the list of "on" events.
        MaxEventList &process (const MaxEventList &elist)
        {
#ifdef USE_BOOLEAN_MEMBERS
            toggles ^= elist & ~triggers;
            triggers = elist;
#else
            for (int i = 0; i < EVENT_MAX_EVENT/32; i++)
            {
                ((dword *)toggles.mask)[i] ^= ((dword *)elist.mask)[i] & ~((dword *)triggers.mask)[i];
                ((dword *)triggers.mask)[i] = ((dword *)elist.mask)[i];
            }
#endif
            return toggles;
        }

        // Set the given toggle to "on"
        void set (const MaxEvent evt)
        {
            toggles.add (evt);
            triggers.add (evt);
        }

        // Clear a specific event toggle
        void clear (const MaxEvent evt)
        {
            toggles.remove (evt);
            //--- Leave these: triggers.remove (evt);
        }

        // Wipe out the triggers and toggles.  (Return to initial state
        void reset ()
        {
            for (int i = 0; i < EVENT_MAX_EVENT/32; i++)
                ((dword *)toggles.mask)[i] = ((dword *)triggers.mask)[i] = 0;
        }
};

//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// The specification of a set of input conditions
// (usually associated with an Event)
// This class needs a few utility members, but it's usable as-is.
//���������������������������������������������������������������������������
class MaxTrigger
{
public:
        enum    { max_keys = 4 };

        word    Keys[max_keys];     // Up to 3 keys can be specified in order
                                    // to generate the specified event.
        word    MouseButtons;       // Bit 0 = Button 1
                                    // Bit 1 = Button 2, etc
        word    JoyButtons;         // Bit 0 = Button 1
                                    // Bit 1 = Button 2, etc
        short   BegX, EndX;         // Cursor X ranges for Mouse & Joystick.
        short   BegY, EndY;         // Cursor Y ranges for Mouse & Joystick.
        short   DeltaX, DeltaY;     // Motion required for event to be valid.

public:
        MaxTrigger ();

        // Triggers are identical if their memory images match.
        int operator == (const MaxTrigger &) const;

        // Compare this EventTrigger's conditions against real devices
        int check (const MaxDevices &) const;

        // Determine the device requirements of this trigger
        int uses_mouse () const;
        int uses_keyboard () const;
        int uses_joystick () const;
};


//���������������������������������������������������������������������������
//
//                               Inlines
//
//���������������������������������������������������������������������������


// These members are inlined for efficiency since the compiler can
// often do fun things with the code if we give it some leeway.
inline MaxEvent::MaxEvent (int event_number):
    packed (word (((event_number >> 3) << 8) +
                  (1 << (event_number & 0x7))))
{
}

inline int MaxEvent::operator == (const MaxEvent &evt) const
{
    return packed == evt.packed;
}


inline int MaxEvent::offset () const
{
    return packed >> 8;
}

inline int MaxEvent::mask () const
{
    return packed & 0xff;
}

//���������������������������������������������������������������������������

inline MaxEventList::MaxEventList (int init)
{
    memset (mask, init ? 0xff: 0, sizeof (mask));
}

inline void MaxEventList::add (const MaxEvent evt)
{
    mask[evt.offset()] |= byte (evt.mask());
}

inline void MaxEventList::remove (const MaxEvent evt)
{
    mask[evt.offset()] &= byte (~evt.mask());
}

inline int MaxEventList::check (const MaxEvent evt) const
{
    return (mask[evt.offset()] & evt.mask()) != 0;
}


//���������������������������������������������������������������������������

inline int MaxTrigger::operator == (const MaxTrigger &et) const
{
    return memcmp (this, &et, sizeof (MaxTrigger)) == 0;
}

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - maxevt.hpp ���
