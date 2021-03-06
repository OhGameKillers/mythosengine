//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//                   DOS Version                             | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//    Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// vngpal.cpp
//
//     The C++ palette classes for the VanGogh Draw library.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <assert.h>

#include "debug.h"
#include "portable.h"
#include "ivory.h"
#include "felix.hpp"
#include "xfile.hpp"

#include "vngdefs.h"
#include "vngcolor.hpp"
#include "vngpal.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�


//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭 VngoHwPal 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoHwPal::init(VngoColor24bit pal[],int count);                         �
//     This function sets the first count number of palette entries to the  �
//     the values stored in the pal array that is passed in.  It does not   �
//     modeify the current state of the hardware, it simply modifies the    �
//     table entries.  If you pass in the flag VNGO_PAL_HWINIT, it will     �
//     update the hardware as well.                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int VngoHwPal::init(VngoColor24bit pal[],int count)
{
    for (int i=0;i < count;i++)
    {
        p[i] = pal[i];
    }
    return (0);
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭� VngoPal 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPal::release                                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void VngoPal::release()
{
    if ((flags & VNGO_MYMEM_SHADE) && shd_pal)
    {
        delete shd_pal;
        shd_pal = NULL;
        flags &= ~VNGO_MYMEM_SHADE;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPal::~VngoPal();                                                     �
//     This is the destructor for the VngoPal.  It will delete any memory   �
//     that was allocated during the construction of this class.            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
VngoPal::~VngoPal()
{
    if ((flags & VNGO_MYMEM_SHADE) && shd_pal)
    {
        delete shd_pal;
        shd_pal = NULL;
        flags &= ~VNGO_MYMEM_SHADE;
    }
#if 0
    if ((flags & VNGO_MYMEM_HAZE) && hz_pal)
    {
        delete hz_pal;
        hz_pal = NULL;
        flags &= ~VNGO_MYMEM_HAZE;
    }
#endif
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPal8::VngoPal8();                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
VngoPal8::VngoPal8()
{
    // No special construction, just the ol' vtable stuff
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPal8::~VngoPal8();                                                   �
//     This is the destructor for the VngoPal.  It will delete any memory   �
//     that was allocated during the construction of this class.            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
VngoPal8::~VngoPal8()
{
    if ((flags & VNGO_MYMEM_SHADE) && shd_pal)
    {
        delete (VngoShadePal8 *)shd_pal;
        shd_pal = NULL;
        flags &= ~VNGO_MYMEM_SHADE;
    }
#if 0
    if ((flags & VNGO_MYMEM_HAZE) && hz_pal)
    {
        delete hz_pal;
        hz_pal = NULL;
        flags &= ~VNGO_MYMEM_HAZE;
    }
#endif
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPal8::release                                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void VngoPal8::release()
{
    if ((flags & VNGO_MYMEM_SHADE) && shd_pal)
    {
        delete (VngoShadePal8 *)shd_pal;
        shd_pal = NULL;
        flags &= ~VNGO_MYMEM_SHADE;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPal::init(dword _flags,VngoHwPal *hw,VngoShadePal *hz);              �
//     This function will allocate memory for any of the structures that    �
//     you do not pass a buffer in for.                                     �
//     If you pass in the VNGO_PAL_HWINIT flag, it will write the passed in �
//     hardware palette, if you didn't pass in a VngoHwPal then this flag is�
//     ignored.                                                             �
//     If you pass in the VNGO_PAL_CALC flag, it will initialize the all    �
//     three of the calculated tables in this order:                        �
//         1)  Color conversion table.                                      �
//         2)  Shade Palette table.                                         �
//         3)  Haze Palette table.                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int VngoPal8::init(dword _flags,VngoHwPal *hw,VngoShadePal8 *sh)
{
    if (hw)
    {
        for (int i=0;i < 256;i++)
        {
            hw_pal.p[i] = hw->p[i];
        }
    }
    if (!sh)
    {
        if (!shd_pal)
        {
            shd_pal = (VngoShadePal *)new VngoShadePal8 (32);
            flags |= VNGO_MYMEM_SHADE;
        }
        // Once there is a mechanism to initialize the palette with a specified
        // number of shade levels rather than the hard coded 32, then more
        // checking will need to be done here.
    }
    else
    {
        shd_pal = (VngoShadePal *)sh;
    }


    if (_flags & VNGO_PAL_CALC)
    {
        convert.init(this,1);
    }
    else
    {
        convert.init(this);
    }

    return (0);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPal::init(dword _flags,const char *palfile);                         �
//     This function will load a palette from a file whos name is passed in.�
//     It will fist initialize a palette to get all of the required memory  �
//     allocated, and will not do any of the calculations.  It will then    �
//     read the palette from the specified file, and write it to the        �
//     physical device if the VNGO_PAL_HWINIT flag was passed to it.        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int VngoPal8::init(dword _flags,const char *palfile)
{
    int         err;
    VngoPalIFF8 loadpal(this);

    init(0);
    err=loadpal.load(palfile);

    return (err);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPal::init(dword _flags,char *palfile);                               �
//     This function will load a palette from a file whos name is passed in.�
//     It will fist initialize a palette to get all of the required memory  �
//     allocated, and will not do any of the calculations.  It will then    �
//     read the palette from the specified file, and write it to the        �
//     physical device if the VNGO_PAL_HWINIT flag was passed to it.        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int VngoPal8::init(dword _flags,XFParseIFF *palfile)
{
    int         err;
    VngoPalIFF8 loadpal(this);

    init(0);
    err=loadpal.load(palfile);

    return (err);
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭� VngoPalIFF8 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPalIFF8::VngoPalIFF8();                                              �
//     This  constructor will set the palettes name to 'Default' and set the�
//     palette pointer to NULL.  No reading or writing will take place.     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
VngoPalIFF8::VngoPalIFF8()
{
    name[0]='D';
    name[1]='e';
    name[2]='f';
    name[3]='a';
    name[4]='u';
    name[5]='l';
    name[6]='t';
    name[7]=0;

    pal = NULL;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPalIFF8::VngoPalIFF8(VngoPal *p);                                    �
//     This  constructor will set the palettes name to 'Default' and set the�
//     palette pointer to the passed in palette. No file IO will take place.�
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
VngoPalIFF8::VngoPalIFF8(VngoPal *p)
{
    name[0]='D';
    name[1]='e';
    name[2]='f';
    name[3]='a';
    name[4]='u';
    name[5]='l';
    name[6]='t';
    name[7]=0;

    pal = (VngoPal8 *)p;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPalIFF8::save(const char *filename);                                 �
//     This  will save the palette that is associated with the object to the�
//     file specified in the parameters.  All fields will be stored to the  �
//     file, including the name.                                            �
//     It returns any errors that may occur during the file IO.             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int VngoPalIFF8::save(const char *filename)
{
    XFParseIFF  iffp;
    int         err=0;

    // Assert that there is memory allocated for all fields.
    assert(pal != NULL);
    assert(pal->shd_pal != NULL);
//    assert(pal->hz_pal != NULL);

    err=iffp.create(filename,0);
    if (err)
        return(err);

    err = save(&iffp);
    if (err)
        return (err);

    return ( iffp.close() );
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPalIFF8::save(XFParseIFF *iffp);                                     �
//     This  will save the palette that is associated with the object to the�
//     file specified in the parameters.  All fields will be stored to the  �
//     file, including the name.                                            �
//     It returns any errors that may occur during the file IO.             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int VngoPalIFF8::save(XFParseIFF *iffp)
{
    int             err=0;
    VngoShadePal8   *tpal = (VngoShadePal8 *)pal->shd_pal;

    // Assert that there is memory allocated for all fields.
    assert(pal != NULL);
    assert(pal->shd_pal != NULL);
    //assert(tpal->hz_pal != NULL);

    err = iffp->newform(iffp->makeid('V','P','A','L'));
    if (err)
        return(err);

    // ---- Write the name of the palette.
    err = iffp->write(iffp->makeid('n','a','m','e'),name,16);
    if (err)
        return(err);

    // ---- Save the shade palette.

    err = iffp->newform (iffp->makeid('s','h','d','P'));
    if (err)
        return(err);

    VngoShadePal::HDR hdr;
    hdr.type = VNGO_8BIT;
    hdr.num_levels = tpal->num_shd_lvl;
    hdr.level_bits = tpal->num_shd_lvl_bits;
    hdr.mid_point  = tpal->mid_point;

    // output the number of shade levels in the shade palette.
    err = iffp->write(iffp->makeid ('H','D','R',' '), &hdr, sizeof(hdr));
    if (err)
        return(err);

    dword id = iffp->makeid('s','h','d','L');
    for (int i=0; i < VNGO_PAL_SIZE;i++)
    {
        err = iffp->write (id, &(*tpal)[i], tpal->num_shd_lvl * sizeof (byte));
        if (err)
            return(err);
    }

    iffp->leaveform();


    // ---- Save the hardware palette.
    err = iffp->write(iffp->makeid('h','w','d','P'), &((VngoPal8 *)pal)->hw_pal,sizeof(VngoHwPal));
    if (err)
        return(err);

    // ---- Save the color conversion table.
    err = iffp->write(iffp->makeid('c','n','v','t'),&((VngoPal8 *)pal)->convert,sizeof(VngoClrConvert));
    if (err)
        return(err);

    err = iffp->leaveform();

    return(err);

}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPalIFF8::load(const char *filename);                                 �
//     This  will load the palette that is associated with the object to the�
//     file specified in the parameters.  All fields will be read from the  �
//     file, including the name.                                            �
//     It returns any errors that may occur during the file IO.             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int VngoPalIFF8::load(const char *filename)
{
    XFParseIFF      iffp;
    int             err=0;

    // Assert that there is memory allocated to load into.
    assert(pal != NULL);
    assert(pal->shd_pal != NULL);
    //assert(pal->hz_pal != NULL);

    err=iffp.open(filename,XF_OPEN_READ);
    if (err)
        return (err);

    err = load(&iffp);
    if (err)
        return (err);

    return (iffp.close() );
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPalIFF8::load(XFParseIFF *iffp);                                     �
//     This  will load the palette that is associated with the object to the�
//     file specified in the parameters.  All fields will be read from the  �
//     file, including the name.                                            �
//     It returns any errors that may occur during the file IO.             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int VngoPalIFF8::load(XFParseIFF *iffp)
{
    int             err=0;
    VngoShadePal8   *tpal = (VngoShadePal8 *)pal->shd_pal;

    // Assert that there is memory allocated to load into.
    assert(tpal != NULL);
    assert(pal->shd_pal != NULL);
    //assert(pal->hz_pal != NULL);

find_pal:

    err = iffp->seekform(iffp->makeid('V','P','A','L'));
    if (err)
        return (err);

    err = iffp->enterform();
    if (err)
        return (err);

    char nbuff[16];
    err = iffp->seekchunk (iffp->makeid('n','a','m','e'));
    if (err)
        return err;

    if (sizeof(nbuff) < iffp->chunkSize)
        return XF_ERR_CHUNKNOTFOUND;

    err = iffp->read(nbuff);
    if (err)
        return err;

    if (strcmp(name,"Default"))
    {
        if (strcmp(name,nbuff))
        {
            iffp->leaveform();
            goto find_pal;
        }
    }

    strncpy(name,nbuff,16);

    // ---- Find and read the shade palette.

    err = iffp->seekform (iffp->makeid('s','h','d','P'));
    if (err)
        return(err);

    err = iffp->enterform();
    if (err)
        return (err);

    VngoShadePal::HDR hdr;
    err = iffp->seekchunk (iffp->makeid ('H','D','R',' '));
    if (err)
        return (err);

    if (sizeof (hdr) != iffp->chunkSize)
        return XF_ERR_CHUNKNOTFOUND;

    err = iffp->read (&hdr);
    if (err)
        return (err);

    if (hdr.type != VNGO_8BIT)
        return XF_ERR_CHUNKNOTFOUND;

    // Get the new information
    tpal->num_shd_lvl = hdr.num_levels;
    tpal->num_shd_lvl_bits = hdr.level_bits;
    tpal->mid_point = hdr.mid_point;

    dword id = iffp->makeid('s','h','d','L');
    for (int i=0; i < VNGO_PAL_SIZE; i++)
    {
        err = iffp->seekchunk (id);
        if (err)
            return (err);

        if (tpal->num_shd_lvl * sizeof (byte) != iffp->chunkSize)
            return XF_ERR_CHUNKNOTFOUND;

        err = iffp->read (&(*tpal)[i]);
        if (err)
            return (err);
    }
    iffp->leaveform();


    // ---- Find and read the hardware palette.
    err = iffp->seekchunk(iffp->makeid('h','w','d','P'));
    if (err)
        return (err);

    err = iffp->read(&((VngoPal8 *)pal)->hw_pal);
    if (err)
        return (err);

    // ---- Find and read the color conversion table.
    err = iffp->seekchunk(iffp->makeid('c','n','v','t'));
    if (err)
        return (err);

    err = iffp->read(&((VngoPal8 *)pal)->convert);
    if (err)
        return (err);

    // ---- Clean up and close down.
    err = iffp->leaveform();

    return (err);
}

//葦� End of module - vngpal.cpp 憶�
