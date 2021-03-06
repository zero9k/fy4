 // buy.c
#include <ansi.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
void pay_him( object who, int amount);
int affordable(object who, int amount);
int main(object me, string arg)
{
        string item, targ;
        object ob, owner;
        int price, afford, change;
        if( arg ) {
                //-> Added by neon :P   
                arg = replace_string(arg, "$BLK$", BLK);
                arg = replace_string(arg, "$RED$", RED);
                arg = replace_string(arg, "$GRN$", GRN);
                arg = replace_string(arg, "$YEL$", YEL);
                arg = replace_string(arg, "$BLU$", BLU);
                arg = replace_string(arg, "$MAG$", MAG);
                arg = replace_string(arg, "$CYN$", CYN);
                arg = replace_string(arg, "$WHT$", WHT);
                arg = replace_string(arg, "$HIR$", HIR);
                arg = replace_string(arg, "$HIG$", HIG);
                arg = replace_string(arg, "$HIY$", HIY);
                arg = replace_string(arg, "$HIB$", HIB);
                arg = replace_string(arg, "$HIM$", HIM);
                arg = replace_string(arg, "$HIC$", HIC);
                arg = replace_string(arg, "$HIW$", HIW);
                arg = replace_string(arg, "$NOR$", NOR);
        }
        
        if( me->is_busy())
                return notify_fail("你上一个动作还没有完成，不能买物品。\n");
                
        if( !arg || sscanf(arg, "%s from %s", item, targ)!=2 )
                return notify_fail("指令格式：buy <某物> from <某人>\n"); 
        if( !objectp(owner = present(targ, environment(me))) )
                return notify_fail("你要跟谁买东西？\n"); 
        if( userp(owner) ) {
                message_vision("$N想向$n购买「" + item + "」。\n", me, owner);
           return 1;
        } 
//      notify_fail("对方好像没有你想要的东西。\n");
//      if( (price = owner->buy_object(me, item)) < 1 ) return 0; 
        if( (price = owner->buy_object(me, item)) < 1 )
        return notify_fail("对方好像没有你想要的东西。\n");
        if( afford = affordable(me, price) ) {
                
                if(owner->compelete_trade(me, item) ) {
                        pay_him(me, afford-price);
                        owner->add("richness",price);
                } else return notify_fail("交易没有做成。\n");
                
                return 1;
        } else
                return notify_fail("你的钱不够。\n");
        me->start_busy(1);
} 
int help(object me)
{
   write( @HELP
指令格式: buy <something> from <someone> 
这一指令让你可以从某些人身上买到物品。 
你可以使用英文ID或中文名字。如果所购买的物品有颜色，请参照以下
规则： 
buy <颜色代码><物品名称>$NOR$ from <someone> 
<颜色代码> 
$BLK$ - 黑色            $NOR$ - 恢复正常颜色
$RED$ - 红色            $HIR$ - 亮红色
$GRN$ - 绿色            $HIG$ - 亮绿色
$YEL$ - 土黄色          $HIY$ - 黄色
$BLU$ - 深蓝色          $HIB$ - 蓝色
$MAG$ - 浅紫色          $HIM$ - 粉红色
$CYN$ - 蓝绿色          $HIC$ - 天青色
$WHT$ - 浅灰色          $HIW$ - 白色 
HELP
   );
   return 1;
} 
void pay_him(object who, int amount) 
{
        object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
        if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);  
        if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
           ob->set_amount(amount);
                ob->move(who);
        }
} 
int affordable(object me, int amount)
{
        int total;
        object cash, tencash, gold, silver, coin; 
        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me); 
        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value(); 
        if( total < amount ) return 0; 
        return total;
}     
