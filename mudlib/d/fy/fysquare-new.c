#include <room.h>
inherit ROOM; 
void midnight_event();
void sunrise_event(); 
void create()
{       object con,item;
        set("short", "风云天下");
        set("long", @LONG
风风雨雨，风云城的中心广场依旧鲜亮如新。风街和云路在这里交会，宽阔的
街道围成一个巨大的广场。广场中央的水池已经干涸，当年碧绿的池水和尾尾金鱼
不复存在，留下的是个几丈方圆，深不见底的大洞。水池旁的蟠龙摩天石柱饱经岁
月沧桑，依然不屈不挠地耸立，石柱上九条飞龙张牙舞爪，直欲冲天而去。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nwind1",
  "south" : __DIR__"swind1",
  "east" : __DIR__"ecloud1",
  "west" : __DIR__"wcloud1",
//  "down" : AREA_CAVE"tt", //temp. link for coordinate expandsion
]));
        set("outdoors", "fengyun"); 
        set("objects", ([
                __DIR__"npc/center_soldier" : 1,
                __DIR__"npc/half_god" : 1,
                __DIR__"obj/gui1" : 1,
                "/d/cave/obj/slayedman" : 1,
       ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        set("no_dazuo",1);
        set("no_study",1);
        setup();
        con = present("mugui",this_object());
        item = present("slayed corpse",this_object());
        item->set_amount(1+random(1));
        item->move(con);

        // To "load" the board, don't ever "clone" a bulletin board.
         call_other( "/obj/board/fysquare_b", "???" );
//      NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
}
/* Take out Bandit by xxder
void midnight_event() {
        object badguy;
        object room = this_object();
   int i, bandit_no = 2 + random(5);
        
        if(!random(10)) {
                for(i=0; i<bandit_no; i++) {
                        if(objectp(badguy = new("/obj/npc/bandit"))) {
                                badguy->setup_bandit("山西土匪", "/obj/armor/cloth", "/obj/weapon/blade_guitou", "fy");
                                badguy->move(room);
                                badguy->ccommand("chat 月黑杀人，风高放火！");
                        }
                }
                NATURE_D->add_day_event(3, 1, this_object(), (: sunrise_event :));
        } else {
                NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
        }
} 
void sunrise_event() {
        object *ob_list;
        int i;
        
        ob_list = children("/obj/npc/bandit");
        for(i=0; i<sizeof(ob_list); i++) {
                if(ob_list[i]->query("area_mark") == "fy") {
                        if(environment(ob_list[i])) {
                                message_vision("$N叫道：天晓也，扯乎！\n",ob_list[i]);
                        }
                        destruct(ob_list[i]);
                }
        }
        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}
*/    
