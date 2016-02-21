 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "小屋");
        set("long", @LONG
一间破旧的石屋，陈设极为简陋。屋子里到处都积着灰尘，像
是已许久没有人来过！蛛网。在风中飘摇，有些蛛网巳被风吹
断了，蜘蛛正忙着在重新绘起。 
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"yongdao7",
                
                
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        add_action("do_pull", "pull");
} 
int do_pull(string arg)
{
        object room;
        object me;
        me = this_player();
        room = load_object(__DIR__"studyroom");
        message_vision("$N只听“格”的一声，接着，又是一连串‘格格”声响，蛛网下的一堆枯柴突然缓缓移
动，露出一个洞来！\n",me);
        tell_object(me,"你越坠越快．．．．你似乎听见了一声惨叫，不禁毛骨悚然。\n");
        me->move(room);
        return 1;
}   
