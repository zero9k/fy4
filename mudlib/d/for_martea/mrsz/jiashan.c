 inherit ROOM;
void create()
{
        set("short", "假山");
        set("long", @LONG
这是一座怪石嶙峋的假山，下面铺着很多大大小小的鹅卵石。假山上有很多孔
洞，一阵微风吹过，孔洞穴发出“飕飕”的响声，不过有很多孔洞被地上的鹅卵石
塞的严严实实，不知道是不是有人刻意镶嵌上去的。假山的西面是个池塘。东面依
山而建一座楼阁，门上横匾上写“栖鹤轩”三字。
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"qihexuan",
        "south" : __DIR__"changlang5",
        "west" : __DIR__"chitang",
        "northwest" : __DIR__"houhuayuan1",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
