 // gold.c
#include <ansi.h>
inherit MONEY; 
void create()
{
        set_name(HIY"碎金"NOR, ({"gold piece", "gold"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "黄澄澄的碎金，人见人爱的金子，啊～～金子！\n");
                set("unit", "些");
                set("base_value", 10000 );
                set("base_unit", "块");
                set("base_weight", 37);
        }
        set_amount(1);
}       
