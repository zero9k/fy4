 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "石壁栈道");
        set("long", @LONG
说是路，实际只是在石壁上凿出尺把宽的一条栈道，勉强可以容一人行走。石
面生满了青苔，一不小心就有可能滑入瀑布中，幸好没过几步石壁上就凿有铁链可
以把握。栈道在瀑布内侧往上延伸，三叠瀑外看不出一丝痕迹。
LONG
        );
        set("exits", ([ 
                "eastup" : __DIR__"oneway2",
                "westdown" : __DIR__"exit",
                        ]));
        set("outdoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object who, string dir){
        int i, room_full;
        object *inv, room;
        
        if (!userp(who))        return 1;
        if(dir == "eastup"){
        
        
        
        
        
        
                room=find_object(__DIR__"oneway2");
                if(!objectp(room)) 
                room = load_object(__DIR__"oneway2"); 
                inv = all_inventory(room);
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i])) room_full=1;
                }
           if (room_full) {
                        tell_object(who,"前方道路狭窄，只能容一人行走。\n");
                        return notify_fail("");
                }       
        }       
        return 1;
} 
void init() {
        object ob;
        ob = this_player();
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
} 
void greeting(object ob) {
        
        object *inv, room;
        int i, room_full;
        inv = all_inventory(this_object());
        for (i=0;i<sizeof(inv);i++){
                if (!inv[i]->query("dungeon_npc")) room_full++;
        }
        if (room_full>1) {
                call_out("jump_down",2,ob);
                ob->start_busy(3);
        }       
}  
int jump_down(object me)        {
        object room;
        if(!objectp(me)) return 1;
        if (me->is_ghost()) return 1;
        message_vision("$N东摇西晃，找不到立足之地，一个筋斗向瀑布中栽了下去。\n",me);
        tell_object(me,YEL"你越坠越快．．．．你似乎听见了一声惨叫，不禁毛骨悚然。\n"NOR);
        tell_object(me,YEL"扑通一声，你一头扎进了潭水中。\n\n"NOR);
        room=find_object(AREA_EREN"waterfall");
        if(!objectp(room)) 
                room = load_object(AREA_EREN"waterfall"); 
        me->move(room);
        message_vision(HIG"$N湿淋淋地从水里浮了起来爬上岸。\n"NOR,me);
        return 1;
}     
