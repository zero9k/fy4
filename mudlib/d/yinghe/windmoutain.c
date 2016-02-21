 // Room: windmoutain.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "黄风山"); 
        set("long", @LONG
险峻的山岭上，茅草及腰，怪风阵阵。山路边时有遗留的骸骨，也不知道是人
骨还是兽骨。行于此处，你不得不打点精神，小心行动。
LONG);
        set("long_night", @LONG
险峻的山岭上，荧光微微，怪枭夜啼。山路边时有遗留的骸骨，也不知道是人
骨还是兽骨。行于此处，你不得不打点精神，小心行动。
LONG);  
        set("outdoors", "yinghe");
        set("exits",([
                "eastdown":__DIR__"dryroad",
                "westdown":__DIR__"dryroad3",
        ]) );
        //}}
        set("objects", ([
                __DIR__"npc/bandit" : 2+random(3),
                __DIR__"npc/crazy_dog" : 1,
        ]));
        setup();
        replace_program(ROOM);
}   
