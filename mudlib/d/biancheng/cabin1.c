 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "Сľ��");
        set("long", @LONG
һ����Ȼ�Ѳоɡ�ȴ�Ǻ�ľ���İ��������Ͱ����Ŷ��档������һ��ȱ������
�������룬�����Ÿ����裬���湩��ȴ���ǹط��ӣ��������ﱧ�������޵����ӹ�
�������������������ľ���ӣ���һ�����������Ȼ�Ѿ��ܾ�û�����ù���ױ̨��
һ���⻨ͭ�������ǻҳ���ľ��ĳ�Ҳ���˺ü�����
LONG
        );
        set("exits", ([ 
        "east": __DIR__"smallroad1",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",-1160);
        set("coor/y",170);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      