#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
    set_name(CYN"沧海明月心"NOR, ({ "moonheart"}) );
        set_weight(15);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", CYN"一粒龙眼般大小的，光采圆润夺目的珍珠，在皎洁的月光下闪烁着令人眩目的\n五彩光华。很久以前，传说美人鱼的眼泪能化作价值连城的宝石。人们就伤害\n人鱼，令她们流泪以获取财富。这一切惹怒了海之神，他催动海潮，淹没了大\n地。大地万物，尽入汪洋。 潮水退后，幸存的人们所能看到的只是这一颗在\n阳光下傲视一切的珍珠。这是大海留给人们的纪念。它仿佛在告诉人们，告诉\n人们应该追求什么。。。年轻人啊，爱情才是最珍贵的东西。\n\n"NOR+HIR"                      珍惜她吧，直到永远!  \n\n"NOR);

        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);
        set("unit", "颗");
        set("value", 0);
        set("armor_prop/personality", 6);
           set("wear_msg", HIC"$N轻轻地把一颗$n"HIC"镶在发髻中，顿时整个房间都亮了起来。\n$N沐浴在五彩的光华中，仿佛仙子下凡一般。\n"NOR);
        set("remove_msg", HIC"$N小心翼翼地把$n"HIC"除了下来。\n"NOR);
                set("female_only", 1);
        }
        ::init_head();
}     
void owner_is_killed(object killer)
{
      	if(objectp(killer))
        {
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}
