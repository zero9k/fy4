#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"仙笑歌"NOR, ({ "xxge" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "谱");
            set("material", "stone");
                set("long", @LONG
原本是名震天下的大旗谷谷主夜帝之子。后与美绝天下的水灵光相恋。那
朱藻本是琴，棋，书，画，无所不通之人。身为夜帝之子，武功自是不在
话下。于水灵光热恋之时，曾写有一谱仙笑歌，奏时有如仙乐飘飘，璀金
饮月。令人把凡尘俗世，苦痛离愁，都抛之脑后。实是绝世之佳作。更兼
其中蕴藏着大旗英雄派之绝世心法。或是造化弄人，在他和水灵光成婚之
晚，竟发现二人乃是同父异母的同胞兄妹。如此惊变，任是朱藻一代侠士，
还是难以承受。极悲之下，夺门绝尘而去。自此，消声匿迹，那一谱仙笑
歌也不知所踪。武林中人对这仙笑歌自是垂唁已久。自然不会放过这个练
就绝世武功的机会。群集而寻，虽苦劳不获，却依然乐此不疲。殊不知，
从古至今，绝世武功兼由人而创。武林秘籍，也是由人而来。真正的绝世
武功乃是在心中，又岂是靠运气而来。
LONG);

//        set("no_drop", 1);
//        set("no_sell", 1);
//        set("no_give", 1);
//        set("no_put", 1);
          set("skill", ([
                        "name":         "ill-quan",             
                        "exp_required": 50000,                          
                        "sen_cost":     50,                     
                        "difficulty":   50,                     
                        "max_skill":    50              
                        ]) );
          } 
    ::init_item();
}