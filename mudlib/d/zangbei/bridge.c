 inherit ROOM;
#include <ansi.h>
int lu_disappear(object lu); 
void create() 
{
        set("short", "С����ˮ");
        set("long", @LONG
���ɫ�ĳ���������ɽ�ּ䡢Ȫˮ�������ֽ���һ�������Ʈ��Ʈɢ��Զ����
С���Ե����������м������߳���������������Ů�������ߴ��ź�Ƿ���������ŷ�
�ŵ�ս�֡��������㲻��������õ���ľ���õ�Ů�ˣ��������������Լ���
��Ϊ��Զ�޷�ʵ�ֵ����롣ֻҪ�㹻��������������������������˵�����
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"bigtree",
                "west":  __DIR__"happywood",
                "east":  __DIR__"happyroom",
        ]));
        set("objects", ([
                __DIR__"npc/huhua": 1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}  
void reset() {
        int dayTime;
        mixed *local;
        object lu;
        
        :: reset();
        local = NATURE_D->get_current_time();
        dayTime = local[5];
        if(dayTime > 240 && dayTime < 900) {
                call_out("do_reveal",2);
        } 
} 
int do_reveal() {
   object lu,qin;
        object *inv, *players;
        int i;
        
        message("vision",CYN"\n�и��˴Ӹ��ϴ���������߳�����������С�š�\n"NOR,this_object());
        lu=new(__DIR__"npc/lumantian2");
        lu->move(this_object());
        qin=present("qin huhua",this_object());
        if (qin && !userp(qin) && !qin->is_fighting()) 
                message("vision",CYN"
�ػ�����Ц��ͻȻ��ͣ���ˣ����ϵ���ɫ���̱�úܹ��������������Ϲ�����
������ֻ���˵�ͷ�����⺮�������䡣\n\n"NOR,this_object());
        inv = all_inventory();
        players = filter_array(inv, (: interactive($1) :));
        for(i=0; i<sizeof(players); i++) {
                if (!players[i]->query("zangbei/�Ӵ�ɱ����")) continue;
                tell_object(players[i],"��������ϴ�Ľ������̲�ס�����࿴�˼��ۡ�\n");
                if (!players[i]->query("zangbei/�����_½����")) 
                        players[i]->set("zangbei/�����_½����", 1);
        }
        call_out("lu_disappear",10,lu);
        return 1;
}  
int     lu_disappear(object lu) {
        
        
        if (!lu) return 1;
        if (lu->is_fighting()) {
                call_out("lu_disappear",lu,10);
                return 1;
        }
        message_vision(CYN"$N���߳��˿���֡�\n"NOR,lu);
        destruct(lu);
        return 1;
}      