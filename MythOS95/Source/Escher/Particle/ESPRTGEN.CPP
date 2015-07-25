//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
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
// Created by Tim Little & Chuck Walbourn
//
// esprtgen.cpp
//
// Contains the code for the EschParticleGenerator class which creates
// particles based on stochastic parameters.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"

//���������������������������������������������������������������������������
//
//                                 Macros
//
//���������������������������������������������������������������������������

// Returns a uniform psuedo random number between -1.0 and 1.0
#define RANDOM() (float(flx_rand().flx) / 2147483647.0f)

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticleGenerator - Constructor                                      �
//���������������������������������������������������������������������������
EschParticleGenerator::EschParticleGenerator() :
    EschParticleSystem(),
    func(esch_generate_particle),
    data(0),
    pal(0)
{
    dtyp = ESCH_DRWT_PGENERATOR;
};

EschParticleGenerator::EschParticleGenerator(ulong mc) :
    EschParticleSystem(),
    func(esch_generate_particle),
    data(0),
    pal(0)
{
    dtyp = ESCH_DRWT_PGENERATOR;

    init(mc);
};


//�������������������������������������������������������������������������Ŀ
// EschParticleGenerator - Destructor                                       �
//���������������������������������������������������������������������������
EschParticleGenerator::~EschParticleGenerator()
{
};



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticleGenerator - init                                             �
//���������������������������������������������������������������������������
esch_error_codes EschParticleGenerator::init(ulong mc)
{
//��� Call base
    esch_error_codes err = EschParticleSystem::init(mc);
    if (err)
        return err;

//��� Set default values
    world.reset();                      // Align to world space
    set_sphere(1);                      // Sphere generation area of size 1
    set_parts(1);                       // 1 particle per second
    set_speed(1);                       // 1 unit per second speed
    set_size(0);                        // Size of 0
    set_lifetime(10);                   // 10 frame lifetime
    set_color(1);                       // Color index 1
    set_alpha(255);                     // Alpha level 255

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschParticleGenerator - animate                                          �
//                                                                          �
// This calls the base animate after generating new particles.              �
//���������������������������������������������������������������������������
void EschParticleGenerator::animate()
{
    if (!(flags & ESCH_PRTG_NOAUTOGENERATE))
        generate();

    EschParticleSystem::animate();
}


//�������������������������������������������������������������������������Ŀ
// EschParticleGenerator - generate                                         �
//                                                                          �
// This call generates new particles.                                       �
//���������������������������������������������������������������������������
ulong EschParticleGenerator::generate()
{
//��� Determine how many particles to generate this frame based on
//��� distribution as either frame-based or time-based rates
    if (flags & ESCH_PRTG_FRAMEBASED)
    {
        if (var_parts > 0)
            part_accum += (mean_parts + RANDOM()*var_parts);
        else
            part_accum += mean_parts;
    }
    else
    {
        if (var_parts > 0)
            part_accum += (mean_parts + RANDOM()*var_parts) * interval;
        else
            part_accum += mean_parts * interval;
    }

//��� Create new particles, if any
    for(ulong count=0; part_accum >= 1; part_accum -= 1.0f, count++)
    {
        EschParticleGenParams parms(this,data);

        //��� Compute position/directory based on generation area in local
        if (flags & ESCH_PRTG_CIRCLE)
        {
            //��������� Circular generation area on x/z plane of local coords
            assertMyth("EschParticleGenerator::generate needs valid circle radius",
                       gsize1 > 0);

            parms.pos.x = RANDOM() * gsize1;
            parms.pos.y = 0;
            parms.pos.z = RANDOM() * gsize1;

            parms.velocity.i = 0;
            parms.velocity.j = 1;
            parms.velocity.k = 0;

            assertMyth("EschParticleGenerator::generate needs valid max angle",
                       maxangle >= 0);

            if (maxangle > 0)
            {
                parms.velocity.rotatex(RANDOM()*maxangle);
                parms.velocity.rotatez(RANDOM()*maxangle);
            }
        }
        else if (flags & ESCH_PRTG_RECTANGLE)
        {
            //������ Rectangular generation area on x/z plane of local coords
            assertMyth("EschParticleGenerator::generate needs valid rectangle size",
                       (gsize1 > 0) && (gsize2 > 0));

            parms.pos.x = RANDOM() * gsize1;
            parms.pos.y = 0;
            parms.pos.z = RANDOM() * gsize2;

            parms.velocity.i = 0;
            parms.velocity.j = 1;
            parms.velocity.k = 0;

            assertMyth("EschParticleGenerator::generate needs valid max angle",
                       maxangle >= 0);

            if (maxangle > 0)
            {
                parms.velocity.rotatex(RANDOM()*maxangle);
                parms.velocity.rotatez(RANDOM()*maxangle);
            }
        }
        else
        {
            //����������������� Spherical generation area within local coords
            assertMyth("EschParticleGenerator::generate needs valid sphere radius",
                       gsize1 > 0);

            parms.pos.x = RANDOM() * gsize1;
            parms.pos.y = RANDOM() * gsize1;
            parms.pos.z = RANDOM() * gsize1;

            parms.velocity.i = parms.pos.x;
            parms.velocity.j = parms.pos.y;
            parms.velocity.k = parms.pos.z;

            float mag = parms.velocity.magnitude();
            if (mag > 0)
            {
                parms.velocity /= mag;
            }
            else
            {
                parms.velocity.i = 0;
                parms.velocity.j = 1;
                parms.velocity.k = 0;
            }
        }

        //��� Transform from local to world for position/velocity
        parms.pos.transform(&world);
        parms.velocity.transform(&world);

        //��� Compute speed and set into velocity
        if (var_speed > 0)
            parms.velocity *= mean_speed + RANDOM()*var_speed;
        else
            parms.velocity *= mean_speed;

        //��� Compute size
        if (var_size > 0)
        {
            parms.size = mean_size + RANDOM()*var_size;
            if (parms.size <= 0)
                parms.size = mean_size;
        }
        else
            parms.size = mean_size;


        //��� Compute color
        if (pal && (var_color_r || var_color_g || var_color_b))
        {
            float r = float(mean_color_r) + RANDOM()*float(var_color_r);
            if (r > 255)
                r = 255;
            else if (r < 0)
                r = 0;

            float g = float(mean_color_g) + RANDOM()*float(var_color_g);
            if (g > 255)
                g = 255;
            else if (g < 0)
                g = 0;

            float b = float(mean_color_b) + RANDOM()*float(var_color_b);
            if (b > 255)
                b = 255;
            else if (b < 0)
                b = 0;

            parms.color = pal->get_index(VngoColor24bit(byte(r),
                                                        byte(g),
                                                        byte(b)));
        }
        else
            parms.color = cindex;

        //��� Compute lifetime
        if (var_life > 0)
        {
            parms.lifetime = mean_life + RANDOM()*var_life;
            if (parms.lifetime <= 0)
                parms.lifetime = mean_life;
        }
        else
            parms.lifetime = mean_life;

        //��� Compute alpha
        if (var_alpha > 0)
        {
            float a = float(mean_alpha) + RANDOM()*float(var_alpha);
            if (a > 255)
                a = 255;
            else if (a < 0)
                a = 0;

            parms.alpha = byte(a);
        }
        else
            parms.alpha = mean_alpha;

        //��� Create new particle with callback
        EschParticle *p = func(&parms);
        if (!p)
            break;

        //��� Add to system
        add(p);
    }

    return count;
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticleGenerator - set_callback                                     �
//                                                                          �
// This sets the callback function for the generator.                       �
//���������������������������������������������������������������������������
void EschParticleGenerator::set_callback(EschParticleGenCallback f, void *d)
{
    if (!f)
        func = esch_generate_particle;
    else
        func = f;

    data=d;
}



//���������������������������������������������������������������������������
//���������������������������� Callback routines ����������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// esch_generate_particle
//
// Default callback routine which creates an instance of EschParticle
//���������������������������������������������������������������������������
EschParticle *esch_generate_particle(EschParticleGenParams *parms)
{
    assert(parms != 0 && parms->generator != 0);

    EschParticle *p = new EschParticle(&parms->pos, &parms->velocity,
                                       parms->color, parms->lifetime);
    if (!p)
        return 0;

    if (!(parms->generator->flags & ESCH_PRTG_FRAMEBASED))
        p->set_flags(p->flags | ESCH_PRT_TIMEBASED);

    return p;
}


//���������������������������������������������������������������������������
// esch_generate_pyramid
//
// Callback routine which creates an instance of EschParticlePyramid
//���������������������������������������������������������������������������
EschParticle *esch_generate_pyramid(EschParticleGenParams *parms)
{
    assert(parms != 0 && parms->generator != 0);

    EschParticlePyramid *p = new EschParticlePyramid(parms->size,
                                                     &parms->pos,
                                                     &parms->velocity,
                                                     parms->color,
                                                     parms->lifetime);
    if (!p)
        return 0;

    if (!(parms->generator->flags & ESCH_PRTG_FRAMEBASED))
        p->set_flags(p->flags | ESCH_PRT_TIMEBASED);

    return p;
}


//���������������������������������������������������������������������������
// esch_generate_sprite
//
// Callback routine which creates an instance of EschParticleSprite and
// an associated EschSprite instance.
//���������������������������������������������������������������������������
EschParticle *esch_generate_sprite(EschParticleGenParams *parms)
{
    assert(parms != 0 && parms->generator != 0 && parms->data != 0);

    EschSprite *sprite = new EschSprite(*((EschSprite*)parms->data));
    if (!sprite)
        return 0;

    sprite->set_position(&parms->pos);
    sprite->set_alpha(parms->alpha);
    sprite->set_flags(sprite->flags & ~ESCH_DRW_SKIP);

    EschParticleSprite *p = new EschParticleSprite(sprite,
                                                   &parms->velocity,
                                                   parms->lifetime);
    if (!p)
    {
        delete sprite;
        return 0;
    }

    if (!(parms->generator->flags & ESCH_PRTG_FRAMEBASED))
        p->set_flags(p->flags | ESCH_PRT_TIMEBASED);

    return p;
}

//��� End of module - esprtgen.cpp ���
