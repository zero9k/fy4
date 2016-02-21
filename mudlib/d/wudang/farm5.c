 inherit ROOM;
void create()
{
        set("short", "庄稼地");
        set("long", @LONG
一块绿油油的麦田。田中半人高的麦杆儿随风而动，正如江湖中
的你，随著江湖之中汹涌的波涛，四处飘摇。你想到江湖中的无奈,
不禁沧然泪下。 
LONG
        );
        set("exits", ([
                "north" : __DIR__"farm1",
                "south" : __DIR__"farm5",
                "east" : __DIR__"farm7",
                "west" : __DIR__"farm5",
        ]));
        set("outdoors", "wudang");
        set("coor/x",70);
        set("coor/y",-80);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
