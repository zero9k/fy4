inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "山坡");
        set("long", @LONG
山坡一片青绿，看来并不高，也不太远。坡顶上一座大坟，坟头矗立着一块九
尺高的青石碑，坟上草色已苍，几棵白杨，伶仃地站在西风里。山坡前一片大草原，
接连着碧天。风吹长草，正如海洋中的波浪。
LONG
        );
        set("exits", ([ 
                "southdown" : __DIR__"grassland6",
        ]));
        set("objects", ([
                __DIR__"obj/tomb" : 1,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1090);
        set("coor/y",290);
        set("coor/z",10);
        set("discussion_shen",1);
        setup();
        //eplace_program(ROOM);
}      
void init()
{
        object xing;
        mixed *current_time;
        
        current_time=NATURE_D->get_current_time();
        if(xing=present("shen sanniang",this_object()))
        {
                if(current_time[5]<480||current_time[5]>1200)
                {
                   message_vision("沈叁娘沉默了好久好久，擦了擦坟头，又转身离开了。\n",this_player());
  
                        destruct(xing);
                }
                else if(current_time[5]>1080)
                {
                        message_vision("沈叁娘无奈地对$N笑了笑，整理了一下衣裳，转身就不见了。”\n",this_player());
                      
                        destruct(xing);
                }
        }
        else
                if(current_time[5]>480&&current_time[5]<960)
                {
                        xing=new(__DIR__"npc/sanniang");
                        xing->move(this_object());
                        message_vision("沈叁娘缓缓走了过来，抬头看了你一眼。”\n",xing);
                }
                

        
} 