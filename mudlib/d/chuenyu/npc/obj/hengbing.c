#include <ansi.h>
#include <weapon.h> 
inherit SWORD; 
void create()
{
        set_name( "銮鱼衡冰", ({ "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把银白色的的长剑，份量大约有十来斤左右，剑身上雕了十二个人形。\n");
                set("value", 20000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入背後的剑鞘。\n");
                                set("skill", ([
                        "name":         "spring-sword",             
                        "exp_required": 200000,                          
                        "sen_cost":     200,                     
                        "difficulty":   200,                     
                        "max_skill":    200              
                        ]) );
//              set("no_sell",1);
/*              set("no_drop",1);
                set("no_get",1); */
                }
        ::init_sword(50);
}     
