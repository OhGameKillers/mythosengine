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
// Created by Tim Little & Chuck Walbourn
//
// espartik.hpp
//
// EschParticle is a class for dynamic particles affected by an accleration
// and have a velocity.  The base implementation draws a colored point
// at the particle's position.
//
// EschParticleLine draws the particle as a line from the old position
// to the new.
//
// EschParticlePyramid draws the particle as a 4-sided polyhedra.
//
// EschParticleSprite draws an EschSprite instance at the particle's
// location.
//
// EschParticleGeometry draws an EschGeometry instance at the particle's
// location.
//
// EschParticleSystem is a particle container class which can be used
// to maintain a large number of particles draws together as a single
// drawable instance.
//
// EschParticleGenerator is a drawable class which generates particles
// based on stochastic distributions.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __ESPARTIK_HPP
#define __ESPARTIK_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "esdraw.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class EschParticleGenerator;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleGenParams - Parameters for a newly generated particle.       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct EschParticleGenParams
{
    EschParticleGenerator   *generator;
    void                    *data;
    EschPoint               pos;
    EschVector              velocity;
    float                   size;
    dword                   color;
    float                   lifetime;
    byte                    alpha;
    byte                    na[3];
    float                   rot_rate;

    EschParticleGenParams(EschParticleGenerator *g, void *d=0) :
        generator(g),
        data(d) {}
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Typedefs
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class EschParticle;

typedef EschParticle * (*EschParticleGenCallback) (EschParticleGenParams *);

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticle - A dynamic particle in 3-space.                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschParticle : public EschDrawable
{
protected:
    float       interval;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschPoint   pos;                        // Position
    dword       color;                      // Color
    float       life;                       // Lifetime (0=unlimited)
    EschVector  velocity;                   // Velocity of particle
    EschVector  acceleration;               // Acceleration of particle

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschParticle() : EschDrawable(ESCH_DRWT_PARTICLE) {}
    EschParticle(float ix, float iy, float iz, dword c, float l=0);
    EschParticle(float ix, float iy, float iz,
                 float ii, float ij, float ik, dword c, float l=0);
    EschParticle(const EschPoint *p, const EschVector *v, dword c, float l=0);

    virtual ~EschParticle() {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual void draw();
    virtual void animate();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_interval(float i) { interval = i; }

    void set_position(float ix, float iy, float iz)
    {
        pos.x = ix;  pos.y = iy;  pos.z = iz;
    }
    void set_position(EschPoint *pnt)
    {
        pos.x = pnt->x;  pos.y = pnt->y;  pos.z = pnt->z;
    }

    void set_color(dword c) { color = c; }

    void set_lifetime(float l) { life = l; }

    void set_velocity(float ii, float ij, float ik)
    {
        velocity.i = ii;  velocity.j = ij;  velocity.k = ik;
    }
    void set_velocity(const EschVector *v)
    {
        velocity.i = v->i;  velocity.j = v->j;  velocity.k = v->k;
    }

    void set_acceleration(float ii, float ij, float ik)
    {
        acceleration.i = ii;  acceleration.j = ij;  acceleration.k = ik;
    }
    void set_acceleration(const EschVector *v)
    {
        acceleration.i = v->i;  acceleration.j = v->j;  acceleration.k = v->k;
    }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleLine - A dynamic line in 3-space.                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschParticleLine : public EschParticle
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschPoint   pos2;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschParticleLine() : EschParticle(), pos2(0,0,0) { dtyp=ESCH_DRWT_PRTLINE; }
    EschParticleLine(float ix, float iy, float iz, dword c, float l=0);
    EschParticleLine(float ix, float iy, float iz,
                     float ii, float ij, float ik, dword c, float l=0);
    EschParticleLine(const EschPoint *p, const EschVector *v, dword c, float l=0);

    virtual ~EschParticleLine() {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual void draw();
    virtual void animate();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_position(float ix, float iy, float iz)
    {
        pos2 = pos;
        pos.x = ix;  pos.y = iy;  pos.z = iz;
    }
    void set_position(EschPoint *pnt)
    {
        pos2 = pos;
        pos.x = pnt->x;  pos.y = pnt->y;  pos.z = pnt->z;
    }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticlePyramid - A dynamic polygonal pyramid in 3-space.            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschParticlePyramid : public EschParticle
{
protected:
    void check_workspace();

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschFrameRef    world;
    float           size;
    float           rotate_i;
    float           rotate_j;
    float           rotate_k;
    float           alpha;
    float           alpha_rate;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschParticlePyramid() : EschParticle(), alpha(255) { dtyp=ESCH_DRWT_PRTPYRAMID; }
    EschParticlePyramid(float s, float ix, float iy, float iz, dword c, float l=0);
    EschParticlePyramid(float s, float ix, float iy, float iz,
                        float ii, float ij, float ik, dword c, float l=0);
    EschParticlePyramid(float s, const EschPoint *p, const EschVector *v, dword c, float l=0);

    virtual ~EschParticlePyramid() {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual void draw();
    virtual void animate();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_position(float ix, float iy, float iz)
    {
        pos.x = ix;  pos.y = iy;  pos.z = iz;
        world.set_position(ix, iy, iz);
    }
    void set_position(EschPoint *pnt)
    {
        pos.x = pnt->x;  pos.y = pnt->y;  pos.z = pnt->z;
        world.set_position(pnt->x, pnt->y, pnt->z);
    }

    void set_lifetime(float l)
    {
        life = l;
        alpha_rate = (l > 0) ? (float(255) / l) : float(255);
    }

    void set_size(float s) { size=s; }

    void set_rotate_i(float r) { rotate_i=r; }
    void set_rotate_j(float r) { rotate_j=r; }
    void set_rotate_k(float r) { rotate_k=r; }

    void set_alpha(byte a)
    {
        alpha = float(a);
        alpha_rate = alpha / float((long)life);
    }

    void reset() { world.reset(); world.set_position(&pos); }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleSprite - A dynamic sprite in 3-space.                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschParticleSprite : public EschParticle
{
protected:
    EschSprite    *sprite;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    float       alpha;
    float       alpha_rate;
    float       rot_rate;
    float       scale_rate;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschParticleSprite() : EschParticle(), sprite(0) { dtyp=ESCH_DRWT_PRTSPRITE; }
    EschParticleSprite(EschSprite *s, float l=0);
    EschParticleSprite(EschSprite *s, float ii, float ij, float ik, float l=0);
    EschParticleSprite(EschSprite *s, const EschVector *v, float l=0);

    virtual ~EschParticleSprite();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    const EschParticleSprite &operator = (const EschParticleSprite &ps);

    virtual void draw();
    virtual void animate();

    virtual void release();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_position(float ix, float iy, float iz);
    void set_position(EschPoint *pnt)
    {
        set_position(pnt->x, pnt->y, pnt->z);
    }

    void set_lifetime(float l)
    {
        life = l;

        alpha = float((sprite) ? sprite->get_alpha() : 255);
        alpha_rate = (l > 0) ? (alpha / l) : 0;
    }

    void set_rot_rate(float r)
    {
        rot_rate = r;
    }
    void set_rotation(float r)
    {
        if (sprite)
            sprite->set_rotation(r);
    }

    void set_scale_rate (float s)
    {
        scale_rate = s;
    }
    void set_scale (float s)
    {
        if (sprite)
            sprite->set_scale (s);
    }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleGeometry - A dynamic geometry in 3-space.                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschGeometry;

class EschParticleGeometry : public EschParticle
{
protected:
    EschGeometry    *geom;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    float   rotate_i;
    float   rotate_j;
    float   rotate_k;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschParticleGeometry() : EschParticle(), geom(0) { dtyp=ESCH_DRWT_PRTGEOMETRY; }
    EschParticleGeometry(EschGeometry *g, float l=0);
    EschParticleGeometry(EschGeometry *g, float ii, float ij, float ik, float l=0);
    EschParticleGeometry(EschGeometry *g, const EschVector *v, float l=0);

    virtual ~EschParticleGeometry();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    const EschParticleGeometry &operator = (const EschParticleGeometry &pg);

    virtual void draw();
    virtual void animate();

    virtual void release();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_position(float ix, float iy, float iz);
    void set_position(EschPoint *pnt)
    {
        set_position(pnt->x, pnt->y, pnt->z);
    }

    void set_rotate_i(float r) { rotate_i=r; }
    void set_rotate_j(float r) { rotate_j=r; }
    void set_rotate_k(float r) { rotate_k=r; }

    void reset();
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleSystem - A dynamic particle collection class.                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschParticleSystem : public EschDrawable
{
protected:
    float       interval;
    BOOL        linear_accel;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    ulong           maxcount;
    EschParticle    **particles;
    EschVector      l_acceleration;
    EschVector      acceleration;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschParticleSystem() :
        EschDrawable(ESCH_DRWT_PSYSTEM),
        interval(1),
        particles(0),
        acceleration(0,0,0) {}

    EschParticleSystem(ulong mc) :
        EschDrawable(ESCH_DRWT_PSYSTEM),
        interval(1),
        particles(0),
        acceleration(0,0,0)
    {
        init(mc);
    }

    virtual ~EschParticleSystem();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    const EschParticleSystem &operator = (const EschParticleSystem &ps);

    virtual void draw();
    virtual void animate();

    virtual esch_error_codes init(ulong mc);
    virtual void release();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void add(EschParticle *p);

    void set_interval(float i);

    void set_acceleration(float ii, float ij, float ik)
    {
        l_acceleration.i = ii;  l_acceleration.j = ij;  l_acceleration.k = ik;

        acceleration.i = l_acceleration.i * l_acceleration.i;
        acceleration.j = l_acceleration.j * l_acceleration.j;
        acceleration.k = l_acceleration.k * l_acceleration.k;

        if (l_acceleration.i < 0)
            acceleration.i *= -1.0f;
        if (l_acceleration.j < 0)
            acceleration.j *= -1.0f;
        if (l_acceleration.k < 0)
            acceleration.k *= -1.0f;
    }
    void set_acceleration(const EschVector *v)
    {
        l_acceleration.i = v->i;  l_acceleration.j = v->j;  l_acceleration.k = v->k;

        acceleration.i = l_acceleration.i * l_acceleration.i;
        acceleration.j = l_acceleration.j * l_acceleration.j;
        acceleration.k = l_acceleration.k * l_acceleration.k;

        if (l_acceleration.i < 0)
            acceleration.i *= -1.0f;
        if (l_acceleration.j < 0)
            acceleration.j *= -1.0f;
        if (l_acceleration.k < 0)
            acceleration.k *= -1.0f;
    }

    void set_linear(BOOL l) {linear_accel = (!!l);}
    BOOL is_linear() {return linear_accel;}
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleGenerator - A stochastic particle generator class.           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschParticleGenerator : public EschParticleSystem
{
protected:
    EschParticleGenCallback     func;
    void                        *data;
    float                       part_accum;
    dword                       cindex;
    VngoPal                     *pal;

    EschVector                  init_dir;


public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschFrameRef    world;
    float           gsize1;             // Size of generation area (circle/
    float           gsize2;             // sphere uses gsize1, rect uses both)
    float           maxangle;           // Max angle (degrees) of ejection
    float           mean_parts;         // Distribution of particle generation
    float           var_parts;
    float           mean_speed;         // Distribution of particle speed
    float           var_speed;
    float           mean_size;          // Distribution of particle size
    float           var_size;
    float           mean_life;          // Distribution of particle lifetime
    float           var_life;
    byte            mean_color_r;       // Distribution of particle color
    byte            mean_color_g;
    byte            mean_color_b;
    byte            var_color_r;
    byte            var_color_g;
    byte            var_color_b;
    byte            mean_alpha;         // Distribution of particle alpha
    byte            var_alpha;

    float           rot_rate;
    float           var_rot_rate;
    float           rot_rate_low;
    float           rot_rate_high;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschParticleGenerator();
    EschParticleGenerator(ulong mc);

    virtual ~EschParticleGenerator();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual esch_error_codes init(ulong mc);
    virtual void animate();

    virtual ulong generate();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void get_init_dir(EschVector *d) const { *d = init_dir;}
    void set_init_dir (float i, float j, float k)
    {
        if (i != 0 || j != 0 || k != 0)
        {
            init_dir.i = i; init_dir.j = j; init_dir.k = k;
            init_dir.normalize();
        }
        else
        {
            init_dir.i = 0; init_dir.j = 1.0f; init_dir.k = 0;
        }
    }
    void set_init_dir (EschVector *v)
    {
        set_init_dir (v->i, v->j, v->k);
    }

    void get_position(EschPoint *p) const { world.get_position(p);}

    void set_position(float ix, float iy, float iz, dword update=ESCH_UPD_ALL)
    {
        world.set_position(ix, iy, iz, update);
    }
    void set_position(const EschPoint *pnt, dword update=ESCH_UPD_ALL)
    {
        world.set_position(pnt->x, pnt->y, pnt->z, update);
    }

    void set_top(float ii, float ij, float ik, dword update=ESCH_UPD_ALL)
    {
        world.set_top(ii, ij, ik, update);
    }
    void set_top(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        world.set_top(v, update);
    }

    void set_direction(float ii, float ij, float ik, dword update=ESCH_UPD_ALL)
    {
        world.set_direction(ii, ij, ik, update);
    }
    void set_direction(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        world.set_direction(v, update);
    }

    void rotatex(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.rotatex(degrees,update);
    }
    void rotatey(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.rotatey(degrees,update);
    }
    void rotatez(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.rotatez(degrees,update);
    }

    void rotate(const EschVector *v, const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.rotate(v,degrees,update);
    }

    void pitch(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.pitch(degrees,update);
    }
    void roll(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.roll(degrees,update);
    }
    void yaw(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.yaw(degrees,update);
    }

    void translate(const float idx, const float idy, const float idz, dword update=ESCH_UPD_ALL)
    {
        world.translate(idx,idy,idz,update);
    }
    void translate(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        world.translate(v,update);
    }

    void move(const float idx, const float idy, const float idz, dword update=ESCH_UPD_ALL)
    {
        world.move(idx,idy,idz,update);
    }
    void move(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        world.move(v,update);
    }

    void scale(const float is, dword update=ESCH_UPD_ALL)
    {
        world.scale(is,update);
    }

    void orthogonalize(dword update=ESCH_UPD_ALL)
    {
        world.orthogonalize(update);
    }
    void orthogonalize_top(dword update=ESCH_UPD_ALL)
    {
        world.orthogonalize_top(update);
    }
    void orthogonalize_right(dword update=ESCH_UPD_ALL)
    {
        world.orthogonalize_right(update);
    }

    void reset() { world.reset(); }

    void set_sphere(float r)
    {
        flags &= ~(ESCH_PRTG_CIRCLE | ESCH_PRTG_RECTANGLE);
        gsize1 = r;
        gsize2 = 0;
        maxangle = 0;
    }

    void set_circle(float r, float ma)
    {
        flags &= ~ESCH_PRTG_RECTANGLE;
        flags |= ESCH_PRTG_CIRCLE;
        gsize1 = r;
        gsize2 = 0;
        maxangle = ma;
    }

    void set_rectangle(float l, float w, float ma)
    {
        flags &= ~ESCH_PRTG_CIRCLE;
        flags |= ESCH_PRTG_RECTANGLE;
        gsize1 = l;
        gsize2 = w;
        maxangle = ma;
    }

    void set_parts(float mean, float var=0)
    {
        mean_parts = mean;
        var_parts = var;
    }

    void set_speed(float mean, float var=0)
    {
        mean_speed = mean;
        var_speed = var;
    }

    void set_size(float mean, float var=0)
    {
        mean_size = mean;
        var_size = var;
    }

    void set_lifetime(float mean, float var=0)
    {
        mean_life = mean;
        var_life = var;
    }

    void set_color(dword c)
    {
        cindex = c;
        pal = 0;
        mean_color_r =
        mean_color_g =
        mean_color_b =
        var_color_r  =
        var_color_g  =
        var_color_b  = 0;
    }
    void set_color(VngoPal *p, VngoColor24bit mean, VngoColor24bit var=0)
    {
        pal = p;
        mean_color_r = mean.r;
        mean_color_g = mean.g;
        mean_color_b = mean.b;
        var_color_r = var.r;
        var_color_g = var.g;
        var_color_b = var.b;

        assert(pal != 0);
        cindex = pal->get_index(mean);
    }

    void set_alpha(byte mean, byte var=0)
    {
        mean_alpha = mean;
        var_alpha = var;
    }

    void set_rotrate (float rr, float var=0)
    {
        rot_rate = rr;
        var_rot_rate = var;
    }

    void set_rotrate_low (float rrl)
    {
        rot_rate_low = rrl;
    }
    void set_rotrate_high (float rrh)
    {
        rot_rate_high = rrh;
    }

    void set_callback(EschParticleGenCallback f, void *d=0);
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Prototypes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

EschParticle *esch_generate_particle(EschParticleGenParams *parms);
EschParticle *esch_generate_line(EschParticleGenParams *parms);
EschParticle *esch_generate_pyramid(EschParticleGenParams *parms);
EschParticle *esch_generate_sprite(EschParticleGenParams *parms);

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - espartik.hpp 憶�

