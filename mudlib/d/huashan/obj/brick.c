#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name("ש�߶�", ({ "brick", "ש�߶�" }) );
        set_weight(50000);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep","in");
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long", "һ��ɢ�ҵ�ש�顣\n");
            set("value", 1);
        }
        ::init_item();
} 
int is_container() { return 1; }    
