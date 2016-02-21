 // Room: rope_net.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "寒水井");
        set("long", @LONG
这是一块空地，目前什么都还没有修。
LONG); 
        set("indoors", "yinghe");
        setup();
} 
void init(){
        add_action("do_climb", "climb");
} 
int do_climb(string arg)
{
   object me, room; 
   me = this_player();
   if(me->is_busy() || me->is_fighting())
                return notify_fail("你现在没空！\n");
   switch (random(3)) {
   case 0:
      message_vision("$N手脚并用地往上爬，才爬到一半，一失手又摔了下来。\n", me);
      me->receive_damage("gin",20);
                me->start_busy(3);
      break;
   case 1:
      message_vision("$N手脚并用地往上爬，眼看快到井口了，结果一失手又摔了下来。\n", me);
      me->receive_damage("gin",40);
                me->start_busy(3);
      break;
   case 2:
      if(!arg || arg != "上" && arg != "up" ) return 0;
      room = find_object(__DIR__"woodroad");
      if(!objectp(room)) room=load_object(__DIR__"woodroad");
      me->move(room);
      message_vision("$N浑身湿淋淋地从水井中爬了上来。\n", me);
      break;
   }
   return 1;
}
