 inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("��̳", ({ "altar","jitan","��̳"}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����̳����������ڵ���ᣡ�\n");
                set("prep","up");
                set("value", 1);
        }
        ::init_item();
} 
int is_container() { return 1; }   
