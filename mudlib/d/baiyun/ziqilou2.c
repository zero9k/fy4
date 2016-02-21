 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
#include <ansi.h>
inherit ROOM; 
void create() 
{ 
        set("short", "紫气东来二楼");
        set("long", @LONG 
相比于一楼的雍容华丽，金壁辉煌，二楼却格外的清淡素雅，四面都是敞亮的窗
户，楼内整整齐齐放了四张檀木香几，东侧摆的是一个瑶琴，南首放了一盘玉雕棋秤，
西面挂了一幅水墨淋漓的狂草，而北面搁着一卷画轴。
LONG 
           ); 
        set("exits",  
           ([  
       "down" : __DIR__"ziqilou",
            ])); 
        set("objects",  
           ([  
//       __DIR__"npc/yexingshi" : 1,
        "/d/baiyun/obj/desk" : 1,
        
            ])); 
        set("indoors", "baiyun");
        set("type","house");
        set("coor/x",0); 
        set("coor/y",-1800); 
        set("coor/z",25); 
        setup(); 
//        replace_program(ROOM); 
}       
void reset()
{
        object *inv;
        object con, item;
        ::reset();
        
        con = present("desk", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv) ) {
        item = new("/d/shaolin/obj/bupin");
        item->move(con);
        item = new("/d/shaolin/obj/keedrug2");
        item->move(con);
        item = new("/d/shaolin/obj/keedrug");
        item->move(con);
        item = new("/d/shaolin/obj/dan");
        item->move(con);
        if (random (1000)<100) item = new("/d/baiyun/obj/timepill");
        item->move(con);
        }
}       
void init()
{
        object me; 
        if( interactive(me = this_player()) ) 
        {
                call_out("greeting", 1, me);
        }
} 
int greeting(object me)
{
        object room; 
        if( userp(me) && me->query("age")<300 )
        {
                room = find_object("/d/baiyun/skystreet");
                if(!objectp(room)) 
                        room = load_object("/d/baiyun/skystreet");
                message_vision(MAG"远处钟声突然响起．．．$N一害怕，从窗口跳了出去．．．\n"NOR,me);
                me->move(room);
           me->receive_damage("kee",5000);
                message_vision(MAG"$N听到钟声慢慢由远而近，又由近而远，不其然打了个冷战．．．\n"NOR,me);
        }
}      
