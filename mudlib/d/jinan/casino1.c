 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
�������ıڼ�Ϊ�Իͣ���ǽֽ���Ƕ����ģ��ڵƻ���
�������⡣��������������һ������ǧ֧�������һ���
�޵ƣ�ʹ��������û��һ���ڰ��Ľ��䡣�ſ�һ�źڵ׽�
�����ӣ�������
LONG
  );
  set("exits",([
     "west"  :__DIR__"street1",
         "northeast" : __DIR__"summer",
         "southeast" : __DIR__"spring",
         "east" : __DIR__"silver",
               ]));
        set("objects", ([
                __DIR__"npc/hun" : 1,
       ]) );
        set("item_desc", ([
                "sign": "
�����淨��
�������      ���˽⵱ǰ�Ķľ֣���ɫΪ��ע�ߣ���ɫΪ��Ȩ�ߡ�
������        ���ڶľֿ�ʼ֮ǰ������һ�ֽ���֮�����ľ֡� 
        take <��λ> <����> <��������>
        <��λ>��Ϊnorth��south��east��west
        <����>����
        <��������>����
�����        ��������һ��
�������      ����һ�ֽ���֮���뿪��̨
������      �������������
����          ������Ӵ��ע 
�������ù棺
һ¥��ɰٷ�֮����
��¥��ɰٷ�֮����
��¥��ɰٷ�֮һ��
"
        ]) );
        set("coor/x",40);
        set("coor/y",1970);
        set("coor/z",0);
        setup();
    replace_program(ROOM); 
}  