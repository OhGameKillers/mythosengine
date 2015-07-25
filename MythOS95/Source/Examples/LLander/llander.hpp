//���������������������������������������������������������������������������
//
//                                /\    /\
//                               /  \  /  \
//                              /    \/    \
//                             /  /\    /\  \
//                            /  /  \  /  Y T H O S
//                           /  /    \/    \  \
//                          /  /            \  \
//                         /__/              \__\
//
//                      Microsoft Windows '95 Version
//
//            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
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
//                          LUNAR LANDER EXAMPLE
//
// Created by Chuck Walbourn and Dan Higdon
//
// llander.hpp
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//
//���������������������������������������������������������������������������

#include <simgine.hpp>

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//��������������������������� Primary Game State ����������������������������
//���������������������������������������������������������������������������

class Terrain;

//���������������������������������������������������������������������������
// LanderNetwork
//���������������������������������������������������������������������������
class LanderNetwork : public TurnerNetwork
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    LanderNetwork (int players = 2);

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual int handle_msg (DPID, DPID, void *, size_t);
    virtual int sys_newplayer (DPID, LPCSTR, LPCSTR);
    virtual int sys_delplayer (DPID);
};


//���������������������������������������������������������������������������
// Lander - The actual vehicle moving under the player's control.
//���������������������������������������������������������������������������
class Lander
{
    MaxEventSource  *evt;

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    BYTE        lander_color;
    BYTE        flame_color;
    BYTE        *lander_image;
    BYTE        *lander_image_lowburn;
    BYTE        *lander_image_highburn;
    BYTE        *lander_image_leftburn;
    BYTE        *lander_image_rightburn;

    time_t      start_time;
    time_t      last_update;
    DWORD       jcenterx;
    DWORD       jcentery;
    float       gravity;
    float       xacceleration;
    float       yacceleration;
    float       xvelocity;
    float       yvelocity;
    float       xpos;
    float       ypos;
    BOOL        remote;
    BOOL        active;
    DPID        player_id;
    RECT        damage;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    Lander  (MaxEventSource *, BOOL remote = FALSE,
             VngoColor24bit = VngoColor24bit (128, 128, 128));
    ~Lander ();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    void step ();

    void reset (float x = 0, float y = 10);

    void process_events ();
    void update_model ();
    BOOL load_images ();

    void draw (VngoVport *);

    float get_thrust () const
    {
        return flx_abs (yacceleration) + flx_abs (xacceleration);
    }

    BOOL too_fast () const
    {
        return (xvelocity < -15
                || yvelocity > 15
                || xvelocity < -5
                || xvelocity > 5);
    }

    BOOL collided (Terrain *);
    BOOL landed (Terrain *);
};


//���������������������������������������������������������������������������
// Terrain - The terrain is the moon's surface.
//���������������������������������������������������������������������������
class Terrain
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    WORD        *aHeights;
    WORD        cHeights;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    Terrain (int num);
    ~Terrain ();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    void        draw     (VngoVport *) const;
    WORD        col_size (int wid) const { return wid / cHeights; }
};


//���������������������������������������������������������������������������
// LanderGame - Main state for lander game
//���������������������������������������������������������������������������
class LanderGame : public SimState
{
    VngoVport       *vport;

    MaxEventUser    *evt;

    UINT            frame;
    Chronometer     timer;

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    enum        { NUM_LANDERS = 4 };
    Lander      *aLanders[NUM_LANDERS];
    Terrain     terrain;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    LanderGame();
    virtual ~LanderGame();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();

    void    draw_terrain ();

    Lander *get_lander (DPID player);
    Lander *init_lander (DPID player);
    void kill_lander (DPID player);

    void restore (LPRECT);
};



//���������������������������������������������������������������������������
//��������������������������� Misc Game States ������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// LanderTitle
//���������������������������������������������������������������������������
class LanderTitle : public SimState
{
    MaxEventUser    *evt;

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    EschScene       *scene;
    VngoVport       *vport;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    LanderTitle();
    virtual ~LanderTitle();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();
};


//���������������������������������������������������������������������������
// LanderEnd
//���������������������������������������������������������������������������
class LanderEnd : public SimState
{
    MaxEventUser    *evt;

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    int         crashed;
    int         lander_dx;
    int         lander_dy;
    int         frame_rate;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    LanderEnd();
    virtual ~LanderEnd();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();
};



//���������������������������������������������������������������������������
//���������������������������� Application Class  ���������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// LanderApp
//���������������������������������������������������������������������������
class LanderApp : public SimGine
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    LanderTitle *title;
    LanderGame  *game;
    LanderEnd   *end;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    LanderApp();
    virtual ~LanderApp();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual BOOL init_instance();
    virtual int exit_instance();
};

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern LanderApp theSim;

extern char szINI[];
extern char szIFF[];

//��� End of header - llander.hpp ���
