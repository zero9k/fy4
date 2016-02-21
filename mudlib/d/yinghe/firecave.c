 // FYteam
#include <ansi.h>
inherit ROOM; 
void create(){
        set("short", "重生火殿");
        set("long", @LONG
这是一个巨大的殿堂，正面只有一座浴火凤凰的雕像。神座似乎在燃烧一般，
发出明灭的红光。热浪滚滚扑面而来，如烤如炙。神座上的凤凰则似在烈火中翩翩
起舞。
LONG); 
        //{{ --- by MapMaker
        set("exits",([
                "north":__DIR__"center",
        ]) );
        set("item_desc", ([
                "shenzuo" : "映着明灭的红光，神座上的凤凰似在烈火中翩翩起舞。（ｔｏｕｃｈ）\n",
                "神座" : "映着明灭的红光，神座上的凤凰似在烈火中翩翩起舞。（ｔｏｕｃｈ）\n",
        ]));
        set("indoors", "yinghe");
        setup();
} 
void init(){
        add_action("do_touch", "touch");
} 
int do_touch(string arg){
        object me, room;
        
        me = this_player();
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("你正在忙！\n");
        }
        if(arg == "神座" || arg == "shenzuo"){
                if(me->query("attribute_mark") == "fire") {
                        message_vision(HIR"\n$N伸手摸向神座，蓦然间红光大炽。\n\n"NOR, me);
                        tell_object(me, HIR"你只觉得热浪滚滚，透过红光，眼前景色逐渐模糊。\n\n"NOR);
                        message("vision", me->name()+"的身影在红光中逐渐变淡，最终消失不见。\n", environment(me), me);
                        tell_object(me, "\n一阵微风袭来，眼前又是一番景象。\n\n");
                        room = find_object(__DIR__"pheonix_den");
                        if(!objectp(room)){
                                room = load_object(__DIR__"pheonix_den");
                   }
                        me->move(room);
                        message("vision", "你感觉一阵热浪袭来，" + me->name() +"的身影出现在眼前。\n", environment(me), me);
                        return 1;
                } else {
                        tell_object(me, "灼热的感觉让你根本无法靠近神座。\n");
                        return 1;
                }
        }
        return 0;
}      
