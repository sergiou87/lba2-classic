#ifndef TYPES_H
#define TYPES_H

#include <OBJECT/AFF_OBJ.H>
#include "COMMON.H"
#include "PTRFUNC.H"

typedef struct
{
  U8 Func;
  U8 TypeAnswer;
  S16 Value;
} T_EXE_SWITCH;

/*──────────────────────────────────────────────────────────────────────────*/
/*──────────────────────────────────────────────────────────────────────────*/

// structure normalement alignée
typedef struct
{
  U8 GenBody;   // 0 à 254 mais je veux -1
  U8 Col;       /* brick en collision (inutile?) */
  S16 SizeSHit; // Toujours carres

  U16 GenAnim;
  U16 NextGenAnim;

  S32 OldPosX; /* old pos world */
  S32 OldPosY;
  S32 OldPosZ;

  S32 Info; /* infos pour DoDir */
  S32 Info1;
  S32 Info2;
  S32 Info3;

  union
  {
    struct
    {
      S32 SHitX;
      S32 SHitY; // Coups Super Hit
      S32 SHitZ; // Servent aussi pour les Anim3DS
    } SHit;

    // ATTENTION: un PUSHABLE ne peut pas lancer de SUPER_HIT
    struct
    {
      S32 PushX;
      S32 PushY;
      S32 PushZ;
    } Push;

    struct
    {
      S32 Num;
      S32 Deb;
      S32 Fin;
    } A3DS;
  } Coord;

  /* B*/ U8 HitBy;      /* frappe par */
  /* B*/ U8 HitForce;   /* si !=0 force de frappe anim */
  /* B*/ S16 LifePoint; /* point de vie en cours */
  S16 OptionFlags;      /* flag d'init 2 */

  U8 *PtrAnimAction;

  S16 Sprite;
  S16 OffsetLabelTrack;

  // divers
  T_OBJ_3D Obj;

  U8 *PtrFile3D;
  S32 IndexFile3D;

  // constantes
  /* B*/ S16 NbBonus; /* nb bonus to give */
  /* B*/ U8 Armure;   /* resistance */
  U8 CoulObj;         /* couleur dominante de l'objet */

  /* game infos */
  S16 XMin; /* ZV */
  S16 XMax;
  S16 YMin;
  S16 YMax;
  S16 ZMin;
  S16 ZMax;

  S32 OldBeta; /* angle de la boucle precedente */

  BOUND_MOVE BoundAngle; /* valeur real time de rotation */

  U8 *PtrTrack;    /* ptr track prog */
  S16 OffsetTrack; /* offset dans la track */

  S16 SRot; /* vitesse de rotation */

  U8 *PtrLife;

  S16 OffsetLife; /* offset dans la vie */
  U16 AnimDial;   // se trouve ici pour l'alignement

  /* B*/ S16 CarryBy;
  /* B*/ U8 Move;   /* type de deplacement */
  /* B*/ U8 ObjCol; /* num obj en collision */

  S16 ZoneSce;                 /* zone declenchement scenarique */
  /* B*/ S16 LabelTrack;       /* dernier label de track */
  /* B*/ S16 MemoLabelTrack;   /* memo dernier label de track */
  /* B*/ S16 MemoComportement; /* memo comportement life */

  U32 Flags;     /* flags divers permanent */
                 //	U16	Flags2 ;		/* flags divers permanent */
  U32 WorkFlags; /* flags de gestion */

  S16 DoorWidth; // pour les DOOR

  /* B*/ U8 FlagAnim; /* type d'anim en cours (dans flags?) */

  U8 CodeJeu; // brick spéciale sample ou action

  T_EXE_SWITCH ExeSwitch;

  //	S16	MessageChapter[MAX_CHAPTER] ;

  T_ZONE *PtrZoneRail;

  S32 SampleAlways; // Handle du sample always en train de se jouer
  U8 SampleVolume;
} T_OBJET;

typedef struct
{
  S32 X;
  S32 Y;
  S32 Z;
} T_TRACK;

typedef struct
{
  U8 Type;
  U8 Num;

} T_TABALLCUBE;

#endif // TYPES_H
