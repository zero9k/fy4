 inherit ROOM;
void create()
{
        set("short", "ɽ�����"); 
        set("long", @LONG
���������ģ������ȥ�����������Լ�����ָ�����¿Ŀİ�����Ҳ��֪��
��ȵ�ʲô�������������Ǿ���������·�ĺá�Զ����ͣ�Ĵ�������ɽϪ������
�����ƺ��ڸ����㲻Զ�ĵط������������е�������Դ��
LONG);
        set("outdoors", "fugui");
        set("type","road");
        set("exits",([
                "east":__DIR__"shanlin1",
                "south":__DIR__"shanlin2",
                "west":__DIR__"shanlin",
                "north":__DIR__"shanlin3",
        ]) );
        set("coor/x",-590);
        set("coor/y",160);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}      