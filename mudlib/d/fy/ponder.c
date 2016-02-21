 inherit ROOM;
void create()
{
        set("short", "洗礼池");
        set("long", @LONG
“黄沙百战穿金甲，不破楼兰终不还“，风云城里的官兵经常出外征战，这里
是他们回来接受洗礼（ｓａｌｕｔｅ），以求洗去杀孽之气的地方。布置得很简单，
偌大的一个屋子，中间一个水池，池中冒出袅袅雾气。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"ecloud4",
]));
        set("outdoors", "fengyun");
        set("coor/x",40);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
}
void init()
{
       add_action("do_ponder","salute");
}
int do_ponder(string arg)
{
       object who; 
       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("你的神不够。\n");
       message_vision("$N将双手浸入水池中。\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N身上的杀孽之气似乎轻了。 \n" , who);
    return 1;
}       
