 inherit ROOM;
void create()
{
        set("short", "隐仙岩");
        set("long", @LONG
走到这里，已是武当山腰。在这里仰望浮云，俯视流水。当真有
“荡胸生层云”的体会。回过身来，但见天尽处，落日熔金，暮云合
壁，艳丽无方。
LONG
        );
        set("exits", ([
        "eastup" : __DIR__"tianzhufeng",
        ]));
        set("outdoors", "wudang");
        set("coor/x",100);
        set("coor/y",-180);
    set("coor/z",90);
        setup();
        replace_program(ROOM);
}       
