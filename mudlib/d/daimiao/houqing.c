 //mac's houqing.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
  set("short","后寝宫");
  set("long",@LONG
神龛内奉东岳大帝和帝后塑像，高一丈，两伺女分立左右，神龛
外两侧配有太监塑像，平台上有日形和月形碑各一块，以示日月同辉
之意。很多虔诚的信徒都在这儿膜拜（ｍｏｂａｉ）。
LONG
  );
  set("exits",([
         "north":__DIR__"tongting.c",
         "south":__DIR__"tiankuang.c",
         "east" :__DIR__"peiqing1.c",
         "west" :__DIR__"peiqing2.c",
               ]));
        set("item_desc", ([
                "东岳大帝": "
东岳大帝高六尺，型貌活灵活现，宛如真人一般。\n",
        ]) );
  set("coor/x",310);
        set("coor/y",2340);
        set("coor/z",0);
        setup();
} 
void init()
{
add_action("do_mobai", "mobai");
} 
int do_mobai()
{
       object who;
       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("你的神不够。\n");
       message_vision("$N虔诚地跪在东岳大帝塑像前磕了个头。\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N身上的杀孽之气似乎轻了。 \n" , who);
      add("number",1);
        if((int) query("number") ==     random(80) + 20 )
        {
        if  ((int)who->query("force") > 5000)
           {
        message_vision( HIW "\n\n$N忽然听见天空中一阵电闪雷鸣！！！伴随着一声怒吼：难道不知足么！！！\n\n"NOR,who);
        return 1;
        }
        message_vision( HIG "\n\n$N正拜得头昏脑涨，石像跟前忽然传来一丝清香。。。\n\n"NOR,who);

       if ( !objectp(who = present("force pill", this_object())) )
                {
                who = new(__DIR__"obj/forcedan");
                who->move(this_object());
                }   
        }       
        return 1;
} 
void reset()
{
object obj;
:: reset();
delete("number");
if(objectp(obj = present("master dadi", this_object())) )
destruct(obj);
}     
