//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
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
// Created by Paul Masters
//
// eslimbsg.cpp
//
// Contains the code for the EschLimbSegment class.  This class is
// the base class for a constrained pitch, yaw, roll object.  The LimbSegment
// is assumed to be a part of an EschLimb object which is a collector class.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <stdio.h>

#include "escher.hpp"

#include "estoken.hpp"
#include "esfile.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegment - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschLimbSegment::EschLimbSegment() :
    EschKeyframeDraw(),
    secondary_pitch (0),
    secondary_roll (0),
    secondary_yaw (0),
    fore_pitch (0),
    side_pitch (0)
{
    for (int i=0; i<ESCH_MAX_SIMULTANEOUS; i++)
    {
        interim[i].rotations.i = 0.0f;
        interim[i].rotations.j = 0.0f;
        interim[i].rotations.k = 0.0f;
        pre_interim[i].rotations.i = 0.0f;
        pre_interim[i].rotations.j = 0.0f;
        pre_interim[i].rotations.k = 0.0f;
    }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegment - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschLimbSegment::~EschLimbSegment()
{
};



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegment - step
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschLimbSegment::step(float interval, float scalar)
{
    int retval=0;
    int retval2=0;

    for (int i=0; i<key_chain_count; i++)
    {
//        if (tween_step[i] >= 1.0f)
        {
            retval = get_next_key(i, interval);
            if (retval >= 0)
            {
                if (keyheads[i]->root->flags & ESCH_KEYFRAME_SWAPPING_1
                    || keyheads[i]->root->flags & ESCH_KEYFRAME_SWAPPING_2)
                {
                    tween_step[i] = 2 * step_times[i];
                }
                else
                {
                    tween_step[i] = step_times[i];
                }
                calc_step(i);
                init_tween(i);
                if (scalar != 0.0f)
                {
                    scale_step(i, scalar);
                }
            }
        }
    }
    if ((key_chain_count)&&(retval>=0))
    {
        build_keyframe(scalar, interval);
        do_rotations(&work);
    }

    if ((!(k_type & ESCH_KEYFRAME_ROOT)) &&
        next() &&
        (next()->get_type()==ESCH_DRWT_SKELETON))
    {
        retval2 = ((EschLimbSegment *)next())->step(interval, scalar);

    }
    if (child() &&
        (child()->get_type()==ESCH_DRWT_SKELETON))
    {
        retval2 = ((EschLimbSegment *)child())->step(interval, scalar);
    }
    if (retval < 0)
    {
        retval = 0;
    }
    return (retval|retval2);
}


#if 0
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegment - set_key
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschLimbSegment::set_key(EschKeyframe *key, float scalar)
{
    // find an empty spot
    // if none found, cancel one of the ones that is going
    int keynum;
    if (get_type()==ESCH_DRWT_SKELETON)
    {
        keynum = get_keyframe_spot(key);

        keyheads[keynum] = key;
        keyframes[keynum] = key;
//        if (keyframes[keynum]->child)
//        {
//            next_keyframes[keynum] = keyheads[keynum]->child;
//        }
//        else
//        {
//            next_keyframes[keynum] = keyheads[keynum];
//        }
        next_keyframes[keynum] = key;
        while (next_keyframes[keynum]->child)
        {
            next_keyframes[keynum] = next_keyframes[keynum]->child;
        }
        calc_step(keynum);
        init_tween(keynum);
        if (scalar != 0.0f)
        {
            scale_step(keynum, scalar);
        }
        if ((!(k_type&ESCH_KEYFRAME_ROOT)) && next() &&
            (next()->get_type()==ESCH_DRWT_SKELETON))
        {
            EschKeyframe *temp;
            temp = EschKeyframeMan->get (((EschLimbSegment *)next())->get_ktype(), key->root->m_type, 0);
            ((EschLimbSegment *)next())->set_key(temp,scalar);
        }
        if (child())
        {
            EschKeyframe *temp;
            temp = EschKeyframeMan->get (((EschLimbSegment *)child())->get_ktype(), key->root->m_type, 0);
            ((EschLimbSegment *)child())->set_key(temp,scalar);
        }
        return(keynum);
    }
    return (-1);
}
#endif

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegment - do_rotations
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschLimbSegment::do_rotations(EschVector *rot)
{
    memcpy (&local, &home, sizeof(local));

    if (k_type & (ESCH_KEYFRAME_TORSO))
    {
        step_pitch += rot->i;
        if (step_pitch > max_pitch)
        {
            step_pitch = max_pitch;
        }
        else if (step_pitch < min_pitch)
        {
            step_pitch = min_pitch;
        }
        current_pitch = step_pitch;

        step_roll += rot->j;
        if (step_roll > max_roll)
        {
            step_roll = max_roll;
        }
        else if (step_roll < min_roll)
        {
            step_roll = min_roll;
        }
        current_roll = step_roll;

        step_yaw += rot->k;
        if (step_yaw > max_yaw)
        {
            if (k_type & ESCH_KEYFRAME_ROOT)
            {
                step_yaw += 360.0f;
            }
            else
            {
                step_yaw = max_yaw;
            }
        }
        else if (step_yaw < min_yaw)
        {
            if (k_type & ESCH_KEYFRAME_ROOT)
            {
                step_yaw -= 360.0f;
            }
            else
            {
                step_yaw = min_yaw;
            }
        }
        current_yaw = step_yaw;
    }
    else
    {
        if (rot->i > max_pitch)
        {
            step_pitch = max_pitch;
        }
        else if (rot->i < min_pitch)
        {
            step_pitch = min_pitch;
        }
        else
        {
            step_pitch = rot->i;
        }
        current_pitch = step_pitch;

        if (rot->j > max_roll)
        {
            step_roll = max_roll;
        }
        else if (rot->j < min_roll)
        {
            step_roll = min_roll;
        }
        else
        {
            step_roll = rot->j;
        }
        current_roll = step_roll;

        if (k_type & (ESCH_KEYFRAME_ROOT|ESCH_KEYFRAME_FOOT))
        {
            step_yaw += rot->k;
            if (step_yaw > max_yaw)
            {
                if (k_type & ESCH_KEYFRAME_ROOT)
                {
                    step_yaw += 360.0f;
                }
                else
                {
                    step_yaw = max_yaw;
                }
            }
            else if (step_yaw < min_yaw)
            {
                if (k_type & ESCH_KEYFRAME_ROOT)
                {
                    step_yaw -= 360.0f;
                }
                else
                {
                    step_yaw = min_yaw;
                }
            }
        }
        else
        {
            if (rot->k > max_yaw)
            {
                if (k_type & ESCH_KEYFRAME_ROOT)
                {
                    step_yaw += 360.0f;
                }
                else
                {
                    step_yaw = max_yaw;
                }
            }
            else if (rot->k < min_yaw)
            {
                if (k_type & ESCH_KEYFRAME_ROOT)
                {
                    step_yaw -= 360.0f;
                }
                else
                {
                    step_yaw = min_yaw;
                }
            }
            else
            {
                step_yaw = rot->k;
            }
        }
        current_yaw = step_yaw;
    }

    float temp_yaw = (current_yaw + secondary_yaw);
    float temp_pitch = (current_pitch + secondary_pitch);
    float temp_roll = (current_roll + secondary_roll);

    if (temp_yaw != 0.0f
        || temp_pitch != 0.0f
        || temp_roll != 0.0f)
    {
        local.yaw (-temp_yaw);
        local.pitch (temp_pitch);
        local.roll (-temp_roll);
        local.orthogonalize();
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegement - swap_motion
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschLimbSegment::swap_motion (char *str1, char *str2)
{
    if (!str1 || !str2)
    {
        return 0;
    }
    if (!strcmp (str1,str2))
    {
        return 0;
    }
    for (int i=0; i<key_chain_count; i++)
    {
        if (!strcmp (str1, keyheads[i]->root->m_type))
        {
            // found a match
            EschKeyframe *temp = EschKeyframeMan->get (k_type, str2, 0);
            if (temp)
            {
                keyheads[i] = temp;
                keyframes[i] = temp;
                next_keyframes[i] = keyframes[i]->child;
                calc_step (i);
                init_tween (i);

                steps[i] *= 0;
            }

            if (!(k_type&ESCH_KEYFRAME_ROOT))
            {
                if (next())
                {
                    ((EschLimbSegment *)next())->swap_motion(str1,str2);
                }
            }
            if (child())
            {
                ((EschLimbSegment *)child())->swap_motion(str1,str2);
            }
            return 1;
        }
    }
    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                           旭� Protected 旭�
// EschLimbSegment - build_interim
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschLimbSegment::build_interim(int num)
{
    pre_interim[num] = interim[num];
    interim[num] = *next_keyframes[num];

    interim[num].rotations.i += fore_pitch;
//    interim[num].rotations.k += (side_pitch * side_pitch_mul);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                           旭� Protected 旭�
// EschLimbSegment - calc_step
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschLimbSegment::calc_step(int num)
{
    build_interim(num);
    steps[num] = interim[num].rotations - pre_interim[num].rotations;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                           旭� Protected 旭�
// EschLimbSegment - init_tween
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschLimbSegment::init_tween(int num)
{
    if (keyframes[num])
    {
        tweens[num] = pre_interim[num].rotations;
        tween_step[num] = 0.0f;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                           旭� Protected 旭�
// EschLimbSegment - calc_stride
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
float EschLimbSegment::calc_stride(char *mt, dword *count)
{
    // Must calculate all positions for all LimbSegments on one leg
    //  for the first keyframe and the last keyframe.
    // The stride_length is the distance from frame_0 to frame_last
    //  of the leading foot plus the distance from frame_0 to
    //  frame_last of the trailing_foot
    // This function should only ever be called for an articulated
    //  character's parent

    if (!(k_type & ESCH_KEYFRAME_ROOT))
    {
        return (float (0));
    }
    EschKeyframe *temp = EschKeyframeMan->get(k_type, mt, 0);
    if (temp)
    {
        // get the keyframe count -- includes a zero frame
        EschKeyframe *ktemp = temp;
        *count = 1;
        while (ktemp->child)
        {
            ktemp = ktemp->child;
            (*count)++;
        }

        EschVector startrot;
        EschVector endrot;
        EschFrameRef stride_mtx;

        // Calculate position of foot for frame_num 0
        memcpy (&stride_mtx, &local, sizeof (local));
        if (calc_foot(ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG, mt,
                      &startrot, &stride_mtx, 0))
        {
            return (float (0));
        }

        // Calculate position of foot for last frame
        memcpy (&stride_mtx, &local, sizeof (local));
        if (calc_foot(ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG, mt,
                      &endrot, &stride_mtx, ktemp->frame_num))
        {
            return (float (0));
        }

        EschVector mrot;
        mrot = (startrot-endrot);

        return (mrot.magnitude());
    }
    return (float (0));
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                           旭� Protected 旭�
// EschLimbSegment - calc_foot
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschLimbSegment::calc_foot(ulong kt, char *mt, EschVector *ret,
                               EschFrameRef *stride_mtx, int frame_num)
{
    // step to the child
    EschLimbSegment *kid = ((EschLimbSegment *)child());
    EschFrameRef local_trans;


    if (kid)
    {
        while ((kid->next()) && (!(kid->k_type & kt)))
        {
            kid = ((EschLimbSegment *)kid->next());
        }
        EschKeyframe *frame = EschKeyframeMan->get(kid->k_type, mt, frame_num);
        if (!frame)
        {
            return (ESCH_ERR_NOTFOUND);
        }
        if (kid->k_type & kt)
        {
            // calculate the stride_mtx in relation to its parent
            // stride matrix is child's mtx concat onto local
            memcpy(&local_trans, &kid->local, sizeof (local_trans));

            local_trans.rotatex (frame->rotations.i);
            local_trans.rotatey (frame->rotations.j);
            local_trans.rotatez (frame->rotations.k);

            stride_mtx->concat (&local_trans);

            if (kid->child())
            {
                kid->calc_foot(kt, mt, ret, stride_mtx, frame_num);
            }
            else    // its the foot
            {
                // apply the stride_mtx to the object
                stride_mtx->get_position (&ret->i, &ret->j, &ret->k);
            }
        }
    }
    return (ESCH_ERR_NONE);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                           旭� Protected 旭�
// EschLimbSegment - get_next_key
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschLimbSegment::get_next_key(int num,float side_vel)
{
    int retval=0;

    keyframes[num] = next_keyframes[num];
    if (next_keyframes[num]->child)
    {
        next_keyframes[num] = next_keyframes[num]->child;
    }
    else
    {
        if (k_type & (ESCH_KEYFRAME_LEADING | ESCH_KEYFRAME_TRAILING))
        {
            // bypass the base frame
            if (keyheads[num]->child)
            {
                next_keyframes[num] = keyheads[num]->child;
            }
            else
            {
                next_keyframes[num] = keyheads[num];
            }

            // bypass the initial loop frame
            if (next_keyframes[num]->child)
            {
                next_keyframes[num] = next_keyframes[num]->child;
            }
            retval = 1;
        }
        else
        {
            if (keyheads[num]->child)
            {
                next_keyframes[num] = keyheads[num]->child;
            }
            else
            {
                next_keyframes[num] = keyheads[num];
            }
        }
    }
    return (retval);
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Functions  碓旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegement - pitch_c
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
float EschLimbSegment::pitch_c (const float degrees, dword update)
{
    memcpy (&local,&home,sizeof(local));

    float temp_pitch = current_pitch;

    step_pitch += degrees;
    if (step_pitch>max_pitch)
    {
        step_pitch = max_pitch;
    }
    else if (step_pitch < min_pitch)
    {
        step_pitch = min_pitch;
    }
    current_pitch = step_pitch;
    temp_pitch = current_pitch - temp_pitch;

    local.yaw (current_yaw,update);
    local.pitch (current_pitch,update);
    local.roll (current_roll,update);
    if (update & ESCH_UPD_WORLD)
    {
        compute_world(update);
    }

    return temp_pitch;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegement - roll_c
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
float EschLimbSegment::roll_c(const float degrees, dword update)
{
    memcpy (&local,&home,sizeof(local));

    float temp_roll = current_roll;

    step_roll += degrees;
    if (step_roll>max_roll)
    {
        step_roll = max_roll;
    }
    else if (step_roll < min_roll)
    {
        step_roll = min_roll;
    }
    current_roll = step_roll;
    temp_roll = current_roll - temp_roll;

    local.yaw (current_yaw,update);
    local.pitch (current_pitch,update);
    local.roll (current_roll,update);
    if (update & ESCH_UPD_WORLD)
    {
        compute_world(update);
    }

    return temp_roll;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegement - yaw_c
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
float EschLimbSegment::yaw_c(const float degrees, dword update)
{
    memcpy (&local,&home,sizeof(local));

    float temp_yaw = current_yaw;

    step_yaw += degrees;
    if (step_yaw>max_yaw)
    {
        if (k_type & ESCH_KEYFRAME_ROOT)
        {
            step_yaw -= 360.0f;
        }
        else
        {
            step_yaw = max_yaw;
        }
    }
    else if (step_yaw<min_yaw)
    {
        if (k_type & ESCH_KEYFRAME_ROOT)
        {
            step_yaw += 360.0f;
        }
        else
        {
            step_yaw = min_yaw;
        }
    }

    current_yaw = step_yaw;
    temp_yaw = current_yaw - temp_yaw;

    local.yaw (current_yaw,update);
    local.pitch (current_pitch,update);
    local.roll (current_roll,update);
    if (update & ESCH_UPD_WORLD)
    {
        compute_world(update);
    }

    return temp_yaw;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegement - change_second_pitch
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
float EschLimbSegment::change_second_pitch (float degrees)
{
    secondary_pitch += degrees;
    if (secondary_pitch > max_pitch)
    {
        secondary_pitch = max_pitch;
    }
    else if (secondary_pitch < min_pitch)
    {
        secondary_pitch = min_pitch;
    }
    return secondary_pitch;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegement - change_second_yaw
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
float EschLimbSegment::change_second_yaw (float degrees)
{
    secondary_yaw += degrees;
    if (secondary_yaw > max_yaw)
    {
        secondary_yaw = max_yaw;
    }
    else if (secondary_yaw < min_yaw)
    {
        secondary_yaw = min_yaw;
    }
    return secondary_yaw;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegement - change_second_roll
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
float EschLimbSegment::change_second_roll (float degrees)
{
    secondary_roll += degrees;
    if (secondary_roll > max_roll)
    {
        secondary_roll = max_roll;
    }
    else if (secondary_roll < min_roll)
    {
        secondary_roll = min_roll;
    }
    return secondary_roll;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegement - set_second_pitch
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschLimbSegment::set_second_pitch (float degrees)
{
    if (degrees > max_pitch)
    {
        secondary_pitch = max_pitch;
    }
    else if (degrees < min_pitch)
    {
        secondary_pitch = min_pitch;
    }
    else
    {
        secondary_pitch = degrees;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegement - set_second_roll
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschLimbSegment::set_second_roll (float degrees)
{
    if (degrees > max_roll)
    {
        secondary_roll = max_roll;
    }
    else if (degrees < min_roll)
    {
        secondary_roll = min_roll;
    }
    else
    {
        secondary_roll = degrees;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegement - set_second_yaw
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschLimbSegment::set_second_yaw (float degrees)
{
    if (degrees > max_yaw)
    {
        secondary_yaw = max_yaw;
    }
    else if (degrees < min_yaw)
    {
        secondary_yaw = min_yaw;
    }
    else
    {
        secondary_yaw = degrees;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegement - fore_pitch_change
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschLimbSegment::fore_pitch_change (float pit, int swap)
{
    if (k_type & ESCH_KEYFRAME_LEG)
    {
        if (k_type & ESCH_KEYFRAME_LEADING)
        {
            if (k_type & ESCH_KEYFRAME_SHIN)
            {
                fore_pitch = -pit;
            }
            else if ((k_type & ESCH_KEYFRAME_HIP) ||
                     (k_type & ESCH_KEYFRAME_FOOT))
            {
                fore_pitch = pit;
            }
        }
        else if (k_type & ESCH_KEYFRAME_TRAILING)
        {
            if (!swap&&(pit < 0))
            {
                if (k_type & ESCH_KEYFRAME_SHIN)
                {
                    fore_pitch = pit;
                }
                else if ((k_type & ESCH_KEYFRAME_HIP) ||
                         (k_type & ESCH_KEYFRAME_FOOT))
                {
                    fore_pitch = - pit;
                }
            }
            else if ((k_type & ESCH_KEYFRAME_HIP) ||
                     (k_type & ESCH_KEYFRAME_FOOT))
            {
                fore_pitch =  pit;
            }
            else if (k_type & ESCH_KEYFRAME_SHIN)
            {
                fore_pitch = - pit;
            }
            else
            {
                fore_pitch = 0;
            }
        }
        else
        {
            fore_pitch = 0;
        }
    }
    else
    {
        fore_pitch = 0;
    }
    if (!(k_type & ESCH_KEYFRAME_ROOT))
    {
        if (next())
        {
            ((EschLimbSegment *)next())->fore_pitch_change(pit, swap);
        }
    }
    if (child())
    {
        ((EschLimbSegment *)child())->fore_pitch_change(pit, swap);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegement - side_pitch_change
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschLimbSegment::side_pitch_change (float pit, int swap)
{
    if (k_type & ESCH_KEYFRAME_THIGH)
    {
        side_pitch = pit;
    }
    else
    {
        side_pitch = 0;
    }
    if (!(k_type & ESCH_KEYFRAME_ROOT))
    {
        if (next())
        {
            ((EschLimbSegment *)next())->side_pitch_change(pit,swap);
        }
    }
    if (child())
    {
        ((EschLimbSegment *)child())->side_pitch_change(pit,swap);
    }
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  I/O Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                           旭� Protected 旭�
// EschLimbSegment - set_rot_limits
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschLimbSegment::set_rot_limits()
{
    if (k_type & ESCH_KEYFRAME_FOOT)
    {
        set_pitch_max (float(ESCH_FOOT_MAX_PITCH));
        set_pitch_min (float(ESCH_FOOT_MIN_PITCH));
        set_roll_max (float(ESCH_FOOT_MAX_ROLL));
        set_roll_min (float(ESCH_FOOT_MIN_ROLL));
        if (k_type & ESCH_KEYFRAME_LEFT)
        {
            set_yaw_max (float(-ESCH_FOOT_MIN_YAW));
            set_yaw_min (float(-ESCH_FOOT_MAX_YAW));
        }
        else
        {
            set_yaw_max (float(ESCH_FOOT_MAX_YAW));
            set_yaw_min (float(ESCH_FOOT_MIN_YAW));
        }
    }
    else if (k_type & ESCH_KEYFRAME_HAND)
    {
        set_pitch_max (float(ESCH_HAND_MAX_PITCH));
        set_pitch_min (float(ESCH_HAND_MIN_PITCH));
        set_roll_max (float(ESCH_HAND_MAX_ROLL));
        set_roll_min (float(ESCH_HAND_MIN_ROLL));
        if (k_type & ESCH_KEYFRAME_LEFT)
        {
            set_yaw_max (float(-ESCH_HAND_MIN_YAW));
            set_yaw_min (float(-ESCH_HAND_MAX_YAW));
        }
        else
        {
            set_yaw_max (float(ESCH_HAND_MAX_YAW));
            set_yaw_min (float(ESCH_HAND_MIN_YAW));
        }
    }
    else if (k_type & ESCH_KEYFRAME_SHIN)
    {
        set_pitch_max (float(ESCH_SHIN_MAX_PITCH));
        set_pitch_min (float(ESCH_SHIN_MIN_PITCH));
        set_roll_max (float(ESCH_SHIN_MAX_ROLL));
        set_roll_min (float(ESCH_SHIN_MIN_ROLL));
        if (k_type & ESCH_KEYFRAME_LEFT)
        {
            set_yaw_max (float(-ESCH_SHIN_MIN_YAW));
            set_yaw_min (float(-ESCH_SHIN_MAX_YAW));
        }
        else
        {
            set_yaw_max (float(ESCH_SHIN_MAX_YAW));
            set_yaw_min (float(ESCH_SHIN_MIN_YAW));
        }
    }
    else if (k_type & ESCH_KEYFRAME_FOREARM)
    {
        set_pitch_max (float(ESCH_FOREARM_MAX_PITCH));
        set_pitch_min (float(ESCH_FOREARM_MIN_PITCH));
        set_roll_max (float(ESCH_FOREARM_MAX_ROLL));
        set_roll_min (float(ESCH_FOREARM_MIN_ROLL));
        if (k_type & ESCH_KEYFRAME_LEFT)
        {
            set_yaw_max (float(-ESCH_FOREARM_MIN_YAW));
            set_yaw_min (float(-ESCH_FOREARM_MAX_YAW));
        }
        else
        {
            set_yaw_max (float(ESCH_FOREARM_MAX_YAW));
            set_yaw_min (float(ESCH_FOREARM_MIN_YAW));
        }
    }
    else if (k_type & ESCH_KEYFRAME_THIGH)
    {
        set_pitch_max (float(ESCH_THIGH_MAX_PITCH));
        set_pitch_min (float(ESCH_THIGH_MIN_PITCH));
        set_roll_max (float(ESCH_THIGH_MAX_ROLL));
        set_roll_min (float(ESCH_THIGH_MIN_ROLL));
        if (k_type & ESCH_KEYFRAME_LEFT)
        {
            set_yaw_max (float(-ESCH_THIGH_MIN_YAW));
            set_yaw_min (float(-ESCH_THIGH_MAX_YAW));
        }
        else
        {
            set_yaw_max (float(ESCH_THIGH_MAX_YAW));
            set_yaw_min (float(ESCH_THIGH_MIN_YAW));
        }
    }
    else if (k_type & ESCH_KEYFRAME_UPARM)
    {
        set_pitch_max (float(ESCH_UPARM_MAX_PITCH));
        set_pitch_min (float(ESCH_UPARM_MIN_PITCH));
        set_roll_max (float(ESCH_UPARM_MAX_ROLL));
        set_roll_min (float(ESCH_UPARM_MIN_ROLL));
        if (k_type & ESCH_KEYFRAME_LEFT)
        {
            set_yaw_max (float(-ESCH_UPARM_MIN_YAW));
            set_yaw_min (float(-ESCH_UPARM_MAX_YAW));
        }
        else
        {
            set_yaw_max (float(ESCH_UPARM_MAX_YAW));
            set_yaw_min (float(ESCH_UPARM_MIN_YAW));
        }
    }
    else if (k_type & ESCH_KEYFRAME_TORSO)
    {
        set_pitch_max (float(ESCH_TORSO_MAX_PITCH));
        set_pitch_min (float(ESCH_TORSO_MIN_PITCH));
        set_roll_max (float(ESCH_TORSO_MAX_ROLL));
        set_roll_min (float(ESCH_TORSO_MIN_ROLL));
        set_yaw_max (float(ESCH_TORSO_MAX_YAW));
        set_yaw_min (float(ESCH_TORSO_MIN_YAW));
    }
    else if (k_type & ESCH_KEYFRAME_HEAD)
    {
        set_pitch_max (float(ESCH_HEAD_MAX_PITCH));
        set_pitch_min (float(ESCH_HEAD_MIN_PITCH));
        set_roll_max (float(ESCH_HEAD_MAX_ROLL));
        set_roll_min (float(ESCH_HEAD_MIN_ROLL));
        set_yaw_max (float(ESCH_HEAD_MAX_YAW));
        set_yaw_min (float(ESCH_HEAD_MIN_YAW));
    }
    else if (k_type & ESCH_KEYFRAME_SHLDR)
    {
        set_pitch_max (float(ESCH_SHLDR_MAX_PITCH));
        set_pitch_min (float(ESCH_SHLDR_MIN_PITCH));
        set_roll_max (float(ESCH_SHLDR_MAX_ROLL));
        set_roll_min (float(ESCH_SHLDR_MIN_ROLL));
        if (k_type & ESCH_KEYFRAME_LEFT)
        {
            set_yaw_max (float(-ESCH_SHLDR_MIN_YAW));
            set_yaw_min (float(-ESCH_SHLDR_MAX_YAW));
        }
        else
        {
            set_yaw_max (float(ESCH_SHLDR_MAX_YAW));
            set_yaw_min (float(ESCH_SHLDR_MIN_YAW));
        }
    }
    else if (k_type & ESCH_KEYFRAME_DOME)
    {
        set_pitch_max (float(ESCH_DOME_MAX_PITCH));
        set_pitch_min (float(ESCH_DOME_MIN_PITCH));
        set_roll_max (float(ESCH_DOME_MAX_ROLL));
        set_roll_min (float(ESCH_DOME_MIN_ROLL));
        set_yaw_max (float(ESCH_DOME_MAX_YAW));
        set_yaw_min (float(ESCH_DOME_MIN_YAW));
    }
    else if (k_type & ESCH_KEYFRAME_HIP)
    {
        set_pitch_max (float(ESCH_HIP_MAX_PITCH));
        set_pitch_min (float(ESCH_HIP_MIN_PITCH));
        set_roll_max (float(ESCH_HIP_MAX_ROLL));
        set_roll_min (float(ESCH_HIP_MIN_ROLL));
        if (k_type & ESCH_KEYFRAME_LEFT)
        {
            set_yaw_max (float(-ESCH_HIP_MIN_YAW));
            set_yaw_min (float(-ESCH_HIP_MAX_YAW));
        }
        else
        {
            set_yaw_max (float(ESCH_HIP_MAX_YAW));
            set_yaw_min (float(ESCH_HIP_MIN_YAW));
        }
    }
    else if (k_type & ESCH_KEYFRAME_ROOT)
    {
        set_yaw_max (360.0f);
        set_yaw_min (0.0f);
        set_roll_max (float (360));
        set_roll_min (0.0f);
        set_pitch_max (float(-ESCH_HIP_MIN_PITCH));
        set_pitch_min (float(-ESCH_HIP_MAX_PITCH));
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLimbSegment - load
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschLimbSegment::load(const char *fname, const char *oname,
                                               VngoPal *pal, EschMesh *msh, char *pn,
                                               dword ctrlfl)
{
   esch_error_codes err;

//陳 Detach frame mesh, if any
    if (mesh)
    {
        detach();
    }

//陳 Create mesh, if needed
    if (!msh)
    {
        msh = new EschMesh;
        if (!msh)
            return ESCH_ERR_NOMEMORY;
        flags |= ESCH_DRW_OWNSDATA;
    }

    local.orient.reset();

//陳 Load
    if ((err=msh->load(fname,oname,pal,&local.orient,pn,ctrlfl)) != 0)
        return err;

//陳 Attach
    if ((err=attach(msh)) != 0)
        return err;

//陳 Update drawble information
    local.dir.i = local.orient.mtx[ESCH_MTX_G];
    local.dir.j = local.orient.mtx[ESCH_MTX_H];
    local.dir.k = local.orient.mtx[ESCH_MTX_I];

    local.compute_inverse();
    float dummy,y;
    local.get_position(&dummy, &y, &dummy);

    compute_world();

    memcpy (&home,&local,sizeof(local));

    return ESCH_ERR_NONE;
}

esch_error_codes EschLimbSegment::load(XFParseIFF *iff, const char *oname,
                                           VngoPal *pal, EschMesh *msh, char *pn,
                                           dword ctrlfl)
{
   esch_error_codes err;

//陳 Detach frame mesh, if any
    if (mesh)
    {
        detach();
    }

//陳 Create mesh, if needed
    if (!msh)
    {
        msh = new EschMesh;
        if (!msh)
            return ESCH_ERR_NOMEMORY;
        flags |= ESCH_DRW_OWNSDATA;
    }

    local.orient.reset();

//陳 Load
    if ((err=msh->load(iff,oname,pal,&local.orient,pn,ctrlfl))!=0)
        return err;

//陳 Attach
    if ((err=attach(msh)) != 0)
        return err;

//陳 tokenize name into an esch_limb_type
    tokenize_name ();
    set_rot_limits();

//陳 Update drawble information
    local.dir.i = local.orient.mtx[ESCH_MTX_G];
    local.dir.j = local.orient.mtx[ESCH_MTX_H];
    local.dir.k = local.orient.mtx[ESCH_MTX_I];

    current_pitch = 0;
    current_roll = 0;
    current_yaw = 0;

    local.compute_inverse();

    memcpy (&home,&local,sizeof(local));

    compute_world();
    return ESCH_ERR_NONE;
}

//葦� End of module - eslimbsg.cpp 憶�
