 // icy_boot.c
#include <ansi.h>
#include <armor.h> 
inherit BOOTS; 
void create()
{
        set_name(  "�Ʋ�Ь" , ({ "shoes", "shoes" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("value", 8000);
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/dodge", 10);
        }
        ::init_boots();
}     
