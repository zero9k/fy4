 // TIE@FY3
#include <armor.h>
inherit NECK;
#include <ansi.h>
void create()
{
        set_name(HIW"天竺佛珠"NOR, ({ "fozhu" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("long", @LONG
这是西藏高僧葛伦喇嘛佩带的佛珠，在西藏古老而神秘的宗教传统中，葛伦喇嘛
不仅是位深通佛理的高僧，也是治理万民的大吏，他的地位仅次于他们的活佛达
赖。从一被册封为活佛，这串佛珠就注定要伴随着他这一生，也许千万次生死轮
回。葛伦年轻的时候，它出现的地方就是一片腥风血雨，因为他说过：“我们的
教义和中土不同，我们不戒杀生，因为不杀生就不能降魔。我们对付妖魔罪人叛
徒仇敌的方法就只有一种，同样的一种----以眼还眼，以牙还牙！”在唯一的亲
人普松死在“心剑”下以后，卜鹰的一剑使他幡然悟道，从此专注于佛学，青灯
白卷，这串佛珠就是他唯一的伙伴，光亮润滑的表面是多年摩挲的结果，幽幽的，
闪烁着暗红的光芒。
但是正邪双方八角街一战，纵火烧掉了他的寺庙，这串佛珠也就此不知所踪。正
耶，邪耶，是耶，非耶，谁又能分得清？虽然说物我两忘，每当夕阳在大漠戚戚
落下的时候，葛伦喇嘛总是想起它......
LONG);
                set("material", "stone");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);
                set("armor_prop/armor", 10);
                set("armor_prop/composure",2);
        }
        ::init_neck();
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
