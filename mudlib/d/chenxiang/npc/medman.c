 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("中药店老板", ({ "medman" }) );
        set("gender", "男性" );
        set("age", 75);
        set("long",
                "
一个正忙得不可开交的中药店老板，他正在煮汤．
\n");
        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("per",1);
        set("inquiry", ([
                "当归补血鱼汤" : "那你可要买：北芪，淮山，党参，杞子，和当归．\n",
                "soup" : "那你可要买：北芪，淮山，党参，杞子，和当归．\n",
        ])); 
        setup();
        set_temp("apply/damage",300);
        carry_object("/obj/armor/cloth")->wear();
} 
int accept_object(object me, object obj)
{
 if((int)me->query("combat_exp") < 500000) return 0;
 if((string)obj->query("marks") == "special_coin")
 {
  message_vision("$N看了$n一眼，指了一下小火炉。\n",this_object(),me);
  message_vision("$N犹豫了一下，将身上的一文钱扔入小火炉中。\n",me);
  message_vision("铜钱上的裂痕中冒出一股绿烟，将整个铜钱染成碧绿！\n",me);
  obj->set("marks","special_green_coin");
  obj->set("long","这是一枚碧绿的铜钱，铜钱上有一条浅浅的裂痕。\n");
  return 0;
 }
 return 0;
}   
