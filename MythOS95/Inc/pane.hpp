//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//������������������旭旭旭�����旭旭旭姻���旭�����旭姻旭旭旭旭旭��������������
//�����������������葦姻���姻�葦姻���葦���葦姻���葦姻葦姻���������������������
//����������������碓甥���甥�碓甥����臼��碓碓���碓甥碓甥����������������������
//���������������渦臼葦渦��渦臼葦渦臼��渦臼姻�憶甥渦臼葦渦�������������������
//��������������渦甥������憶�����渦甥�渦甥�悔渦甥渦甥������������������������
//�������������憶悔������憶悔���憶悔�憶悔��臆渦�憶悔�������������������������
//������������臆悔������臆悔���臆悔�臆悔���臆悔臆臆臆臆臆��������������������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1996-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
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
// Created by Sean Gallagher
//
// pane.hpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __PANE_HPP
#define __PANE_HPP    1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <vangogh.hpp>
#include <max.hpp>
#include <gutenbrg.hpp>
#include <chronos.hpp>

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Defines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define IMAGE_SCROLL_LEFT    1
#define IMAGE_SCROLL_RIGHT   2
#define IMAGE_SCROLL_UP      3
#define IMAGE_SCROLL_DOWN    4

#define KEY_LEFT_ARROW      0x14B
#define KEY_RIGHT_ARROW     0x14D
#define KEY_BACKSPACE       0x008
#define KEY_ESCAPE          0x01B
#define KEY_ENTER           0x00D
#define KEY_DELETE          0x153
#define KEY_DOUBLEQUOTE     0x022
#define KEY_ASTERISK        0x02A
#define KEY_QUESTIONMARK    0x03F
#define KEY_FWDSLASH        0x02F
#define KEY_BACKSLASH       0x05C
#define KEY_PIPE            0x07C

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Template
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneDieT template
//
// A random roller class template
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
template<int sides>
class PaneDieT
{

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    PaneDieT()
    {
        clock_t time = chronos_time_now();

        srand(time);
    }

    PaneDieT(int dummy) {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    int roll()
    {
        int random (rand());
        int res = random % sides;

        if (res < 0)
            res = abs(res);

        return res + 1;
    }

    operator int () { return roll(); }
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneImageScroll class
//
// A scrolling image viewer
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class PaneImageScroll
{
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Data                                                                 �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    int         scroll_delta;      // scroll increment/decrement

    int         img_x;             // The x,y in the image to be drawn
    int         img_y;             // to the viewport

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    PaneImageScroll(VngoVport *gvp, VngoTexture *img,
                    int vp_x, int vp_y, int delta);
    ~PaneImageScroll() { }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public Data                                                          �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    VngoVport   *gvport;
    VngoTexture *image;

    int         map_x;            // The last selected coords
    int         map_y;            // in map coords

    int         vp_anchor_x;
    int         vp_anchor_y;      // upper left of list box in screen coords

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Display
    void        render();
    void        scroll(int direction);
    void        scroll_up()     { scroll(IMAGE_SCROLL_UP);      }
    void        scroll_down()   { scroll(IMAGE_SCROLL_DOWN);    }
    void        scroll_left()   { scroll(IMAGE_SCROLL_LEFT);    }
    void        scroll_right()  { scroll(IMAGE_SCROLL_RIGHT);   }

    //陳� General operations
    void        center_image(int x = -1, int y = -1);
    void        drag_image(int ax, int ay, int x, int y);
    int         get_scroll_x() { return img_x; }
    int         get_scroll_y() { return img_y; }
    void        reset_image() { img_x = img_y = 0; render(); }
    void        set_scroll_delta(int delta) { scroll_delta = delta; }
    void        set_image_pos(int newx,int newy) { img_x = -newx; img_y = -newy; }
    void        screen_to_image(short &x, short &y);
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneInputText class
//
// An edit field control
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class PaneInputText
{
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Data                                                                 �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    VngoVport           *gvport;
    MaxKbBuffer         *kbbuf;

    MaxKeyboard         *kbd;

    VngoRect            input_rect;

    char                *str;

    int                 str_len;
    int                 maxsize;
    int                 curs_pos;               // relative to string to str index
    int                 ibx;
    int                 iby;

    int                 mode;
    int                 cursor_type;

    dword               flags;

    dword               fg;                     // font colors
    dword               bg;

    char                font_type[GBERG_MAX_NAME];

    Chronometer         timer;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Data                                                                 �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    enum
    {
        INPUT           =0,
        RENDER          =1,
        INACTIVE        =2,
    };

    enum
    {
        INPUT_DRAW_OUTLINE          = 0x1,
        INPUT_SPEC_CHARS            = 0x2,
        INPUT_CLEAR_VPORT           = 0x4,
    };

    enum
    {
        CURSOR_UNDERLINE       =0,
        CURSOR_VERTICAL        =1,
        CURSOR_BLOCK           =2,
    };

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    PaneInputText(VngoVport *gvp, VngoRect *rct, char *fname);
    ~PaneInputText();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    BOOL        init(int sz, char *def_str, MaxKeyboard *kbd);
    BOOL        process_events();
    void        set_colors(dword _f, dword _b) { fg=_f; bg=_b; }
    void        set_cursor(int c) { cursor_type = c; }
    void        set_mode(int m);

    //陳� Display
    void        draw_cursor();
    void        draw_outline_box();
    void        render();
    void        clear_input();

    //陳� Input String operations
    char        back_space();
    int         ins_char(char c);
    char        del_char();

    //陳� Accessor functions
    char        *get_str(char *buff);
    void        put_str(char *new_str);
    int         query_mode() { return mode; }
    void        set_flags(dword _f) { flags = _f; }
    void        set_vport(VngoVport *vp) { gvport = vp; }
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneListBox class
//
// A listbox control
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class PaneListBox
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Equates                                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    enum direction_t
    {
        UP      =1,
        DOWN    =2,
    };

private:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Data                                                                 �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    char        *strings;
    ushort      font_width;

    ushort      row_height;

    VngoRect    vrc;

    ushort      max_string_len;
    ushort      max_string_entries;
    ushort      num_visible;
    ushort      first_visible;
    ushort      last_visible;
    ushort      cur_sel;

    ushort      spacing;          // number of spaces above and below each
                                  // character

    ushort      count;            // Number of strings in the list box

    ulong       screen_x;         // upper left of list box in screen coords
    ulong       screen_y;

    dword       fg;               // Foreground color for the list box
    dword       bg;               // Background color for the list box

    BOOL        hilite_cur_sel;

    ulong delete_data(ulong index);
    ulong insert_data(ulong index, void *extra);

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    PaneListBox(VngoVport *gvp, const char *f_type);
    ~PaneListBox();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public Data                                                          �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    VngoVport   *gvport;

    void        *edata_ptr;
    ulong       sizeof_edata;

    char        font_type[GBERG_MAX_NAME];

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Initialize
    BOOL        init(short sx, short sy,
                     ushort maxlen, ushort maxentries,
                     ulong sedata=0, ushort _spc = 0);

    //陳� Release data
    void        release();

    //陳� Display
    void        render();
    void        scroll(direction_t);
    void        scroll_up() { scroll(UP); }
    void        scroll_down() { scroll(DOWN); }
    void        set_colors(dword _f, dword _b) { fg=_f; bg=_b; }

    //陳� General operations
//    ulong       find_insertion_index(ulong ind);
    int         get_pick_index(int x, int y);
    void       *get_item_data(ulong index);
    void        get_selected_item(ulong index, char *dest);

    ushort      set_cur_sel(ulong index);
    ushort      set_font(const char *f_type);
    void        set_hilite(BOOL f) { hilite_cur_sel = f; }
    ulong       set_top_index(ulong index);

    //陳� String operations
    ushort      add_string(const char *new_str, void *extra = 0);
//    ushort      add_string(ulong id, void *extra = 0);
    ushort      delete_string(ulong index);
    ushort      insert_string(ulong index, const char *ins_str, void *extra=0);
    void        reset_content();
    void        set_selected_item(ulong index, char *src);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Accessor functions                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    ushort      get_bottom_index()
    {
        if (count)
            return count-1;
        else
            return 0;
    }
    ushort      get_count() { return count; }
    ushort      get_cur_sel() { return cur_sel; }
    ushort      get_num_visible() { return num_visible; }
    ushort      get_top_index() { return first_visible; }
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneDie
//
// A random roll class
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class PaneDie
{
    int sides;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    PaneDie(int _sides=2):
        sides(_sides)
    {
        clock_t time = chronos_time_now();

        srand(time);
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    int roll()
    {
        int random (rand());
        int res = random % sides;

        if (res < 0)
            res = abs(res);

        return res + 1;
    }

    int roll(int _sides)
    {
        int random (rand());
        int res = random % _sides;

        if (res < 0)
            res = abs(res);

        return res + 1;
    }

    operator int () { return roll(); }
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneTextScroll class
//
// A text scrolling class
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class PaneTextScroll
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Equates                                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    enum direction_t
    {
        UP      =1,
        DOWN    =2,
        PAGEUP  =3,
        PAGEDN  =4,
    };

private:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Data                                                                 �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    char        *text;
    ulong       font_height;
    ulong       font_width;
    VngoRect    vrc;

    ulong       string_len;
    ulong       max_chars_per_line;
    ulong       cur_line;
    ulong       num_lines;
    ulong       visible_lines;

    dword       fg;               // Foreground color for the list box
    dword       bg;               // Background color for the list box

    ulong       count_lines(char *sp);
    BOOL        parse_string(char *sp);

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    PaneTextScroll(VngoVport *gvp, const char *f_type);
    ~PaneTextScroll();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public Data                                                          �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    VngoVport   *gvport;
    char        font_type[GBERG_MAX_NAME];

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Initialize (1 on success, 0 otherwise)
    BOOL        init(char *txt);

    //陳� Release data
    void        release();

    //陳� Display
    void        render();
    void        set_colors(dword _f, dword _b) { fg=_f; bg=_b; }

    //陳� General operations
    void        scroll(direction_t);
    void        scroll_up() { scroll(UP); }
    void        scroll_down() { scroll(DOWN); }
    void        page_up() { scroll(PAGEUP); }
    void        page_down() { scroll(PAGEDN); }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Accessor functions                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
};

#endif

//葦� end of header - pane.hpp 憶�
