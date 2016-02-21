 inherit ROOM;
void create()
{
        set("short", "长乐坊");
        set("long", @LONG
这里本是一品钦差殷大人在风云城的衙门所在，自殷大人遗失了当今圣上的尚
方宝剑，被皇上一怒之下贬至济南为官后，旧日风光无限的衙门便门厅冷落，破败
不堪。后来一名行走江湖的落魄客却偏偏拣了这里摆开道场，玩起了江湖把戏，不
过牛皮倒真不是吹的，至今为止无人能拆穿这骗子的小把戏。这骗子也从中捞了不
少，更堂而皇之的在衙门旧址建起了这家长乐坊。东面的墙壁上高高挂了一个牌子
（ｓｉｇｎ），上面写着游戏的玩法。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud2",
]));
        set("item_desc", ([
                "sign": @TEXT
这里是长乐坊，以下是游戏的玩法： 
要玩本游戏你身上必须要有银子才行
play    开始玩游戏
show    查看状态
resign  认输
take    拿石子
比如： take 5 3 表示从第五行拿三个石子
规则很简单，大家轮流拿石子，谁先拿到最后一个谁就赢了。 
TEXT
        ]) );
        set("objects", ([
        __DIR__"npc/pianzi": 1,
                        ]) ); 
        set("indoors", "fengyun");
        set("coor/x",-20);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
