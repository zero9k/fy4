 inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name("碎纸片右上角", ({ "some paper","paper"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
        set("long", "一张撕碎了的纸片，上面写着“桃花娘子”。\n");
        set("value", 2);
        set("lore",1);
        }
        ::init_item(); 
}  
 