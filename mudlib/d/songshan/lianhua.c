 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "莲花寺");
        set("long", @LONG
莲花寺，寺如其名，北方山地之中，居然有如此多，如此美的
荷花，实在让人难以相信。碧绿的潭水衬着满池粉红的荷花，寺内
简朴自然，绝无金壁辉煌之修。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"erzu",
  "southdown" : __DIR__"qingliang",
]));
        set("objects", ([
        "/d/taoyuan/npc/rabbit": 2,
        ]) ); 
        set("coor/x",-220);
        set("coor/y",390);
        set("coor/z",60);
        setup();
        replace_program(ROOM);
}       
