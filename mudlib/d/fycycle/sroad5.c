 inherit ROOM;
void create() 
{ 
        set("short", "城南小路"); 
        set("long", @LONG 
小径沿着风云城的护城河向北弯去。南边是一片古木参天的树林。 
树林里传来一阵阵的兵刃交击的声音，不时还夹杂着几声吆喝，吆喝的 
人中气很足，一听就知道是武林高手。路上的行人面带焦虑，气氛有些 
紧张。 
LONG 
        ); 
        set("exits", ([ /* sizeof() == 4 */ 
 //"east" : "/u/hangzhou/road0", 
  "northeast" : __DIR__"sroad6", 
  "southwest": __DIR__"sroad4", 
])); 
        set("outdoors", "fengyun"); 
        set("coor/x",40); 
        set("coor/y",-80); 
        set("coor/z",0); 
            replace_program(ROOM); 
 
        set("coor/x",40); 
        set("coor/y",-80); 
        set("coor/z",0); 
        setup(); 
} 
     
