 inherit ROOM;
void create()
{
        set("short", "栖鹤轩");
        set("long", @LONG
与盘龙阁与卧虎堂比起来，栖鹤轩可要颇富诗意多了，这里倒更象是一处书房。
一张古意盎然的书案放在房间正中，案上摆着几本翻开了的线装书籍，一支铁笔斜
斜的压在上面，笔尖寒光闪闪，份量不轻。由于子鹤三少爷自幼不愿与父习武，全
凭一手高超的暗器防身，想必那是他的独门暗器了。
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"jiashan",
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
