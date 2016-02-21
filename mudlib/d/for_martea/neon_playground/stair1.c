 // Copyright (C) 2002, by neon. All rights reserved by Fengyun Workshop.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "玄石阶梯");
        set("long", @LONG
一条往下蜿蜒的石阶道路。黑黝黝的阶石无止境地延伸向下，没入
沉沉的黑暗中。石街不知道是用什么石料做成的，踩上去竟有种柔软的
感觉。一阵阵阴风从下面吹来。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"hall",
  ]));
        set("outdoors", "neon_playground");
        set("coor/x",-50);
        set("coor/y",30000);
        set("coor/z",-20);
        setup();
        replace_program(ROOM);
}
