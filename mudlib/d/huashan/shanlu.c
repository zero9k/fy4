 inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
穿过松树林，一条小路出现在眼前，石阶铺就的山路断断续续先前延伸。路旁
石壁上生长着一大片青苔，触手之下冰凉湿润，青苔下石缝间有水滴一滴滴缓缓流
下，最后凝聚在一个小小的石凹里。
LONG
        );
    set("exits", ([ 
                "northeast" : __DIR__"ziqi",
            "westup" : __DIR__"yanluo",
        ]));
   
    set("outdoors", "huashan"); 
    set("coor/x",-600);
    set("coor/y",-100);
    set("coor/z",70);
        setup();
    replace_program(ROOM);
}  
