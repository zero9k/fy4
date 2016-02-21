#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"竹牌"NOR, ({ "zhupai" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "块");
            set("material", "stone");
                set("long", @LONG
昔年西方魔教力挺中原时，教主羽天白带领手下四大长老：金狮，银龙，
铜驼，铁燕，经过无数浴血奋战，终于在中原打出一番天。正当魔教声势
如日中天时，教主羽天白却值练功紧要关头，须修关一月。遂将教内之事
与于四大长老掌管，封刀闭关。却岂不料，四大长老中的金，银，铁三人
趁此关头，打着魔教的名头，横行武林，所到之处，竟是血雨腥风，为中
原武林带来无尽灾难。想那魔教本是外来势力插足于中原。虽为异类，却
并不输于那名门正派之流。但如此一来，中原武林五大门派便群起而攻之，
力图扫尽魔教。时执再有两天便是教主羽天白出关之日。金，银，铁三大
长老惟恐羽天白在出关之日迁怒于己，竟卑鄙至极。秘密窜通五大门派，
埋伏于祁连山之上，要将魔教弟子尽数歼灭。想是苍天有眼。魔教三大护
法之一青竹竟在无意中从五大门派弟子口中得此消息。于是他日夜兼程赶
往四大长老之一忠心耿耿的铜驼求救。却不料途中遭到埋伏。生死关头，
将叛逆名字刻于他所持竹牌之上，暗中抛下深渊。企盼老天有眼，日后若
让铜驼得此竹派，定会为魔教千万弟兄报此深仇。
LONG);

      set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);
          } 
    ::init_item();
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