 inherit ROOM;
void create()
{
        set("short", "����԰");
        set("long", @LONG
��վ�ں��ɳǱ�������԰���԰�ﳤ���˸�ʽ�����滨��ݡ�
������ʵĳ�ǽ�ϳ�������ɫ�����١����ٴ�ǽ��һֱ������Ľ��¡�
������������ΰ�ĺ��ɸ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"west_blackge",
        ]));
        set("item_desc", ([
                "wall": "��ǽ�䶸�������������١����ƺ�����������(climb)��ȥ��\n",
                "��ǽ": "��ǽ�䶸�������������١����ƺ�����������(climb)��ȥ��\n",
                "����": "���ٳ����˳�ǽ�����ƺ�����������(climb)��ȥ��\n"       
        ]) );
                set("objects", ([
                __DIR__"npc/gardener" : 1,
                __DIR__"npc/bee" : 2,
        ]) ); 
       set("outdoors", "chuenyu"); 
        set("coor/x",100);
        set("coor/y",190);
        set("coor/z",40);
        setup();
} 
void init()
{
        add_action("climbing", "climb");
} 
int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
   }
        if( arg == "wall" || arg == "����" || arg == "��ǽ")
        {
                me = this_player();
                if (me->query_temp("climbdown"))
                        {
                                write("���Ѿ������ˡ�\n");
                                return 1;
                        }
                message_vision("$Nץ�����٣�������˳�ų�ǽ������ȥ��\n", me);
                me->start_busy(3);
                call_out("fliping",4,me);
//              me->stop_busy();
                me->set_temp("climbdown",1);
                return 1;
        }
        else
        {
                write("�㲻������"+arg+"��\n");
                return 1;
        }
} 
int fliping(object me)
{
        if(!me->is_ghost()){
                me->move(__DIR__"west_castle.c");
                message_vision("$N�ɿ����٣��ӳ�ǽ������ߴ�һԾ���¡�\n", me);
        }
        me->delete_temp("climbdown",1);
        return 1;
}     