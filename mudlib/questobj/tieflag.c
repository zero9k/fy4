 //tieflag.c
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR "铁血大旗" NOR, ({ "tiexue-flag" }) );
    set_weight(10000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "面");
            set("value", 0);
            set("material", "cloth");
            set("long", "一面用鲜血染成的旗帜，是铁血大旗门掌门信物。\n");

//        set("no_drop", 1);
//        set("no_sell", 1);
//        set("no_give", 1);
//        set("no_put", 1);
          set("skill", ([
                        "name":         "tie-steps",             
                        "exp_required": 50000,                          
                        "sen_cost":     50,                     
                        "difficulty":   50,                     
                        "max_skill":    100              
                        ]) );
          } 
    ::init_item();
}      
