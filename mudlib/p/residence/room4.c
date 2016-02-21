 inherit ROOM;
void create ()
{
  set ("short", "泰安广场");
  set ("long", @LONG
在这里你能享受到城内少有的清净。彩色石块铺成的大道向四方伸延。广场
呈菱形，街面是由碗口大的彩色石块铺成，青兰紫绿，煞是好看。广场旁有个清
水池，池内鱼虾龟虫倒也养了不少，在这四季如春的气候下，荷花睡莲无比妖娆。
LONG);
        set("exits", ([
//"down" : __DIR__"kxin1032739838",
//"up" : __DIR__"coldhan1029438380",
//"west" : __DIR__"nfy1025472485",
//"westup" : __DIR__"sunlx1020433536",
"east" : __DIR__"xiaolang1",
"west" : __DIR__"feather1",
"eastup" : __DIR__"mars1",
"north" : __DIR__"owen1",
  "south" : __DIR__"room3",
  "northeast" : __DIR__"room6",
  "northwest" : __DIR__"room5",
]));
        set("coor/x",10);
        set("coor/y",2030);
        set("coor/z",30);
        set("owner","public");
        setup();
  replace_program(ROOM); 
} 
      
