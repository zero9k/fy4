#include <ansi.h>
#include <armor.h> 
inherit NECK; 
void create()
{
        set_name(WHT"��ɫ����"NOR, ({ "white bead", "bead" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("value", 7000);
        set("material", "cloth");
        set("armor_prop/armor", 10);
        set("wear_msg", "$N�ó�һ��$n��Ħ���˼��£�Ȼ����ھ��ϡ�\n");
        set("unwear_msg", "$N�������е�$n��\n");
        }
        ::init_neck();
}