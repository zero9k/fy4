 // Room: waterhole.c --- by MapMaker
#include <ansi.h>
inherit ROOM; 
string spring();
void diving(object me);
void create(){
        set("short", "寒水泉");
        set("long", @LONG
一阵寒气扑面而来，让人精神一震。抬头望，前方不远处有一小潭，潭中
央是一泉眼，泉水携带着阵阵寒气涌出平静的水面；潭边黑色的岩石上结满了
厚厚的冰霜，上面寸草不生。
LONG); 
        //{{ --- by MapMaker
        set("exits",([
        "east":__DIR__"waterpath",
        "southwest":__DIR__"weaponroom",
        ]) );
        //}}
        set("item_desc", ([
                "泉眼" : (: spring :),
                "spring" : (: spring :),
                "泉" : (: spring :),
        ]));    
        set("indoors", "yinghe");
        setup();
} 
string spring(){
        object me;
        
        me = this_player();
        tell_object(me, "泉水携带着阵阵寒气涌出平静的水面，你不由得想一探究竟。（ｄｉｖｅ）\n");
        add_action("do_dive", "dive");
        return "";
} 
int do_dive(){
        object *inv, obj, me;
        string att, temp_att;
        int i;
        me = this_player();
        att = me->query("attribute_mark");
   temp_att = me->query_temp("attribute_mark");
        inv = all_inventory(me);
        if(att == "water" || att == "earth"){
                diving(me);
                return 1;
        }
        if(att == "gold" || att == "wood") {
                for(i=0;i<sizeof(inv); i++){
                        if((inv[i]->query("attribute") == att && inv[i]->query("yinghe_weapon"))){
                                diving(me);
                                return 1;
                        }
                }
        }
        if(att == "fire") {
                if(temp_att == "water" || temp_att == "earth") {
                        diving(me);
                        return 1;
                }
                message("vision", me->name() + "缓缓向前移动几步继而驻足不前。\n", environment(me), me);
                tell_object(me, HIR"寒冷的水气让你觉得浑身疼痛难当。\n"NOR);
                me->receive_damage("kee", 100);
                return 1;
        } 
        message("vision", me->name() + "缓缓向前移动几步继而驻足不前。\n", environment(me),me);
        tell_object(me, "浸入筋骨的潮寒之气让你浑身一震驻足不前。\n");
        return 1;
} 
void diving(object me){
        object room;
        
        room = find_object(__DIR__"watertunnel");
        message_vision(HIC"\n$N纵身越入冷潭向下潜去。\n\n"NOR, me);
        if(!objectp(room)){
                room = load_object(__DIR__"watertunnel");
        }
        tell_object(me,"蓦然间你眼前一亮。\n\n");
        me->move(room);
        
}  
