#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(HIB"����"NOR, ({ "quman" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 100);
                set("armor_prop/karma", 50);
                set("long", @LONG
�ڷ����ڶ������֮�У������Ǽ��������һ������������һ����������
�ı��£����Ҿ�˵�����Դ�������һ��һ���ĺ��ˡ�����������һ������
���˵Ĺ��¡�
һ�������������Ĺ������ֽй����ȡ������۾��������ϵ�����һ��������
����ͷ��������ķ�һ��Ʈ�ᡣ������ȴ�����ˡ�һ�������в������
ҽ�������޲ߵĲ��������Ƕ��Ѿ���������£�����ľվ�˳���������Ҫ
����ɽ�������Ƕ�����һ����ԭ����ʱ�ڹ��ϵĲ�����������һ��Ϯϰ��
���ǵ������װ����˴�Σ��ʱ���������ܶ���һ�ˣ�����ǧ����ൽ��
ɽ��ժ��ǧ��ѩ������ôɽ��ͻ���˶��ж����Ӷ���������ʩ�������
�ס�����ȴ��һ������ð�յ����顣�������������������ȡ�㰮�˵���
����������һƬ��Ȼ��ʱ�򣬰���ľ���ĵ��뿪������һ���������ϡ���
��������ڹ��ⷢ��������ʬ�塣�������н������ŵ�ȴ��������������
��ǧ��ѩ�����������Թ����ȵİ��ж���ɽ�񣬹����Ⱥܿ���Ȭ�ˡ�Ȼ��
����ľ�����ˣ������Ȼ�������ʲô���塣�������ڰ���ľ����ĵ����죬
��������ľ��ʬ������������Ϊ�˼������ǡ��Ͱ���ǧ��ѩ��������һ��
���ġ�
LONG);
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);
        }
        ::init_cloth();
}      
void owner_is_killed(object killer)
{
	if(objectp(killer))
        {
        message_vision("����������ʬ�������$N�Ļ��У�\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}