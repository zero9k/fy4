 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "ǡ�˲���ɽ");
        set("long", @LONG
ʯ����ԫ��ب�ڲ���������ǡ�˲���ɽ֮�䣬ɽͷ�ϲ�����¥����������Ժ��
���٣���ɽ��ԶԶ�������������������Ǹ�������ʯ�ϵľ޴�Ǳ��������������
����Ĵ�����������������ô��������ô���͡�
LONG
        );
        set("exits", ([ 
                "northeast":  __DIR__"garden",
                "south":  AREA_RESORT"smallroad4",
        ]));
        set("objects", ([
                
        ]) );
        set("outdoors", "guanwai");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}